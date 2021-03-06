// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 12 ".././src/grammar.y"

#include <iostream>
#include <string>
#include <cmath>

#include "operations.h"
#include "scanner.h"
#include "symbol_table.h"

using Operations = gvl::lang::Operations;

gvl::lang::SymbolTable table;

#line 53 "parser.cpp"




#include "parser.h"




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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 8 ".././src/grammar.y"
namespace gvl { namespace lang {
#line 153 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (yyscan_t scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.copy< gvl::lang::Operations > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.copy< std::int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.move< gvl::lang::Operations > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.move< std::int32_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.YY_MOVE_OR_COPY< gvl::lang::Operations > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.YY_MOVE_OR_COPY< std::int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.move< gvl::lang::Operations > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.move< std::int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.copy< gvl::lang::Operations > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.copy< std::int32_t > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        value.move< gvl::lang::Operations > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        value.move< std::int32_t > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case symbol_kind::S_bool_expr: // bool_expr
      case symbol_kind::S_t_bool_expr: // t_bool_expr
      case symbol_kind::S_f_bool_expr: // f_bool_expr
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_num_rel: // num_rel
      case symbol_kind::S_str_rel: // str_rel
        yylhs.value.emplace< gvl::lang::Operations > ();
        break;

      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_num_expr: // num_expr
      case symbol_kind::S_t_num_expr: // t_num_expr
      case symbol_kind::S_f_num_expr: // f_num_expr
        yylhs.value.emplace< std::int32_t > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_str_expr: // str_expr
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
  case 2: // num_expr: num_expr PLUS t_num_expr
#line 89 ".././src/grammar.y"
                                           {
                    yylhs.value.as < std::int32_t > () = yystack_[2].value.as < std::int32_t > () + yystack_[0].value.as < std::int32_t > ();
                }
#line 812 "parser.cpp"
    break;

  case 3: // num_expr: num_expr MINUS t_num_expr
#line 92 ".././src/grammar.y"
                                            {
                    yylhs.value.as < std::int32_t > () = yystack_[2].value.as < std::int32_t > () - yystack_[0].value.as < std::int32_t > ();
                }
#line 820 "parser.cpp"
    break;

  case 4: // num_expr: t_num_expr
#line 95 ".././src/grammar.y"
                             {
                    yylhs.value.as < std::int32_t > () = yystack_[0].value.as < std::int32_t > ();
                }
#line 828 "parser.cpp"
    break;

  case 5: // t_num_expr: t_num_expr MUL f_num_expr
#line 100 ".././src/grammar.y"
                                            {
                    yylhs.value.as < std::int32_t > () = yystack_[2].value.as < std::int32_t > () * yystack_[0].value.as < std::int32_t > ();
                }
#line 836 "parser.cpp"
    break;

  case 6: // t_num_expr: t_num_expr DIV f_num_expr
#line 103 ".././src/grammar.y"
                                            {
                    yylhs.value.as < std::int32_t > () = yystack_[2].value.as < std::int32_t > () / yystack_[0].value.as < std::int32_t > ();
                }
#line 844 "parser.cpp"
    break;

  case 7: // t_num_expr: t_num_expr MOD f_num_expr
#line 106 ".././src/grammar.y"
                                            {
                    yylhs.value.as < std::int32_t > () = yystack_[2].value.as < std::int32_t > () % yystack_[0].value.as < std::int32_t > ();
                }
#line 852 "parser.cpp"
    break;

  case 8: // t_num_expr: f_num_expr
#line 109 ".././src/grammar.y"
                             {
                    yylhs.value.as < std::int32_t > () = yystack_[0].value.as < std::int32_t > ();
                }
#line 860 "parser.cpp"
    break;

  case 9: // f_num_expr: NUM
#line 114 ".././src/grammar.y"
                      {
                    yylhs.value.as < std::int32_t > () = yystack_[0].value.as < std::int32_t > ();
                }
#line 868 "parser.cpp"
    break;

  case 10: // f_num_expr: IDENT
#line 117 ".././src/grammar.y"
                        {
                    yylhs.value.as < std::int32_t > () = table.LookupInteger(yystack_[0].value.as < std::string > (), {yystack_[0].location.begin.line, yystack_[0].location.begin.column});
                }
#line 876 "parser.cpp"
    break;

  case 11: // f_num_expr: READINT
#line 120 ".././src/grammar.y"
                          {
                    std::int32_t input;
                    std::cout << "Enter integer: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    yylhs.value.as < std::int32_t > () = input;
                }
#line 888 "parser.cpp"
    break;

  case 12: // f_num_expr: MINUS num_expr
#line 127 ".././src/grammar.y"
                                 {
                    yylhs.value.as < std::int32_t > () = -yystack_[0].value.as < std::int32_t > ();
                }
#line 896 "parser.cpp"
    break;

  case 13: // f_num_expr: LPAREN num_expr RPAREN
#line 130 ".././src/grammar.y"
                                         {
                    yylhs.value.as < std::int32_t > () = (yystack_[1].value.as < std::int32_t > ());
                }
#line 904 "parser.cpp"
    break;

  case 14: // f_num_expr: LENGTH LPAREN str_expr RPAREN
#line 133 ".././src/grammar.y"
                                                {
                    std::string str = yystack_[1].value.as < std::string > ();
                    yylhs.value.as < std::int32_t > () = str.length();
                }
#line 913 "parser.cpp"
    break;

  case 15: // f_num_expr: POSITION LPAREN str_expr COMMA str_expr RPAREN
#line 137 ".././src/grammar.y"
                                                                 {
                    std::int32_t pos = yystack_[3].value.as < std::string > ().find(yystack_[1].value.as < std::string > ());
                    return pos != std::string::npos ? pos : 0;
                }
#line 922 "parser.cpp"
    break;

  case 16: // str_expr: STRING
#line 144 ".././src/grammar.y"
                         {
                    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
                }
#line 930 "parser.cpp"
    break;

  case 17: // str_expr: IDENT
#line 147 ".././src/grammar.y"
                        {
                    yylhs.value.as < std::string > () = table.LookupString(yystack_[0].value.as < std::string > (), {yystack_[0].location.begin.line, yystack_[0].location.begin.column});
                }
#line 938 "parser.cpp"
    break;

  case 18: // str_expr: READSTR
#line 150 ".././src/grammar.y"
                          {
                    std::string input;
                    std::cout << "Enter integer: ";
                    std::cin >> input;
                    std::cout << std::endl;
                    yylhs.value.as < std::string > () = input;
                }
#line 950 "parser.cpp"
    break;

  case 19: // str_expr: CONCATENATE LPAREN str_expr COMMA str_expr RPAREN
#line 157 ".././src/grammar.y"
                                                                    {
                    yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + yystack_[1].value.as < std::string > ();
                }
#line 958 "parser.cpp"
    break;

  case 20: // str_expr: SUBSTRING LPAREN str_expr COMMA num_expr COMMA num_expr RPAREN
#line 160 ".././src/grammar.y"
                                                                                 {
                    yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > ().substr(yystack_[3].value.as < std::int32_t > (), yystack_[1].value.as < std::int32_t > ());
                }
#line 966 "parser.cpp"
    break;

  case 21: // num_rel: EQ
#line 166 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kEq;
                }
#line 974 "parser.cpp"
    break;

  case 22: // num_rel: LT
#line 169 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kLt;
                }
#line 982 "parser.cpp"
    break;

  case 23: // num_rel: LE
#line 172 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kLe;
                }
#line 990 "parser.cpp"
    break;

  case 24: // num_rel: GT
#line 175 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kGt;
                }
#line 998 "parser.cpp"
    break;

  case 25: // num_rel: GE
#line 178 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kGe;
                }
#line 1006 "parser.cpp"
    break;

  case 26: // num_rel: NE
#line 181 ".././src/grammar.y"
                     {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kNe;
                }
#line 1014 "parser.cpp"
    break;

  case 27: // str_rel: STR_EQ
#line 186 ".././src/grammar.y"
                         {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kEq;
                }
#line 1022 "parser.cpp"
    break;

  case 28: // str_rel: STR_NE
#line 189 ".././src/grammar.y"
                         {
                    yylhs.value.as < gvl::lang::Operations > () = Operations::kNe;
                }
#line 1030 "parser.cpp"
    break;

  case 29: // bool_expr: bool_expr OR t_bool_expr
#line 194 ".././src/grammar.y"
                                           {
                    yylhs.value.as < bool > () = yystack_[2].value.as < bool > () || yystack_[0].value.as < bool > ();
                }
#line 1038 "parser.cpp"
    break;

  case 30: // bool_expr: t_bool_expr
#line 197 ".././src/grammar.y"
                              {
                    yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
                }
#line 1046 "parser.cpp"
    break;

  case 31: // t_bool_expr: t_bool_expr AND f_bool_expr
#line 202 ".././src/grammar.y"
                                              {
                    yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > ();
                }
#line 1054 "parser.cpp"
    break;

  case 32: // t_bool_expr: f_bool_expr
#line 205 ".././src/grammar.y"
                              {
                    yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
                }
#line 1062 "parser.cpp"
    break;

  case 33: // f_bool_expr: BOOL_TRUE
#line 210 ".././src/grammar.y"
                            {
                    yylhs.value.as < bool > () = true;
                }
#line 1070 "parser.cpp"
    break;

  case 34: // f_bool_expr: BOOL_FALSE
#line 213 ".././src/grammar.y"
                             {
                    yylhs.value.as < bool > () = false;
                }
#line 1078 "parser.cpp"
    break;

  case 35: // f_bool_expr: LPAREN bool_expr RPAREN
#line 216 ".././src/grammar.y"
                                          {
                    yylhs.value.as < bool > () = (yystack_[1].value.as < bool > ());
                }
#line 1086 "parser.cpp"
    break;

  case 36: // f_bool_expr: NOT bool_expr
#line 219 ".././src/grammar.y"
                                {
                    yylhs.value.as < bool > () = !yystack_[0].value.as < bool > ();
                }
#line 1094 "parser.cpp"
    break;

  case 37: // f_bool_expr: num_expr num_rel num_expr
#line 222 ".././src/grammar.y"
                                            {
                    bool result;
                    switch(yystack_[1].value.as < gvl::lang::Operations > ()) {
                        case Operations::kEq:
                            result = (yystack_[2].value.as < std::int32_t > () == yystack_[0].value.as < std::int32_t > ());
                            break;
                        case Operations::kLt:
                            result = (yystack_[2].value.as < std::int32_t > () < yystack_[0].value.as < std::int32_t > ());
                            break;
                        case Operations::kLe:
                            result = (yystack_[2].value.as < std::int32_t > () <= yystack_[0].value.as < std::int32_t > ());
                            break;
                        case Operations::kGt:
                            result = (yystack_[2].value.as < std::int32_t > () > yystack_[0].value.as < std::int32_t > ());
                            break;
                        case Operations::kGe:
                            result = (yystack_[2].value.as < std::int32_t > () >= yystack_[0].value.as < std::int32_t > ());
                            break;
                        case Operations::kNe:
                            result = (yystack_[2].value.as < std::int32_t > () != yystack_[0].value.as < std::int32_t > ());
                            break;
                        default:
                            break;
                    }
                    yylhs.value.as < bool > () = result;
                }
#line 1125 "parser.cpp"
    break;

  case 38: // f_bool_expr: str_expr str_rel str_expr
#line 248 ".././src/grammar.y"
                                            {
                    bool result;
                    switch(yystack_[1].value.as < gvl::lang::Operations > ()) {
                        case Operations::kStrEq:
                            result = (yystack_[2].value.as < std::string > () == yystack_[0].value.as < std::string > ());
                            break;
                        case Operations::kStrNe:
                            result = (yystack_[2].value.as < std::string > () != yystack_[0].value.as < std::string > ());
                            break;
                        default:
                            break;
                    }
                    yylhs.value.as < bool > () = result;
                }
#line 1144 "parser.cpp"
    break;

  case 49: // assign_stat: IDENT ASSIGN num_expr
#line 281 ".././src/grammar.y"
                                        {
                    table.AssignInteger(yystack_[2].value.as < std::string > (), {yystack_[2].location.begin.line, yystack_[2].location.begin.column}, yystack_[0].value.as < std::int32_t > ());
                }
#line 1152 "parser.cpp"
    break;

  case 50: // assign_stat: IDENT ASSIGN str_expr
#line 284 ".././src/grammar.y"
                                        {
                    table.AssignString(yystack_[2].value.as < std::string > (), {yystack_[2].location.begin.line, yystack_[2].location.begin.column}, yystack_[0].value.as < std::string > ());
                }
#line 1160 "parser.cpp"
    break;

  case 55: // output_stat: PRINT LPAREN num_expr RPAREN
#line 303 ".././src/grammar.y"
                                               {
                    std::cout << yystack_[1].value.as < std::int32_t > () << std::endl;
                }
#line 1168 "parser.cpp"
    break;

  case 56: // output_stat: PRINT LPAREN str_expr RPAREN
#line 306 ".././src/grammar.y"
                                               {
                    std::cout << yystack_[1].value.as < std::string > () << std::endl;
                }
#line 1176 "parser.cpp"
    break;


#line 1180 "parser.cpp"

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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
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
    YY_STACK_PRINT ();
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -30;

  const signed char Parser::yytable_ninf_ = -18;

  const signed char
  Parser::yypact_[] =
  {
       4,   -17,    36,    36,     4,   -29,     4,   -30,   -30,   -26,
     -30,   -30,   -30,   -30,   -30,    23,    76,   -30,   -30,    -7,
      36,   -30,   -30,    33,    37,    53,    60,   -30,   -30,    66,
      36,   104,    16,   -30,    15,    35,    57,   -30,    -3,    63,
      76,   -12,     4,   -30,    66,    -1,   -30,   101,    99,    99,
      99,    99,   -30,    -1,    93,     1,    66,    66,   -30,   -30,
     -30,   -30,   -30,   -30,    66,    66,    66,    66,   -30,   -30,
      99,    36,     4,    36,     4,    36,    22,    64,   -30,   -30,
      44,   -30,    65,    70,    69,    71,   -30,   -30,    16,    16,
      -1,   -30,   -30,   -30,   -30,    57,   103,   -30,   -30,   101,
     -30,   -30,    66,   -30,    99,    99,     4,   -23,    77,    83,
     -30,    66,   -30,   -30,    82,   -30
  };

  const signed char
  Parser::yydefact_[] =
  {
      48,     0,     0,     0,     0,     0,    48,    45,    47,    57,
      39,    40,    41,    42,    44,     0,     0,     9,    16,    10,
       0,    11,    18,     0,     0,     0,     0,    33,    34,     0,
       0,     0,     4,     8,     0,     0,    30,    32,     0,     0,
       0,     0,     0,     1,     0,    49,    50,    36,     0,     0,
       0,     0,    10,    12,     0,     0,     0,     0,    21,    22,
      24,    23,    25,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    46,
       0,    17,     0,     0,     0,     0,    13,    35,     2,     3,
      37,     5,     6,     7,    38,    29,    51,    31,    53,    54,
      55,    56,     0,    14,     0,     0,     0,     0,     0,     0,
      52,     0,    15,    19,     0,    20
  };

  const short
  Parser::yypgoto_[] =
  {
     -30,   -15,    10,    18,   -14,   -30,   -30,     0,    47,    61,
      -4,   130,   -30,   -30,   -30,   -30,   -30,   -30
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,    31,    32,    33,    34,    64,    70,    35,    36,    37,
       8,     9,    10,    11,    12,    13,    14,    15
  };

  const signed char
  Parser::yytable_[] =
  {
      39,    45,    46,    38,    71,    56,    57,    78,    71,     1,
      16,    74,    40,     2,    53,    54,     3,    42,     4,     5,
      47,   111,     6,    43,     7,    76,    77,    56,    57,    80,
      55,    42,   -17,   -17,    82,    83,    84,    85,    79,    17,
      18,    19,    71,    87,    20,    72,    65,    66,    67,    90,
      56,    57,    21,    22,    68,    69,    94,    23,    24,    25,
      26,    27,    28,    73,   100,    29,    88,    89,    96,    17,
      98,    52,    56,    57,    48,    99,    75,    30,    49,    17,
      18,    19,    21,    91,    92,    93,    86,   107,    24,    25,
     108,   109,    21,    22,    50,    29,   114,    23,    24,    25,
      26,    51,   110,    18,    81,    29,   101,    44,    71,   102,
      56,    57,   103,   104,   106,   105,    22,    44,    95,   112,
      23,    56,    57,    26,   115,   113,    58,    59,    60,    61,
      62,    63,    56,    57,    97,    86,    41,    58,    59,    60,
      61,    62,    63
  };

  const signed char
  Parser::yycheck_[] =
  {
       4,    16,    16,     3,     7,    28,    29,    19,     7,     5,
      27,    14,    41,     9,    29,    30,    12,    43,    14,    15,
      20,    44,    18,     0,    20,    40,    40,    28,    29,    44,
      30,    43,    39,    40,    48,    49,    50,    51,    42,     3,
       4,     5,     7,    42,     8,    10,    30,    31,    32,    64,
      28,    29,    16,    17,    39,    40,    70,    21,    22,    23,
      24,    25,    26,     6,    42,    29,    56,    57,    72,     3,
      74,     5,    28,    29,    41,    75,    13,    41,    41,     3,
       4,     5,    16,    65,    66,    67,    42,   102,    22,    23,
     104,   105,    16,    17,    41,    29,   111,    21,    22,    23,
      24,    41,   106,     4,     5,    29,    42,    41,     7,    44,
      28,    29,    42,    44,    11,    44,    17,    41,    71,    42,
      21,    28,    29,    24,    42,    42,    33,    34,    35,    36,
      37,    38,    28,    29,    73,    42,     6,    33,    34,    35,
      36,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     5,     9,    12,    14,    15,    18,    20,    55,    56,
      57,    58,    59,    60,    61,    62,    27,     3,     4,     5,
       8,    16,    17,    21,    22,    23,    24,    25,    26,    29,
      41,    46,    47,    48,    49,    52,    53,    54,    52,    55,
      41,    56,    43,     0,    41,    46,    49,    52,    41,    41,
      41,    41,     5,    46,    46,    52,    28,    29,    33,    34,
      35,    36,    37,    38,    50,    30,    31,    32,    39,    40,
      51,     7,    10,     6,    14,    13,    46,    49,    19,    55,
      46,     5,    49,    49,    49,    49,    42,    42,    47,    47,
      46,    48,    48,    48,    49,    53,    55,    54,    55,    52,
      42,    42,    44,    42,    44,    44,    11,    46,    49,    49,
      55,    44,    42,    42,    46,    42
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    45,    46,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     1,     2,     3,     4,     6,     1,     1,     1,     6,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     3,     2,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     0,     3,
       3,     4,     6,     4,     4,     4,     4,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "STRING",
  "IDENT", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "WHILE", "UNTIL",
  "DO", "PRINT", "READINT", "READSTR", "BEG", "END", "EXIT", "SUBSTRING",
  "LENGTH", "POSITION", "CONCATENATE", "BOOL_TRUE", "BOOL_FALSE", "ASSIGN",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "LT", "GT", "LE", "GE", "NE",
  "STR_EQ", "STR_NE", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "$accept",
  "num_expr", "t_num_expr", "f_num_expr", "str_expr", "num_rel", "str_rel",
  "bool_expr", "t_bool_expr", "f_bool_expr", "simple_instr", "instr",
  "assign_stat", "if_stat", "while_stat", "until_stat", "output_stat",
  "program", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    89,    89,    92,    95,   100,   103,   106,   109,   114,
     117,   120,   127,   130,   133,   137,   144,   147,   150,   157,
     160,   166,   169,   172,   175,   178,   181,   186,   189,   194,
     197,   202,   205,   210,   213,   216,   219,   222,   248,   265,
     266,   267,   268,   269,   270,   271,   275,   276,   277,   281,
     284,   290,   291,   295,   299,   303,   306,   312
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    // Last valid token kind.
    const int code_max = 299;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 8 ".././src/grammar.y"
} } // gvl::lang
#line 1617 "parser.cpp"

#line 314 ".././src/grammar.y"

 
void gvl::lang::Parser::error(const location_type& loc, const std::string& msg) {
    std::cerr << "[" << loc.begin.line << "] Error: " << msg << std::endl;
}
