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





#include "vcgen-parser.hpp"


// Unqualified %code blocks.
#line 37 "/home/ferhat/git/vc-gen/vcgen-parser.yy"

# include "vcgen-driver.hpp"

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




#line 68 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"


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
#line 162 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  vcgen_parser::yytnamerr_ (const char *yystr)
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
  vcgen_parser::vcgen_parser (vcgen_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  vcgen_parser::~vcgen_parser ()
  {}

  vcgen_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  vcgen_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  vcgen_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  vcgen_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  vcgen_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  vcgen_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  vcgen_parser::symbol_number_type
  vcgen_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  vcgen_parser::stack_symbol_type::stack_symbol_type ()
  {}

  vcgen_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 41: // aexp
        value.YY_MOVE_OR_COPY< ast::ArithmeticExpression > (YY_MOVE (that.value));
        break;

      case 54: // assertion
        value.YY_MOVE_OR_COPY< ast::Assertion > (YY_MOVE (that.value));
        break;

      case 47: // block
        value.YY_MOVE_OR_COPY< ast::Block > (YY_MOVE (that.value));
        break;

      case 42: // bexp
        value.YY_MOVE_OR_COPY< ast::BooleanExpression > (YY_MOVE (that.value));
        break;

      case 43: // comp
        value.YY_MOVE_OR_COPY< ast::Comparison > (YY_MOVE (that.value));
        break;

      case 45: // inv
        value.YY_MOVE_OR_COPY< ast::Invariant > (YY_MOVE (that.value));
        break;

      case 52: // post
        value.YY_MOVE_OR_COPY< ast::PostCondition > (YY_MOVE (that.value));
        break;

      case 50: // pre
        value.YY_MOVE_OR_COPY< ast::PreCondition > (YY_MOVE (that.value));
        break;

      case 49: // prog
        value.YY_MOVE_OR_COPY< ast::Program > (YY_MOVE (that.value));
        break;

      case 44: // stmt
        value.YY_MOVE_OR_COPY< ast::Statement > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 46: // inv_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Invariant> > (YY_MOVE (that.value));
        break;

      case 53: // post_list
        value.YY_MOVE_OR_COPY< std::vector<ast::PostCondition> > (YY_MOVE (that.value));
        break;

      case 51: // pre_list
        value.YY_MOVE_OR_COPY< std::vector<ast::PreCondition> > (YY_MOVE (that.value));
        break;

      case 48: // stmt_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Statement> > (YY_MOVE (that.value));
        break;

      case 55: // identifier_list
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

  vcgen_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< ast::ArithmeticExpression > (YY_MOVE (that.value));
        break;

      case 54: // assertion
        value.move< ast::Assertion > (YY_MOVE (that.value));
        break;

      case 47: // block
        value.move< ast::Block > (YY_MOVE (that.value));
        break;

      case 42: // bexp
        value.move< ast::BooleanExpression > (YY_MOVE (that.value));
        break;

      case 43: // comp
        value.move< ast::Comparison > (YY_MOVE (that.value));
        break;

      case 45: // inv
        value.move< ast::Invariant > (YY_MOVE (that.value));
        break;

      case 52: // post
        value.move< ast::PostCondition > (YY_MOVE (that.value));
        break;

      case 50: // pre
        value.move< ast::PreCondition > (YY_MOVE (that.value));
        break;

      case 49: // prog
        value.move< ast::Program > (YY_MOVE (that.value));
        break;

      case 44: // stmt
        value.move< ast::Statement > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 46: // inv_list
        value.move< std::vector<ast::Invariant> > (YY_MOVE (that.value));
        break;

      case 53: // post_list
        value.move< std::vector<ast::PostCondition> > (YY_MOVE (that.value));
        break;

      case 51: // pre_list
        value.move< std::vector<ast::PreCondition> > (YY_MOVE (that.value));
        break;

      case 48: // stmt_list
        value.move< std::vector<ast::Statement> > (YY_MOVE (that.value));
        break;

      case 55: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  vcgen_parser::stack_symbol_type&
  vcgen_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< ast::ArithmeticExpression > (that.value);
        break;

      case 54: // assertion
        value.move< ast::Assertion > (that.value);
        break;

      case 47: // block
        value.move< ast::Block > (that.value);
        break;

      case 42: // bexp
        value.move< ast::BooleanExpression > (that.value);
        break;

      case 43: // comp
        value.move< ast::Comparison > (that.value);
        break;

      case 45: // inv
        value.move< ast::Invariant > (that.value);
        break;

      case 52: // post
        value.move< ast::PostCondition > (that.value);
        break;

      case 50: // pre
        value.move< ast::PreCondition > (that.value);
        break;

      case 49: // prog
        value.move< ast::Program > (that.value);
        break;

      case 44: // stmt
        value.move< ast::Statement > (that.value);
        break;

      case 39: // "number"
        value.move< int > (that.value);
        break;

      case 38: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 46: // inv_list
        value.move< std::vector<ast::Invariant> > (that.value);
        break;

      case 53: // post_list
        value.move< std::vector<ast::PostCondition> > (that.value);
        break;

      case 51: // pre_list
        value.move< std::vector<ast::PreCondition> > (that.value);
        break;

      case 48: // stmt_list
        value.move< std::vector<ast::Statement> > (that.value);
        break;

      case 55: // identifier_list
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
  vcgen_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  vcgen_parser::yy_print_ (std::ostream& yyo,
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
  vcgen_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  vcgen_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  vcgen_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  vcgen_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  vcgen_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  vcgen_parser::debug_level_type
  vcgen_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  vcgen_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  vcgen_parser::state_type
  vcgen_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  vcgen_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  vcgen_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  vcgen_parser::operator() ()
  {
    return parse ();
  }

  int
  vcgen_parser::parse ()
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
#line 28 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 662 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"


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
        yylhs.value.emplace< ast::ArithmeticExpression > ();
        break;

      case 54: // assertion
        yylhs.value.emplace< ast::Assertion > ();
        break;

      case 47: // block
        yylhs.value.emplace< ast::Block > ();
        break;

      case 42: // bexp
        yylhs.value.emplace< ast::BooleanExpression > ();
        break;

      case 43: // comp
        yylhs.value.emplace< ast::Comparison > ();
        break;

      case 45: // inv
        yylhs.value.emplace< ast::Invariant > ();
        break;

      case 52: // post
        yylhs.value.emplace< ast::PostCondition > ();
        break;

      case 50: // pre
        yylhs.value.emplace< ast::PreCondition > ();
        break;

      case 49: // prog
        yylhs.value.emplace< ast::Program > ();
        break;

      case 44: // stmt
        yylhs.value.emplace< ast::Statement > ();
        break;

      case 39: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 38: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 46: // inv_list
        yylhs.value.emplace< std::vector<ast::Invariant> > ();
        break;

      case 53: // post_list
        yylhs.value.emplace< std::vector<ast::PostCondition> > ();
        break;

      case 51: // pre_list
        yylhs.value.emplace< std::vector<ast::PreCondition> > ();
        break;

      case 48: // stmt_list
        yylhs.value.emplace< std::vector<ast::Statement> > ();
        break;

      case 55: // identifier_list
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
#line 154 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 855 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 3:
#line 155 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 861 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 4:
#line 156 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 867 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 5:
#line 157 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 873 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 6:
#line 158 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 879 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 7:
#line 159 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 885 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 8:
#line 160 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 891 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 9:
#line 161 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 897 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 10:
#line 162 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 903 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 11:
#line 163 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression > () = yystack_[1].value.as < ast::ArithmeticExpression > ();}
#line 909 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 12:
#line 167 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 915 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 13:
#line 168 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 921 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 14:
#line 169 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 927 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 15:
#line 170 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 933 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 16:
#line 171 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression > () = yystack_[1].value.as < ast::BooleanExpression > ();}
#line 939 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 17:
#line 175 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 945 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 18:
#line 176 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 951 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 19:
#line 177 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 957 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 20:
#line 178 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 963 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 21:
#line 179 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 969 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 22:
#line 180 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 975 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 23:
#line 184 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 981 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 24:
#line 185 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 987 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 25:
#line 186 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 993 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 26:
#line 187 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 999 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 27:
#line 188 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1005 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 28:
#line 189 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1011 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 29:
#line 193 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1017 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 30:
#line 197 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1023 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 31:
#line 198 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1029 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 32:
#line 202 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1035 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 33:
#line 206 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1041 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 34:
#line 207 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1047 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 35:
#line 211 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1053 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 36:
#line 214 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1059 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 37:
#line 218 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1065 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 38:
#line 219 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1071 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 39:
#line 222 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1077 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 40:
#line 226 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1083 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 41:
#line 227 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1089 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 42:
#line 231 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1095 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 43:
#line 232 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1101 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 44:
#line 233 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1107 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 45:
#line 234 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1113 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 46:
#line 235 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { }
#line 1119 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 47:
#line 236 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { print<std::string>(yystack_[2].value.as < std::vector<std::string> > ());}
#line 1125 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 48:
#line 237 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { print<std::string>(yystack_[2].value.as < std::vector<std::string> > ());}
#line 1131 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 49:
#line 238 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion > () = yystack_[1].value.as < ast::Assertion > ();}
#line 1137 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 50:
#line 242 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()};}
#line 1143 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 51:
#line 243 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ());}
#line 1149 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;


#line 1153 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"

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
  vcgen_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  vcgen_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char vcgen_parser::yypact_ninf_ = -23;

  const signed char vcgen_parser::yytable_ninf_ = -1;

  const short
  vcgen_parser::yypact_[] =
  {
     -22,   -19,    45,    37,   -23,     2,   -23,    39,     9,     2,
       2,    85,    85,   106,   -23,   149,   -23,    48,     2,   -23,
     -23,    64,     9,   172,   136,    50,    48,   -23,   -17,    66,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     2,     2,     2,    48,    98,   -23,   162,   -23,
     -23,     2,   -23,     2,    46,   172,   172,   130,   130,   169,
     169,   169,   169,   169,   169,   169,    -1,    48,    48,     4,
       4,   -14,   -23,   119,    98,    48,    48,   -23,     4,     4,
     111,   -23,    56,     9,   132,     9,   -23,   -23,   113,   108,
       4,     4,    98,     2,   -23,    79,    89,   161,    51,   -23,
     164,   108,   133,    48,    98,   -23,   -23,     9,   163,    98,
     -23,   158,    57,     9,   159,   -23,     9,   107,   -23,   112,
     -23,   -23
  };

  const unsigned char
  vcgen_parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,    37,     0,     0,     0,
       0,     0,     0,     2,     3,     0,    42,    36,     0,    38,
      40,     0,     0,     5,     0,     0,    43,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,    41,     0,    11,
      49,     0,    51,     0,     0,     6,     7,     8,     9,    10,
      17,    18,    19,    20,    21,    22,    44,    45,    46,     0,
       0,     0,    33,     0,    32,    47,    48,     4,     0,     0,
       0,    12,     0,     0,     0,     0,    35,    34,     0,    13,
       0,     0,     0,     0,    30,     0,     0,     0,     0,    16,
      14,    15,     0,    29,     0,    31,    23,     0,     0,     0,
      27,     0,     0,     0,     0,    28,     0,     0,    26,     0,
      25,    24
  };

  const short
  vcgen_parser::yypgoto_[] =
  {
     -23,    -8,    12,    10,   114,    90,   -23,    29,   -23,   -23,
     179,   -23,   166,   -23,    -7,   177
  };

  const signed char
  vcgen_parser::yydefgoto_[] =
  {
      -1,    15,    80,    16,    72,    94,    95,    73,    74,     2,
       6,     7,    20,    21,    17,    28
  };

  const unsigned char
  vcgen_parser::yytable_[] =
  {
      23,    24,    25,    26,    51,    83,     8,    84,     8,     1,
       9,    45,    78,     8,    48,    85,    42,    22,    10,     3,
      79,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    44,    66,    67,    68,    11,    12,
      13,    14,    13,    14,    75,     4,    76,    13,    14,    31,
      32,    33,    34,    35,    31,    32,    33,    34,    35,    50,
      31,    32,    33,    34,    35,    42,    43,    42,    43,     5,
      24,     5,    18,    90,    91,    96,    77,    98,   116,    81,
      81,   108,    82,    44,    93,    44,   103,    53,    81,    81,
      88,    89,    31,    32,    33,    34,    35,    18,    46,   112,
      81,    81,   100,   101,    52,   117,   104,    93,   119,   106,
      31,    32,    33,    34,    35,    31,    32,    33,    34,    35,
      69,   102,    99,    27,    70,    90,    91,   120,    90,    91,
      90,    91,   121,   111,    92,    30,    71,    35,   114,    31,
      32,    33,    34,    35,    86,    49,    36,    37,    38,    39,
      40,    41,    31,    32,    33,    34,    35,   109,   110,    36,
      37,    38,    39,    40,    41,    31,    32,    33,    34,    35,
      97,    49,    31,    32,    33,    34,    35,    33,    34,    35,
     107,    90,   113,   115,   118,   105,    19,    47,    87,    29
  };

  const unsigned char
  vcgen_parser::yycheck_[] =
  {
       8,     9,     9,    10,    21,    19,     4,    21,     4,    31,
       8,    18,     8,     4,    22,    29,    17,     8,    16,    38,
      16,    38,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    35,    42,    43,    44,    36,    37,
      38,    39,    38,    39,    51,     0,    53,    38,    39,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     9,
       3,     4,     5,     6,     7,    17,    18,    17,    18,    32,
      78,    32,    33,    17,    18,    83,    30,    85,    21,    69,
      70,    30,    70,    35,    28,    35,    93,    21,    78,    79,
      78,    79,     3,     4,     5,     6,     7,    33,    34,   107,
      90,    91,    90,    91,    38,   113,    27,    28,   116,    20,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      22,    92,     9,    38,    26,    17,    18,    20,    17,    18,
      17,    18,    20,   104,    23,    29,    38,     7,   109,     3,
       4,     5,     6,     7,    25,     9,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,     7,    24,    25,    10,
      11,    12,    13,    14,    15,     3,     4,     5,     6,     7,
      38,     9,     3,     4,     5,     6,     7,     5,     6,     7,
      19,    17,    19,    25,    25,    95,     7,    21,    74,    12
  };

  const unsigned char
  vcgen_parser::yystos_[] =
  {
       0,    31,    49,    38,     0,    32,    50,    51,     4,     8,
      16,    36,    37,    38,    39,    41,    43,    54,    33,    50,
      52,    53,     8,    41,    41,    54,    54,    38,    55,    55,
      29,     3,     4,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    17,    18,    35,    54,    34,    52,    41,     9,
       9,    21,    38,    21,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    54,    54,    54,    22,
      26,    38,    44,    47,    48,    54,    54,    30,     8,    16,
      42,    43,    42,    19,    21,    29,    25,    44,    42,    42,
      17,    18,    23,    28,    45,    46,    41,    38,    41,     9,
      42,    42,    47,    54,    27,    45,    20,    19,    30,    24,
      25,    47,    41,    19,    47,    25,    21,    41,    25,    41,
      20,    20
  };

  const unsigned char
  vcgen_parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    44,    45,
      46,    46,    47,    48,    48,    49,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55
  };

  const unsigned char
  vcgen_parser::yyr2_[] =
  {
       0,     2,     1,     1,     4,     2,     3,     3,     3,     3,
       3,     3,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     8,     7,     7,     5,     6,     2,
       1,     2,     1,     1,     2,     7,     2,     1,     2,     2,
       1,     2,     1,     2,     3,     3,     3,     4,     4,     3,
       1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const vcgen_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"(\"", "\")\"", "\"=\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"<\"", "\">\"", "\"!\"", "\"||\"", "\"&&\"", "\":=\"",
  "\";\"", "\",\"", "\"if\"", "\"then\"", "\"else\"", "\"end\"",
  "\"while\"", "\"do\"", "\"inv\"", "\"[\"", "\"]\"", "\"program\"",
  "\"pre\"", "\"post\"", "\"is\"", "\"==>\"", "\"forall\"", "\"exists\"",
  "\"identifier\"", "\"number\"", "$accept", "aexp", "bexp", "comp",
  "stmt", "inv", "inv_list", "block", "stmt_list", "prog", "pre",
  "pre_list", "post", "post_list", "assertion", "identifier_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  vcgen_parser::yyrline_[] =
  {
       0,   154,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   167,   168,   169,   170,   171,   175,   176,   177,
     178,   179,   180,   184,   185,   186,   187,   188,   189,   193,
     197,   198,   202,   206,   207,   210,   214,   218,   219,   222,
     226,   227,   231,   232,   233,   234,   235,   236,   237,   238,
     242,   243
  };

  // Print the state stack on the debug stream.
  void
  vcgen_parser::yystack_print_ ()
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
  vcgen_parser::yy_reduce_print_ (int yyrule)
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
#line 1627 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"

#line 245 "/home/ferhat/git/vc-gen/vcgen-parser.yy"


void
yy::vcgen_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
