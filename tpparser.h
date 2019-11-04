// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file tpparser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_TPPARSER_H_INCLUDED
# define YY_YY_TPPARSER_H_INCLUDED
// //                    "%code requires" blocks.
#line 5 "tpparser.yy" // lalr1.cc:401

#include <string>
#include <sstream>
#include "common.h"
#include "ast.h"
class BParser;

#line 56 "tpparser.h" // lalr1.cc:401

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 172 "tpparser.h" // lalr1.cc:401



  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // assignment_statement
      char dummy1[sizeof (AST::AssignmentStmtNode*)];

      // main_block
      // block
      char dummy2[sizeof (AST::BlockNode*)];

      // callable_declaration
      char dummy3[sizeof (AST::CallableDeclNode*)];

      // callable_declarations
      char dummy4[sizeof (AST::CallableDeclarationsNode*)];

      // compound_statement
      char dummy5[sizeof (AST::CompoundStmtNode*)];

      // empty_statement
      char dummy6[sizeof (AST::EmptyStmtNode*)];

      // output_value
      // expression
      // simple_expression
      // term
      // complemented_factor
      // signed_factor
      // factor
      // function_call_or_variable_rvalue
      // constant
      char dummy7[sizeof (AST::ExprNode*)];

      // function_declaration
      char dummy8[sizeof (AST::FunctionDeclNode*)];

      // if_statement
      char dummy9[sizeof (AST::IfStmtNode*)];

      // procedure_statement
      char dummy10[sizeof (AST::ProcedureCallStmtNode*)];

      // procedure_declaration
      char dummy11[sizeof (AST::ProcedureDeclNode*)];

      // read_statement
      char dummy12[sizeof (AST::ReadStmtNode*)];

      // statement
      char dummy13[sizeof (AST::StmtNode*)];

      // variable_declaration
      // parameter_list
      char dummy14[sizeof (AST::VariableDeclNode*)];

      // variable_declarations
      // opt_parameters
      char dummy15[sizeof (AST::VariableDeclarationsNode*)];

      // variable_lvalue
      char dummy16[sizeof (AST::VariableNode*)];

      // while_statement
      char dummy17[sizeof (AST::WhileStmtNode*)];

      // write_statement
      char dummy18[sizeof (AST::WriteStmtNode*)];

      // type
      // array_type
      char dummy19[sizeof (LNG::DataType)];

      // rel_op
      // add_op
      // mult_op
      char dummy20[sizeof (LNG::ExprOperator)];

      // simple_type
      char dummy21[sizeof (LNG::SimpleDataType)];

      // list_callable_declarations
      char dummy22[sizeof (std::list<AST::CallableDeclNode*>)];

      // optional_arguments
      // list_argument
      char dummy23[sizeof (std::list<AST::ExprNode*>)];

      // list_statement
      char dummy24[sizeof (std::list<AST::StmtNode*>)];

      // list_variable_declaration
      // list_parameter_list
      char dummy25[sizeof (std::list<AST::VariableDeclNode*>)];

      // list_identifier
      char dummy26[sizeof (std::list<std::string>)];

      // t_identifier
      // t_integer_l
      // t_real_l
      // t_string_l
      char dummy27[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        t_eoi = 0,
        t_assign = 258,
        t_eq = 259,
        t_gt = 260,
        t_gteq = 261,
        t_lt = 262,
        t_lteq = 263,
        t_neq = 264,
        t_minus = 265,
        t_plus = 266,
        t_or = 267,
        t_multiply = 268,
        t_divide = 269,
        t_div = 270,
        t_and = 271,
        t_not = 272,
        t_colon = 273,
        t_comma = 274,
        t_dot = 275,
        t_lbracket = 276,
        t_lparenthesis = 277,
        t_rbracket = 278,
        t_rparenthesis = 279,
        t_subrange = 280,
        t_semicolon = 281,
        t_else = 282,
        t_then = 283,
        t_array = 284,
        t_begin = 285,
        t_boolean = 286,
        t_do = 287,
        t_end = 288,
        t_false = 289,
        t_function = 290,
        t_if = 291,
        t_integer = 292,
        t_of = 293,
        t_procedure = 294,
        t_program = 295,
        t_read = 296,
        t_readln = 297,
        t_real = 298,
        t_true = 299,
        t_var = 300,
        t_while = 301,
        t_write = 302,
        t_writeln = 303,
        t_identifier = 304,
        t_integer_l = 305,
        t_real_l = 306,
        t_string_l = 307,
        t_unknown = 308
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::AssignmentStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::AssignmentStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::BlockNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::BlockNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::CallableDeclNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::CallableDeclNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::CallableDeclarationsNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::CallableDeclarationsNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::CompoundStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::CompoundStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::EmptyStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::EmptyStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::ExprNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::ExprNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::FunctionDeclNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::FunctionDeclNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::IfStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::IfStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::ProcedureCallStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::ProcedureCallStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::ProcedureDeclNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::ProcedureDeclNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::ReadStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::ReadStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::StmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::StmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::VariableDeclNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::VariableDeclNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::VariableDeclarationsNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::VariableDeclarationsNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::VariableNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::VariableNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::WhileStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::WhileStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::WriteStmtNode*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::WriteStmtNode*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LNG::DataType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LNG::DataType& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LNG::ExprOperator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LNG::ExprOperator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LNG::SimpleDataType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LNG::SimpleDataType& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<AST::CallableDeclNode*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<AST::CallableDeclNode*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<AST::ExprNode*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<AST::ExprNode*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<AST::StmtNode*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<AST::StmtNode*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<AST::VariableDeclNode*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<AST::VariableDeclNode*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 82: // assignment_statement
        value.template destroy< AST::AssignmentStmtNode* > ();
        break;

      case 57: // main_block
      case 79: // block
        value.template destroy< AST::BlockNode* > ();
        break;

      case 69: // callable_declaration
        value.template destroy< AST::CallableDeclNode* > ();
        break;

      case 67: // callable_declarations
        value.template destroy< AST::CallableDeclarationsNode* > ();
        break;

      case 65: // compound_statement
        value.template destroy< AST::CompoundStmtNode* > ();
        break;

      case 81: // empty_statement
        value.template destroy< AST::EmptyStmtNode* > ();
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
        value.template destroy< AST::ExprNode* > ();
        break;

      case 73: // function_declaration
        value.template destroy< AST::FunctionDeclNode* > ();
        break;

      case 86: // if_statement
        value.template destroy< AST::IfStmtNode* > ();
        break;

      case 83: // procedure_statement
        value.template destroy< AST::ProcedureCallStmtNode* > ();
        break;

      case 70: // procedure_declaration
        value.template destroy< AST::ProcedureDeclNode* > ();
        break;

      case 84: // read_statement
        value.template destroy< AST::ReadStmtNode* > ();
        break;

      case 80: // statement
        value.template destroy< AST::StmtNode* > ();
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.template destroy< AST::VariableDeclNode* > ();
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.template destroy< AST::VariableDeclarationsNode* > ();
        break;

      case 91: // variable_lvalue
        value.template destroy< AST::VariableNode* > ();
        break;

      case 87: // while_statement
        value.template destroy< AST::WhileStmtNode* > ();
        break;

      case 85: // write_statement
        value.template destroy< AST::WriteStmtNode* > ();
        break;

      case 62: // type
      case 64: // array_type
        value.template destroy< LNG::DataType > ();
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.template destroy< LNG::ExprOperator > ();
        break;

      case 63: // simple_type
        value.template destroy< LNG::SimpleDataType > ();
        break;

      case 68: // list_callable_declarations
        value.template destroy< std::list<AST::CallableDeclNode*> > ();
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.template destroy< std::list<AST::ExprNode*> > ();
        break;

      case 66: // list_statement
        value.template destroy< std::list<AST::StmtNode*> > ();
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.template destroy< std::list<AST::VariableDeclNode*> > ();
        break;

      case 61: // list_identifier
        value.template destroy< std::list<std::string> > ();
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::t_eoi || tok == token::t_assign || tok == token::t_eq || tok == token::t_gt || tok == token::t_gteq || tok == token::t_lt || tok == token::t_lteq || tok == token::t_neq || tok == token::t_minus || tok == token::t_plus || tok == token::t_or || tok == token::t_multiply || tok == token::t_divide || tok == token::t_div || tok == token::t_and || tok == token::t_not || tok == token::t_colon || tok == token::t_comma || tok == token::t_dot || tok == token::t_lbracket || tok == token::t_lparenthesis || tok == token::t_rbracket || tok == token::t_rparenthesis || tok == token::t_subrange || tok == token::t_semicolon || tok == token::t_else || tok == token::t_then || tok == token::t_array || tok == token::t_begin || tok == token::t_boolean || tok == token::t_do || tok == token::t_end || tok == token::t_false || tok == token::t_function || tok == token::t_if || tok == token::t_integer || tok == token::t_of || tok == token::t_procedure || tok == token::t_program || tok == token::t_read || tok == token::t_readln || tok == token::t_real || tok == token::t_true || tok == token::t_var || tok == token::t_while || tok == token::t_write || tok == token::t_writeln || tok == token::t_unknown);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::t_eoi || tok == token::t_assign || tok == token::t_eq || tok == token::t_gt || tok == token::t_gteq || tok == token::t_lt || tok == token::t_lteq || tok == token::t_neq || tok == token::t_minus || tok == token::t_plus || tok == token::t_or || tok == token::t_multiply || tok == token::t_divide || tok == token::t_div || tok == token::t_and || tok == token::t_not || tok == token::t_colon || tok == token::t_comma || tok == token::t_dot || tok == token::t_lbracket || tok == token::t_lparenthesis || tok == token::t_rbracket || tok == token::t_rparenthesis || tok == token::t_subrange || tok == token::t_semicolon || tok == token::t_else || tok == token::t_then || tok == token::t_array || tok == token::t_begin || tok == token::t_boolean || tok == token::t_do || tok == token::t_end || tok == token::t_false || tok == token::t_function || tok == token::t_if || tok == token::t_integer || tok == token::t_of || tok == token::t_procedure || tok == token::t_program || tok == token::t_read || tok == token::t_readln || tok == token::t_real || tok == token::t_true || tok == token::t_var || tok == token::t_while || tok == token::t_write || tok == token::t_writeln || tok == token::t_unknown);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::t_identifier || tok == token::t_integer_l || tok == token::t_real_l || tok == token::t_string_l);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::t_identifier || tok == token::t_integer_l || tok == token::t_real_l || tok == token::t_string_l);
      }
#endif
    };

    /// Build a parser object.
    parser (BParser& prs_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_eoi (location_type l)
      {
        return symbol_type (token::t_eoi, std::move (l));
      }
#else
      static
      symbol_type
      make_t_eoi (const location_type& l)
      {
        return symbol_type (token::t_eoi, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_assign (location_type l)
      {
        return symbol_type (token::t_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_t_assign (const location_type& l)
      {
        return symbol_type (token::t_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_eq (location_type l)
      {
        return symbol_type (token::t_eq, std::move (l));
      }
#else
      static
      symbol_type
      make_t_eq (const location_type& l)
      {
        return symbol_type (token::t_eq, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_gt (location_type l)
      {
        return symbol_type (token::t_gt, std::move (l));
      }
#else
      static
      symbol_type
      make_t_gt (const location_type& l)
      {
        return symbol_type (token::t_gt, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_gteq (location_type l)
      {
        return symbol_type (token::t_gteq, std::move (l));
      }
#else
      static
      symbol_type
      make_t_gteq (const location_type& l)
      {
        return symbol_type (token::t_gteq, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_lt (location_type l)
      {
        return symbol_type (token::t_lt, std::move (l));
      }
#else
      static
      symbol_type
      make_t_lt (const location_type& l)
      {
        return symbol_type (token::t_lt, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_lteq (location_type l)
      {
        return symbol_type (token::t_lteq, std::move (l));
      }
#else
      static
      symbol_type
      make_t_lteq (const location_type& l)
      {
        return symbol_type (token::t_lteq, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_neq (location_type l)
      {
        return symbol_type (token::t_neq, std::move (l));
      }
#else
      static
      symbol_type
      make_t_neq (const location_type& l)
      {
        return symbol_type (token::t_neq, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_minus (location_type l)
      {
        return symbol_type (token::t_minus, std::move (l));
      }
#else
      static
      symbol_type
      make_t_minus (const location_type& l)
      {
        return symbol_type (token::t_minus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_plus (location_type l)
      {
        return symbol_type (token::t_plus, std::move (l));
      }
#else
      static
      symbol_type
      make_t_plus (const location_type& l)
      {
        return symbol_type (token::t_plus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_or (location_type l)
      {
        return symbol_type (token::t_or, std::move (l));
      }
#else
      static
      symbol_type
      make_t_or (const location_type& l)
      {
        return symbol_type (token::t_or, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_multiply (location_type l)
      {
        return symbol_type (token::t_multiply, std::move (l));
      }
#else
      static
      symbol_type
      make_t_multiply (const location_type& l)
      {
        return symbol_type (token::t_multiply, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_divide (location_type l)
      {
        return symbol_type (token::t_divide, std::move (l));
      }
#else
      static
      symbol_type
      make_t_divide (const location_type& l)
      {
        return symbol_type (token::t_divide, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_div (location_type l)
      {
        return symbol_type (token::t_div, std::move (l));
      }
#else
      static
      symbol_type
      make_t_div (const location_type& l)
      {
        return symbol_type (token::t_div, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_and (location_type l)
      {
        return symbol_type (token::t_and, std::move (l));
      }
#else
      static
      symbol_type
      make_t_and (const location_type& l)
      {
        return symbol_type (token::t_and, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_not (location_type l)
      {
        return symbol_type (token::t_not, std::move (l));
      }
#else
      static
      symbol_type
      make_t_not (const location_type& l)
      {
        return symbol_type (token::t_not, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_colon (location_type l)
      {
        return symbol_type (token::t_colon, std::move (l));
      }
#else
      static
      symbol_type
      make_t_colon (const location_type& l)
      {
        return symbol_type (token::t_colon, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_comma (location_type l)
      {
        return symbol_type (token::t_comma, std::move (l));
      }
#else
      static
      symbol_type
      make_t_comma (const location_type& l)
      {
        return symbol_type (token::t_comma, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_dot (location_type l)
      {
        return symbol_type (token::t_dot, std::move (l));
      }
#else
      static
      symbol_type
      make_t_dot (const location_type& l)
      {
        return symbol_type (token::t_dot, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_lbracket (location_type l)
      {
        return symbol_type (token::t_lbracket, std::move (l));
      }
#else
      static
      symbol_type
      make_t_lbracket (const location_type& l)
      {
        return symbol_type (token::t_lbracket, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_lparenthesis (location_type l)
      {
        return symbol_type (token::t_lparenthesis, std::move (l));
      }
#else
      static
      symbol_type
      make_t_lparenthesis (const location_type& l)
      {
        return symbol_type (token::t_lparenthesis, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_rbracket (location_type l)
      {
        return symbol_type (token::t_rbracket, std::move (l));
      }
#else
      static
      symbol_type
      make_t_rbracket (const location_type& l)
      {
        return symbol_type (token::t_rbracket, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_rparenthesis (location_type l)
      {
        return symbol_type (token::t_rparenthesis, std::move (l));
      }
#else
      static
      symbol_type
      make_t_rparenthesis (const location_type& l)
      {
        return symbol_type (token::t_rparenthesis, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_subrange (location_type l)
      {
        return symbol_type (token::t_subrange, std::move (l));
      }
#else
      static
      symbol_type
      make_t_subrange (const location_type& l)
      {
        return symbol_type (token::t_subrange, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_semicolon (location_type l)
      {
        return symbol_type (token::t_semicolon, std::move (l));
      }
#else
      static
      symbol_type
      make_t_semicolon (const location_type& l)
      {
        return symbol_type (token::t_semicolon, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_else (location_type l)
      {
        return symbol_type (token::t_else, std::move (l));
      }
#else
      static
      symbol_type
      make_t_else (const location_type& l)
      {
        return symbol_type (token::t_else, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_then (location_type l)
      {
        return symbol_type (token::t_then, std::move (l));
      }
#else
      static
      symbol_type
      make_t_then (const location_type& l)
      {
        return symbol_type (token::t_then, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_array (location_type l)
      {
        return symbol_type (token::t_array, std::move (l));
      }
#else
      static
      symbol_type
      make_t_array (const location_type& l)
      {
        return symbol_type (token::t_array, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_begin (location_type l)
      {
        return symbol_type (token::t_begin, std::move (l));
      }
#else
      static
      symbol_type
      make_t_begin (const location_type& l)
      {
        return symbol_type (token::t_begin, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_boolean (location_type l)
      {
        return symbol_type (token::t_boolean, std::move (l));
      }
#else
      static
      symbol_type
      make_t_boolean (const location_type& l)
      {
        return symbol_type (token::t_boolean, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_do (location_type l)
      {
        return symbol_type (token::t_do, std::move (l));
      }
#else
      static
      symbol_type
      make_t_do (const location_type& l)
      {
        return symbol_type (token::t_do, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_end (location_type l)
      {
        return symbol_type (token::t_end, std::move (l));
      }
#else
      static
      symbol_type
      make_t_end (const location_type& l)
      {
        return symbol_type (token::t_end, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_false (location_type l)
      {
        return symbol_type (token::t_false, std::move (l));
      }
#else
      static
      symbol_type
      make_t_false (const location_type& l)
      {
        return symbol_type (token::t_false, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_function (location_type l)
      {
        return symbol_type (token::t_function, std::move (l));
      }
#else
      static
      symbol_type
      make_t_function (const location_type& l)
      {
        return symbol_type (token::t_function, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_if (location_type l)
      {
        return symbol_type (token::t_if, std::move (l));
      }
#else
      static
      symbol_type
      make_t_if (const location_type& l)
      {
        return symbol_type (token::t_if, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_integer (location_type l)
      {
        return symbol_type (token::t_integer, std::move (l));
      }
#else
      static
      symbol_type
      make_t_integer (const location_type& l)
      {
        return symbol_type (token::t_integer, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_of (location_type l)
      {
        return symbol_type (token::t_of, std::move (l));
      }
#else
      static
      symbol_type
      make_t_of (const location_type& l)
      {
        return symbol_type (token::t_of, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_procedure (location_type l)
      {
        return symbol_type (token::t_procedure, std::move (l));
      }
#else
      static
      symbol_type
      make_t_procedure (const location_type& l)
      {
        return symbol_type (token::t_procedure, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_program (location_type l)
      {
        return symbol_type (token::t_program, std::move (l));
      }
#else
      static
      symbol_type
      make_t_program (const location_type& l)
      {
        return symbol_type (token::t_program, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_read (location_type l)
      {
        return symbol_type (token::t_read, std::move (l));
      }
#else
      static
      symbol_type
      make_t_read (const location_type& l)
      {
        return symbol_type (token::t_read, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_readln (location_type l)
      {
        return symbol_type (token::t_readln, std::move (l));
      }
#else
      static
      symbol_type
      make_t_readln (const location_type& l)
      {
        return symbol_type (token::t_readln, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_real (location_type l)
      {
        return symbol_type (token::t_real, std::move (l));
      }
#else
      static
      symbol_type
      make_t_real (const location_type& l)
      {
        return symbol_type (token::t_real, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_true (location_type l)
      {
        return symbol_type (token::t_true, std::move (l));
      }
#else
      static
      symbol_type
      make_t_true (const location_type& l)
      {
        return symbol_type (token::t_true, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_var (location_type l)
      {
        return symbol_type (token::t_var, std::move (l));
      }
#else
      static
      symbol_type
      make_t_var (const location_type& l)
      {
        return symbol_type (token::t_var, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_while (location_type l)
      {
        return symbol_type (token::t_while, std::move (l));
      }
#else
      static
      symbol_type
      make_t_while (const location_type& l)
      {
        return symbol_type (token::t_while, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_write (location_type l)
      {
        return symbol_type (token::t_write, std::move (l));
      }
#else
      static
      symbol_type
      make_t_write (const location_type& l)
      {
        return symbol_type (token::t_write, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_writeln (location_type l)
      {
        return symbol_type (token::t_writeln, std::move (l));
      }
#else
      static
      symbol_type
      make_t_writeln (const location_type& l)
      {
        return symbol_type (token::t_writeln, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_identifier (std::string v, location_type l)
      {
        return symbol_type (token::t_identifier, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_t_identifier (const std::string& v, const location_type& l)
      {
        return symbol_type (token::t_identifier, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_integer_l (std::string v, location_type l)
      {
        return symbol_type (token::t_integer_l, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_t_integer_l (const std::string& v, const location_type& l)
      {
        return symbol_type (token::t_integer_l, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_real_l (std::string v, location_type l)
      {
        return symbol_type (token::t_real_l, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_t_real_l (const std::string& v, const location_type& l)
      {
        return symbol_type (token::t_real_l, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_string_l (std::string v, location_type l)
      {
        return symbol_type (token::t_string_l, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_t_string_l (const std::string& v, const location_type& l)
      {
        return symbol_type (token::t_string_l, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_t_unknown (location_type l)
      {
        return symbol_type (token::t_unknown, std::move (l));
      }
#else
      static
      symbol_type
      make_t_unknown (const location_type& l)
      {
        return symbol_type (token::t_unknown, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 187,     ///< Last index in yytable_.
      yynnts_ = 49,  ///< Number of nonterminal symbols.
      yyfinal_ = 4, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 54  ///< Number of tokens.
    };


    // User arguments.
    BParser& prs;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    const unsigned user_token_number_max_ = 308;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 82: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (std::move (that.value));
        break;

      case 57: // main_block
      case 79: // block
        value.move< AST::BlockNode* > (std::move (that.value));
        break;

      case 69: // callable_declaration
        value.move< AST::CallableDeclNode* > (std::move (that.value));
        break;

      case 67: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (std::move (that.value));
        break;

      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (std::move (that.value));
        break;

      case 81: // empty_statement
        value.move< AST::EmptyStmtNode* > (std::move (that.value));
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
        value.move< AST::ExprNode* > (std::move (that.value));
        break;

      case 73: // function_declaration
        value.move< AST::FunctionDeclNode* > (std::move (that.value));
        break;

      case 86: // if_statement
        value.move< AST::IfStmtNode* > (std::move (that.value));
        break;

      case 83: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (std::move (that.value));
        break;

      case 70: // procedure_declaration
        value.move< AST::ProcedureDeclNode* > (std::move (that.value));
        break;

      case 84: // read_statement
        value.move< AST::ReadStmtNode* > (std::move (that.value));
        break;

      case 80: // statement
        value.move< AST::StmtNode* > (std::move (that.value));
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.move< AST::VariableDeclNode* > (std::move (that.value));
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.move< AST::VariableDeclarationsNode* > (std::move (that.value));
        break;

      case 91: // variable_lvalue
        value.move< AST::VariableNode* > (std::move (that.value));
        break;

      case 87: // while_statement
        value.move< AST::WhileStmtNode* > (std::move (that.value));
        break;

      case 85: // write_statement
        value.move< AST::WriteStmtNode* > (std::move (that.value));
        break;

      case 62: // type
      case 64: // array_type
        value.move< LNG::DataType > (std::move (that.value));
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.move< LNG::ExprOperator > (std::move (that.value));
        break;

      case 63: // simple_type
        value.move< LNG::SimpleDataType > (std::move (that.value));
        break;

      case 68: // list_callable_declarations
        value.move< std::list<AST::CallableDeclNode*> > (std::move (that.value));
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.move< std::list<AST::ExprNode*> > (std::move (that.value));
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (std::move (that.value));
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.move< std::list<AST::VariableDeclNode*> > (std::move (that.value));
        break;

      case 61: // list_identifier
        value.move< std::list<std::string> > (std::move (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 82: // assignment_statement
        value.copy< AST::AssignmentStmtNode* > (YY_MOVE (that.value));
        break;

      case 57: // main_block
      case 79: // block
        value.copy< AST::BlockNode* > (YY_MOVE (that.value));
        break;

      case 69: // callable_declaration
        value.copy< AST::CallableDeclNode* > (YY_MOVE (that.value));
        break;

      case 67: // callable_declarations
        value.copy< AST::CallableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
        value.copy< AST::CompoundStmtNode* > (YY_MOVE (that.value));
        break;

      case 81: // empty_statement
        value.copy< AST::EmptyStmtNode* > (YY_MOVE (that.value));
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
        value.copy< AST::ExprNode* > (YY_MOVE (that.value));
        break;

      case 73: // function_declaration
        value.copy< AST::FunctionDeclNode* > (YY_MOVE (that.value));
        break;

      case 86: // if_statement
        value.copy< AST::IfStmtNode* > (YY_MOVE (that.value));
        break;

      case 83: // procedure_statement
        value.copy< AST::ProcedureCallStmtNode* > (YY_MOVE (that.value));
        break;

      case 70: // procedure_declaration
        value.copy< AST::ProcedureDeclNode* > (YY_MOVE (that.value));
        break;

      case 84: // read_statement
        value.copy< AST::ReadStmtNode* > (YY_MOVE (that.value));
        break;

      case 80: // statement
        value.copy< AST::StmtNode* > (YY_MOVE (that.value));
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.copy< AST::VariableDeclNode* > (YY_MOVE (that.value));
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.copy< AST::VariableDeclarationsNode* > (YY_MOVE (that.value));
        break;

      case 91: // variable_lvalue
        value.copy< AST::VariableNode* > (YY_MOVE (that.value));
        break;

      case 87: // while_statement
        value.copy< AST::WhileStmtNode* > (YY_MOVE (that.value));
        break;

      case 85: // write_statement
        value.copy< AST::WriteStmtNode* > (YY_MOVE (that.value));
        break;

      case 62: // type
      case 64: // array_type
        value.copy< LNG::DataType > (YY_MOVE (that.value));
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.copy< LNG::ExprOperator > (YY_MOVE (that.value));
        break;

      case 63: // simple_type
        value.copy< LNG::SimpleDataType > (YY_MOVE (that.value));
        break;

      case 68: // list_callable_declarations
        value.copy< std::list<AST::CallableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.copy< std::list<AST::ExprNode*> > (YY_MOVE (that.value));
        break;

      case 66: // list_statement
        value.copy< std::list<AST::StmtNode*> > (YY_MOVE (that.value));
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.copy< std::list<AST::VariableDeclNode*> > (YY_MOVE (that.value));
        break;

      case 61: // list_identifier
        value.copy< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 82: // assignment_statement
        value.move< AST::AssignmentStmtNode* > (YY_MOVE (s.value));
        break;

      case 57: // main_block
      case 79: // block
        value.move< AST::BlockNode* > (YY_MOVE (s.value));
        break;

      case 69: // callable_declaration
        value.move< AST::CallableDeclNode* > (YY_MOVE (s.value));
        break;

      case 67: // callable_declarations
        value.move< AST::CallableDeclarationsNode* > (YY_MOVE (s.value));
        break;

      case 65: // compound_statement
        value.move< AST::CompoundStmtNode* > (YY_MOVE (s.value));
        break;

      case 81: // empty_statement
        value.move< AST::EmptyStmtNode* > (YY_MOVE (s.value));
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
        value.move< AST::ExprNode* > (YY_MOVE (s.value));
        break;

      case 73: // function_declaration
        value.move< AST::FunctionDeclNode* > (YY_MOVE (s.value));
        break;

      case 86: // if_statement
        value.move< AST::IfStmtNode* > (YY_MOVE (s.value));
        break;

      case 83: // procedure_statement
        value.move< AST::ProcedureCallStmtNode* > (YY_MOVE (s.value));
        break;

      case 70: // procedure_declaration
        value.move< AST::ProcedureDeclNode* > (YY_MOVE (s.value));
        break;

      case 84: // read_statement
        value.move< AST::ReadStmtNode* > (YY_MOVE (s.value));
        break;

      case 80: // statement
        value.move< AST::StmtNode* > (YY_MOVE (s.value));
        break;

      case 60: // variable_declaration
      case 78: // parameter_list
        value.move< AST::VariableDeclNode* > (YY_MOVE (s.value));
        break;

      case 58: // variable_declarations
      case 76: // opt_parameters
        value.move< AST::VariableDeclarationsNode* > (YY_MOVE (s.value));
        break;

      case 91: // variable_lvalue
        value.move< AST::VariableNode* > (YY_MOVE (s.value));
        break;

      case 87: // while_statement
        value.move< AST::WhileStmtNode* > (YY_MOVE (s.value));
        break;

      case 85: // write_statement
        value.move< AST::WriteStmtNode* > (YY_MOVE (s.value));
        break;

      case 62: // type
      case 64: // array_type
        value.move< LNG::DataType > (YY_MOVE (s.value));
        break;

      case 100: // rel_op
      case 101: // add_op
      case 102: // mult_op
        value.move< LNG::ExprOperator > (YY_MOVE (s.value));
        break;

      case 63: // simple_type
        value.move< LNG::SimpleDataType > (YY_MOVE (s.value));
        break;

      case 68: // list_callable_declarations
        value.move< std::list<AST::CallableDeclNode*> > (YY_MOVE (s.value));
        break;

      case 88: // optional_arguments
      case 89: // list_argument
        value.move< std::list<AST::ExprNode*> > (YY_MOVE (s.value));
        break;

      case 66: // list_statement
        value.move< std::list<AST::StmtNode*> > (YY_MOVE (s.value));
        break;

      case 59: // list_variable_declaration
      case 77: // list_parameter_list
        value.move< std::list<AST::VariableDeclNode*> > (YY_MOVE (s.value));
        break;

      case 61: // list_identifier
        value.move< std::list<std::string> > (YY_MOVE (s.value));
        break;

      case 49: // t_identifier
      case 50: // t_integer_l
      case 51: // t_real_l
      case 52: // t_string_l
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
    };
    return token_type (yytoken_number_[type]);
  }


} // yy
#line 2921 "tpparser.h" // lalr1.cc:401




#endif // !YY_YY_TPPARSER_H_INCLUDED
