%require "3.2"
%language "c++"

%code requires
{
#include <string>
#include <sstream>
#include "common.h"
#include "ast.h"
class BParser;
}

%parse-param { BParser& prs }
%lex-param { BParser& prs }
%locations
%define api.value.type variant
%define api.token.constructor
%define parse.assert
%define parse.trace
%define parse.error verbose

%code
{
  using namespace std;
  using namespace AST;
  #include "bparser.h"
  SymbolTable::Entry* symbol_table_lookup( BParser& p, const std::string& id );

  namespace yy
  {
    // Return the next token.
    auto yylex ( BParser& prs ) -> parser::symbol_type
    {
        prs.lexer_.get( prs.token_ );
        yy::position pos( nullptr, prs.token_.loc.line, prs.token_.loc.col );
        parser::location_type loc( pos, pos );

        switch ( prs.token_.name ) {
        case LNG::TN::t_assign:     return parser::make_t_assign(loc);
        case LNG::TN::t_divide:     return parser::make_t_divide(loc);
        case LNG::TN::t_eq:         return parser::make_t_eq(loc);
        case LNG::TN::t_gt:         return parser::make_t_gt(loc);
        case LNG::TN::t_gteq:       return parser::make_t_gteq(loc);
        case LNG::TN::t_lt:         return parser::make_t_lt(loc);
        case LNG::TN::t_lteq:       return parser::make_t_lteq(loc);
        case LNG::TN::t_minus:      return parser::make_t_minus(loc);
        case LNG::TN::t_multiply:   return parser::make_t_multiply(loc);
        case LNG::TN::t_neq:        return parser::make_t_neq(loc);
        case LNG::TN::t_plus:       return parser::make_t_plus(loc);

        case LNG::TN::t_colon:          return parser::make_t_colon(loc);
        case LNG::TN::t_comma:          return parser::make_t_comma(loc);
        case LNG::TN::t_dot:            return parser::make_t_dot(loc);
        case LNG::TN::t_lbracket:       return parser::make_t_lbracket(loc);
        case LNG::TN::t_lparenthesis:   return parser::make_t_lparenthesis(loc);
        case LNG::TN::t_rbracket:       return parser::make_t_rbracket(loc);
        case LNG::TN::t_rparenthesis:   return parser::make_t_rparenthesis(loc);
        case LNG::TN::t_subrange:       return parser::make_t_subrange(loc);
        case LNG::TN::t_semicolon:      return parser::make_t_semicolon(loc);

        case LNG::TN::t_and:        return parser::make_t_and(loc);
        case LNG::TN::t_array:      return parser::make_t_array(loc);
        case LNG::TN::t_begin:      return parser::make_t_begin(loc);
        case LNG::TN::t_boolean:    return parser::make_t_boolean(loc);
        case LNG::TN::t_div:        return parser::make_t_div(loc);
        case LNG::TN::t_do:         return parser::make_t_do(loc);
        case LNG::TN::t_else:       return parser::make_t_else(loc);
        case LNG::TN::t_end:        return parser::make_t_end(loc);
        case LNG::TN::t_false:      return parser::make_t_false(loc);
        case LNG::TN::t_function:   return parser::make_t_function(loc);
        case LNG::TN::t_if:         return parser::make_t_if(loc);
        case LNG::TN::t_integer:    return parser::make_t_integer(loc);
        case LNG::TN::t_not:        return parser::make_t_not(loc);
        case LNG::TN::t_of:         return parser::make_t_of(loc);
        case LNG::TN::t_or:         return parser::make_t_or(loc);
        case LNG::TN::t_procedure:  return parser::make_t_procedure(loc);
        case LNG::TN::t_program:    return parser::make_t_program(loc);
        case LNG::TN::t_read:       return parser::make_t_read(loc);
        case LNG::TN::t_readln:     return parser::make_t_readln(loc);
        case LNG::TN::t_real:       return parser::make_t_real(loc);
        case LNG::TN::t_then:       return parser::make_t_then(loc);
        case LNG::TN::t_true:       return parser::make_t_true(loc);
        case LNG::TN::t_var:        return parser::make_t_var(loc);
        case LNG::TN::t_while:      return parser::make_t_while(loc);
        case LNG::TN::t_write:      return parser::make_t_write(loc);
        case LNG::TN::t_writeln:    return parser::make_t_writeln(loc);

        case LNG::TN::t_identifier: return parser::make_t_identifier(prs.token_.text, loc);

        case LNG::TN::t_integer_l:  return parser::make_t_integer_l(prs.token_.text, loc);
        case LNG::TN::t_real_l:     return parser::make_t_real_l(prs.token_.text, loc);
        case LNG::TN::t_string_l:   return parser::make_t_string_l(prs.token_.text, loc);

        case LNG::TN::t_eoi:        return parser::make_t_eoi(loc);
        default:                    return parser::make_t_unknown(loc);
        }
    }
  }
}

%nonassoc   t_assign
%nonassoc   t_eq t_gt t_gteq t_lt t_lteq t_neq
%left       t_minus t_plus t_or
%left       t_multiply t_divide t_div t_and
%right      t_not

%token  t_colon
%token  t_comma
%token  t_dot
%token  t_lbracket
%token  t_lparenthesis
%token  t_rbracket
%token  t_rparenthesis
%token  t_subrange
%token  t_semicolon

%right  t_else t_then   // to resolve the dangling-else problem

%token  t_array
%token  t_begin
%token  t_boolean
%token  t_do
%token  t_end
%token  t_false
%token  t_function
%token  t_if
%token  t_integer
%token  t_of
%token  t_procedure
%token  t_program
%token  t_read
%token  t_readln
%token  t_real
%token  t_true
%token  t_var
%token  t_while
%token  t_write
%token  t_writeln

%token  t_identifier
%token  t_integer_l
%token  t_real_l
%token  t_string_l

%token  t_eoi 0
%token  t_unknown

%type <std::string> t_identifier
%type <std::string> t_integer_l
%type <std::string> t_real_l
%type <std::string> t_string_l

%type <AST::BlockNode*> main_block

%type <AST::VariableDeclarationsNode*> variable_declarations
%type <std::list<AST::VariableDeclNode*>> list_variable_declaration
%type <AST::VariableDeclNode*> variable_declaration
%type <std::list<std::string>> list_identifier

%type <LNG::SimpleDataType> simple_type
%type <LNG::DataType> array_type
%type <LNG::DataType> type

%type <AST::CallableDeclarationsNode*> callable_declarations

%type <std::list<AST::StmtNode*>> list_statement
%type <AST::StmtNode*> statement
%type <AST::CompoundStmtNode*> compound_statement

%type <AST::EmptyStmtNode*> empty_statement
%type <AST::AssignmentStmtNode*> assignment_statement
%type <AST::VariableNode*> variable_lvalue

%type <std::list<AST::CallableDeclNode*>> list_callable_declarations
%type <AST::CallableDeclNode*> callable_declaration
%type <AST::ProcedureDeclNode*> procedure_declaration
%type <AST::FunctionDeclNode*> function_declaration
%type <AST::VariableDeclarationsNode*> opt_parameters
%type <std::list<AST::VariableDeclNode*>> list_parameter_list
%type <AST::VariableDeclNode*> parameter_list
%type <AST::BlockNode*> block

%type <std::list<AST::ExprNode*>> optional_arguments
%type <std::list<AST::ExprNode*>> list_argument
%type <AST::ProcedureCallStmtNode*> procedure_statement
%type <AST::ReadStmtNode*> read_statement
%type <AST::WriteStmtNode*> write_statement
%type <AST::IfStmtNode*> if_statement
%type <AST::WhileStmtNode*> while_statement

%type <AST::ExprNode*> output_value

%type <AST::ExprNode*> expression

%type <AST::ExprNode*> simple_expression
%type <AST::ExprNode*> term
%type <AST::ExprNode*> complemented_factor
%type <AST::ExprNode*> signed_factor
%type <AST::ExprNode*> factor

%type <LNG::ExprOperator> rel_op
%type <LNG::ExprOperator> add_op
%type <LNG::ExprOperator> mult_op

%type <AST::ExprNode*> constant
%type <AST::ExprNode*> function_call_or_variable_rvalue

%%
program:
    t_program t_identifier t_semicolon
    { prs.scope_ = ""; }
    main_block
    t_dot
    { prs.set_AST( new AST::ProgramNode( $2, $5 ) ); }
;

main_block:
    variable_declarations
    callable_declarations
    compound_statement
    { $$ = new AST::BlockNode( $1, $2, $3 ); }
;

variable_declarations:
    t_var list_variable_declaration
    { $$ = new AST::VariableDeclarationsNode( $2 ); }
    |
    { $$ = nullptr; }
;

list_variable_declaration:
    list_variable_declaration variable_declaration t_semicolon
    { $1.push_back( $2 ); $$ = $1; }
    |
    variable_declaration t_semicolon
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

variable_declaration:
    list_identifier t_colon type
    {
        auto st = prs.get_SymbolTable();
        for (auto &id : $1) {
            auto entry = st->lookup(prs.scope_, id);
            if (entry != nullptr) {
              error(@1, "Duplicate identifier '" + id + "'");
              exit(1);
            }
            st->add_var(prs.scope_, id, $3);
        }
        $$ = new AST::VariableDeclNode( $1, $3 );
    }
;

list_identifier:
    list_identifier t_comma t_identifier
    { $1.push_back( $3 ); $$ = $1; }
    |
    t_identifier
    { std::list<std::string> lst; lst.push_back( $1 ); $$ = lst; }
;

type:
    simple_type     { $$ = LNG::DataType($1); }
    |
    array_type      { $$ = $1; }
;

simple_type:
    t_integer       { $$ = LNG::SimpleDataType::tInteger; }
    |
    t_boolean       { $$ = LNG::SimpleDataType::tBoolean; }
    |
    t_real          { $$ = LNG::SimpleDataType::tReal; }
;

array_type:
    t_array t_lbracket t_integer_l t_subrange t_integer_l t_rbracket t_of simple_type
    { $$ = $$ = LNG::DataType( $8, std::stoi($3), std::stoi($5) ); }
;

compound_statement:
    t_begin
    list_statement
    t_end
    { $$ = new AST::CompoundStmtNode($2); };
;

list_statement:
    list_statement t_semicolon statement
    { $1.push_back( $3 ); $$ = $1; }
    |
    statement
    { std::list<AST::StmtNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

callable_declarations:
    list_callable_declarations
    { $$ = new CallableDeclarationsNode( $1 ); }
;

list_callable_declarations:
    list_callable_declarations callable_declaration
    { $1.push_back( $2 ); $$ = $1; }
    |
    { $$ = std::list<AST::CallableDeclNode*>(); }
;

callable_declaration:
    procedure_declaration   { $$ = $1; }
    |
    function_declaration    { $$ = $1; }
;

procedure_declaration:
    t_procedure t_identifier
    { prs.scope_ = $2; }
    opt_parameters t_semicolon
    {
        auto st = prs.get_SymbolTable();
        auto entry = st->lookup(prs.scope_, $2);
        if (entry != nullptr) {
            error(@2, "Duplicate procedure declaration '" + $2 + "'");
            exit(1);
        }
        st->add_procedure( $2, "" );
    }
    block t_semicolon
    {
        prs.scope_ = "";
        $$ = new AST::ProcedureDeclNode( $2, $4, $7 );
    }
;

function_declaration:
    t_function t_identifier
    { prs.scope_ = $2; }
    opt_parameters t_colon simple_type t_semicolon
    {
        auto st = prs.get_SymbolTable();
        auto entry = st->lookup(prs.scope_, $2);
        if (entry != nullptr) {
            error(@2, "Duplicate function declaration '" + $2 + "'");
            exit(1);
        }
        st->add_function( $2, "", LNG::DataType($6) );
    }
    block t_semicolon
    {
        prs.scope_ = "";
        $$ = new AST::FunctionDeclNode( $2, $4, $9, LNG::DataType($6) );
    }
;

opt_parameters:
    t_lparenthesis list_parameter_list t_rparenthesis
    { $$ = new AST::VariableDeclarationsNode( $2 ); }
    |
    { $$ = nullptr; }
;

list_parameter_list:
    list_parameter_list t_semicolon parameter_list
    { $1.push_back( $3 ); $$ = $1; }
    |
    parameter_list
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

parameter_list:
    list_identifier t_colon simple_type
    {
        auto st = prs.get_SymbolTable();
        for (auto &id : $1) {
            auto entry = st->lookup(prs.scope_, id);
            if (entry != nullptr) {
                error(@2, "Duplicate identifier '" + id + "'");
                exit(1);
            }
            st->add_var(prs.scope_, id, LNG::DataType( $3 ) );
        }
        $$ = new AST::VariableDeclNode( $1, LNG::DataType( $3 ) );
    }
;

block:
    variable_declarations
    compound_statement
    { $$ = new AST::BlockNode( $1, nullptr, $2 ); }
;

statement:
    assignment_statement    { $$ = $1; }
    |
    procedure_statement     { $$ = $1; }
    |
    read_statement          { $$ = $1; }
    |
    write_statement         { $$ = $1; }
    |
    compound_statement      { $$ = $1; }
    |
    if_statement            { $$ = $1; }
    |
    while_statement         { $$ = $1; }
    |
    empty_statement         { $$ = $1; }
;

empty_statement:
    { $$ = new AST::EmptyStmtNode(); }
;

assignment_statement:
    variable_lvalue t_assign expression
    { $$ = new AST::AssignmentStmtNode( $1, $3); }
;

procedure_statement:
    t_identifier optional_arguments
    { $$ = new AST::ProcedureCallStmtNode($1, $2); }
;

read_statement:
    t_read t_lparenthesis variable_lvalue t_rparenthesis
    { $$ = new AST::ReadStmtNode( $3 ); }
    |
    t_readln t_lparenthesis variable_lvalue t_rparenthesis
    { $$ = new AST::ReadStmtNode( $3, true); }
;

write_statement:
    t_write t_lparenthesis output_value t_rparenthesis
    { $$ = new AST::WriteStmtNode( $3 ); }
    |
    t_writeln t_lparenthesis output_value t_rparenthesis
    { $$ = new AST::WriteStmtNode( $3, true ); }
;

if_statement:
    t_if expression t_then statement
    { $$ = new AST::IfStmtNode( $2, $4, nullptr ); }
    |
    t_if expression t_then statement t_else statement
    { $$ = new AST::IfStmtNode( $2, $4, $6 ); }
;

while_statement:
    t_while expression t_do statement
    { $$ = new AST::WhileStmtNode( $2, $4 ); }
;

optional_arguments:
    t_lparenthesis list_argument t_rparenthesis
    { $$ = $2; }
    |
    { $$ = std::list<AST::ExprNode*>(); }
;

list_argument:
    list_argument t_comma expression
    { $1.push_back( $3 ); $$ = $1; }
    |
    expression
    { std::list<AST::ExprNode*> lst; lst.push_back( $1 ); $$ = lst; }
;

output_value:
    t_string_l
    { $$ = new AST::StringExprNode($1); }
    |
    expression
    { $$ = $1; }
;

variable_lvalue:
    t_identifier
    {
        auto entry = symbol_table_lookup( prs, $1 );
        if ( entry == nullptr ) {
            error( @1, "Identifier not found \"" + $1 + "\"" );
            exit(1);
        }
        $$ = new AST::VariableNode( $1, nullptr );
    }
    |
    t_identifier t_lbracket expression t_rbracket
    {
        auto entry = symbol_table_lookup( prs, $1 );  // NOTE: must be array-variable?
        if ( entry == nullptr ) {
            error( @1, "Identifier not found \"" + $1 + "\"" );
            exit(1);
        }
        $$ = new AST::VariableNode( $1, $3 );
    }
;

expression:
    expression rel_op simple_expression
    { $$ = new AST::OpExprNode( $2, $1, $3); }
    |
    simple_expression
    { $$ = $1; }
;

simple_expression:
    simple_expression add_op term
    { $$ = new AST::OpExprNode( $2, $1, $3); }
    |
    term
    { $$ = $1; }
;

term:
    term mult_op complemented_factor
    { $$ = new AST::OpExprNode( $2, $1, $3); }
    |
    complemented_factor
    { $$ = $1; }
;

complemented_factor:
    signed_factor
    { $$ = $1; }
    |
    t_not signed_factor
    { $$ = new AST::OpExprNode( LNG::ExprOperator::o_not, nullptr, $2 ); }
;

signed_factor:
    factor
    { $$ = $1; }
    |
    t_plus factor
    { $$ = $2; }
    |
    t_minus factor
    { $$ = new AST::OpExprNode( LNG::ExprOperator::o_minus, nullptr, $2 ); }
;

factor:
    constant
    { $$ = $1; }
    |
    t_lparenthesis expression t_rparenthesis
    { $$ = $2; }
    |
    function_call_or_variable_rvalue
    { $$ = $1; }
;

function_call_or_variable_rvalue:
    t_identifier
    {
        auto entry = symbol_table_lookup( prs, $1 );
        if ( entry == nullptr ) {
            error( @1, "Identifier not found \"" + $1 + "\"" );
            exit(1);
        }
        if ( entry->entry_type == SymbolTable::EntryType::sFunction ) {
            $$ = new AST::FunctionCallExprNode( $1, std::list<ExprNode*>() );
        } else {
            $$ = new AST::VariableExprNode( $1, nullptr );
        }
    }
    |
    t_identifier t_lparenthesis list_argument t_rparenthesis
    {
        auto entry = symbol_table_lookup( prs, $1 );
        if ( entry == nullptr ) {
            error( @1, "Identifier not found \"" + $1 + "\"" );
            exit(1);
        }
        $$ = new AST::FunctionCallExprNode($1, $3);
    }
    |
    t_identifier t_lbracket expression t_rbracket
    {
        auto entry = symbol_table_lookup( prs, $1 );
        if ( entry == nullptr ) {
            error( @1, "Identifier not found \"" + $1 + "\"" );
            exit(1);
        }
        $$ = new AST::VariableExprNode( $1, $3 );
    }

constant:
    t_integer_l
    { $$ = new AST::IntegerExprNode( std::stoi( $1 ) ); }
    |
    t_real_l
    { $$ = new AST::RealExprNode( std::stof( $1 ) ); } //NOTE: Pascal real valid C++ real?
    |
    t_true
    { $$ = new AST::BooleanExprNode( true ); }
    |
    t_false
    { $$ = new AST::BooleanExprNode( false ); }
;

rel_op:
    t_eq    { $$ = LNG::ExprOperator::o_eq; }
    |
    t_gt    { $$ = LNG::ExprOperator::o_gt; }
    |
    t_gteq  { $$ = LNG::ExprOperator::o_gteq; }
    |
    t_neq   { $$ = LNG::ExprOperator::o_neq; }
    |
    t_lt    { $$ = LNG::ExprOperator::o_lt; }
    |
    t_lteq  { $$ = LNG::ExprOperator::o_lteq; }
;

add_op:
    t_plus   { $$ = LNG::ExprOperator::o_plus; }
    |
    t_minus  { $$ = LNG::ExprOperator::o_minus; }
    |
    t_or     { $$ = LNG::ExprOperator::o_or; }
;

mult_op:
    t_multiply  { $$ = LNG::ExprOperator::o_multiply; }
    |
    t_divide    { $$ = LNG::ExprOperator::o_divide; }
    |
    t_div       { $$ = LNG::ExprOperator::o_div; }
    |
    t_and       { $$ = LNG::ExprOperator::o_and; }
;

%%

    SymbolTable::Entry* symbol_table_lookup( BParser& p, const std::string& id ) {
        auto st = p.get_SymbolTable();
        auto entry = st->lookup( p.scope_, id );
        if (entry == nullptr && !p.scope_.empty()) {
          entry = st->lookup("", id);
        }
        return entry;
    }

    namespace yy
    {
        // Report an error to the user.
        auto parser::error(const location_type& l, const std::string &msg) -> void {
            std::cerr << msg << " at (" << l.begin.line << ',' << l.begin.column << ")\n";
        }
    }