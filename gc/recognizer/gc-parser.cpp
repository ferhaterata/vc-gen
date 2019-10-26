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





#include "gc-parser.hpp"


// Unqualified %code blocks.
#line 39 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"

# include "gc-driver.hpp"

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

gc::Program *program;               /* the top level root node of our final AST */


#line 68 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"


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

#line 8 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
namespace gc {
#line 163 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  gc_parser::yytnamerr_ (const char *yystr)
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
  gc_parser::gc_parser (gc_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  gc_parser::~gc_parser ()
  {}

  gc_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  gc_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  gc_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  gc_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  gc_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  gc_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  gc_parser::symbol_number_type
  gc_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  gc_parser::stack_symbol_type::stack_symbol_type ()
  {}

  gc_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 42: // aexp
        value.YY_MOVE_OR_COPY< gc::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 58: // assertion
        value.YY_MOVE_OR_COPY< gc::Assertion* > (YY_MOVE (that.value));
        break;

      case 51: // block
        value.YY_MOVE_OR_COPY< gc::Block* > (YY_MOVE (that.value));
        break;

      case 45: // bexp
        value.YY_MOVE_OR_COPY< gc::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 46: // comp
        value.YY_MOVE_OR_COPY< gc::Comparison* > (YY_MOVE (that.value));
        break;

      case 44: // constant
        value.YY_MOVE_OR_COPY< gc::Constant* > (YY_MOVE (that.value));
        break;

      case 50: // inv
        value.YY_MOVE_OR_COPY< gc::Invariant* > (YY_MOVE (that.value));
        break;

      case 48: // location
        value.YY_MOVE_OR_COPY< gc::Location* > (YY_MOVE (that.value));
        break;

      case 57: // post
        value.YY_MOVE_OR_COPY< gc::PostCondition* > (YY_MOVE (that.value));
        break;

      case 55: // pre
        value.YY_MOVE_OR_COPY< gc::PreCondition* > (YY_MOVE (that.value));
        break;

      case 53: // prog
        value.YY_MOVE_OR_COPY< gc::Program* > (YY_MOVE (that.value));
        break;

      case 43: // reference
        value.YY_MOVE_OR_COPY< gc::Reference* > (YY_MOVE (that.value));
        break;

      case 47: // stmt
        value.YY_MOVE_OR_COPY< gc::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 49: // inv_list
        value.YY_MOVE_OR_COPY< std::vector<gc::Invariant*> > (YY_MOVE (that.value));
        break;

      case 56: // post_list
        value.YY_MOVE_OR_COPY< std::vector<gc::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 54: // pre_list
        value.YY_MOVE_OR_COPY< std::vector<gc::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 52: // stmt_list
        value.YY_MOVE_OR_COPY< std::vector<gc::Statement*> > (YY_MOVE (that.value));
        break;

      case 59: // identifier_list
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

  gc_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 42: // aexp
        value.move< gc::ArithmeticExpression* > (YY_MOVE (that.value));
        break;

      case 58: // assertion
        value.move< gc::Assertion* > (YY_MOVE (that.value));
        break;

      case 51: // block
        value.move< gc::Block* > (YY_MOVE (that.value));
        break;

      case 45: // bexp
        value.move< gc::BooleanExpression* > (YY_MOVE (that.value));
        break;

      case 46: // comp
        value.move< gc::Comparison* > (YY_MOVE (that.value));
        break;

      case 44: // constant
        value.move< gc::Constant* > (YY_MOVE (that.value));
        break;

      case 50: // inv
        value.move< gc::Invariant* > (YY_MOVE (that.value));
        break;

      case 48: // location
        value.move< gc::Location* > (YY_MOVE (that.value));
        break;

      case 57: // post
        value.move< gc::PostCondition* > (YY_MOVE (that.value));
        break;

      case 55: // pre
        value.move< gc::PreCondition* > (YY_MOVE (that.value));
        break;

      case 53: // prog
        value.move< gc::Program* > (YY_MOVE (that.value));
        break;

      case 43: // reference
        value.move< gc::Reference* > (YY_MOVE (that.value));
        break;

      case 47: // stmt
        value.move< gc::Statement* > (YY_MOVE (that.value));
        break;

      case 39: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 38: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 49: // inv_list
        value.move< std::vector<gc::Invariant*> > (YY_MOVE (that.value));
        break;

      case 56: // post_list
        value.move< std::vector<gc::PostCondition*> > (YY_MOVE (that.value));
        break;

      case 54: // pre_list
        value.move< std::vector<gc::PreCondition*> > (YY_MOVE (that.value));
        break;

      case 52: // stmt_list
        value.move< std::vector<gc::Statement*> > (YY_MOVE (that.value));
        break;

      case 59: // identifier_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  gc_parser::stack_symbol_type&
  gc_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 42: // aexp
        value.move< gc::ArithmeticExpression* > (that.value);
        break;

      case 58: // assertion
        value.move< gc::Assertion* > (that.value);
        break;

      case 51: // block
        value.move< gc::Block* > (that.value);
        break;

      case 45: // bexp
        value.move< gc::BooleanExpression* > (that.value);
        break;

      case 46: // comp
        value.move< gc::Comparison* > (that.value);
        break;

      case 44: // constant
        value.move< gc::Constant* > (that.value);
        break;

      case 50: // inv
        value.move< gc::Invariant* > (that.value);
        break;

      case 48: // location
        value.move< gc::Location* > (that.value);
        break;

      case 57: // post
        value.move< gc::PostCondition* > (that.value);
        break;

      case 55: // pre
        value.move< gc::PreCondition* > (that.value);
        break;

      case 53: // prog
        value.move< gc::Program* > (that.value);
        break;

      case 43: // reference
        value.move< gc::Reference* > (that.value);
        break;

      case 47: // stmt
        value.move< gc::Statement* > (that.value);
        break;

      case 39: // "number"
        value.move< int > (that.value);
        break;

      case 38: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 49: // inv_list
        value.move< std::vector<gc::Invariant*> > (that.value);
        break;

      case 56: // post_list
        value.move< std::vector<gc::PostCondition*> > (that.value);
        break;

      case 54: // pre_list
        value.move< std::vector<gc::PreCondition*> > (that.value);
        break;

      case 52: // stmt_list
        value.move< std::vector<gc::Statement*> > (that.value);
        break;

      case 59: // identifier_list
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
  gc_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  gc_parser::yy_print_ (std::ostream& yyo,
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
  gc_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  gc_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  gc_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  gc_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  gc_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  gc_parser::debug_level_type
  gc_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  gc_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  gc_parser::state_type
  gc_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  gc_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  gc_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  gc_parser::operator() ()
  {
    return parse ();
  }

  int
  gc_parser::parse ()
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
#line 30 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 699 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"


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
      case 42: // aexp
        yylhs.value.emplace< gc::ArithmeticExpression* > ();
        break;

      case 58: // assertion
        yylhs.value.emplace< gc::Assertion* > ();
        break;

      case 51: // block
        yylhs.value.emplace< gc::Block* > ();
        break;

      case 45: // bexp
        yylhs.value.emplace< gc::BooleanExpression* > ();
        break;

      case 46: // comp
        yylhs.value.emplace< gc::Comparison* > ();
        break;

      case 44: // constant
        yylhs.value.emplace< gc::Constant* > ();
        break;

      case 50: // inv
        yylhs.value.emplace< gc::Invariant* > ();
        break;

      case 48: // location
        yylhs.value.emplace< gc::Location* > ();
        break;

      case 57: // post
        yylhs.value.emplace< gc::PostCondition* > ();
        break;

      case 55: // pre
        yylhs.value.emplace< gc::PreCondition* > ();
        break;

      case 53: // prog
        yylhs.value.emplace< gc::Program* > ();
        break;

      case 43: // reference
        yylhs.value.emplace< gc::Reference* > ();
        break;

      case 47: // stmt
        yylhs.value.emplace< gc::Statement* > ();
        break;

      case 39: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 38: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 49: // inv_list
        yylhs.value.emplace< std::vector<gc::Invariant*> > ();
        break;

      case 56: // post_list
        yylhs.value.emplace< std::vector<gc::PostCondition*> > ();
        break;

      case 54: // pre_list
        yylhs.value.emplace< std::vector<gc::PreCondition*> > ();
        break;

      case 52: // stmt_list
        yylhs.value.emplace< std::vector<gc::Statement*> > ();
        break;

      case 59: // identifier_list
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
#line 159 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = yystack_[0].value.as < gc::Reference* > (); }
#line 904 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 3:
#line 160 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::ArrayReference(*yystack_[3].value.as < gc::Reference* > (), *yystack_[1].value.as < gc::ArithmeticExpression* > ()); }
#line 910 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 4:
#line 161 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = yystack_[0].value.as < gc::Constant* > (); }
#line 916 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 5:
#line 162 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Negate(*yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 922 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 6:
#line 163 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Sum(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ());}
#line 928 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 7:
#line 164 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Subtract(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 934 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 8:
#line 165 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Multiply(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 940 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 9:
#line 166 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Divide(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 946 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 10:
#line 167 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = new gc::Mod(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 952 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 11:
#line 168 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ArithmeticExpression* > () = yystack_[1].value.as < gc::ArithmeticExpression* > ();}
#line 958 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 12:
#line 171 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Reference* > () = new gc::Reference(yystack_[0].value.as < std::string > ()); }
#line 964 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 13:
#line 174 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Constant* > () = new gc::Constant(yystack_[0].value.as < int > ()); }
#line 970 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 14:
#line 178 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::BooleanExpression* > () = yystack_[0].value.as < gc::Comparison* > (); }
#line 976 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 15:
#line 179 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::BooleanExpression* > () = new gc::NotExpression(*yystack_[0].value.as < gc::BooleanExpression* > ()); }
#line 982 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 16:
#line 180 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::BooleanExpression* > () = new gc::OrExpression(*yystack_[2].value.as < gc::BooleanExpression* > (), *yystack_[0].value.as < gc::BooleanExpression* > ()); }
#line 988 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 17:
#line 181 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::BooleanExpression* > () = new gc::AndExpression(*yystack_[2].value.as < gc::BooleanExpression* > (), *yystack_[0].value.as < gc::BooleanExpression* > ()); }
#line 994 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 18:
#line 182 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::BooleanExpression* > () = yystack_[1].value.as < gc::BooleanExpression* > ();}
#line 1000 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 19:
#line 186 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::EqualComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1006 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 20:
#line 187 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::NotEqualComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1012 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 21:
#line 188 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::LeqComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1018 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 22:
#line 189 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::GeqComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1024 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 23:
#line 190 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::LtComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1030 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 24:
#line 191 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Comparison* > () = new gc::GtComparison(*yystack_[2].value.as < gc::ArithmeticExpression* > (), *yystack_[0].value.as < gc::ArithmeticExpression* > ()); }
#line 1036 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 25:
#line 195 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::AssignmentStatement(*yystack_[3].value.as < gc::Location* > (), *yystack_[1].value.as < gc::ArithmeticExpression* > ());}
#line 1042 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 26:
#line 196 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::MultipleAssignmentStatement(*yystack_[7].value.as < gc::Location* > (), *yystack_[5].value.as < gc::Location* > (), *yystack_[3].value.as < gc::ArithmeticExpression* > (), *yystack_[1].value.as < gc::ArithmeticExpression* > ());}
#line 1048 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 27:
#line 197 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::ArrayAssignmentStatement(*yystack_[6].value.as < gc::Location* > (), *yystack_[4].value.as < gc::ArithmeticExpression* > (), *yystack_[1].value.as < gc::ArithmeticExpression* > ());}
#line 1054 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 28:
#line 198 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::IfThenElseStatement(*yystack_[5].value.as < gc::BooleanExpression* > (), *yystack_[3].value.as < gc::Block* > (), *yystack_[1].value.as < gc::Block* > ());}
#line 1060 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 29:
#line 199 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::IfThenStatement(*yystack_[3].value.as < gc::BooleanExpression* > (), *yystack_[1].value.as < gc::Block* > ());}
#line 1066 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 30:
#line 200 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Statement* > () = new gc::WhileStatement(*yystack_[4].value.as < gc::BooleanExpression* > (), yystack_[3].value.as < std::vector<gc::Invariant*> > (), *yystack_[1].value.as < gc::Block* > ());}
#line 1072 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 31:
#line 203 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Location* > () = new gc::Location(yystack_[0].value.as < std::string > ()); }
#line 1078 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 32:
#line 207 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::Invariant*> > () = {yystack_[0].value.as < gc::Invariant* > ()}; }
#line 1084 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 33:
#line 208 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::Invariant*> > () = enlist(yystack_[1].value.as < std::vector<gc::Invariant*> > (), yystack_[0].value.as < gc::Invariant* > ()); }
#line 1090 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 34:
#line 211 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Invariant* > () = new gc::Invariant(*yystack_[0].value.as < gc::Assertion* > ()); }
#line 1096 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 35:
#line 214 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Block* > () = new gc::Block(yystack_[0].value.as < std::vector<gc::Statement*> > ()); /*print<gc::Statement>($1);*/}
#line 1102 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 36:
#line 218 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::Statement*> > () = {yystack_[0].value.as < gc::Statement* > ()};}
#line 1108 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 37:
#line 219 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::Statement*> > () = enlist(yystack_[1].value.as < std::vector<gc::Statement*> > (), yystack_[0].value.as < gc::Statement* > ()); }
#line 1114 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 38:
#line 224 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Program* > () = new gc::Program(yystack_[5].value.as < std::string > (), yystack_[4].value.as < std::vector<gc::PreCondition*> > (), yystack_[3].value.as < std::vector<gc::PostCondition*> > (), *yystack_[1].value.as < gc::Block* > ()); driver.program = yylhs.value.as < gc::Program* > ();}
#line 1120 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 39:
#line 226 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { clear_stack (); }
#line 1126 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 40:
#line 230 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::PreCondition*> > () = {yystack_[0].value.as < gc::PreCondition* > ()}; }
#line 1132 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 41:
#line 231 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::PreCondition*> > () = enlist(yystack_[1].value.as < std::vector<gc::PreCondition*> > (), yystack_[0].value.as < gc::PreCondition* > ()); }
#line 1138 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 42:
#line 234 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::PreCondition* > () = new gc::PreCondition(*yystack_[0].value.as < gc::Assertion* > ()); }
#line 1144 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 43:
#line 238 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::PostCondition*> > () = {yystack_[0].value.as < gc::PostCondition* > ()}; }
#line 1150 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 44:
#line 239 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::PostCondition*> > () = enlist(yystack_[1].value.as < std::vector<gc::PostCondition*> > (), yystack_[0].value.as < gc::PostCondition* > ()); }
#line 1156 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 45:
#line 242 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::PostCondition* > () = new gc::PostCondition(*yystack_[0].value.as < gc::Assertion* > ()); }
#line 1162 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 46:
#line 246 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = yystack_[0].value.as < gc::Comparison* > (); }
#line 1168 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 47:
#line 247 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::Negation(*yystack_[0].value.as < gc::Assertion* > ()); }
#line 1174 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 48:
#line 248 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::Disjunction(*yystack_[2].value.as < gc::Assertion* > (), *yystack_[0].value.as < gc::Assertion* > ()); }
#line 1180 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 49:
#line 249 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::Conjunction(*yystack_[2].value.as < gc::Assertion* > (), *yystack_[0].value.as < gc::Assertion* > ()); }
#line 1186 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 50:
#line 250 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::Implication(*yystack_[2].value.as < gc::Assertion* > (), *yystack_[0].value.as < gc::Assertion* > ()); }
#line 1192 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 51:
#line 251 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::UniversalQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < gc::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1198 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 52:
#line 252 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = new gc::ExistentialQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < gc::Assertion* > ()); /*print<std::string>($2);*/ }
#line 1204 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 53:
#line 253 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::Assertion* > () = yystack_[1].value.as < gc::Assertion* > (); }
#line 1210 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 54:
#line 254 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    {  }
#line 1216 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 55:
#line 258 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
#line 1222 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 56:
#line 259 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 1228 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;


#line 1232 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"

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
  gc_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  gc_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char gc_parser::yypact_ninf_ = -36;

  const signed char gc_parser::yytable_ninf_ = -1;

  const short
  gc_parser::yypact_[] =
  {
      16,   -22,   -33,    20,   -36,    14,   -36,    33,   -21,   -36,
      15,     6,    33,   -23,   -23,   -36,   -36,   168,    55,   -36,
     -36,    85,    33,   -36,   -25,   -36,    15,   188,    97,   155,
      70,    85,   -36,   -17,   115,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    33,    33,    33,
      85,   119,   -36,   181,   -36,   -36,   -36,    33,   -36,    33,
     188,   188,   102,   102,   195,   195,   195,   195,   195,   195,
     195,    53,   -11,    85,    85,    47,    47,   -36,   -36,   121,
     112,   119,    85,    85,   -36,    47,    47,   174,   -36,    90,
      15,    76,    15,   -36,   -36,   137,    48,    47,    47,   119,
      33,    84,   -36,   118,   120,    89,   -36,   127,    48,    92,
      85,   119,   -36,   -36,    15,   130,   119,   -36,   122,    94,
      15,   126,   -36,    15,   123,   -36,   128,   -36,   -36
  };

  const unsigned char
  gc_parser::yydefact_[] =
  {
       0,     0,     0,     0,    39,     0,     1,     0,     0,    40,
       0,     0,     0,     0,     0,    12,    13,     0,     2,     4,
      46,    42,     0,    41,     0,    43,     0,     5,     0,     0,
       0,    47,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,    44,     0,    54,    11,    53,     0,    56,     0,
       6,     7,     8,     9,    10,    19,    20,    21,    22,    23,
      24,     0,    48,    49,    50,     0,     0,    31,    36,     0,
       0,    35,    51,    52,     3,     0,     0,     0,    14,     0,
       0,     0,     0,    38,    37,     0,    15,     0,     0,     0,
       0,     0,    32,     0,     0,     0,    18,    16,    17,     0,
      34,     0,    33,    25,     0,     0,     0,    29,     0,     0,
       0,     0,    30,     0,     0,    28,     0,    27,    26
  };

  const short
  gc_parser::yypgoto_[] =
  {
     -36,   -10,   -36,   -36,   -24,    -8,    71,    65,   -36,    62,
     -35,   -36,   -36,   -36,   169,   -36,   152,    -9,   175
  };

  const signed char
  gc_parser::yydefgoto_[] =
  {
      -1,    17,    18,    19,    87,    20,    78,    79,   101,   102,
      80,    81,     3,     8,     9,    24,    25,    21,    33
  };

  const unsigned char
  gc_parser::yytable_[] =
  {
      27,    29,    30,    31,    57,     5,    47,    28,    22,    51,
      10,     7,    22,    50,    11,    32,    53,     1,     4,    10,
       6,    58,    12,    26,    49,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    10,    72,    73,
      74,    11,    13,    14,    15,    16,     7,     2,    82,    12,
      83,    10,    89,    15,    16,    85,    35,    36,    37,    38,
      39,    95,    96,    86,   109,    97,    98,    88,    88,    13,
      14,    15,    16,   107,   108,    29,   118,    88,    88,    56,
     103,   121,   105,    84,    46,    15,    16,    47,    48,    88,
      88,   110,    35,    36,    37,    38,    39,    35,    36,    37,
      38,    39,    47,    48,   119,    49,    54,    97,    98,    39,
     124,   111,   100,   126,    77,   123,   116,   117,   100,   115,
      49,    35,    36,    37,    38,    39,    35,    36,    37,    38,
      39,    35,    36,    37,    38,    39,    59,    93,   113,   114,
      90,    75,    91,   127,    97,    76,   106,   122,   128,   120,
      92,   125,    94,    58,    97,    98,   104,    77,    35,    36,
      37,    38,    39,   112,    55,    40,    41,    42,    43,    44,
      45,    35,    36,    37,    38,    39,    52,    23,    40,    41,
      42,    43,    44,    45,    35,    36,    37,    38,    39,    34,
      55,    97,    98,    37,    38,    39,     0,    99,    35,    36,
      37,    38,    39
  };

  const signed char
  gc_parser::yycheck_[] =
  {
      10,    11,    11,    12,    21,    38,    17,     1,    33,    34,
       4,    32,    33,    22,     8,    38,    26,     1,    40,     4,
       0,    38,    16,     8,    35,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     4,    47,    48,
      49,     8,    36,    37,    38,    39,    32,    31,    57,    16,
      59,     4,    76,    38,    39,     8,     3,     4,     5,     6,
       7,    85,    86,    16,    99,    17,    18,    75,    76,    36,
      37,    38,    39,    97,    98,    85,   111,    85,    86,     9,
      90,   116,    92,    30,    29,    38,    39,    17,    18,    97,
      98,   100,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    17,    18,   114,    35,     9,    17,    18,     7,
     120,    27,    28,   123,    38,    21,    24,    25,    28,    30,
      35,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    21,    25,    20,    19,
      19,    22,    21,    20,    17,    26,     9,    25,    20,    19,
      29,    25,    81,    38,    17,    18,    91,    38,     3,     4,
       5,     6,     7,   101,     9,    10,    11,    12,    13,    14,
      15,     3,     4,     5,     6,     7,    24,     8,    10,    11,
      12,    13,    14,    15,     3,     4,     5,     6,     7,    14,
       9,    17,    18,     5,     6,     7,    -1,    23,     3,     4,
       5,     6,     7
  };

  const unsigned char
  gc_parser::yystos_[] =
  {
       0,     1,    31,    53,    40,    38,     0,    32,    54,    55,
       4,     8,    16,    36,    37,    38,    39,    42,    43,    44,
      46,    58,    33,    55,    56,    57,     8,    42,     1,    42,
      58,    58,    38,    59,    59,     3,     4,     5,     6,     7,
      10,    11,    12,    13,    14,    15,    29,    17,    18,    35,
      58,    34,    57,    42,     9,     9,     9,    21,    38,    21,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    58,    58,    58,    22,    26,    38,    47,    48,
      51,    52,    58,    58,    30,     8,    16,    45,    46,    45,
      19,    21,    29,    25,    47,    45,    45,    17,    18,    23,
      28,    49,    50,    42,    48,    42,     9,    45,    45,    51,
      58,    27,    50,    20,    19,    30,    24,    25,    51,    42,
      19,    51,    25,    21,    42,    25,    42,    20,    20
  };

  const unsigned char
  gc_parser::yyr1_[] =
  {
       0,    41,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43,    44,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59
  };

  const unsigned char
  gc_parser::yyr2_[] =
  {
       0,     2,     1,     4,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     8,     7,     7,     5,
       6,     1,     1,     2,     2,     1,     1,     2,     7,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     3,     3,
       3,     4,     4,     3,     3,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const gc_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"(\"", "\")\"", "\"=\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"<\"", "\">\"", "\"!\"", "\"||\"", "\"&&\"", "\":=\"",
  "\";\"", "\",\"", "\"if\"", "\"then\"", "\"else\"", "\"end\"",
  "\"while\"", "\"do\"", "\"inv\"", "\"[\"", "\"]\"", "\"program\"",
  "\"pre\"", "\"post\"", "\"is\"", "\"==>\"", "\"forall\"", "\"exists\"",
  "\"identifier\"", "\"number\"", "\"\\n\"", "$accept", "aexp",
  "reference", "constant", "bexp", "comp", "stmt", "location", "inv_list",
  "inv", "block", "stmt_list", "prog", "pre_list", "pre", "post_list",
  "post", "assertion", "identifier_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  gc_parser::yyrline_[] =
  {
       0,   159,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   171,   174,   178,   179,   180,   181,   182,   186,
     187,   188,   189,   190,   191,   195,   196,   197,   198,   199,
     200,   203,   207,   208,   211,   214,   218,   219,   223,   225,
     230,   231,   234,   238,   239,   242,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   258,   259
  };

  // Print the state stack on the debug stream.
  void
  gc_parser::yystack_print_ ()
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
  gc_parser::yy_reduce_print_ (int yyrule)
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


#line 8 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
} // gc
#line 1712 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"

#line 261 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"


void
gc::gc_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}

// Deletes all the nodes that were allocated
void
clear_stack ()
{
  while (!nodes.empty ()) {
    delete nodes.top ();
    nodes.pop ();
  }
}
