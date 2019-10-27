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

# include "imp-driver.hpp"

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
#line 162 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[0].value.as < imp::ast::Reference* > (); }
#line 904 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 3:
#line 163 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::ArrayReference(*yystack_[3].value.as < imp::ast::Reference* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 910 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 4:
#line 164 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[0].value.as < imp::ast::Constant* > (); }
#line 916 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 5:
#line 165 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Negate(*yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 922 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 6:
#line 166 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Sum(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ());}
#line 928 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 7:
#line 167 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Subtract(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 934 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 8:
#line 168 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Multiply(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 940 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 9:
#line 169 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Divide(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 946 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 10:
#line 170 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = new imp::ast::Mod(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 952 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 11:
#line 171 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::ArithmeticExpression* > () = yystack_[1].value.as < imp::ast::ArithmeticExpression* > ();}
#line 958 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 12:
#line 174 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Reference* > () = new imp::ast::Reference(yystack_[0].value.as < std::string > ()); }
#line 964 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 13:
#line 177 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Constant* > () = new imp::ast::Constant(yystack_[0].value.as < int > ()); }
#line 970 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 14:
#line 181 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = yystack_[0].value.as < imp::ast::Comparison* > (); }
#line 976 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 15:
#line 182 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::NotExpression(*yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 982 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 16:
#line 183 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::OrExpression(*yystack_[2].value.as < imp::ast::BooleanExpression* > (), *yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 988 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 17:
#line 184 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = new imp::ast::AndExpression(*yystack_[2].value.as < imp::ast::BooleanExpression* > (), *yystack_[0].value.as < imp::ast::BooleanExpression* > ()); }
#line 994 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 18:
#line 185 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::BooleanExpression* > () = yystack_[1].value.as < imp::ast::BooleanExpression* > ();}
#line 1000 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 19:
#line 189 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::EqualComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1006 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 20:
#line 190 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::NotEqualComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1012 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 21:
#line 191 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::LeqComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1018 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 22:
#line 192 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::GeqComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1024 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 23:
#line 193 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::LtComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1030 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 24:
#line 194 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Comparison* > () = new imp::ast::GtComparison(*yystack_[2].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[0].value.as < imp::ast::ArithmeticExpression* > ()); }
#line 1036 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 25:
#line 198 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::AssignmentStatement(*yystack_[3].value.as < imp::ast::Location* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1042 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 26:
#line 199 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::MultipleAssignmentStatement(*yystack_[7].value.as < imp::ast::Location* > (), *yystack_[5].value.as < imp::ast::Location* > (), *yystack_[3].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1048 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 27:
#line 200 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::ArrayAssignmentStatement(*yystack_[6].value.as < imp::ast::Location* > (), *yystack_[4].value.as < imp::ast::ArithmeticExpression* > (), *yystack_[1].value.as < imp::ast::ArithmeticExpression* > ());}
#line 1054 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 28:
#line 201 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::IfThenElseStatement(*yystack_[5].value.as < imp::ast::BooleanExpression* > (), *yystack_[3].value.as < imp::ast::Block* > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1060 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 29:
#line 202 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::IfThenStatement(*yystack_[3].value.as < imp::ast::BooleanExpression* > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1066 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 30:
#line 203 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Statement* > () = new imp::ast::WhileStatement(*yystack_[4].value.as < imp::ast::BooleanExpression* > (), yystack_[3].value.as < std::vector<imp::ast::Invariant*> > (), *yystack_[1].value.as < imp::ast::Block* > ());}
#line 1072 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 31:
#line 206 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Location* > () = new imp::ast::Location(yystack_[0].value.as < std::string > ()); }
#line 1078 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 32:
#line 210 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Invariant*> > () = {yystack_[0].value.as < imp::ast::Invariant* > ()}; }
#line 1084 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 33:
#line 211 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Invariant*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::Invariant*> > (), yystack_[0].value.as < imp::ast::Invariant* > ()); }
#line 1090 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 34:
#line 214 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Invariant* > () = new imp::ast::Invariant(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1096 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 35:
#line 217 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Block* > () = new imp::ast::Block(yystack_[0].value.as < std::vector<imp::ast::Statement*> > ()); /*print<imp::ast::Statement>($1);*/}
#line 1102 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 36:
#line 221 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Statement*> > () = {yystack_[0].value.as < imp::ast::Statement* > ()};}
#line 1108 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 37:
#line 222 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::Statement*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::Statement*> > (), yystack_[0].value.as < imp::ast::Statement* > ()); }
#line 1114 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 38:
#line 227 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Program* > () = new imp::ast::Program(yystack_[5].value.as < std::string > (), yystack_[4].value.as < std::vector<imp::ast::PreCondition*> > (), yystack_[3].value.as < std::vector<imp::ast::PostCondition*> > (), *yystack_[1].value.as < imp::ast::Block* > ()); driver.program = yylhs.value.as < imp::ast::Program* > ();}
#line 1120 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 39:
#line 231 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PreCondition*> > () = {yystack_[0].value.as < imp::ast::PreCondition* > ()}; }
#line 1126 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 40:
#line 232 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PreCondition*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::PreCondition*> > (), yystack_[0].value.as < imp::ast::PreCondition* > ()); }
#line 1132 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 41:
#line 235 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::PreCondition* > () = new imp::ast::PreCondition(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1138 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 42:
#line 239 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PostCondition*> > () = {yystack_[0].value.as < imp::ast::PostCondition* > ()}; }
#line 1144 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 43:
#line 240 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<imp::ast::PostCondition*> > () = enlist(yystack_[1].value.as < std::vector<imp::ast::PostCondition*> > (), yystack_[0].value.as < imp::ast::PostCondition* > ()); }
#line 1150 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 44:
#line 243 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::PostCondition* > () = new imp::ast::PostCondition(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1156 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 45:
#line 247 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = yystack_[0].value.as < imp::ast::Comparison* > (); }
#line 1162 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 46:
#line 248 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Negation(*yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1168 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 47:
#line 249 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Disjunction(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1174 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 48:
#line 250 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Conjunction(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1180 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 49:
#line 251 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::Implication(*yystack_[2].value.as < imp::ast::Assertion* > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); }
#line 1186 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 50:
#line 252 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::UniversalQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1192 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 51:
#line 253 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = new imp::ast::ExistentialQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < imp::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1198 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 52:
#line 254 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < imp::ast::Assertion* > () = yystack_[1].value.as < imp::ast::Assertion* > (); }
#line 1204 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 53:
#line 255 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    {  }
#line 1210 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 54:
#line 259 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
#line 1216 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;

  case 55:
#line 260 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1222 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"
    break;


#line 1226 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"

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
     -26,   -30,    20,    49,   -31,    33,   -21,   -31,    15,     6,
      33,   -23,   -23,   -31,   -31,   167,    55,   -31,   -31,    29,
      33,   -31,    69,   -31,    15,   190,    98,   154,    70,    29,
     -31,   -17,    97,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    33,    33,    33,    29,   118,
     -31,   180,   -31,   -31,   -31,    33,   -31,    33,   190,   190,
     102,   102,   187,   187,   187,   187,   187,   187,   187,    53,
     -11,    29,    29,    47,    47,   -31,   -31,    87,    92,   118,
      29,    29,   -31,    47,    47,   128,   -31,    48,    15,    76,
      15,   -31,   -31,     0,   121,    47,    47,   118,    33,    84,
     -31,   117,   124,    89,   -31,   135,   121,   125,    29,   118,
     -31,   -31,    15,   136,   118,   -31,   116,    94,    15,   129,
     -31,    15,   122,   -31,   127,   -31,   -31
  };

  const unsigned char
  imp_parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,    39,     0,     0,
       0,     0,     0,    12,    13,     0,     2,     4,    45,    41,
       0,    40,     0,    42,     0,     5,     0,     0,     0,    46,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      43,     0,    53,    11,    52,     0,    55,     0,     6,     7,
       8,     9,    10,    19,    20,    21,    22,    23,    24,     0,
      47,    48,    49,     0,     0,    31,    36,     0,     0,    35,
      50,    51,     3,     0,     0,     0,    14,     0,     0,     0,
       0,    38,    37,     0,    15,     0,     0,     0,     0,     0,
      32,     0,     0,     0,    18,    16,    17,     0,    34,     0,
      33,    25,     0,     0,     0,    29,     0,     0,     0,     0,
      30,     0,     0,    28,     0,    27,    26
  };

  const short
  imp_parser::yypgoto_[] =
  {
     -31,    -8,   -31,   -31,   -22,    -6,    83,    86,   -31,    77,
      39,   -31,   -31,   -31,   182,   -31,   176,    -7,   188
  };

  const signed char
  imp_parser::yydefgoto_[] =
  {
      -1,    15,    16,    17,    85,    18,    76,    77,    99,   100,
      78,    79,     2,     6,     7,    22,    23,    19,    31
  };

  const unsigned char
  imp_parser::yytable_[] =
  {
      25,    27,    28,    29,    55,     1,    45,    26,     3,   104,
       8,     5,    20,    48,     9,    30,    51,    95,    96,     8,
       4,    56,    10,    24,    47,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     8,    70,    71,
      72,     9,    11,    12,    13,    14,    45,    46,    80,    10,
      81,     8,    87,    13,    14,    83,    33,    34,    35,    36,
      37,    93,    94,    84,    47,    95,    96,    86,    86,    11,
      12,    13,    14,   105,   106,    27,    98,    86,    86,    54,
     101,     5,   103,    82,    44,    13,    14,    45,    46,    86,
      86,   108,    33,    34,    35,    36,    37,    33,    34,    35,
      36,    37,    20,    49,   117,    47,    88,    52,    89,    37,
     122,   109,    98,   124,    75,   121,    90,    91,    57,   113,
      33,    34,    35,    36,    37,    33,    34,    35,    36,    37,
      33,    34,    35,    36,    37,    56,   107,   111,    95,    96,
      73,   120,   125,   112,    74,    95,    96,   126,   116,   114,
     115,    97,    95,   119,   123,   118,    75,    33,    34,    35,
      36,    37,    92,    53,    38,    39,    40,    41,    42,    43,
      33,    34,    35,    36,    37,   102,   110,    38,    39,    40,
      41,    42,    43,    33,    34,    35,    36,    37,    21,    53,
      33,    34,    35,    36,    37,    35,    36,    37,    50,     0,
      32
  };

  const signed char
  imp_parser::yycheck_[] =
  {
       8,     9,     9,    10,    21,    31,    17,     1,    38,     9,
       4,    32,    33,    20,     8,    38,    24,    17,    18,     4,
       0,    38,    16,     8,    35,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     4,    45,    46,
      47,     8,    36,    37,    38,    39,    17,    18,    55,    16,
      57,     4,    74,    38,    39,     8,     3,     4,     5,     6,
       7,    83,    84,    16,    35,    17,    18,    73,    74,    36,
      37,    38,    39,    95,    96,    83,    28,    83,    84,     9,
      88,    32,    90,    30,    29,    38,    39,    17,    18,    95,
      96,    98,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    33,    34,   112,    35,    19,     9,    21,     7,
     118,    27,    28,   121,    38,    21,    29,    25,    21,    30,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    38,    97,    20,    17,    18,
      22,    25,    20,    19,    26,    17,    18,    20,   109,    24,
      25,    23,    17,   114,    25,    19,    38,     3,     4,     5,
       6,     7,    79,     9,    10,    11,    12,    13,    14,    15,
       3,     4,     5,     6,     7,    89,    99,    10,    11,    12,
      13,    14,    15,     3,     4,     5,     6,     7,     6,     9,
       3,     4,     5,     6,     7,     5,     6,     7,    22,    -1,
      12
  };

  const unsigned char
  imp_parser::yystos_[] =
  {
       0,    31,    52,    38,     0,    32,    53,    54,     4,     8,
      16,    36,    37,    38,    39,    41,    42,    43,    45,    57,
      33,    54,    55,    56,     8,    41,     1,    41,    57,    57,
      38,    58,    58,     3,     4,     5,     6,     7,    10,    11,
      12,    13,    14,    15,    29,    17,    18,    35,    57,    34,
      56,    41,     9,     9,     9,    21,    38,    21,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      57,    57,    57,    22,    26,    38,    46,    47,    50,    51,
      57,    57,    30,     8,    16,    44,    45,    44,    19,    21,
      29,    25,    46,    44,    44,    17,    18,    23,    28,    48,
      49,    41,    47,    41,     9,    44,    44,    50,    57,    27,
      49,    20,    19,    30,    24,    25,    50,    41,    19,    50,
      25,    21,    41,    25,    41,    20,    20
  };

  const unsigned char
  imp_parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    43,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    47,    48,    48,    49,    50,    51,    51,    52,    53,
      53,    54,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58
  };

  const unsigned char
  imp_parser::yyr2_[] =
  {
       0,     2,     1,     4,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     8,     7,     7,     5,
       6,     1,     1,     2,     2,     1,     1,     2,     7,     1,
       2,     2,     1,     2,     2,     1,     2,     3,     3,     3,
       4,     4,     3,     3,     1,     2
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
       0,   162,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   174,   177,   181,   182,   183,   184,   185,   189,
     190,   191,   192,   193,   194,   198,   199,   200,   201,   202,
     203,   206,   210,   211,   214,   217,   221,   222,   226,   231,
     232,   235,   239,   240,   243,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   259,   260
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
#line 1706 "/home/ferhat/git/vc-gen/imp/recognizer/imp-parser.cpp"

#line 262 "/home/ferhat/git/vc-gen/imp/imp-parser.yy"


void
imp::imp_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
