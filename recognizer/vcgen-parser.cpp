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

ast::Program *program; /* the top level root node of our final AST */


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
        value.YY_MOVE_OR_COPY< ast::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 57: // assertion
        value.YY_MOVE_OR_COPY< ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 50: // block
        value.YY_MOVE_OR_COPY< ast::Block* > (YY_MOVE (that.value));
        break;

      case 44: // bexp
        value.YY_MOVE_OR_COPY< ast::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 45: // comp
        value.YY_MOVE_OR_COPY< ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 43: // constant
        value.YY_MOVE_OR_COPY< ast::Constant* > (YY_MOVE (that.value));
        break;

      case 49: // inv
        value.YY_MOVE_OR_COPY< ast::Invariant* > (YY_MOVE (that.value));
        break;

      case 47: // location
        value.YY_MOVE_OR_COPY< ast::Location* > (YY_MOVE (that.value));
        break;

      case 56: // post
        value.YY_MOVE_OR_COPY< ast::PostCondition* > (YY_MOVE (that.value));
        break;

      case 54: // pre
        value.YY_MOVE_OR_COPY< ast::PreCondition* > (YY_MOVE (that.value));
        break;

      case 52: // prog
        value.YY_MOVE_OR_COPY< ast::Program* > (YY_MOVE (that.value));
        break;

      case 42: // reference
        value.YY_MOVE_OR_COPY< ast::Reference* > (YY_MOVE (that.value));
        break;

      case 46: // stmt
        value.YY_MOVE_OR_COPY< ast::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 48: // inv_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Invariant*> > (YY_MOVE (that.value));
        break;

      case 55: // post_list
        value.YY_MOVE_OR_COPY< std::vector<ast::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 53: // pre_list
        value.YY_MOVE_OR_COPY< std::vector<ast::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 51: // stmt_list
        value.YY_MOVE_OR_COPY< std::vector<ast::Statement*> > (YY_MOVE (that.value));
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

  vcgen_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< ast::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 57: // assertion
        value.move< ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 50: // block
        value.move< ast::Block* > (YY_MOVE (that.value));
        break;

      case 44: // bexp
        value.move< ast::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 45: // comp
        value.move< ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 43: // constant
        value.move< ast::Constant* > (YY_MOVE (that.value));
        break;

      case 49: // inv
        value.move< ast::Invariant* > (YY_MOVE (that.value));
        break;

      case 47: // location
        value.move< ast::Location* > (YY_MOVE (that.value));
        break;

      case 56: // post
        value.move< ast::PostCondition* > (YY_MOVE (that.value));
        break;

      case 54: // pre
        value.move< ast::PreCondition* > (YY_MOVE (that.value));
        break;

      case 52: // prog
        value.move< ast::Program* > (YY_MOVE (that.value));
        break;

      case 42: // reference
        value.move< ast::Reference* > (YY_MOVE (that.value));
        break;

      case 46: // stmt
        value.move< ast::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 48: // inv_list
        value.move< std::vector<ast::Invariant*> > (YY_MOVE (that.value));
        break;

      case 55: // post_list
        value.move< std::vector<ast::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 53: // pre_list
        value.move< std::vector<ast::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 51: // stmt_list
        value.move< std::vector<ast::Statement*> > (YY_MOVE (that.value));
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
  vcgen_parser::stack_symbol_type&
  vcgen_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 41: // aexp
        value.move< ast::ArithmeticExpression* > (that.value);
        break;

      case 57: // assertion
        value.move< ast::Assertion* > (that.value);
        break;

      case 50: // block
        value.move< ast::Block* > (that.value);
        break;

      case 44: // bexp
        value.move< ast::BooleanExpression* > (that.value);
        break;

      case 45: // comp
        value.move< ast::Comparison* > (that.value);
        break;

      case 43: // constant
        value.move< ast::Constant* > (that.value);
        break;

      case 49: // inv
        value.move< ast::Invariant* > (that.value);
        break;

      case 47: // location
        value.move< ast::Location* > (that.value);
        break;

      case 56: // post
        value.move< ast::PostCondition* > (that.value);
        break;

      case 54: // pre
        value.move< ast::PreCondition* > (that.value);
        break;

      case 52: // prog
        value.move< ast::Program* > (that.value);
        break;

      case 42: // reference
        value.move< ast::Reference* > (that.value);
        break;

      case 46: // stmt
        value.move< ast::Statement* > (that.value);
        break;

      case 39: // "number"
        value.move< int > (that.value);
        break;

      case 38: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 48: // inv_list
        value.move< std::vector<ast::Invariant*> > (that.value);
        break;

      case 55: // post_list
        value.move< std::vector<ast::PostCondition*> > (that.value);
        break;

      case 53: // pre_list
        value.move< std::vector<ast::PreCondition*> > (that.value);
        break;

      case 51: // stmt_list
        value.move< std::vector<ast::Statement*> > (that.value);
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

#line 698 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"


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
        yylhs.value.emplace< ast::ArithmeticExpression* > ();
        break;

      case 57: // assertion
        yylhs.value.emplace< ast::Assertion* > ();
        break;

      case 50: // block
        yylhs.value.emplace< ast::Block* > ();
        break;

      case 44: // bexp
        yylhs.value.emplace< ast::BooleanExpression* > ();
        break;

      case 45: // comp
        yylhs.value.emplace< ast::Comparison* > ();
        break;

      case 43: // constant
        yylhs.value.emplace< ast::Constant* > ();
        break;

      case 49: // inv
        yylhs.value.emplace< ast::Invariant* > ();
        break;

      case 47: // location
        yylhs.value.emplace< ast::Location* > ();
        break;

      case 56: // post
        yylhs.value.emplace< ast::PostCondition* > ();
        break;

      case 54: // pre
        yylhs.value.emplace< ast::PreCondition* > ();
        break;

      case 52: // prog
        yylhs.value.emplace< ast::Program* > ();
        break;

      case 42: // reference
        yylhs.value.emplace< ast::Reference* > ();
        break;

      case 46: // stmt
        yylhs.value.emplace< ast::Statement* > ();
        break;

      case 39: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 38: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 48: // inv_list
        yylhs.value.emplace< std::vector<ast::Invariant*> > ();
        break;

      case 55: // post_list
        yylhs.value.emplace< std::vector<ast::PostCondition*> > ();
        break;

      case 53: // pre_list
        yylhs.value.emplace< std::vector<ast::PreCondition*> > ();
        break;

      case 51: // stmt_list
        yylhs.value.emplace< std::vector<ast::Statement*> > ();
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
#line 157 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = yystack_[0].value.as < ast::Reference* > (); }
#line 903 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 3:
#line 158 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::ArrayReference(*yystack_[3].value.as < ast::Reference* > (), *yystack_[1].value.as < ast::ArithmeticExpression* > ()); }
#line 909 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 4:
#line 159 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = yystack_[0].value.as < ast::Constant* > (); }
#line 915 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 5:
#line 160 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Negate(*yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 921 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 6:
#line 161 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Sum(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ());}
#line 927 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 7:
#line 162 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Subtract(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 933 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 8:
#line 163 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Multiply(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 939 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 9:
#line 164 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Divide(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 945 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 10:
#line 165 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = new ast::Mod(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 951 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 11:
#line 166 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::ArithmeticExpression* > () = yystack_[1].value.as < ast::ArithmeticExpression* > ();}
#line 957 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 12:
#line 169 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Reference* > () = new ast::Reference(yystack_[0].value.as < std::string > ()); }
#line 963 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 13:
#line 172 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Constant* > () = new ast::Constant(yystack_[0].value.as < int > ()); }
#line 969 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 14:
#line 176 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression* > () = yystack_[0].value.as < ast::Comparison* > (); }
#line 975 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 15:
#line 177 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression* > () = new ast::NotExpression(*yystack_[0].value.as < ast::BooleanExpression* > ()); }
#line 981 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 16:
#line 178 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression* > () = new ast::OrExpression(*yystack_[2].value.as < ast::BooleanExpression* > (), *yystack_[0].value.as < ast::BooleanExpression* > ()); }
#line 987 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 17:
#line 179 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression* > () = new ast::AndExpression(*yystack_[2].value.as < ast::BooleanExpression* > (), *yystack_[0].value.as < ast::BooleanExpression* > ()); }
#line 993 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 18:
#line 180 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::BooleanExpression* > () = yystack_[1].value.as < ast::BooleanExpression* > ();}
#line 999 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 19:
#line 184 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::EqualComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1005 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 20:
#line 185 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::NotEqualComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1011 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 21:
#line 186 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::LeqComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1017 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 22:
#line 187 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::GeqComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1023 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 23:
#line 188 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::LtComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1029 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 24:
#line 189 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Comparison* > () = new ast::GtComparison(*yystack_[2].value.as < ast::ArithmeticExpression* > (), *yystack_[0].value.as < ast::ArithmeticExpression* > ()); }
#line 1035 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 25:
#line 193 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::AssignmentStatement(*yystack_[3].value.as < ast::Location* > (), *yystack_[1].value.as < ast::ArithmeticExpression* > ());}
#line 1041 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 26:
#line 194 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::MultipleAssignmentStatement(*yystack_[7].value.as < ast::Location* > (), *yystack_[5].value.as < ast::Location* > (), *yystack_[3].value.as < ast::ArithmeticExpression* > (), *yystack_[1].value.as < ast::ArithmeticExpression* > ());}
#line 1047 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 27:
#line 195 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::ArrayAssignmentStatement(*yystack_[6].value.as < ast::Location* > (), *yystack_[4].value.as < ast::ArithmeticExpression* > (), *yystack_[1].value.as < ast::ArithmeticExpression* > ());}
#line 1053 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 28:
#line 196 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::IfThenElseStatement(*yystack_[5].value.as < ast::BooleanExpression* > (), *yystack_[3].value.as < ast::Block* > (), *yystack_[1].value.as < ast::Block* > ());}
#line 1059 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 29:
#line 197 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::IfThenStatement(*yystack_[3].value.as < ast::BooleanExpression* > (), *yystack_[1].value.as < ast::Block* > ());}
#line 1065 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 30:
#line 198 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Statement* > () = new ast::WhileStatement(*yystack_[4].value.as < ast::BooleanExpression* > (), yystack_[3].value.as < std::vector<ast::Invariant*> > (), *yystack_[1].value.as < ast::Block* > ());}
#line 1071 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 31:
#line 201 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Location* > () = new ast::Location(yystack_[0].value.as < std::string > ()); }
#line 1077 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 32:
#line 205 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::Invariant*> > () = {yystack_[0].value.as < ast::Invariant* > ()}; }
#line 1083 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 33:
#line 206 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::Invariant*> > () = enlist(yystack_[1].value.as < std::vector<ast::Invariant*> > (), yystack_[0].value.as < ast::Invariant* > ()); }
#line 1089 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 34:
#line 209 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Invariant* > () = new ast::Invariant(*yystack_[0].value.as < ast::Assertion* > ()); }
#line 1095 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 35:
#line 212 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Block* > () = new ast::Block(yystack_[0].value.as < std::vector<ast::Statement*> > ()); /*print<ast::Statement>($1);*/}
#line 1101 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 36:
#line 216 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::Statement*> > () = {yystack_[0].value.as < ast::Statement* > ()};}
#line 1107 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 37:
#line 217 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::Statement*> > () = enlist(yystack_[1].value.as < std::vector<ast::Statement*> > (), yystack_[0].value.as < ast::Statement* > ()); }
#line 1113 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 38:
#line 221 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Program* > () = new ast::Program(yystack_[5].value.as < std::string > (), yystack_[4].value.as < std::vector<ast::PreCondition*> > (), yystack_[3].value.as < std::vector<ast::PostCondition*> > (), *yystack_[1].value.as < ast::Block* > ()); driver.program = yylhs.value.as < ast::Program* > ();}
#line 1119 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 39:
#line 225 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::PreCondition*> > () = {yystack_[0].value.as < ast::PreCondition* > ()}; }
#line 1125 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 40:
#line 226 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::PreCondition*> > () = enlist(yystack_[1].value.as < std::vector<ast::PreCondition*> > (), yystack_[0].value.as < ast::PreCondition* > ()); }
#line 1131 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 41:
#line 229 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::PreCondition* > () = new ast::PreCondition(*yystack_[0].value.as < ast::Assertion* > ()); }
#line 1137 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 42:
#line 233 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::PostCondition*> > () = {yystack_[0].value.as < ast::PostCondition* > ()}; }
#line 1143 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 43:
#line 234 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<ast::PostCondition*> > () = enlist(yystack_[1].value.as < std::vector<ast::PostCondition*> > (), yystack_[0].value.as < ast::PostCondition* > ()); }
#line 1149 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 44:
#line 237 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::PostCondition* > () = new ast::PostCondition(*yystack_[0].value.as < ast::Assertion* > ()); }
#line 1155 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 45:
#line 241 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = yystack_[0].value.as < ast::Comparison* > (); }
#line 1161 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 46:
#line 242 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::Negation(*yystack_[0].value.as < ast::Assertion* > ()); }
#line 1167 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 47:
#line 243 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::Disjunction(*yystack_[2].value.as < ast::Assertion* > (), *yystack_[0].value.as < ast::Assertion* > ()); }
#line 1173 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 48:
#line 244 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::Conjunction(*yystack_[2].value.as < ast::Assertion* > (), *yystack_[0].value.as < ast::Assertion* > ()); }
#line 1179 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 49:
#line 245 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::Implication(*yystack_[2].value.as < ast::Assertion* > (), *yystack_[0].value.as < ast::Assertion* > ()); }
#line 1185 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 50:
#line 246 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::UniversalQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < ast::Assertion* > ()); print<std::string>(yystack_[2].value.as < std::vector<std::string> > ()); }
#line 1191 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 51:
#line 247 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = new ast::ExistentialQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < ast::Assertion* > ()); print<std::string>(yystack_[2].value.as < std::vector<std::string> > ()); }
#line 1197 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 52:
#line 248 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < ast::Assertion* > () = yystack_[1].value.as < ast::Assertion* > (); }
#line 1203 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 53:
#line 252 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
#line 1209 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;

  case 54:
#line 253 "/home/ferhat/git/vc-gen/vcgen-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1215 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"
    break;


#line 1219 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"

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


  const signed char vcgen_parser::yypact_ninf_ = -30;

  const signed char vcgen_parser::yytable_ninf_ = -1;

  const short
  vcgen_parser::yypact_[] =
  {
     -24,   -29,    17,   -21,   -30,     4,   104,   -30,    11,     4,
       4,    13,    13,   -30,   -30,   154,    34,   -30,   -30,   -12,
       4,   -30,   107,   -30,    11,    90,   141,    53,   -12,   -30,
     -17,    26,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,     4,     4,     4,   -12,   105,   -30,
     167,   -30,   -30,     4,   -30,     4,    90,    90,    84,    84,
     174,   174,   174,   174,   174,   174,   174,    49,     1,   -12,
     -12,     6,     6,   -30,   -30,    71,    94,   105,   -12,   -12,
     -30,     6,     6,   116,   -30,    57,    11,    79,    11,   -30,
     -30,    92,   145,     6,     6,   105,     4,   155,   -30,   100,
     113,    54,   -30,   111,   145,   160,   -12,   105,   -30,   -30,
      11,   123,   105,   -30,   101,    62,    11,   124,   -30,    11,
     109,   -30,   118,   -30,   -30
  };

  const unsigned char
  vcgen_parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,    39,     0,     0,
       0,     0,     0,    12,    13,     0,     2,     4,    45,    41,
       0,    40,     0,    42,     0,     5,     0,     0,    46,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    43,
       0,    11,    52,     0,    54,     0,     6,     7,     8,     9,
      10,    19,    20,    21,    22,    23,    24,     0,    47,    48,
      49,     0,     0,    31,    36,     0,     0,    35,    50,    51,
       3,     0,     0,     0,    14,     0,     0,     0,     0,    38,
      37,     0,    15,     0,     0,     0,     0,     0,    32,     0,
       0,     0,    18,    16,    17,     0,    34,     0,    33,    25,
       0,     0,     0,    29,     0,     0,     0,     0,    30,     0,
       0,    28,     0,    27,    26
  };

  const short
  vcgen_parser::yypgoto_[] =
  {
     -30,    -8,   -30,   -30,     0,     5,    98,    99,   -30,    91,
      23,   -30,   -30,   -30,   181,   -30,   168,    -7,   177
  };

  const signed char
  vcgen_parser::yydefgoto_[] =
  {
      -1,    15,    16,    17,    83,    18,    74,    75,    97,    98,
      76,    77,     2,     6,     7,    22,    23,    19,    30
  };

  const unsigned char
  vcgen_parser::yytable_[] =
  {
      25,    26,    27,    28,    53,    44,    45,     1,     8,     3,
       8,     5,     9,    47,    81,     8,    50,     4,    44,    24,
      10,    54,    82,    46,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    46,    68,    69,    70,
      11,    12,    13,    14,    13,    14,    78,    55,    79,    13,
      14,    29,    32,    33,    34,    35,    36,    32,    33,    34,
      35,    36,    52,    43,    54,    32,    33,    34,    35,    36,
      44,    45,    85,    26,    93,    94,    84,    84,    99,    80,
     101,    91,    92,   119,   111,    96,    84,    84,    46,   106,
      86,    36,    87,   103,   104,    34,    35,    36,    84,    84,
      88,   102,   115,    32,    33,    34,    35,    36,   120,    93,
      94,   122,    32,    33,    34,    35,    36,    73,   105,    89,
     109,    32,    33,    34,    35,    36,   118,    71,    93,   123,
     114,    72,   110,    93,    94,   117,     5,    20,   124,    95,
      20,    48,   116,    73,    32,    33,    34,    35,    36,   121,
      51,    37,    38,    39,    40,    41,    42,    32,    33,    34,
      35,    36,    93,    94,    37,    38,    39,    40,    41,    42,
      32,    33,    34,    35,    36,    90,    51,    32,    33,    34,
      35,    36,   107,    96,   112,   113,   100,    21,   108,    31,
      49
  };

  const unsigned char
  vcgen_parser::yycheck_[] =
  {
       8,     9,     9,    10,    21,    17,    18,    31,     4,    38,
       4,    32,     8,    20,     8,     4,    24,     0,    17,     8,
      16,    38,    16,    35,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    35,    44,    45,    46,
      36,    37,    38,    39,    38,    39,    53,    21,    55,    38,
      39,    38,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     9,    29,    38,     3,     4,     5,     6,     7,
      17,    18,    72,    81,    17,    18,    71,    72,    86,    30,
      88,    81,    82,    21,    30,    28,    81,    82,    35,    96,
      19,     7,    21,    93,    94,     5,     6,     7,    93,    94,
      29,     9,   110,     3,     4,     5,     6,     7,   116,    17,
      18,   119,     3,     4,     5,     6,     7,    38,    95,    25,
      20,     3,     4,     5,     6,     7,    25,    22,    17,    20,
     107,    26,    19,    17,    18,   112,    32,    33,    20,    23,
      33,    34,    19,    38,     3,     4,     5,     6,     7,    25,
       9,    10,    11,    12,    13,    14,    15,     3,     4,     5,
       6,     7,    17,    18,    10,    11,    12,    13,    14,    15,
       3,     4,     5,     6,     7,    77,     9,     3,     4,     5,
       6,     7,    27,    28,    24,    25,    87,     6,    97,    12,
      22
  };

  const unsigned char
  vcgen_parser::yystos_[] =
  {
       0,    31,    52,    38,     0,    32,    53,    54,     4,     8,
      16,    36,    37,    38,    39,    41,    42,    43,    45,    57,
      33,    54,    55,    56,     8,    41,    41,    57,    57,    38,
      58,    58,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    29,    17,    18,    35,    57,    34,    56,
      41,     9,     9,    21,    38,    21,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    57,    57,
      57,    22,    26,    38,    46,    47,    50,    51,    57,    57,
      30,     8,    16,    44,    45,    44,    19,    21,    29,    25,
      46,    44,    44,    17,    18,    23,    28,    48,    49,    41,
      47,    41,     9,    44,    44,    50,    57,    27,    49,    20,
      19,    30,    24,    25,    50,    41,    19,    50,    25,    21,
      41,    25,    41,    20,    20
  };

  const unsigned char
  vcgen_parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    43,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    47,    48,    48,    49,    50,    51,    51,    52,    53,
      53,    54,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58
  };

  const unsigned char
  vcgen_parser::yyr2_[] =
  {
       0,     2,     1,     4,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     8,     7,     7,     5,
       6,     1,     1,     2,     2,     1,     1,     2,     7,     1,
       2,     2,     1,     2,     2,     1,     2,     3,     3,     3,
       4,     4,     3,     1,     2
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
  "\"identifier\"", "\"number\"", "$accept", "aexp", "reference",
  "constant", "bexp", "comp", "stmt", "location", "inv_list", "inv",
  "block", "stmt_list", "prog", "pre_list", "pre", "post_list", "post",
  "assertion", "identifier_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  vcgen_parser::yyrline_[] =
  {
       0,   157,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   169,   172,   176,   177,   178,   179,   180,   184,
     185,   186,   187,   188,   189,   193,   194,   195,   196,   197,
     198,   201,   205,   206,   209,   212,   216,   217,   220,   225,
     226,   229,   233,   234,   237,   241,   242,   243,   244,   245,
     246,   247,   248,   252,   253
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
#line 1696 "/home/ferhat/git/vc-gen/recognizer/vcgen-parser.cpp"

#line 255 "/home/ferhat/git/vc-gen/vcgen-parser.yy"


void
yy::vcgen_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
