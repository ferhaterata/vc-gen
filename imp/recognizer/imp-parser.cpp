// A Bison parser, made by GNU Bison 3.4.

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


// Take the name prefix into account.
#define yylex   implex



#include "imp-parser.hpp"


// Unqualified %code blocks.
#line 40 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"

# include "../imp-driver.hpp"

template <class T, class V>
T&& enlist(T& t, V& v)
{
    t.push_back(move(v));
    return move(t);
}

template <typename T>
void print(std::vector<T>& v){
  if ( !v.empty() ) {
    cout << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(cout, ", "));
    cout << "\b\b]";
  }
}


#line 68 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"


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
#if IMPDEBUG

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

#else // !IMPDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !IMPDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
namespace imp {
#line 163 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  imp_parser::yytnamerr_ (const char *yystr)
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
  imp_parser::imp_parser (imp_driver& driver_yyarg)
    :
#if IMPDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  imp_parser::~imp_parser ()
  {}

  imp_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  imp_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  imp_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  imp_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  imp_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  imp_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  imp_parser::symbol_number_type
  imp_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  imp_parser::stack_symbol_type::stack_symbol_type ()
  {}

  imp_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 41: // aexp
        value.YY_MOVE_OR_COPY< imp::ast::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 57: // assertion
        value.YY_MOVE_OR_COPY< imp::ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 50: // block
        value.YY_MOVE_OR_COPY< imp::ast::Block* > (YY_MOVE (that.value));
        break;

      case 44: // bexp
        value.YY_MOVE_OR_COPY< imp::ast::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 45: // comp
        value.YY_MOVE_OR_COPY< imp::ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 43: // constant
        value.YY_MOVE_OR_COPY< imp::ast::Constant* > (YY_MOVE (that.value));
        break;

      case 49: // inv
        value.YY_MOVE_OR_COPY< imp::ast::Invariant* > (YY_MOVE (that.value));
        break;

      case 47: // location
        value.YY_MOVE_OR_COPY< imp::ast::Location* > (YY_MOVE (that.value));
        break;

      case 56: // post
        value.YY_MOVE_OR_COPY< imp::ast::PostCondition* > (YY_MOVE (that.value));
        break;

      case 54: // pre
        value.YY_MOVE_OR_COPY< imp::ast::PreCondition* > (YY_MOVE (that.value));
        break;

      case 52: // prog
        value.YY_MOVE_OR_COPY< imp::ast::Program* > (YY_MOVE (that.value));
        break;

      case 42: // reference
        value.YY_MOVE_OR_COPY< imp::ast::Reference* > (YY_MOVE (that.value));
        break;

      case 46: // stmt
        value.YY_MOVE_OR_COPY< imp::ast::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 48: // inv_list
        value.YY_MOVE_OR_COPY< std::vector<imp::ast::Invariant*> > (YY_MOVE (that.value));
        break;

      case 55: // post_list
        value.YY_MOVE_OR_COPY< std::vector<imp::ast::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 53: // pre_list
        value.YY_MOVE_OR_COPY< std::vector<imp::ast::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 51: // stmt_list
        value.YY_MOVE_OR_COPY< std::vector<imp::ast::Statement*> > (YY_MOVE (that.value));
        break;

      case 58: // identifier_list
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  imp_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< imp::ast::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 57: // assertion
        value.move< imp::ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 50: // block
        value.move< imp::ast::Block* > (YY_MOVE (that.value));
        break;

      case 44: // bexp
        value.move< imp::ast::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 45: // comp
        value.move< imp::ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 43: // constant
        value.move< imp::ast::Constant* > (YY_MOVE (that.value));
        break;

      case 49: // inv
        value.move< imp::ast::Invariant* > (YY_MOVE (that.value));
        break;

      case 47: // location
        value.move< imp::ast::Location* > (YY_MOVE (that.value));
        break;

      case 56: // post
        value.move< imp::ast::PostCondition* > (YY_MOVE (that.value));
        break;

      case 54: // pre
        value.move< imp::ast::PreCondition* > (YY_MOVE (that.value));
        break;

      case 52: // prog
        value.move< imp::ast::Program* > (YY_MOVE (that.value));
        break;

      case 42: // reference
        value.move< imp::ast::Reference* > (YY_MOVE (that.value));
        break;

      case 46: // stmt
        value.move< imp::ast::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 48: // inv_list
        value.move< std::vector<imp::ast::Invariant*> > (YY_MOVE (that.value));
        break;

      case 55: // post_list
        value.move< std::vector<imp::ast::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 53: // pre_list
        value.move< std::vector<imp::ast::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 51: // stmt_list
        value.move< std::vector<imp::ast::Statement*> > (YY_MOVE (that.value));
        break;

      case 58: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  imp_parser::stack_symbol_type&
  imp_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< imp::ast::ArithmeticExpression* > (that.value);
        break;

      case 57: // assertion
        value.move< imp::ast::Assertion* > (that.value);
        break;

      case 50: // block
        value.move< imp::ast::Block* > (that.value);
        break;

      case 44: // bexp
        value.move< imp::ast::BooleanExpression* > (that.value);
        break;

      case 45: // comp
        value.move< imp::ast::Comparison* > (that.value);
        break;

      case 43: // constant
        value.move< imp::ast::Constant* > (that.value);
        break;

      case 49: // inv
        value.move< imp::ast::Invariant* > (that.value);
        break;

      case 47: // location
        value.move< imp::ast::Location* > (that.value);
        break;

      case 56: // post
        value.move< imp::ast::PostCondition* > (that.value);
        break;

      case 54: // pre
        value.move< imp::ast::PreCondition* > (that.value);
        break;

      case 52: // prog
        value.move< imp::ast::Program* > (that.value);
        break;

      case 42: // reference
        value.move< imp::ast::Reference* > (that.value);
        break;

      case 46: // stmt
        value.move< imp::ast::Statement* > (that.value);
        break;

      case 39: // "number"
        value.move< int > (that.value);
        break;

      case 38: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 48: // inv_list
        value.move< std::vector<imp::ast::Invariant*> > (that.value);
        break;

      case 55: // post_list
        value.move< std::vector<imp::ast::PostCondition*> > (that.value);
        break;

      case 53: // pre_list
        value.move< std::vector<imp::ast::PreCondition*> > (that.value);
        break;

      case 51: // stmt_list
        value.move< std::vector<imp::ast::Statement*> > (that.value);
        break;

      case 58: // identifier_list
        value.move< std::vector<std::string> > (that.value);
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
  imp_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if IMPDEBUG
  template <typename Base>
  void
  imp_parser::yy_print_ (std::ostream& yyo,
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
  imp_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  imp_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  imp_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if IMPDEBUG
  std::ostream&
  imp_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  imp_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  imp_parser::debug_level_type
  imp_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  imp_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // IMPDEBUG

  imp_parser::state_type
  imp_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  imp_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  imp_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  imp_parser::operator() ()
  {
    return parse ();
  }

  int
  imp_parser::parse ()
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


    // User initialization code.
#line 31 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 699 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"


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
            symbol_type yylookahead (yylex (driver));
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
      case 41: // aexp
        yylhs.value.emplace< imp::ast::ArithmeticExpression* > ();
        break;

      case 57: // assertion
        yylhs.value.emplace< imp::ast::Assertion* > ();
        break;

      case 50: // block
        yylhs.value.emplace< imp::ast::Block* > ();
        break;

      case 44: // bexp
        yylhs.value.emplace< imp::ast::BooleanExpression* > ();
        break;

      case 45: // comp
        yylhs.value.emplace< imp::ast::Comparison* > ();
        break;

      case 43: // constant
        yylhs.value.emplace< imp::ast::Constant* > ();
        break;

      case 49: // inv
        yylhs.value.emplace< imp::ast::Invariant* > ();
        break;

      case 47: // location
        yylhs.value.emplace< imp::ast::Location* > ();
        break;

      case 56: // post
        yylhs.value.emplace< imp::ast::PostCondition* > ();
        break;

      case 54: // pre
        yylhs.value.emplace< imp::ast::PreCondition* > ();
        break;

      case 52: // prog
        yylhs.value.emplace< imp::ast::Program* > ();
        break;

      case 42: // reference
        yylhs.value.emplace< imp::ast::Reference* > ();
        break;

      case 46: // stmt
        yylhs.value.emplace< imp::ast::Statement* > ();
        break;

      case 39: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 38: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 48: // inv_list
        yylhs.value.emplace< std::vector<imp::ast::Invariant*> > ();
        break;

      case 55: // post_list
        yylhs.value.emplace< std::vector<imp::ast::PostCondition*> > ();
        break;

      case 53: // pre_list
        yylhs.value.emplace< std::vector<imp::ast::PreCondition*> > ();
        break;

      case 51: // stmt_list
        yylhs.value.emplace< std::vector<imp::ast::Statement*> > ();
        break;

      case 58: // identifier_list
        yylhs.value.emplace< std::vector<std::string> > ();
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
#line 149 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[0].value.as < imp::ast::Reference* > (); }
#line 904 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 3:
#line 150 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::ArrayReference(*yystack_[3].value.as < imp::ast::Reference* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 910 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 4:
#line 151 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[0].value.as < imp::ast::Constant* > (); }
#line 916 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 5:
#line 152 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Negate(*yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 922 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 6:
#line 153 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Sum(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ());}
#line 928 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 7:
#line 154 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Subtract(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 934 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 8:
#line 155 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Multiply(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 940 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 9:
#line 156 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Divide(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 946 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 10:
#line 157 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Mod(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 952 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 11:
#line 158 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[1].value.as < imp::ast::ArithmeticExpression* > ();}
#line 958 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 12:
#line 161 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Reference* > () = new imp::ast::Reference(yystack_[0].value.as < std::string > ()); }
#line 964 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 13:
#line 164 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Constant* > () = new imp::ast::Constant(yystack_[0].value.as < int > ()); }
#line 970 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 14:
#line 168 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = yystack_[0].value.as < imp::ast::Comparison* > (); }
#line 976 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 15:
#line 169 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::NotExpression(*yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 982 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 16:
#line 170 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::OrExpression(*yystack_[2].value.as < imp::ast::BooleanExpression* > (), *yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 988 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 17:
#line 171 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::AndExpression(*yystack_[2].value.as < imp::ast::BooleanExpression* > (), *yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 994 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 18:
#line 172 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = yystack_[1].value.as < imp::ast::BooleanExpression* > ();}
#line 1000 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 19:
#line 176 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::EqualComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1006 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 20:
#line 177 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::NotEqualComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1012 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 21:
#line 178 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::LeqComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1018 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 22:
#line 179 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::GeqComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1024 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 23:
#line 180 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::LtComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1030 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 24:
#line 181 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::GtComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1036 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 25:
#line 185 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::AssignmentStatement(*yystack_[3].value.as < imp::ast::Location* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1042 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 26:
#line 186 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::MultipleAssignmentStatement(*yystack_[7].value.as < imp::ast::Location* > (), *yystack_[5].value.as < imp::ast::Location* > (), *yystack_[3].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1048 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 27:
#line 187 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::ArrayAssignmentStatement(*yystack_[6].value.as < imp::ast::Location* > (), *yystack_[4].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1054 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 28:
#line 188 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::IfThenElseStatement(*yystack_[5].value.as < imp::ast::BooleanExpression* > (), *yystack_[3].value.as < imp::ast::Block* > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1060 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 29:
#line 189 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::IfThenStatement(*yystack_[3].value.as < imp::ast::BooleanExpression* > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1066 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 30:
#line 190 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::WhileStatement(*yystack_[4].value.as < imp::ast::BooleanExpression* > (), yystack_[3].value.as < std::vector<imp::ast::Invariant*> > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1072 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 31:
#line 191 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { std::vector<imp::ast::Invariant*> inv;
                                                      yylhs.value.as < imp::ast::Statement* > () = new imp::ast::WhileStatement(*yystack_[3].value.as < imp::ast::BooleanExpression* > (), inv, *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1079 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 32:
#line 195 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Location* > () = new imp::ast::Location(yystack_[0].value.as < std::string > (), driver.fresh(yystack_[0].value.as < std::string > ()));}
#line 1085 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 33:
#line 199 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Invariant*> > () = {yystack_[0].value.as < imp::ast::Invariant* > ()}; }
#line 1091 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 34:
#line 200 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Invariant*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::Invariant*> > (), yystack_[0].value.as < imp::ast::Invariant* > ()); }
#line 1097 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 35:
#line 203 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Invariant* > () = new imp::ast::Invariant(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1103 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 36:
#line 206 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Block* > () = new imp::ast::Block(yystack_[0].value.as < std::vector<imp::ast::Statement*> > ()); /*print<imp::ast::Statement>($1);*/}
#line 1109 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 37:
#line 210 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Statement*> > () = {yystack_[0].value.as < imp::ast::Statement* > ()};}
#line 1115 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 38:
#line 211 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Statement*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::Statement*> > (), yystack_[0].value.as < imp::ast::Statement* > ()); }
#line 1121 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 39:
#line 216 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Program* > () = new imp::ast::Program(yystack_[5].value.as < std::string > (), yystack_[4].value.as < std::vector<imp::ast::PreCondition*> > (), yystack_[3].value.as < std::vector<imp::ast::PostCondition*> > (), *yystack_[1].value.as < imp::ast::Block* > ()); driver.program = yylhs.value.as < imp::ast::Program* > ();}
#line 1127 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 40:
#line 218 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { std::vector<imp::ast::PreCondition*> pre;
        yylhs.value.as < imp::ast::Program* > () = new imp::ast::Program(yystack_[4].value.as < std::string > (), pre, yystack_[3].value.as < std::vector<imp::ast::PostCondition*> > (), *yystack_[1].value.as < imp::ast::Block* > ()); driver.program = yylhs.value.as < imp::ast::Program* > ();}
#line 1134 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 41:
#line 221 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { std::vector<imp::ast::PostCondition*> post;
        yylhs.value.as < imp::ast::Program* > () = new imp::ast::Program(yystack_[4].value.as < std::string > (), yystack_[3].value.as < std::vector<imp::ast::PreCondition*> > (), post, *yystack_[1].value.as < imp::ast::Block* > ()); driver.program = yylhs.value.as < imp::ast::Program* > ();}
#line 1141 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 42:
#line 224 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { std::vector<imp::ast::PreCondition*> pre;
        std::vector<imp::ast::PostCondition*> post;
        yylhs.value.as < imp::ast::Program* > () = new imp::ast::Program(yystack_[3].value.as < std::string > (), pre, post, *yystack_[1].value.as < imp::ast::Block* > ()); driver.program = yylhs.value.as < imp::ast::Program* > ();}
#line 1149 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 43:
#line 230 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PreCondition*> > () = {yystack_[0].value.as < imp::ast::PreCondition* > ()}; }
#line 1155 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 44:
#line 231 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PreCondition*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::PreCondition*> > (), yystack_[0].value.as < imp::ast::PreCondition* > ()); }
#line 1161 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 45:
#line 234 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::PreCondition* > () = new imp::ast::PreCondition(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1167 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 46:
#line 238 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PostCondition*> > () = {yystack_[0].value.as < imp::ast::PostCondition* > ()}; }
#line 1173 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 47:
#line 239 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PostCondition*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::PostCondition*> > (), yystack_[0].value.as < imp::ast::PostCondition* > ()); }
#line 1179 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 48:
#line 242 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::PostCondition* > () = new imp::ast::PostCondition(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1185 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 49:
#line 246 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = yystack_[0].value.as < imp::ast::Comparison* > (); }
#line 1191 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 50:
#line 247 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Negation(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1197 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 51:
#line 248 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Disjunction(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1203 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 52:
#line 249 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Conjunction(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1209 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 53:
#line 250 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Implication(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1215 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 54:
#line 251 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::UniversalQuantifier(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1221 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 55:
#line 252 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::ExistentialQuantifier(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1227 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 56:
#line 253 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = yystack_[1].value.as < imp::ast::Assertion* > (); }
#line 1233 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 57:
#line 254 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    {  }
#line 1239 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 58:
#line 258 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
#line 1245 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 59:
#line 259 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1251 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;


#line 1255 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"

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
  imp_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  imp_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char imp_parser::yypact_ninf_ = -31;

  const signed char imp_parser::yytable_ninf_ = -1;

  const short
  imp_parser::yypact_[] =
  {
     -27,   -30,    18,   168,   -31,    76,    76,   -19,   171,   -31,
     -23,   -31,    24,    60,    76,    22,    22,   -31,   -31,   173,
      -2,   -31,   -31,    13,    13,    65,    65,   -31,   -31,    64,
       4,   -19,   -19,   -31,    84,   -19,   -31,    24,   201,    58,
     160,   107,   -31,   -31,    -5,    34,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    76,    76,
      76,    65,    65,    48,   -31,   164,    24,    32,    24,   -31,
     -31,    53,   -19,    57,   190,   -31,   -31,   -31,    76,   -31,
      76,   201,   201,    79,    79,   153,   153,   153,   153,   153,
     153,   153,    17,   103,    73,    13,   122,   -31,    65,    65,
     -19,   -19,    76,   162,   -31,   130,    83,   102,   -31,    70,
     -31,    13,    13,   -31,   -31,   192,    92,   187,    98,    13,
     -19,   -31,   -31,    24,   119,   -31,   -19,   -31,   -31,   116,
     123,    24,   118,   -31,    24,   142,   -31,   148,   -31,   -31
  };

  const unsigned char
  imp_parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,     0,     0,    43,
       0,    46,     0,     0,     0,     0,     0,    12,    13,     0,
       2,     4,    49,    45,    48,     0,     0,    32,    37,     0,
       0,    36,     0,    44,     0,     0,    47,     0,     5,     0,
       0,     0,    50,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    42,
      38,     0,     0,     0,     0,    57,    11,    56,     0,    59,
       0,     6,     7,     8,     9,    10,    19,    20,    21,    22,
      23,    24,     0,    51,    52,    53,     0,    15,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,    41,     0,
      40,    54,    55,     3,    18,    16,    17,     0,     0,    35,
       0,    34,    25,     0,     0,    39,     0,    29,    31,     0,
       0,     0,     0,    30,     0,     0,    28,     0,    27,    26
  };

  const short
  imp_parser::yypgoto_[] =
  {
     -31,   -12,   -31,   -31,    -9,   -11,   167,    94,   -31,   110,
     -26,   -31,   -31,   -31,   206,   207,    -8,    -1,   200
  };

  const signed char
  imp_parser::yydefgoto_[] =
  {
      -1,    19,    20,    21,    63,    22,    28,    29,   103,   104,
      30,    31,     2,     8,     9,    10,    11,    23,    44
  };

  const unsigned char
  imp_parser::yytable_[] =
  {
      38,    40,    36,    25,     1,    24,    71,    26,     3,    73,
       6,    35,    41,    42,    64,    64,    78,    65,     4,    27,
      46,    47,    48,    49,    50,    74,    36,    57,    12,    69,
      58,    59,    37,    79,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   109,   113,    60,    40,
      64,    64,    96,    97,   105,    80,   107,    93,    94,    95,
      43,    39,    17,    18,    12,    98,    99,    75,    13,    12,
      27,   100,    79,    61,   117,   118,    14,   111,   108,   112,
      12,    62,   110,    66,    13,    67,    50,    64,    64,   115,
     116,    59,    14,    68,   129,   125,    15,    16,    17,    18,
     132,   119,   123,    17,    18,    46,    47,    48,    49,    50,
      99,   130,    15,    16,    17,    18,    77,     6,    72,   135,
      58,    59,   137,   128,    58,    59,    46,    47,    48,    49,
      50,   114,   124,    46,    47,    48,    49,    50,   131,    98,
      99,   133,    60,   136,   134,    46,    47,    48,    49,    50,
     122,    46,    47,    48,    49,    50,    46,    47,    48,    49,
      50,   106,   138,    46,    47,    48,    49,    50,   139,    76,
      51,    52,    53,    54,    55,    56,    46,    47,    48,    49,
      50,    98,    99,    51,    52,    53,    54,    55,    56,   120,
     102,   101,   102,    46,    47,    48,    49,    50,    70,    76,
       5,     6,     7,     5,     6,    32,    48,    49,    50,    98,
      99,   126,   127,   121,    33,    34,    45
  };

  const unsigned char
  imp_parser::yycheck_[] =
  {
      12,    13,    10,    22,    31,     6,    32,    26,    38,    35,
      33,    34,    13,    14,    25,    26,    21,    26,     0,    38,
       3,     4,     5,     6,     7,    37,    34,    29,     4,    25,
      17,    18,     8,    38,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    72,    30,    35,    61,
      61,    62,    61,    62,    66,    21,    68,    58,    59,    60,
      38,     1,    38,    39,     4,    17,    18,     9,     8,     4,
      38,    23,    38,     8,   100,   101,    16,    78,    25,    80,
       4,    16,    25,    19,     8,    21,     7,    98,    99,    98,
      99,    18,    16,    29,   120,    25,    36,    37,    38,    39,
     126,   102,    19,    38,    39,     3,     4,     5,     6,     7,
      18,   123,    36,    37,    38,    39,     9,    33,    34,   131,
      17,    18,   134,    25,    17,    18,     3,     4,     5,     6,
       7,     9,    30,     3,     4,     5,     6,     7,    19,    17,
      18,    25,    35,    25,    21,     3,     4,     5,     6,     7,
      20,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    67,    20,     3,     4,     5,     6,     7,    20,     9,
      10,    11,    12,    13,    14,    15,     3,     4,     5,     6,
       7,    17,    18,    10,    11,    12,    13,    14,    15,    27,
      28,    27,    28,     3,     4,     5,     6,     7,    31,     9,
      32,    33,    34,    32,    33,    34,     5,     6,     7,    17,
      18,    24,    25,   103,     8,     8,    16
  };

  const unsigned char
  imp_parser::yystos_[] =
  {
       0,    31,    52,    38,     0,    32,    33,    34,    53,    54,
      55,    56,     4,     8,    16,    36,    37,    38,    39,    41,
      42,    43,    45,    57,    57,    22,    26,    38,    46,    47,
      50,    51,    34,    54,    55,    34,    56,     8,    41,     1,
      41,    57,    57,    38,    58,    58,     3,     4,     5,     6,
       7,    10,    11,    12,    13,    14,    15,    29,    17,    18,
      35,     8,    16,    44,    45,    44,    19,    21,    29,    25,
      46,    50,    34,    50,    41,     9,     9,     9,    21,    38,
      21,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    57,    57,    57,    44,    44,    17,    18,
      23,    27,    28,    48,    49,    41,    47,    41,    25,    50,
      25,    57,    57,    30,     9,    44,    44,    50,    50,    57,
      27,    49,    20,    19,    30,    25,    24,    25,    25,    50,
      41,    19,    50,    25,    21,    41,    25,    41,    20,    20
  };

  const unsigned char
  imp_parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    43,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    47,    48,    48,    49,    50,    51,    51,    52,
      52,    52,    52,    53,    53,    54,    55,    55,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58
  };

  const unsigned char
  imp_parser::yyr2_[] =
  {
       0,     2,     1,     4,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     8,     7,     7,     5,
       6,     5,     1,     1,     2,     2,     1,     1,     2,     7,
       6,     6,     5,     1,     2,     2,     1,     2,     2,     1,
       2,     3,     3,     3,     4,     4,     3,     3,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const imp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"(\"", "\")\"", "\"=\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"<\"", "\">\"", "\"!\"", "\"||\"", "\"&&\"", "\":=\"",
  "\";\"", "\",\"", "\"if\"", "\"then\"", "\"else\"", "\"end\"",
  "\"while\"", "\"do\"", "\"inv\"", "\"[\"", "\"]\"", "\"program\"",
  "\"pre\"", "\"post\"", "\"is\"", "\"==>\"", "\"forall\"", "\"exists\"",
  "\"identifier\"", "\"number\"", "$accept", "aexp", "reference",
  "constant", "bexp", "comp", "stmt", "location", "inv_list", "inv",
  "block", "stmt_list", "prog", "pre_list", "pre", "post_list", "post",
  "assertion", "identifier_list", YY_NULLPTR
  };

#if IMPDEBUG
  const unsigned short
  imp_parser::yyrline_[] =
  {
       0,   149,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   161,   164,   168,   169,   170,   171,   172,   176,
     177,   178,   179,   180,   181,   185,   186,   187,   188,   189,
     190,   191,   195,   199,   200,   203,   206,   210,   211,   215,
     217,   220,   223,   230,   231,   234,   238,   239,   242,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   258,   259
  };

  // Print the state stack on the debug stream.
  void
  imp_parser::yystack_print_ ()
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
  imp_parser::yy_reduce_print_ (int yyrule)
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
#endif // IMPDEBUG


#line 9 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
} // imp
#line 1740 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"

#line 261 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"


void
imp::imp_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
