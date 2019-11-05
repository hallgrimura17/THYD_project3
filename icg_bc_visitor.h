#ifndef TURBOPASCAL_ICG_BC_VISITOR_H
#define TURBOPASCAL_ICG_BC_VISITOR_H
#include <string>
#include <sstream>
#include "ast.h"
#include "krakatau.h"
#include "symbol_table.h"

class ICG_BC_Visitor : public AST::Visitor {
 public:

  explicit ICG_BC_Visitor( SymbolTable* st ) : st_(st) {}

  ///////////////////////////////////////// Expression Nodes /////////////////////////////////////////////////////////

  void visit( AST::IntegerExprNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.bc_ldc( node->get_value() ) );
  }


  void visit(AST::RealExprNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.bc_ldc( node->get_value() ) );
  }


  void visit(AST::BooleanExprNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.bc_ldc( node->get_value() ) );
  }


  void visit(AST::OpExprNode *node) override {
    assert(node != nullptr);

    if ( node->get_op() == LNG::ExprOperator::o_and ||  node->get_op() == LNG::ExprOperator::o_or ||
         node->get_op() == LNG::ExprOperator::o_not ) {
      boolean_operations( node );
    }
    else {
      if ( (node->get_lhs() != nullptr && node->get_lhs()->get_sdt() == LNG::SimpleDataType::tReal) ||
           node->get_rhs()->get_sdt() == LNG::SimpleDataType::tReal ||
           node->get_op() == LNG::ExprOperator::o_divide ) {
        float_operations( node );
      }
      else {
        int_operations( node );
      }
    }
  }


  void visit(AST::StringExprNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.bc_ldc( "'" + node->get_str() + "'" ) );
  }


  void visit( AST::VariableExprNode *node ) override {
    assert(node != nullptr);
    auto entry = symbol_table_lookup( node->get_name() );
    if ( node->get_expr() != nullptr ) {
      setup_array_reference( node->get_expr(), entry );
      program_.push_back( ic_.bc_aload_sdt( node->get_sdt() ) );
    }
    else {
      load_nonarray_value( entry );
    }
  }


  void visit(AST::FunctionCallExprNode *node) override {
    assert(node != nullptr);
    for (auto expr : node->get_arguments()) {
      accept(expr);
    }
    auto entry = symbol_table_lookup(node->get_name());
    program_.push_back( ic_.bc_invokestatic( node->get_name(), entry->signature ) );
  };


  ///////////////////////////////////////// Statement Nodes /////////////////////////////////////////////////////////

  void visit(AST::EmptyStmtNode *node) override {
    assert(node != nullptr);
  }


  void visit(AST::ProcedureCallStmtNode *node) override {
    assert(node != nullptr);
    for (auto expr : node->get_arguments()) {
      accept(expr);
    }
    auto entry = symbol_table_lookup(node->get_name());
    program_.push_back( ic_.bc_invokestatic( node->get_name(), entry->signature ) );
  };


  void visit(AST::IfStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_expr());
    BC::Label label_end = ic_.label_new();
    if (node->get_stmt_else() != nullptr){
      BC::Label label_else = ic_.label_new();
      program_.push_back( ic_.bc_if( LNG::ExprOperator::o_eq, label_else ) );
      accept(node->get_stmt_if());
      program_.push_back( ic_.bc_goto( label_end ) );
      program_.push_back( ic_.label( label_else ) );
      accept(node->get_stmt_else());
      program_.push_back( ic_.label( label_end ) );
    }
    else {
      program_.push_back( ic_.bc_if( LNG::ExprOperator::o_eq, label_end ) );
      accept(node->get_stmt_if());
      program_.push_back( ic_.label( label_end ) );
    }
  };


  void visit(AST::WhileStmtNode *node) override {
    assert(node != nullptr);
    BC::Label label_cond = ic_.label_new();
    BC::Label label_end = ic_.label_new();
    program_.push_back( ic_.label( label_cond ) );
    accept(node->get_expr());
    program_.push_back( ic_.bc_if( LNG::ExprOperator::o_eq, label_end ) );
    accept(node->get_stmt());
    program_.push_back( ic_.bc_goto( label_cond ) );
    program_.push_back( ic_.label( label_end ) );
  }

  void visit(AST::CompoundStmtNode *node) override {
    assert(node != nullptr);
    for (const auto stmt : node->get_stmts()) {
      accept(stmt);
    }
  };


  void visit(AST::ReadStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_arg());
    // We are not going to implement the read statement.
  }


  void visit(AST::WriteStmtNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.bc_getstatic( "java/lang/System", "out", "Ljava/io/PrintStream;" ) );
    accept(node->get_expr());
    std::string type = "Ljava/lang/String;";
    if ( node->get_expr()->get_sdt() != LNG::SimpleDataType::tVoid ) {
      type = JVMSimpleDataType(node->get_expr()->get_sdt());
    }
    std::string signature = "(" + type + ")V";
    if ( node->get_newline() ) {
      program_.push_back(ic_.bc_invokevirtual("println", "java/io/PrintStream", signature));
    }
    else {
      program_.push_back(ic_.bc_invokevirtual("print", "java/io/PrintStream", signature));
    }
  }


  void visit(AST::AssignmentStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_var());
    auto entry = symbol_table_lookup( node->get_var()->get_name() );
    assert( entry != nullptr );
    if ( entry->data_type.is_array()) {
      setup_array_reference( node->get_var()->get_expr(), entry );
      accept(node->get_expr());
      if(entry->data_type.get_sdt() == LNG::SimpleDataType::tReal && node->get_expr()->get_sdt() == LNG::SimpleDataType::tInteger){
        program_.push_back( ic_.bc_i2f() );
      }
      program_.push_back( ic_.bc_astore_sdt( entry->data_type.get_sdt()) );
    }
    else {
      accept(node->get_expr());
      if(entry->data_type.get_sdt() == LNG::SimpleDataType::tReal && node->get_expr()->get_sdt() == LNG::SimpleDataType::tInteger){
        program_.push_back( ic_.bc_i2f() );
      }
      store_nonarray_value( entry );
    }
  };

  ///////////////////////////////////////// Other Nodes /////////////////////////////////////////////////////////

  void visit(AST::VariableNode *node) override {
    assert(node != nullptr);
    /* Leave empty. It is best to do the implementation in AssignmentStmtNode. */
  }


  void visit(AST::VariableDeclNode *node) override {
    assert(node != nullptr);
    LNG::DataType dt = node->get_data_type();
    int array_size = dt.get_to_index() - dt.get_from_index() + 1;
    for (const auto &id : node->get_identifiers()) {
      if ( scope_.empty() ) {
        program_.push_back( ic_.macro_field( id, JVMDataType(node->get_data_type()) ) );
        if ( dt.is_array() ) {
          init_program_.push_back( ic_.bc_ldc( array_size ) );
          init_program_.push_back( ic_.bc_newarray( dt.get_sdt() ) );
          init_program_.push_back(ic_.bc_putstatic(ic_.get_class(), id,JVMDataType(dt)));
        }
      }
      else {
        ic_.add_to_locals( id );
        if ( dt.is_array() ) {
          program_.push_back( ic_.bc_ldc( array_size ) );
          program_.push_back( ic_.bc_newarray( dt.get_sdt() ) );
          program_.push_back(ic_.bc_astore( id ) );
        }
      }
    }
  }


  void visit(AST::ProcedureDeclNode *node) override {
    assert(node != nullptr);

    // Create a JVM method signature for the procedure, and store it in the symbol table.
    std::string signature = calc_signature( node->get_var_decl(), LNG::SimpleDataType::tVoid );
    auto entry = symbol_table_lookup(node->get_name());
    if ( entry != nullptr ) {
      entry->signature = signature;
    }

    program_.push_back( ic_.macro_method( "public static", node->get_name(), signature)  );
    program_.push_back( ic_.macro_code( 10, count_locals(node->get_var_decl(), node->get_block())  ) );
    scope_ = node->get_name();
    accept(node->get_var_decl());
    accept(node->get_block());
    program_.push_back(ic_.bc_return() );
    scope_ = "";
    program_.push_back( ic_.macro_code_end(  ) );
    program_.push_back( ic_.macro_method_end(  ) );
  }


  void visit(AST::FunctionDeclNode *node) override {
    assert(node != nullptr);

    // Create a JVM method signature for the function, and store it in the symbol table.
    std::string signature = calc_signature( node->get_var_decl(), node->get_data_type().get_sdt() );
    auto entry = symbol_table_lookup(node->get_name());
    if ( entry != nullptr ) {
      entry->signature = signature;
    }

    program_.push_back( ic_.macro_method( "public static", node->get_name(), signature ) );
    program_.push_back( ic_.macro_code( 10, count_locals(node->get_var_decl(), node->get_block())+1 ) );
    scope_ = node->get_name();
    accept(node->get_var_decl());
    ic_.add_to_locals( node->get_name() );  // create a local variable named as the function to store the return value.
    accept(node->get_block());
    program_.push_back(ic_.bc_load_sdt( node->get_data_type().get_sdt(), node->get_name()) );
    program_.push_back(ic_.bc_return( node->get_data_type().get_sdt() ) );
    scope_ = "";
    program_.push_back( ic_.macro_code_end(  ) );
    program_.push_back( ic_.macro_method_end(  ) );
  }


  void visit(AST::VariableDeclarationsNode *node) override {
    assert(node != nullptr);
    for (auto declaration : node->get_declarations()) {
      accept(declaration);
    }
  }


  void visit(AST::CallableDeclarationsNode *node) override {
    assert(node != nullptr);
    for (auto declaration : node->get_declarations()) {
      accept(declaration);
    }
  }


  void visit(AST::BlockNode *node) override {
    assert(node != nullptr);
    accept(node->get_var_decl());
    accept(node->get_call_decl());
    if ( scope_.empty() ) {
      program_.push_back( ic_.macro_method( "public static", "main", "([Ljava/lang/String;)V" ) );
      program_.push_back( ic_.macro_code( 10, 1 ) );
    }
    accept(node->get_stmt());
    if ( scope_.empty() ) {
      program_.push_back( ic_.bc_return( ) );
      program_.push_back( ic_.macro_code_end( ) );
      program_.push_back( ic_.macro_method_end( ) );
    }
  }


  void visit(AST::ProgramNode *node) override {
    assert(node != nullptr);
    program_.push_back( ic_.macro_version( 49 ) );
    program_.push_back( ic_.macro_class( node->get_name() ) );
    program_.push_back( ic_.macro_super( "java/lang/Object" ) );
    program_.push_back( ic_.macro_method( "public", "<init>", "()V" ) );
    program_.push_back( ic_.macro_code( 1, 1 ) );
    program_.push_back( ic_.bc_aload( "0" ) );
    program_.push_back( ic_.bc_invokespecial( "<init>", "()V" ) );
    program_.push_back( ic_.bc_return( ) );
    program_.push_back( ic_.macro_code_end( ) );
    program_.push_back( ic_.macro_method_end( ) );
    scope_ = "";
    accept(node->get_block());

    if ( !init_program_.empty() )  {
      init_program_.push_front( ic_.macro_code( 1, 1 ) );
      init_program_.push_front( ic_.macro_method( "static", "<clinit>", "()V" ) );
      init_program_.push_back( ic_.bc_return( ) );
      init_program_.push_back( ic_.macro_code_end( ) );
      init_program_.push_back( ic_.macro_method_end( ) );
      program_.splice(program_.end(), init_program_ );
    }
    program_.push_back( ic_.macro_source( "?" ) );
    program_.push_back( ic_.macro_class_end( ) );
  }

  //////////////////////////////// Writeout the program when done ////////////////////////////////////////////////////

  void output( std::ostream& os ) {
    for ( auto& instr : program_ ) {
      std::string str = instr.to_string();
      if ( !str.empty() && str[0] != '.' && str[0] != 'L' ) {
        os << '\t';
      }
      os <<  str << '\n';
    }
  }

 private:

  /////////////////////////////////////////////// Helper routines ////////////////////////////////////////////////////

  void accept(AST::Node *node) {
    if (node != nullptr) node->accept(*this);
  }

  SymbolTable::Entry* symbol_table_lookup( const std::string& id ) {
    auto entry = st_->lookup( scope_, id );
    if (entry == nullptr && !scope_.empty()) {
      entry = st_->lookup("", id);
    }
    assert( entry != nullptr );
    return entry;
  }

  std::string calc_signature( const AST::VariableDeclarationsNode* decls, LNG::SimpleDataType ret_sdt ) {
    std::stringstream ss;
    ss << '(';
    if ( decls != nullptr ) {
      for (auto dec : decls->get_declarations() ) {
        LNG::SimpleDataType  sdt = dec->get_data_type().get_sdt();
        for ( int i=0; i<dec->get_identifiers().size(); ++i ) {
          ss << JVMSimpleDataType( sdt );
        }
      }
    }
    ss << ')';
    ss << JVMSimpleDataType( ret_sdt );
    return ss.str();
  }

  std::string JVMSimpleDataType( Language::SimpleDataType sdt ) {
    std::string str;
    switch ( sdt ) {
        case Language::SimpleDataType::tVoid:     str += "V"; break;
        case Language::SimpleDataType::tBoolean:  str += "Z"; break;
        case Language::SimpleDataType::tInteger:  str += "I"; break;
        case Language::SimpleDataType::tReal:     str += "F"; break;
    }
    return str;
  }

  std::string JVMDataType( bool is_array, Language::SimpleDataType sdt ) {
    std::string str;
    if ( is_array ) { str = "["; }
    return str + JVMSimpleDataType( sdt );
  }

  std::string JVMDataType( Language::DataType dt ) {
    return JVMDataType( dt.is_array(), dt.get_sdt() );
  }


  int count_var_decls( AST::VariableDeclarationsNode* node ) {
    int count = 0;
    if ( node != nullptr ) {
      for (auto& declaration : node->get_declarations()) {
        count += declaration->get_identifiers().size();
      }
    }
    return count;
  }

  int count_locals( AST::VariableDeclarationsNode* var_decl, AST::BlockNode* blck ) {
      return count_var_decls( var_decl ) + count_var_decls( blck->get_var_decl() );
  }


  void setup_array_reference( AST::ExprNode* expr, const SymbolTable::Entry* entry ) {
    if ( entry->scope == "" ) {  // Global variable.
      program_.push_back( ic_.bc_getstatic( ic_.get_class(), entry->name, JVMDataType(entry->data_type) ) );
    }
    else { // Local variable.
      program_.push_back(ic_.bc_aload(  entry->name ) );
    }
    accept( expr );
    if ( entry->data_type.get_from_index() > 0 ) {
      program_.push_back(ic_.bc_ldc(entry->data_type.get_from_index()));
      program_.push_back( BC::Instr(BC::InstrCode::isub));
    }
  }

  void load_nonarray_value( const SymbolTable::Entry* entry ) {
    if ( entry->scope == "" ) {  // Global variable.
      program_.push_back( ic_.bc_getstatic( ic_.get_class(), entry->name, JVMDataType(entry->data_type) ) );
    }
    else { // Local variable.
      program_.push_back(ic_.bc_load_sdt( entry->data_type.get_sdt(), entry->name ) );
    }
  }

  void store_nonarray_value( const SymbolTable::Entry* entry ) {
    if ( entry->entry_type == SymbolTable::EntryType::sVariable && entry->scope == "" ) {  // Global variable.
      program_.push_back( ic_.bc_putstatic( ic_.get_class(), entry->name, JVMDataType(entry->data_type) ) );
    }
    else { // Local variable.
      program_.push_back(ic_.bc_store_sdt( entry->data_type.get_sdt(), entry->name ) );
    }
  }

  void int_operations( AST::OpExprNode *node  ) {
    AST::ExprNode* lhs = node->get_lhs();
    AST::ExprNode* rhs = node->get_rhs();
    accept( lhs );
    accept( rhs );
    switch ( node->get_op() ) {
      case LNG::ExprOperator::o_eq:
      case LNG::ExprOperator::o_neq:
      case LNG::ExprOperator::o_gt:
      case LNG::ExprOperator::o_gteq:
      case LNG::ExprOperator::o_lt:
      case LNG::ExprOperator::o_lteq: {
        BC::Label label_true = ic_.label_new();
        BC::Label label_end = ic_.label_new();
        program_.push_back(ic_.bc_if_icmp(node->get_op(), label_true));
        program_.push_back(ic_.bc_ldc(0));
        program_.push_back(ic_.bc_goto(label_end));
        program_.push_back(ic_.label(label_true));
        program_.push_back(ic_.bc_ldc(1));
        program_.push_back(ic_.label(label_end));
      }
        break;
      case LNG::ExprOperator::o_div:
        program_.push_back( BC::Instr( BC::InstrCode::idiv ) );
        break;
      case LNG::ExprOperator::o_minus:
        if ( lhs == nullptr ) {
          program_.push_back( BC::Instr( BC::InstrCode::ineg ) );
        }
        else { program_.push_back( BC::Instr(BC::InstrCode::isub)); }
        break;
      case LNG::ExprOperator::o_multiply:
        program_.push_back( BC::Instr( BC::InstrCode::imul ) );
        break;
      case LNG::ExprOperator::o_plus:
        program_.push_back( BC::Instr( BC::InstrCode::iadd ) );
        break;
      case LNG::ExprOperator::o_uminus:
        program_.push_back( BC::Instr( BC::InstrCode::ineg ) );
        break;
      default:
        assert( false );  // Should not happen.
    }
  }


  void float_operations( AST::OpExprNode *node ) {

    /************************* TO DO: Implement this method ***************************/
    /* Hint:
     *  - Look at the int_operations implementation.
     *  - The floats have comparable arithmetic operations .
     *  - The relational operations are slightly different for floats, use 'fcmpl' followed by 'if'<cmp>.
     * */


    AST::ExprNode* lhs = node->get_lhs();
    AST::ExprNode* rhs = node->get_rhs();
    accept( lhs );
    if (lhs->get_sdt() == LNG::SimpleDataType::tInteger){
        program_.push_back( ic_.bc_i2f() );
    }
    accept( rhs );
    if (rhs->get_sdt() == LNG::SimpleDataType::tInteger){
        program_.push_back( ic_.bc_i2f() );
    }
    switch ( node->get_op() ) {
      case LNG::ExprOperator::o_eq:
      case LNG::ExprOperator::o_neq:
      case LNG::ExprOperator::o_gt:
      case LNG::ExprOperator::o_gteq:
      case LNG::ExprOperator::o_lt:
      case LNG::ExprOperator::o_lteq: {
        BC::Label label_true = ic_.label_new();
        BC::Label label_end = ic_.label_new();
        program_.push_back(ic_.bc_fcmpl());
        program_.push_back(ic_.bc_ldc(0));
        program_.push_back(ic_.bc_goto(label_end));
        program_.push_back(ic_.label(label_true));
        program_.push_back(ic_.bc_ldc(1));
        program_.push_back(ic_.label(label_end));
      }
        break;
      case LNG::ExprOperator::o_divide:
        program_.push_back( BC::Instr( BC::InstrCode::fdiv ) );
        break;
      case LNG::ExprOperator::o_minus:
        program_.push_back( BC::Instr(BC::InstrCode::fsub  ) );
        break;
      case LNG::ExprOperator::o_multiply:
        program_.push_back( BC::Instr( BC::InstrCode::fmul ) );
        break;
      case LNG::ExprOperator::o_plus:
        program_.push_back( BC::Instr( BC::InstrCode::fadd ) );
        break;
      case LNG::ExprOperator::o_uminus:
        program_.push_back( BC::Instr( BC::InstrCode::fneg ) );
        break;
      default:
        assert( false );  // Should not happen.
    }
  }

  void boolean_operations( AST::OpExprNode *node ) {

    /************************* TO DO: Implement this method ***************************/
    /* Hint:
     *  - The operations should leave either 0 (false) or 1 (true) on the JVM-stack.
     *  - Remember that you need to "short-circuit" the 'and' and 'or' evaluation.
     * */
    AST::ExprNode* lhs = node->get_lhs();
    AST::ExprNode* rhs = node->get_rhs();
    auto op = node->get_op();
    BC::Label label_cond = ic_.label_new();
    BC::Label label_end = ic_.label_new();
    if (op == LNG::ExprOperator::o_not) {
      accept( rhs );
      program_.push_back( ic_.bc_if( LNG::ExprOperator::o_eq, label_cond ) );
      program_.push_back( ic_.bc_ldc( 0 ) );
      program_.push_back( ic_.bc_goto( label_end ) );
      program_.push_back( ic_.label( label_cond ) );
      program_.push_back( ic_.bc_ldc( 1 ) );
      program_.push_back( ic_.label( label_end ) );
    }
    accept( lhs );
    if (op == LNG::ExprOperator::o_or) {
      program_.push_back( ic_.bc_ifne( label_cond ) );
      accept( rhs );
      program_.push_back( ic_.bc_goto( label_end ) );
      program_.push_back( ic_.label( label_cond ) );
      program_.push_back( ic_.bc_ldc( 1 ) );
      program_.push_back( ic_.label( label_end ) );
    }
    else if (op == LNG::ExprOperator::o_and) {
      program_.push_back( ic_.bc_ifeq( label_cond ) );
      accept( rhs );
      program_.push_back( ic_.bc_goto( label_end ) );
      program_.push_back( ic_.label( label_cond ) );
      program_.push_back( ic_.bc_ldc( 0 ) );
      program_.push_back( ic_.label( label_end ) );
    }
  }

  //
  // Private variables, feel free to add more if needed (should not be necessary).
  //
  std::string scope_;   // Need to update the scope as we traverse the AST to access the symbol-table correctly.
  SymbolTable* st_;     // We need some information from the symbol table.
  KrakatauAsm ic_;      // Assembler commands for the Krakatau assembler.

  std::list<KrakatauAsm::Instr> init_program_;  // Need to add initalizing code for static arrays.
  std::list<KrakatauAsm::Instr> program_;       // The program code.
};

#endif //TURBOPASCAL_ICG_BC_VISITOR_H
