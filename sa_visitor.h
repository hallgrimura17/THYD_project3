#ifndef TURBOPASCAL_SA_VISITOR_H
#define TURBOPASCAL_SA_VISITOR_H

#include <stack>
#include "ast.h"
#include "symbol_table.h"

class SemanticAnalysisVisitor : public AST::Visitor {
 public:

  explicit SemanticAnalysisVisitor( SymbolTable* st ) : st_(st) {}

  void visit(AST::IntegerExprNode *node) override {
    assert(node != nullptr);
    node->set_sdt( LNG::SimpleDataType::tInteger );
  }

  void visit(AST::RealExprNode *node) override {
    assert(node != nullptr);
    node->set_sdt( LNG::SimpleDataType::tReal );
  }

  void visit(AST::BooleanExprNode *node) override {
    assert(node != nullptr);
    node->set_sdt( LNG::SimpleDataType::tBoolean );
  }

  void visit(AST::OpExprNode *node) override {
    assert(node != nullptr);

    LNG::SimpleDataType sdt_result = LNG::SimpleDataType::tVoid;
    auto lhs = node->get_lhs();
    auto rhs = node->get_rhs();

    accept(lhs);
    accept(rhs);

    LNG::EO op = node->get_op();
    if ( lhs == nullptr ) {  // Unary operation.
      LNG::SimpleDataType sdt_rhs = rhs->get_sdt();
      switch (op) {
        case LNG::EO::o_minus:
          if ( sdt_rhs != LNG::SimpleDataType::tInteger && sdt_rhs != LNG::SimpleDataType::tReal ) {
            error("Type mismatch (minus op): expected Integer or Real, but found ", sdt_rhs);
          }
          sdt_result = sdt_rhs;
          break;
        case LNG::EO::o_not:
          if ( sdt_rhs != LNG::SimpleDataType::tBoolean ) {
            error("Type mismatch (not op): expected Boolean, but found ", sdt_rhs);
          }
          sdt_result = LNG::SimpleDataType::tBoolean;
          break;
        default:
          assert( false );
          break;
      }
    }
    else {
      LNG::SimpleDataType sdt_rhs = rhs->get_sdt();
      LNG::SimpleDataType sdt_lhs = lhs->get_sdt();
      switch (op) {
        case LNG::EO::o_and:
        case LNG::EO::o_not:
        case LNG::EO::o_or:
          if ( sdt_lhs != LNG::SimpleDataType::tBoolean && sdt_rhs != LNG::SimpleDataType::tBoolean ) {
            error("Type mismatch (logical op): expected Boolean, but found ", sdt_lhs, sdt_rhs);
          }
          sdt_result = LNG::SimpleDataType::tBoolean;
          break;
        case LNG::EO::o_eq:
        case LNG::EO::o_lt:
        case LNG::EO::o_lteq:
        case LNG::EO::o_neq:
        case LNG::EO::o_gt:
        case LNG::EO::o_gteq:
          if ( sdt_lhs != LNG::SimpleDataType::tReal && sdt_lhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (relational op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          if ( sdt_rhs != LNG::SimpleDataType::tReal && sdt_rhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (relational op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          sdt_result = LNG::SimpleDataType::tBoolean;
          break;
        case LNG::EO::o_divide:
          if ( sdt_lhs != LNG::SimpleDataType::tReal && sdt_lhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (divide op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          if ( sdt_rhs != LNG::SimpleDataType::tReal && sdt_rhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (divide op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          sdt_result = LNG::SimpleDataType::tReal;
          break;
        case LNG::EO::o_plus:
        case LNG::EO::o_minus:
        case LNG::EO::o_multiply:
          if ( sdt_lhs != LNG::SimpleDataType::tReal && sdt_lhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (plus/minus/multiply op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          if ( sdt_rhs != LNG::SimpleDataType::tReal && sdt_rhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (plus/minus/multiply op): expected int/float, but found ", sdt_lhs, sdt_rhs);
          }
          if ( sdt_lhs == LNG::SimpleDataType::tReal || sdt_rhs == LNG::SimpleDataType::tReal ) {
            sdt_result = LNG::SimpleDataType::tReal;
          }
          else { sdt_result = LNG::SimpleDataType::tInteger; }
          break;

        case LNG::EO::o_div:
          if ( sdt_lhs != LNG::SimpleDataType::tInteger || sdt_rhs != LNG::SimpleDataType::tInteger ) {
            error("Type mismatch (div): expected Integer, but found ", sdt_lhs, sdt_rhs);
          }
          sdt_result = LNG::SimpleDataType::tInteger;
          break;

        default:
          assert( false );
      }
    }
    node->set_sdt( sdt_result );
  }

  void visit(AST::StringExprNode *node) override {
    assert(node != nullptr);
    node->set_sdt( LNG::SimpleDataType::tVoid ); // NOTE
  }

  void visit(AST::VariableExprNode *node) override {
    assert(node != nullptr);
    AST::ExprNode* expr = node->get_expr();
    if ( expr != nullptr ) {
      accept( expr );
      if ( expr->get_sdt() != LNG::SimpleDataType::tInteger ) {
        error("Type mismatch (array index): expected Integer, but found ", expr->get_sdt());
      }
    }
    auto entry = symbol_table_lookup( node->get_name() );
    if ( entry == nullptr ) {
      error("Undeclared variable: ", node->get_name() );
    }
    else if ( entry->data_type.is_array() && expr == nullptr ) {
      error("Array index missing: ", node->get_name() );
    }
    else if ( !entry->data_type.is_array() && expr != nullptr ) {
      error("Indexing an non-array: ", node->get_name() );
    }
    node->set_sdt( entry->data_type.get_sdt() );
  }

  void visit(AST::FunctionCallExprNode *node) override {
    assert(node != nullptr);
    for (auto expr : node->get_arguments()) {
      accept(expr);
    }
    auto entry = symbol_table_lookup( node->get_name() );
    if ( entry == nullptr ) {
      error("Undeclared function: ", node->get_name() );
    }
    node->set_sdt( entry->data_type.get_sdt() );
    std::string signature = to_signature( calc_signature(node->get_arguments()) );
    if ( entry->signature != signature ) {
      // Note that int-to-real type conversion, in function calls is not supported.
      error( "Type mismatch in function call arguments: ", node->get_name(), entry->signature, signature );
    }
  };

  void visit(AST::AssignmentStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_var());
    accept(node->get_expr());

    auto entry = symbol_table_lookup( node->get_var()->get_name() );
    assert( entry != nullptr );

    if ( entry->data_type.get_sdt() != node->get_expr()->get_sdt() ) {
      // Only allowed conversion is from int to real.
      if ( entry->data_type.get_sdt() != LNG::SimpleDataType::tReal ||
           node->get_expr()->get_sdt() != LNG::SimpleDataType::tInteger ) {
        error("Type mismatch (assignment): expected compatible types, but found ",
              entry->data_type.get_sdt(), node->get_expr()->get_sdt());
      }
    }
  };

  void visit(AST::CompoundStmtNode *node) override {
    assert(node != nullptr);
    for (const auto stmt : node->get_stmts()) {
      accept(stmt);
    }
  };

  void visit(AST::EmptyStmtNode *node) override {
    assert(node != nullptr);
  }

  void visit(AST::IfStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_expr());
    if ( node->get_expr()->get_sdt() != LNG::SimpleDataType::tBoolean ) {
      error("Type mismatch (if stmt): expected Boolean, but found ", node->get_expr()->get_sdt());
    }
    accept(node->get_stmt_if());
    accept(node->get_stmt_else());
  };

  void visit(AST::ProcedureCallStmtNode *node) override {
    assert(node != nullptr);
    for (auto expr : node->get_arguments()) {
      accept(expr);
    }
    auto entry = symbol_table_lookup( node->get_name() );
    if ( entry == nullptr ) {
      error("Undeclared procedure: ", node->get_name() );
    }
    std::string signature = to_signature( calc_signature(node->get_arguments()) );
    if ( entry->signature != signature ) {
      // Note that int-to-real type conversion, in function calls is not supported.
      error( "Type mismatch in procedure call arguments: ", node->get_name(), entry->signature, signature );
    }
  };

  void visit(AST::WhileStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_expr());
    LNG::SimpleDataType sdt = node->get_expr()->get_sdt();
    if ( sdt != LNG::SimpleDataType::tBoolean ) {
      error("Type mismatch (while stmt): expected Boolean, but found ", sdt);
    }
    accept(node->get_stmt());
  }

  void visit(AST::ReadStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_arg());
  }

  void visit(AST::WriteStmtNode *node) override {
    assert(node != nullptr);
    accept(node->get_expr());
    LNG::SimpleDataType sdt = node->get_expr()->get_sdt();
    if ( sdt == LNG::SimpleDataType::tVoid ) {
      // NOTE
    }
  }

  void visit(AST::VariableNode *node) override {
    assert(node != nullptr);
    AST::ExprNode* expr = node->get_expr();
    if ( expr != nullptr ) {
      accept( expr );
      if ( expr->get_sdt() != LNG::SimpleDataType::tInteger ) {
        error("Type mismatch (array index): expected Integer, but found ", expr->get_sdt());
      }
    }
    auto entry = symbol_table_lookup( node->get_name() );
    if ( entry == nullptr ) {
      error("Undeclared variable: ", node->get_name() );
    }
    else if ( entry->data_type.is_array() && expr == nullptr ) {
      error("Array index missing: ", node->get_name() );
    }
    else if ( !entry->data_type.is_array() && expr != nullptr ) {
      error("Indexing an non-array: ", node->get_name() );
    }
  }

  void visit(AST::VariableDeclNode *node) override {
    assert(node != nullptr);
    //for (const auto &id : node->get_identifiers()) {
    //}
    if ( node->get_data_type().is_array() ) {
      if ( node->get_data_type().get_from_index() < 0 ||
           node->get_data_type().get_from_index() > node->get_data_type().get_to_index() ) {
        error("Invalid array declaration (index invalid)" );
      }
    }

  }

  void visit(AST::ProcedureDeclNode *node) override {
    assert(node != nullptr);
    auto entry = symbol_table_lookup( node->get_name() );
    assert( entry != nullptr );
    scope_ = node->get_name();
    accept(node->get_var_decl());
    entry->signature = to_signature( calc_signature( node->get_var_decl() ) );
    accept(node->get_block());
    scope_ = "";
  }

  void visit(AST::FunctionDeclNode *node) override {
    assert(node != nullptr);
    auto entry = symbol_table_lookup( node->get_name() );
    assert( entry != nullptr );
    scope_ = node->get_name();
    accept(node->get_var_decl());
    entry->signature = to_signature( calc_signature( node->get_var_decl() ) );
    accept(node->get_block());
    scope_ = "";
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
    accept(node->get_stmt());
  }

  void visit(AST::ProgramNode *node) override {
    assert(node != nullptr);
    scope_ = "";
    accept(node->get_block());
  }

 private:

  void error(const std::string& msg, LNG::SimpleDataType sdt ) {
    std::cout << msg << ' ' << LNG::SimpleTypeToText[sdt] << std::endl;
    exit(1);
  }

  void error(const std::string& msg, LNG::SimpleDataType lhs_sdt, LNG::SimpleDataType rhs_sdt ) {
    std::cout << msg << ' '
              << LNG::SimpleTypeToText[lhs_sdt] << " or " << ' ' << LNG::SimpleTypeToText[rhs_sdt] << std::endl;
    exit(1);
  }

  void error(const std::string& msg, const std::string a1 = "", const std::string a2 = "", const std::string a3 = "" ) {
    std::cout << msg << ' ' << a1 << ' ' << a2 << ' ' << a3 << std::endl;
    exit(1);
  }

  void accept(AST::Node *node) {
    if (node != nullptr) node->accept(*this);
  }

  SymbolTable::Entry* symbol_table_lookup( const std::string& id ) {
    auto entry = st_->lookup( scope_, id );
    if (entry == nullptr && !scope_.empty()) {
      entry = st_->lookup("", id);
    }
    return entry;
  }

  std::string to_signature( const std::list<LNG::SimpleDataType>& list ) {
    std::string signature;
    for ( auto& e : list ) {
      if ( !signature.empty() ) {
        signature += ":";
      }
      signature += LNG::SimpleTypeToText[e];
    }
    return signature;
  }

  const std::list<LNG::SimpleDataType> calc_signature( const std::list<AST::ExprNode*>& expr_list ) {
    std::list<LNG::SimpleDataType> signature_list;
    for ( auto& expr : expr_list ) {
          signature_list.push_back( expr->get_sdt() );
    }
    return signature_list;
  }

  const std::list<LNG::SimpleDataType> calc_signature( const AST::VariableDeclarationsNode* decls ) {
    std::list<LNG::SimpleDataType> signature_list;
    if ( decls != nullptr ) {
      for (auto dec : decls->get_declarations() ) {
        LNG::SimpleDataType  sdt = dec->get_data_type().get_sdt();
        for ( int i=0; i<dec->get_identifiers().size(); ++i ) {
          signature_list.push_back(sdt);
        }
      }
    }
    return signature_list;
  }

  std::string scope_;
  SymbolTable* st_;
};

#endif //TURBOPASCAL_SA_VISITOR_H
