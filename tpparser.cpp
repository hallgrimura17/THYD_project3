// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "tpparser.h"


// Unqualified %code blocks.
#line 23 "tpparser.yy" // lalr1.cc:435

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

#line 123 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 218 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (BParser& prs_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      prs (prs_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 82: // assignment_statement
        value.YY_MOVE_OR_COPY< AST::AssignmentStmtNode* > (YY_MOVE (that.value));
        break;

      case 57: // main_block
      case 79: // block
        value.YY_MOVE_OR_COPY< AST::BlockNode* > (YY_MOVE (that.value));
        break;

      case 69: // callable_declaration
        value.YY_MOVE_OR_COPY< AST::CallableDeclNode* > (YY_MOVE (that.value));
        break;

      case 67: // callable_declarations
        value.YY_MOVE_OR_COPY< AST::CallableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
        value.YY_MOVE_OR_COPY< AST::CompoundStmtNode* > (YY_MOVE (that.value));
        break;

      case 81: // empty_statement
        value.YY_MOVE_OR_COPY< AST::EmptyStmtNode* > (YY_MOVE (that.value));
        break;

      case 90: // output_value
      case 92: // expression
      case 93: // simple_expression
      case 94: // term
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 98: // function_call_or_variable_rvalue
      case 99: // constant
        value.YY_MOVE_OR_COPY< AST::ExprNode* > (YY_MOVE (that.value));
        break;

      case 73: // function_declaration
        value.YY_MOVE_OR_COPY< AST::FunctionDeclNode* > (YY_MOVE (that.value));
        break;

      case 86: // if_statement
        value.YY_MOVE_OR_COPY< AST::IfStmtNode* > (YY_MOVE (that.value));
        break;

      case 83: // procedure_statement
        value.YY_MOVE_OR_COPY< AST::ProcedureCallStmtNode* > (YY_MOVE (that.value));
        break;

      case 70: // procedure_declaration
        value.YY_MOVE_OR_COPY< AST::ProcedureDeclNode* > (YY_MOVE (that.value));
        break;

      case 84: // read_statement
        value.YY_MOVE_OR_COPY< AST::ReadStmtNode* > (YY_MOVE (that.value));
        break;

      case 80: // statement
        value.YY_MOVE_OR_COPY< AST::StmtNode* > (YY_MOVE (that.value));
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.YY_MOVE_OR_COPY< AST::VariableDeclNode* > (YY_MOVE (that.value));
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.YY_MOVE_OR_COPY< AST::VariableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 91: // variable_lvalue
        value.YY_MOVE_OR_COPY< AST::VariableNode* > (YY_MOVE (that.value));
        break;

      case 87: // while_statement
        value.YY_MOVE_OR_COPY< AST::WhileStmtNode* > (YY_MOVE (that.value));
        break;

      case 85: // write_statement
        value.YY_MOVE_OR_COPY< AST::WriteStmtNode* > (YY_MOVE (that.value));
        break;

      case 62: // type
      case 64: // array_type
        value.YY_MOVE_OR_COPY< LNG::DataType > (YY_MOVE (that.value));
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.YY_MOVE_OR_COPY< LNG::ExprOperator > (YY_MOVE (that.value));
        break;

      case 63: // simple_type
        value.YY_MOVE_OR_COPY< LNG::SimpleDataType > (YY_MOVE (that.value));
        break;

      case 68: // list_callable_declarations
        value.YY_MOVE_OR_COPY< std::list<AST::CallableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.YY_MOVE_OR_COPY< std::list<AST::ExprNode*> > (YY_MOVE (that.value));
        break;

      case 66: // list_statement
        value.YY_MOVE_OR_COPY< std::list<AST::StmtNode*> > (YY_MOVE (that.value));
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.YY_MOVE_OR_COPY< std::list<AST::VariableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 61: // list_identifier
        value.YY_MOVE_OR_COPY< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 82: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (YY_MOVE (that.value));
        break;

      case 57: // main_block
      case 79: // block
        value.move< AST::BlockNode* > (YY_MOVE (that.value));
        break;

      case 69: // callable_declaration
        value.move< AST::CallableDeclNode* > (YY_MOVE (that.value));
        break;

      case 67: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (YY_MOVE (that.value));
        break;

      case 81: // empty_statement
        value.move< AST::EmptyStmtNode* > (YY_MOVE (that.value));
        break;

      case 90: // output_value
      case 92: // expression
      case 93: // simple_expression
      case 94: // term
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 98: // function_call_or_variable_rvalue
      case 99: // constant
        value.move< AST::ExprNode* > (YY_MOVE (that.value));
        break;

      case 73: // function_declaration
        value.move< AST::FunctionDeclNode* > (YY_MOVE (that.value));
        break;

      case 86: // if_statement
        value.move< AST::IfStmtNode* > (YY_MOVE (that.value));
        break;

      case 83: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (YY_MOVE (that.value));
        break;

      case 70: // procedure_declaration
        value.move< AST::ProcedureDeclNode* > (YY_MOVE (that.value));
        break;

      case 84: // read_statement
        value.move< AST::ReadStmtNode* > (YY_MOVE (that.value));
        break;

      case 80: // statement
        value.move< AST::StmtNode* > (YY_MOVE (that.value));
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.move< AST::VariableDeclNode* > (YY_MOVE (that.value));
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.move< AST::VariableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 91: // variable_lvalue
        value.move< AST::VariableNode* > (YY_MOVE (that.value));
        break;

      case 87: // while_statement
        value.move< AST::WhileStmtNode* > (YY_MOVE (that.value));
        break;

      case 85: // write_statement
        value.move< AST::WriteStmtNode* > (YY_MOVE (that.value));
        break;

      case 62: // type
      case 64: // array_type
        value.move< LNG::DataType > (YY_MOVE (that.value));
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.move< LNG::ExprOperator > (YY_MOVE (that.value));
        break;

      case 63: // simple_type
        value.move< LNG::SimpleDataType > (YY_MOVE (that.value));
        break;

      case 68: // list_callable_declarations
        value.move< std::list<AST::CallableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.move< std::list<AST::ExprNode*> > (YY_MOVE (that.value));
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (YY_MOVE (that.value));
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.move< std::list<AST::VariableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 61: // list_identifier
        value.move< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 82: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (that.value);
        break;

      case 57: // main_block
      case 79: // block
        value.move< AST::BlockNode* > (that.value);
        break;

      case 69: // callable_declaration
        value.move< AST::CallableDeclNode* > (that.value);
        break;

      case 67: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (that.value);
        break;

      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (that.value);
        break;

      case 81: // empty_statement
        value.move< AST::EmptyStmtNode* > (that.value);
        break;

      case 90: // output_value
      case 92: // expression
      case 93: // simple_expression
      case 94: // term
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 98: // function_call_or_variable_rvalue
      case 99: // constant
        value.move< AST::ExprNode* > (that.value);
        break;

      case 73: // function_declaration
        value.move< AST::FunctionDeclNode* > (that.value);
        break;

      case 86: // if_statement
        value.move< AST::IfStmtNode* > (that.value);
        break;

      case 83: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (that.value);
        break;

      case 70: // procedure_declaration
        value.move< AST::ProcedureDeclNode* > (that.value);
        break;

      case 84: // read_statement
        value.move< AST::ReadStmtNode* > (that.value);
        break;

      case 80: // statement
        value.move< AST::StmtNode* > (that.value);
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.move< AST::VariableDeclNode* > (that.value);
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.move< AST::VariableDeclarationsNode* > (that.value);
        break;

      case 91: // variable_lvalue
        value.move< AST::VariableNode* > (that.value);
        break;

      case 87: // while_statement
        value.move< AST::WhileStmtNode* > (that.value);
        break;

      case 85: // write_statement
        value.move< AST::WriteStmtNode* > (that.value);
        break;

      case 62: // type
      case 64: // array_type
        value.move< LNG::DataType > (that.value);
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.move< LNG::ExprOperator > (that.value);
        break;

      case 63: // simple_type
        value.move< LNG::SimpleDataType > (that.value);
        break;

      case 68: // list_callable_declarations
        value.move< std::list<AST::CallableDeclNode*> > (that.value);
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.move< std::list<AST::ExprNode*> > (that.value);
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (that.value);
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.move< std::list<AST::VariableDeclNode*> > (that.value);
        break;

      case 61: // list_identifier
        value.move< std::list<std::string> > (that.value);
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (prs));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 82: // assignment_statement
        yylhs.value.emplace< AST::AssignmentStmtNode* > ();
        break;

      case 57: // main_block
      case 79: // block
        yylhs.value.emplace< AST::BlockNode* > ();
        break;

      case 69: // callable_declaration
        yylhs.value.emplace< AST::CallableDeclNode* > ();
        break;

      case 67: // callable_declarations
        yylhs.value.emplace< AST::CallableDeclarationsNode* > ();
        break;

      case 65: // compound_statement
        yylhs.value.emplace< AST::CompoundStmtNode* > ();
        break;

      case 81: // empty_statement
        yylhs.value.emplace< AST::EmptyStmtNode* > ();
        break;

      case 90: // output_value
      case 92: // expression
      case 93: // simple_expression
      case 94: // term
      case 95: // complemented_factor
      case 96: // signed_factor
      case 97: // factor
      case 98: // function_call_or_variable_rvalue
      case 99: // constant
        yylhs.value.emplace< AST::ExprNode* > ();
        break;

      case 73: // function_declaration
        yylhs.value.emplace< AST::FunctionDeclNode* > ();
        break;

      case 86: // if_statement
        yylhs.value.emplace< AST::IfStmtNode* > ();
        break;

      case 83: // procedure_statement
        yylhs.value.emplace< AST::ProcedureCallStmtNode* > ();
        break;

      case 70: // procedure_declaration
        yylhs.value.emplace< AST::ProcedureDeclNode* > ();
        break;

      case 84: // read_statement
        yylhs.value.emplace< AST::ReadStmtNode* > ();
        break;

      case 80: // statement
        yylhs.value.emplace< AST::StmtNode* > ();
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        yylhs.value.emplace< AST::VariableDeclNode* > ();
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        yylhs.value.emplace< AST::VariableDeclarationsNode* > ();
        break;

      case 91: // variable_lvalue
        yylhs.value.emplace< AST::VariableNode* > ();
        break;

      case 87: // while_statement
        yylhs.value.emplace< AST::WhileStmtNode* > ();
        break;

      case 85: // write_statement
        yylhs.value.emplace< AST::WriteStmtNode* > ();
        break;

      case 62: // type
      case 64: // array_type
        yylhs.value.emplace< LNG::DataType > ();
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        yylhs.value.emplace< LNG::ExprOperator > ();
        break;

      case 63: // simple_type
        yylhs.value.emplace< LNG::SimpleDataType > ();
        break;

      case 68: // list_callable_declarations
        yylhs.value.emplace< std::list<AST::CallableDeclNode*> > ();
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        yylhs.value.emplace< std::list<AST::ExprNode*> > ();
        break;

      case 66: // list_statement
        yylhs.value.emplace< std::list<AST::StmtNode*> > ();
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        yylhs.value.emplace< std::list<AST::VariableDeclNode*> > ();
        break;

      case 61: // list_identifier
        yylhs.value.emplace< std::list<std::string> > ();
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 211 "tpparser.yy" // lalr1.cc:919
    { prs.scope_ = ""; }
#line 1136 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 3:
#line 214 "tpparser.yy" // lalr1.cc:919
    { prs.set_AST( new AST::ProgramNode( yystack_[4].value.as < std::string > (), yystack_[1].value.as < AST::BlockNode* > () ) ); }
#line 1142 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 4:
#line 221 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::BlockNode* > () = new AST::BlockNode( yystack_[2].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::CallableDeclarationsNode* > (), yystack_[0].value.as < AST::CompoundStmtNode* > () ); }
#line 1148 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 5:
#line 226 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = new AST::VariableDeclarationsNode( yystack_[0].value.as < std::list<AST::VariableDeclNode*> > () ); }
#line 1154 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 6:
#line 228 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = nullptr; }
#line 1160 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 7:
#line 233 "tpparser.yy" // lalr1.cc:919
    { yystack_[2].value.as < std::list<AST::VariableDeclNode*> > ().push_back( yystack_[1].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = yystack_[2].value.as < std::list<AST::VariableDeclNode*> > (); }
#line 1166 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 8:
#line 236 "tpparser.yy" // lalr1.cc:919
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( yystack_[1].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = lst; }
#line 1172 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 9:
#line 241 "tpparser.yy" // lalr1.cc:919
    {
        auto st = prs.get_SymbolTable();
        for (auto &id : yystack_[2].value.as < std::list<std::string> > ()) {
            auto entry = st->lookup(prs.scope_, id);
            if (entry != nullptr) {
              error(yystack_[2].location, "Duplicate identifier '" + id + "'");
              exit(1);
            }
            st->add_var(prs.scope_, id, yystack_[0].value.as < LNG::DataType > ());
        }
        yylhs.value.as < AST::VariableDeclNode* > () = new AST::VariableDeclNode( yystack_[2].value.as < std::list<std::string> > (), yystack_[0].value.as < LNG::DataType > () );
    }
#line 1189 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 10:
#line 257 "tpparser.yy" // lalr1.cc:919
    { yystack_[2].value.as < std::list<std::string> > ().push_back( yystack_[0].value.as < std::string > () ); yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > (); }
#line 1195 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 11:
#line 260 "tpparser.yy" // lalr1.cc:919
    { std::list<std::string> lst; lst.push_back( yystack_[0].value.as < std::string > () ); yylhs.value.as < std::list<std::string> > () = lst; }
#line 1201 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 12:
#line 264 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::DataType > () = LNG::DataType(yystack_[0].value.as < LNG::SimpleDataType > ()); }
#line 1207 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 13:
#line 266 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::DataType > () = yystack_[0].value.as < LNG::DataType > (); }
#line 1213 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 14:
#line 270 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tInteger; }
#line 1219 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 15:
#line 272 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tBoolean; }
#line 1225 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 16:
#line 274 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::SimpleDataType > () = LNG::SimpleDataType::tReal; }
#line 1231 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 17:
#line 279 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::DataType > () = yylhs.value.as < LNG::DataType > () = LNG::DataType( yystack_[0].value.as < LNG::SimpleDataType > (), std::stoi(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < std::string > ()) ); }
#line 1237 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 18:
#line 286 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::CompoundStmtNode* > () = new AST::CompoundStmtNode(yystack_[1].value.as < std::list<AST::StmtNode*> > ()); }
#line 1243 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 19:
#line 291 "tpparser.yy" // lalr1.cc:919
    { yystack_[2].value.as < std::list<AST::StmtNode*> > ().push_back( yystack_[0].value.as < AST::StmtNode* > () ); yylhs.value.as < std::list<AST::StmtNode*> > () = yystack_[2].value.as < std::list<AST::StmtNode*> > (); }
#line 1249 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 20:
#line 294 "tpparser.yy" // lalr1.cc:919
    { std::list<AST::StmtNode*> lst; lst.push_back( yystack_[0].value.as < AST::StmtNode* > () ); yylhs.value.as < std::list<AST::StmtNode*> > () = lst; }
#line 1255 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 21:
#line 299 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::CallableDeclarationsNode* > () = new CallableDeclarationsNode( yystack_[0].value.as < std::list<AST::CallableDeclNode*> > () ); }
#line 1261 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 22:
#line 304 "tpparser.yy" // lalr1.cc:919
    { yystack_[1].value.as < std::list<AST::CallableDeclNode*> > ().push_back( yystack_[0].value.as < AST::CallableDeclNode* > () ); yylhs.value.as < std::list<AST::CallableDeclNode*> > () = yystack_[1].value.as < std::list<AST::CallableDeclNode*> > (); }
#line 1267 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 23:
#line 306 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < std::list<AST::CallableDeclNode*> > () = std::list<AST::CallableDeclNode*>(); }
#line 1273 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 24:
#line 310 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::CallableDeclNode* > () = yystack_[0].value.as < AST::ProcedureDeclNode* > (); }
#line 1279 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 25:
#line 312 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::CallableDeclNode* > () = yystack_[0].value.as < AST::FunctionDeclNode* > (); }
#line 1285 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 26:
#line 317 "tpparser.yy" // lalr1.cc:919
    { prs.scope_ = yystack_[0].value.as < std::string > (); }
#line 1291 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 27:
#line 319 "tpparser.yy" // lalr1.cc:919
    {
        auto st = prs.get_SymbolTable();
        auto entry = st->lookup(prs.scope_, yystack_[3].value.as < std::string > ());
        if (entry != nullptr) {
            error(yystack_[3].location, "Duplicate procedure declaration '" + yystack_[3].value.as < std::string > () + "'");
            exit(1);
        }
        st->add_procedure( yystack_[3].value.as < std::string > (), "" );
    }
#line 1305 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 28:
#line 329 "tpparser.yy" // lalr1.cc:919
    {
        prs.scope_ = "";
        yylhs.value.as < AST::ProcedureDeclNode* > () = new AST::ProcedureDeclNode( yystack_[6].value.as < std::string > (), yystack_[4].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::BlockNode* > () );
    }
#line 1314 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 29:
#line 337 "tpparser.yy" // lalr1.cc:919
    { prs.scope_ = yystack_[0].value.as < std::string > (); }
#line 1320 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 30:
#line 339 "tpparser.yy" // lalr1.cc:919
    {
        auto st = prs.get_SymbolTable();
        auto entry = st->lookup(prs.scope_, yystack_[5].value.as < std::string > ());
        if (entry != nullptr) {
            error(yystack_[5].location, "Duplicate function declaration '" + yystack_[5].value.as < std::string > () + "'");
            exit(1);
        }
        st->add_function( yystack_[5].value.as < std::string > (), "", LNG::DataType(yystack_[1].value.as < LNG::SimpleDataType > ()) );
    }
#line 1334 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 31:
#line 349 "tpparser.yy" // lalr1.cc:919
    {
        prs.scope_ = "";
        yylhs.value.as < AST::FunctionDeclNode* > () = new AST::FunctionDeclNode( yystack_[8].value.as < std::string > (), yystack_[6].value.as < AST::VariableDeclarationsNode* > (), yystack_[1].value.as < AST::BlockNode* > (), LNG::DataType(yystack_[4].value.as < LNG::SimpleDataType > ()) );
    }
#line 1343 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 32:
#line 357 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = new AST::VariableDeclarationsNode( yystack_[1].value.as < std::list<AST::VariableDeclNode*> > () ); }
#line 1349 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 33:
#line 359 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::VariableDeclarationsNode* > () = nullptr; }
#line 1355 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 34:
#line 364 "tpparser.yy" // lalr1.cc:919
    { yystack_[2].value.as < std::list<AST::VariableDeclNode*> > ().push_back( yystack_[0].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = yystack_[2].value.as < std::list<AST::VariableDeclNode*> > (); }
#line 1361 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 35:
#line 367 "tpparser.yy" // lalr1.cc:919
    { std::list<AST::VariableDeclNode*> lst; lst.push_back( yystack_[0].value.as < AST::VariableDeclNode* > () ); yylhs.value.as < std::list<AST::VariableDeclNode*> > () = lst; }
#line 1367 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 36:
#line 372 "tpparser.yy" // lalr1.cc:919
    {
        auto st = prs.get_SymbolTable();
        for (auto &id : yystack_[2].value.as < std::list<std::string> > ()) {
            auto entry = st->lookup(prs.scope_, id);
            if (entry != nullptr) {
                error(yystack_[1].location, "Duplicate identifier '" + id + "'");
                exit(1);
            }
            st->add_var(prs.scope_, id, LNG::DataType( yystack_[0].value.as < LNG::SimpleDataType > () ) );
        }
        yylhs.value.as < AST::VariableDeclNode* > () = new AST::VariableDeclNode( yystack_[2].value.as < std::list<std::string> > (), LNG::DataType( yystack_[0].value.as < LNG::SimpleDataType > () ) );
    }
#line 1384 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 37:
#line 389 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::BlockNode* > () = new AST::BlockNode( yystack_[1].value.as < AST::VariableDeclarationsNode* > (), nullptr, yystack_[0].value.as < AST::CompoundStmtNode* > () ); }
#line 1390 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 38:
#line 393 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::AssignmentStmtNode* > (); }
#line 1396 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 39:
#line 395 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::ProcedureCallStmtNode* > (); }
#line 1402 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 40:
#line 397 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::ReadStmtNode* > (); }
#line 1408 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 41:
#line 399 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::WriteStmtNode* > (); }
#line 1414 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 42:
#line 401 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::CompoundStmtNode* > (); }
#line 1420 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 43:
#line 403 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::IfStmtNode* > (); }
#line 1426 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 44:
#line 405 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::WhileStmtNode* > (); }
#line 1432 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 45:
#line 407 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::StmtNode* > () = yystack_[0].value.as < AST::EmptyStmtNode* > (); }
#line 1438 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 46:
#line 411 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::EmptyStmtNode* > () = new AST::EmptyStmtNode(); }
#line 1444 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 47:
#line 416 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::AssignmentStmtNode* > () = new AST::AssignmentStmtNode( yystack_[2].value.as < AST::VariableNode* > (), yystack_[0].value.as < AST::ExprNode* > ()); }
#line 1450 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 48:
#line 421 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ProcedureCallStmtNode* > () = new AST::ProcedureCallStmtNode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::list<AST::ExprNode*> > ()); }
#line 1456 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 49:
#line 426 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ReadStmtNode* > () = new AST::ReadStmtNode( yystack_[1].value.as < AST::VariableNode* > () ); }
#line 1462 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 50:
#line 429 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ReadStmtNode* > () = new AST::ReadStmtNode( yystack_[1].value.as < AST::VariableNode* > (), true); }
#line 1468 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 51:
#line 434 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::WriteStmtNode* > () = new AST::WriteStmtNode( yystack_[1].value.as < AST::ExprNode* > () ); }
#line 1474 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 52:
#line 437 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::WriteStmtNode* > () = new AST::WriteStmtNode( yystack_[1].value.as < AST::ExprNode* > (), true ); }
#line 1480 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 53:
#line 442 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::IfStmtNode* > () = new AST::IfStmtNode( yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::StmtNode* > (), nullptr ); }
#line 1486 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 54:
#line 445 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::IfStmtNode* > () = new AST::IfStmtNode( yystack_[4].value.as < AST::ExprNode* > (), yystack_[2].value.as < AST::StmtNode* > (), yystack_[0].value.as < AST::StmtNode* > () ); }
#line 1492 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 55:
#line 450 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::WhileStmtNode* > () = new AST::WhileStmtNode( yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::StmtNode* > () ); }
#line 1498 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 56:
#line 455 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < std::list<AST::ExprNode*> > () = yystack_[1].value.as < std::list<AST::ExprNode*> > (); }
#line 1504 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 57:
#line 457 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < std::list<AST::ExprNode*> > () = std::list<AST::ExprNode*>(); }
#line 1510 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 58:
#line 462 "tpparser.yy" // lalr1.cc:919
    { yystack_[2].value.as < std::list<AST::ExprNode*> > ().push_back( yystack_[0].value.as < AST::ExprNode* > () ); yylhs.value.as < std::list<AST::ExprNode*> > () = yystack_[2].value.as < std::list<AST::ExprNode*> > (); }
#line 1516 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 59:
#line 465 "tpparser.yy" // lalr1.cc:919
    { std::list<AST::ExprNode*> lst; lst.push_back( yystack_[0].value.as < AST::ExprNode* > () ); yylhs.value.as < std::list<AST::ExprNode*> > () = lst; }
#line 1522 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 60:
#line 470 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::StringExprNode(yystack_[0].value.as < std::string > ()); }
#line 1528 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 61:
#line 473 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1534 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 62:
#line 478 "tpparser.yy" // lalr1.cc:919
    {
        auto entry = symbol_table_lookup( prs, yystack_[0].value.as < std::string > () );
        if ( entry == nullptr ) {
            error( yystack_[0].location, "Identifier not found \"" + yystack_[0].value.as < std::string > () + "\"" );
            exit(1);
        }
        yylhs.value.as < AST::VariableNode* > () = new AST::VariableNode( yystack_[0].value.as < std::string > (), nullptr );
    }
#line 1547 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 63:
#line 488 "tpparser.yy" // lalr1.cc:919
    {
        auto entry = symbol_table_lookup( prs, yystack_[3].value.as < std::string > () );  // NOTE: must be array-variable?
        if ( entry == nullptr ) {
            error( yystack_[3].location, "Identifier not found \"" + yystack_[3].value.as < std::string > () + "\"" );
            exit(1);
        }
        yylhs.value.as < AST::VariableNode* > () = new AST::VariableNode( yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::ExprNode* > () );
    }
#line 1560 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 64:
#line 500 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode( yystack_[1].value.as < LNG::ExprOperator > (), yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::ExprNode* > ()); }
#line 1566 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 65:
#line 503 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1572 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 66:
#line 508 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode( yystack_[1].value.as < LNG::ExprOperator > (), yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::ExprNode* > ()); }
#line 1578 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 67:
#line 511 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1584 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 68:
#line 516 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode( yystack_[1].value.as < LNG::ExprOperator > (), yystack_[2].value.as < AST::ExprNode* > (), yystack_[0].value.as < AST::ExprNode* > ()); }
#line 1590 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 69:
#line 519 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1596 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 70:
#line 524 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1602 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 71:
#line 527 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode( LNG::ExprOperator::o_not, nullptr, yystack_[0].value.as < AST::ExprNode* > () ); }
#line 1608 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 72:
#line 532 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1614 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 73:
#line 535 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1620 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 74:
#line 538 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::OpExprNode( LNG::ExprOperator::o_minus, nullptr, yystack_[0].value.as < AST::ExprNode* > () ); }
#line 1626 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 75:
#line 543 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1632 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 76:
#line 546 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[1].value.as < AST::ExprNode* > (); }
#line 1638 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 77:
#line 549 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = yystack_[0].value.as < AST::ExprNode* > (); }
#line 1644 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 78:
#line 554 "tpparser.yy" // lalr1.cc:919
    {
        auto entry = symbol_table_lookup( prs, yystack_[0].value.as < std::string > () );
        if ( entry == nullptr ) {
            error( yystack_[0].location, "Identifier not found \"" + yystack_[0].value.as < std::string > () + "\"" );
            exit(1);
        }
        if ( entry->entry_type == SymbolTable::EntryType::sFunction ) {
            yylhs.value.as < AST::ExprNode* > () = new AST::FunctionCallExprNode( yystack_[0].value.as < std::string > (), std::list<ExprNode*>() );
        } else {
            yylhs.value.as < AST::ExprNode* > () = new AST::VariableExprNode( yystack_[0].value.as < std::string > (), nullptr );
        }
    }
#line 1661 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 79:
#line 568 "tpparser.yy" // lalr1.cc:919
    {
        auto entry = symbol_table_lookup( prs, yystack_[3].value.as < std::string > () );
        if ( entry == nullptr ) {
            error( yystack_[3].location, "Identifier not found \"" + yystack_[3].value.as < std::string > () + "\"" );
            exit(1);
        }
        yylhs.value.as < AST::ExprNode* > () = new AST::FunctionCallExprNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::list<AST::ExprNode*> > ());
    }
#line 1674 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 80:
#line 578 "tpparser.yy" // lalr1.cc:919
    {
        auto entry = symbol_table_lookup( prs, yystack_[3].value.as < std::string > () );
        if ( entry == nullptr ) {
            error( yystack_[3].location, "Identifier not found \"" + yystack_[3].value.as < std::string > () + "\"" );
            exit(1);
        }
        yylhs.value.as < AST::ExprNode* > () = new AST::VariableExprNode( yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::ExprNode* > () );
    }
#line 1687 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 81:
#line 589 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::IntegerExprNode( std::stoi( yystack_[0].value.as < std::string > () ) ); }
#line 1693 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 82:
#line 592 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::RealExprNode( std::stof( yystack_[0].value.as < std::string > () ) ); }
#line 1699 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 83:
#line 595 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::BooleanExprNode( true ); }
#line 1705 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 84:
#line 598 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < AST::ExprNode* > () = new AST::BooleanExprNode( false ); }
#line 1711 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 85:
#line 602 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_eq; }
#line 1717 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 86:
#line 604 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_gt; }
#line 1723 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 87:
#line 606 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_gteq; }
#line 1729 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 88:
#line 608 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_neq; }
#line 1735 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 89:
#line 610 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_lt; }
#line 1741 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 90:
#line 612 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_lteq; }
#line 1747 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 91:
#line 616 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_plus; }
#line 1753 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 92:
#line 618 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_minus; }
#line 1759 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 93:
#line 620 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_or; }
#line 1765 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 94:
#line 624 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_multiply; }
#line 1771 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 95:
#line 626 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_divide; }
#line 1777 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 96:
#line 628 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_div; }
#line 1783 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;

  case 97:
#line 630 "tpparser.yy" // lalr1.cc:919
    { yylhs.value.as < LNG::ExprOperator > () = LNG::ExprOperator::o_and; }
#line 1789 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
    break;


#line 1793 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -139;

  const signed char parser::yytable_ninf_ = -63;

  const short
  parser::yypact_[] =
  {
     -35,   -38,    63,    -8,  -139,  -139,    27,    21,    79,  -139,
    -139,    21,    77,    13,  -139,    88,    29,    93,  -139,   -14,
      71,    87,  -139,    72,    75,  -139,  -139,  -139,  -139,   101,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,    16,   103,   104,
      16,   105,   108,     0,  -139,   -19,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,   129,  -139,  -139,   109,    25,    25,
      51,    16,  -139,  -139,    34,  -139,  -139,    82,    97,    26,
    -139,  -139,  -139,  -139,  -139,   111,   111,    73,     2,     2,
      16,    16,  -139,    87,  -139,    16,   135,   135,   136,  -139,
    -139,  -139,   107,    16,    16,  -139,  -139,  -139,  -139,  -139,
    -139,    87,    16,  -139,  -139,  -139,    16,  -139,  -139,  -139,
    -139,    16,   137,   140,   141,    87,  -139,   142,   146,   143,
     133,    11,   146,  -139,   146,    21,   145,   144,   118,  -139,
     139,    24,   147,    97,    26,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,    16,  -139,    65,   -16,  -139,    61,  -139,   148,
    -139,  -139,    87,   146,    61,  -139,    21,   149,    27,   131,
    -139,  -139,  -139,  -139,    88,   150,    61,    27,  -139,  -139,
    -139,   151,  -139
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     2,     6,     0,     0,    23,
      11,     5,     0,     0,     3,     0,    21,     0,     8,     0,
       0,    46,     4,     0,     0,    22,    24,    25,     7,     0,
      15,    14,    16,     9,    12,    13,    10,     0,     0,     0,
       0,     0,     0,    57,    42,     0,    20,    45,    38,    39,
      40,    41,    43,    44,     0,    29,    26,     0,     0,     0,
       0,     0,    84,    83,    78,    81,    82,     0,    65,    67,
      69,    70,    72,    77,    75,     0,     0,     0,     0,     0,
       0,     0,    48,    46,    18,     0,    33,    33,     0,    74,
      73,    71,     0,     0,     0,    85,    86,    87,    89,    90,
      88,    46,     0,    92,    91,    93,     0,    94,    95,    96,
      97,     0,    62,     0,     0,    46,    60,     0,    61,     0,
       0,     0,    59,    19,    47,     0,     0,     0,     0,    76,
       0,     0,    53,    64,    66,    68,    49,    50,    55,    51,
      52,    63,     0,    56,     0,     0,    35,     0,    27,     0,
      80,    79,    46,    58,     0,    32,     0,     0,     6,     0,
      54,    36,    34,    30,     0,     0,     0,     6,    37,    28,
      17,     0,    31
  };

  const short
  parser::yypgoto_[] =
  {
    -139,  -139,  -139,  -139,   166,  -139,   162,  -119,  -139,  -138,
    -139,   -15,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,    91,  -139,    23,    14,   -81,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,    86,   106,    18,   -36,    80,
      78,    76,   123,    38,  -139,  -139,  -139,  -139,  -139
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     6,     8,   164,    11,    12,    13,    33,    34,
      35,    44,    45,    15,    16,    25,    26,    87,   158,    27,
      86,   167,   126,   145,   146,   165,    46,    47,    48,    49,
      50,    51,    52,    53,    82,   121,   117,    54,   118,    68,
      69,    70,    71,    72,    73,    74,   102,   106,   111
  };

  const short
  parser::yytable_[] =
  {
      22,    67,   123,   -62,    77,     1,   144,    83,   155,   157,
     156,     3,    58,    59,    84,    29,   161,    30,     5,    60,
     132,    80,    81,    31,    61,    92,    58,    59,   170,    32,
     142,    19,    20,    60,   138,   143,    62,   144,    61,   107,
     108,   109,   110,   142,   120,   122,    63,    61,   151,   124,
      62,    64,    65,    66,   116,    93,    94,   130,   122,    62,
      63,    58,    59,     4,    23,    64,    65,    66,    24,    63,
      10,   160,     7,    61,    64,    65,    66,    95,    96,    97,
      98,    99,   100,   154,    20,    62,    95,    96,    97,    98,
      99,   100,    30,   113,   114,    63,    89,    90,    31,    14,
      64,    65,    66,    18,    32,   115,   153,   103,   104,   105,
     101,    95,    96,    97,    98,    99,   100,    21,    21,    28,
      36,    55,    57,    37,    56,    75,    76,    78,    38,    39,
      79,   129,    85,    40,    41,    42,    43,    95,    96,    97,
      98,    99,   100,    95,    96,    97,    98,    99,   100,   168,
      95,    96,    97,    98,    99,   100,   141,   125,    80,    88,
     112,   128,   150,   147,   136,   137,   139,   140,   149,   166,
     148,   159,     9,    17,   152,   163,   169,   172,   127,   162,
     131,   171,   133,    91,   134,   119,     0,   135
  };

  const short
  parser::yycheck_[] =
  {
      15,    37,    83,     3,    40,    40,   125,    26,    24,   147,
      26,    49,    10,    11,    33,    29,   154,    31,    26,    17,
     101,    21,    22,    37,    22,    61,    10,    11,   166,    43,
      19,    18,    19,    17,   115,    24,    34,   156,    22,    13,
      14,    15,    16,    19,    80,    81,    44,    22,    24,    85,
      34,    49,    50,    51,    52,    21,    22,    93,    94,    34,
      44,    10,    11,     0,    35,    49,    50,    51,    39,    44,
      49,   152,    45,    22,    49,    50,    51,     4,     5,     6,
       7,     8,     9,    18,    19,    34,     4,     5,     6,     7,
       8,     9,    31,    75,    76,    44,    58,    59,    37,    20,
      49,    50,    51,    26,    43,    32,   142,    10,    11,    12,
      28,     4,     5,     6,     7,     8,     9,    30,    30,    26,
      49,    49,    21,    36,    49,    22,    22,    22,    41,    42,
      22,    24,     3,    46,    47,    48,    49,     4,     5,     6,
       7,     8,     9,     4,     5,     6,     7,     8,     9,   164,
       4,     5,     6,     7,     8,     9,    23,    22,    21,    50,
      49,    25,    23,    18,    24,    24,    24,    24,    50,    38,
      26,    23,     6,    11,    27,    26,    26,    26,    87,   156,
      94,   167,   102,    60,   106,    79,    -1,   111
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    40,    55,    49,     0,    26,    56,    45,    57,    58,
      49,    59,    60,    61,    20,    67,    68,    60,    26,    18,
      19,    30,    65,    35,    39,    69,    70,    73,    26,    29,
      31,    37,    43,    62,    63,    64,    49,    36,    41,    42,
      46,    47,    48,    49,    65,    66,    80,    81,    82,    83,
      84,    85,    86,    87,    91,    49,    49,    21,    10,    11,
      17,    22,    34,    44,    49,    50,    51,    92,    93,    94,
      95,    96,    97,    98,    99,    22,    22,    92,    22,    22,
      21,    22,    88,    26,    33,     3,    74,    71,    50,    97,
      97,    96,    92,    21,    22,     4,     5,     6,     7,     8,
       9,    28,   100,    10,    11,    12,   101,    13,    14,    15,
      16,   102,    49,    91,    91,    32,    52,    90,    92,    90,
      92,    89,    92,    80,    92,    22,    76,    76,    25,    24,
      92,    89,    80,    93,    94,    95,    24,    24,    80,    24,
      24,    23,    19,    24,    61,    77,    78,    18,    26,    50,
      23,    24,    27,    92,    18,    24,    26,    63,    72,    23,
      80,    63,    78,    26,    58,    79,    38,    75,    65,    26,
      63,    79,    26
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    56,    55,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    63,    64,    65,    66,
      66,    67,    68,    68,    69,    69,    71,    72,    70,    74,
      75,    73,    76,    76,    77,    77,    78,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    82,    83,    84,
      84,    85,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     6,     3,     2,     0,     3,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     8,     3,     3,
       1,     1,     2,     0,     1,     1,     0,     0,     8,     0,
       0,    10,     3,     0,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     2,     4,
       4,     4,     4,     4,     6,     4,     3,     0,     3,     1,
       1,     1,     1,     4,     3,     1,     3,     1,     3,     1,
       1,     2,     1,     2,     2,     1,     3,     1,     1,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "t_eoi", "error", "$undefined", "t_assign", "t_eq", "t_gt", "t_gteq",
  "t_lt", "t_lteq", "t_neq", "t_minus", "t_plus", "t_or", "t_multiply",
  "t_divide", "t_div", "t_and", "t_not", "t_colon", "t_comma", "t_dot",
  "t_lbracket", "t_lparenthesis", "t_rbracket", "t_rparenthesis",
  "t_subrange", "t_semicolon", "t_else", "t_then", "t_array", "t_begin",
  "t_boolean", "t_do", "t_end", "t_false", "t_function", "t_if",
  "t_integer", "t_of", "t_procedure", "t_program", "t_read", "t_readln",
  "t_real", "t_true", "t_var", "t_while", "t_write", "t_writeln",
  "t_identifier", "t_integer_l", "t_real_l", "t_string_l", "t_unknown",
  "$accept", "program", "$@1", "main_block", "variable_declarations",
  "list_variable_declaration", "variable_declaration", "list_identifier",
  "type", "simple_type", "array_type", "compound_statement",
  "list_statement", "callable_declarations", "list_callable_declarations",
  "callable_declaration", "procedure_declaration", "$@2", "$@3",
  "function_declaration", "$@4", "$@5", "opt_parameters",
  "list_parameter_list", "parameter_list", "block", "statement",
  "empty_statement", "assignment_statement", "procedure_statement",
  "read_statement", "write_statement", "if_statement", "while_statement",
  "optional_arguments", "list_argument", "output_value", "variable_lvalue",
  "expression", "simple_expression", "term", "complemented_factor",
  "signed_factor", "factor", "function_call_or_variable_rvalue",
  "constant", "rel_op", "add_op", "mult_op", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   211,   211,   210,   218,   225,   228,   232,   235,   240,
     256,   259,   264,   266,   270,   272,   274,   278,   283,   290,
     293,   298,   303,   306,   310,   312,   317,   319,   316,   337,
     339,   336,   356,   359,   363,   366,   371,   387,   393,   395,
     397,   399,   401,   403,   405,   407,   411,   415,   420,   425,
     428,   433,   436,   441,   444,   449,   454,   457,   461,   464,
     469,   472,   477,   487,   499,   502,   507,   510,   515,   518,
     523,   526,   531,   534,   537,   542,   545,   548,   553,   567,
     577,   588,   591,   594,   597,   602,   604,   606,   608,   610,
     612,   616,   618,   620,   624,   626,   628,   630
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2313 "/mnt/c/Users/halli/CLionProjects/TurboPascal/cmake-build-debug/../tpparser.cpp" // lalr1.cc:1242
#line 633 "tpparser.yy" // lalr1.cc:1243


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
