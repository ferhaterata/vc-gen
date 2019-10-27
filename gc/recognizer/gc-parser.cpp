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
#define yylex   gclex



#include "gc-parser.hpp"


// Unqualified %code blocks.
#line 40 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"

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
#if GCDEBUG

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

#else // !GCDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !GCDEBUG

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
#if GCDEBUG
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
      case 38: // assertion
        value.YY_MOVE_OR_COPY< gc::ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 37: // command
        value.YY_MOVE_OR_COPY< gc::ast::Command* > (YY_MOVE (that.value));
        break;

      case 39: // comparison
        value.YY_MOVE_OR_COPY< gc::ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 42: // constant
        value.YY_MOVE_OR_COPY< gc::ast::Constant* > (YY_MOVE (that.value));
        break;

      case 41: // expression
        value.YY_MOVE_OR_COPY< gc::ast::Expression* > (YY_MOVE (that.value));
        break;

      case 40: // location
        value.YY_MOVE_OR_COPY< gc::ast::Location* > (YY_MOVE (that.value));
        break;

      case 35: // prog
        value.YY_MOVE_OR_COPY< gc::ast::Program* > (YY_MOVE (that.value));
        break;

      case 33: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 32: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 36: // commands
        value.YY_MOVE_OR_COPY< std::vector<gc::ast::Command*> > (YY_MOVE (that.value));
        break;

      case 43: // identifiers
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
      case 38: // assertion
        value.move< gc::ast::Assertion* > (YY_MOVE (that.value));
        break;

      case 37: // command
        value.move< gc::ast::Command* > (YY_MOVE (that.value));
        break;

      case 39: // comparison
        value.move< gc::ast::Comparison* > (YY_MOVE (that.value));
        break;

      case 42: // constant
        value.move< gc::ast::Constant* > (YY_MOVE (that.value));
        break;

      case 41: // expression
        value.move< gc::ast::Expression* > (YY_MOVE (that.value));
        break;

      case 40: // location
        value.move< gc::ast::Location* > (YY_MOVE (that.value));
        break;

      case 35: // prog
        value.move< gc::ast::Program* > (YY_MOVE (that.value));
        break;

      case 33: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 32: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 36: // commands
        value.move< std::vector<gc::ast::Command*> > (YY_MOVE (that.value));
        break;

      case 43: // identifiers
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
      case 38: // assertion
        value.move< gc::ast::Assertion* > (that.value);
        break;

      case 37: // command
        value.move< gc::ast::Command* > (that.value);
        break;

      case 39: // comparison
        value.move< gc::ast::Comparison* > (that.value);
        break;

      case 42: // constant
        value.move< gc::ast::Constant* > (that.value);
        break;

      case 41: // expression
        value.move< gc::ast::Expression* > (that.value);
        break;

      case 40: // location
        value.move< gc::ast::Location* > (that.value);
        break;

      case 35: // prog
        value.move< gc::ast::Program* > (that.value);
        break;

      case 33: // "number"
        value.move< int > (that.value);
        break;

      case 32: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 36: // commands
        value.move< std::vector<gc::ast::Command*> > (that.value);
        break;

      case 43: // identifiers
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

#if GCDEBUG
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

#if GCDEBUG
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
#endif // GCDEBUG

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
#line 31 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 591 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"


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
      case 38: // assertion
        yylhs.value.emplace< gc::ast::Assertion* > ();
        break;

      case 37: // command
        yylhs.value.emplace< gc::ast::Command* > ();
        break;

      case 39: // comparison
        yylhs.value.emplace< gc::ast::Comparison* > ();
        break;

      case 42: // constant
        yylhs.value.emplace< gc::ast::Constant* > ();
        break;

      case 41: // expression
        yylhs.value.emplace< gc::ast::Expression* > ();
        break;

      case 40: // location
        yylhs.value.emplace< gc::ast::Location* > ();
        break;

      case 35: // prog
        yylhs.value.emplace< gc::ast::Program* > ();
        break;

      case 33: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 32: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 36: // commands
        yylhs.value.emplace< std::vector<gc::ast::Command*> > ();
        break;

      case 43: // identifiers
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
#line 123 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Program* > () = new gc::ast::Program(yystack_[0].value.as < std::vector<gc::ast::Command*> > ()); driver.program = yylhs.value.as < gc::ast::Program* > ();}
#line 760 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 3:
#line 127 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::ast::Command*> > () = {yystack_[0].value.as < gc::ast::Command* > ()}; }
#line 766 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 4:
#line 128 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::ast::Command*> > () = enlist(yystack_[1].value.as < std::vector<gc::ast::Command*> > (), yystack_[0].value.as < gc::ast::Command* > ()); }
#line 772 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 5:
#line 129 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<gc::ast::Command*> > () = {new gc::ast::Choice(yystack_[2].value.as < std::vector<gc::ast::Command*> > (), yystack_[0].value.as < std::vector<gc::ast::Command*> > ())}; }
#line 778 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 6:
#line 133 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Command* > () = new gc::ast::Assert(*yystack_[1].value.as < gc::ast::Assertion* > ()); }
#line 784 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 7:
#line 134 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Command* > () = new gc::ast::Assume(*yystack_[1].value.as < gc::ast::Assertion* > ()); }
#line 790 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 8:
#line 135 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Command* > () = new gc::ast::Havoc(*yystack_[1].value.as < gc::ast::Location* > ()); }
#line 796 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 9:
#line 136 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Command* > () = new gc::ast::List(yystack_[1].value.as < std::vector<gc::ast::Command*> > ()); }
#line 802 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 10:
#line 141 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = yystack_[0].value.as < gc::ast::Comparison* > (); }
#line 808 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 11:
#line 142 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::Negation(*yystack_[0].value.as < gc::ast::Assertion* > ()); }
#line 814 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 12:
#line 143 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::Disjunction(*yystack_[2].value.as < gc::ast::Assertion* > (), *yystack_[0].value.as < gc::ast::Assertion* > ()); }
#line 820 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 13:
#line 144 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::Conjunction(*yystack_[2].value.as < gc::ast::Assertion* > (), *yystack_[0].value.as < gc::ast::Assertion* > ()); }
#line 826 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 14:
#line 145 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::Implication(*yystack_[2].value.as < gc::ast::Assertion* > (), *yystack_[0].value.as < gc::ast::Assertion* > ()); }
#line 832 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 15:
#line 146 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::UniversalQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < gc::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 838 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 16:
#line 147 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::ExistentialQuantification(yystack_[2].value.as < std::vector<std::string> > (), *yystack_[0].value.as < gc::ast::Assertion* > ()); /*print<std::string>($2);*/ }
#line 844 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 17:
#line 148 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::True(); }
#line 850 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 18:
#line 149 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = new gc::ast::False(); }
#line 856 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 19:
#line 150 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Assertion* > () = yystack_[1].value.as < gc::ast::Assertion* > (); }
#line 862 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 20:
#line 154 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::EqualComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 868 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 21:
#line 155 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::NotEqualComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 874 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 22:
#line 156 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::LeqComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 880 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 23:
#line 157 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::GeqComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 886 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 24:
#line 158 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::LtComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 892 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 25:
#line 159 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Comparison* > () = new gc::ast::GtComparison(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 898 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 26:
#line 162 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Location* > () = new gc::ast::Location(yystack_[0].value.as < std::string > ()); }
#line 904 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 27:
#line 166 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = yystack_[0].value.as < gc::ast::Location* > (); }
#line 910 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 28:
#line 167 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::ArrayLocation(*yystack_[3].value.as < gc::ast::Location* > (), *yystack_[1].value.as < gc::ast::Expression* > ()); }
#line 916 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 29:
#line 168 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = yystack_[0].value.as < gc::ast::Constant* > (); }
#line 922 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 30:
#line 169 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Negate(*yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 928 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 31:
#line 170 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Sum(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ());}
#line 934 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 32:
#line 171 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Subtract(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 940 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 33:
#line 172 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Multiply(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 946 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 34:
#line 173 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Divide(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 952 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 35:
#line 174 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = new gc::ast::Mod(*yystack_[2].value.as < gc::ast::Expression* > (), *yystack_[0].value.as < gc::ast::Expression* > ()); }
#line 958 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 36:
#line 175 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Expression* > () = yystack_[1].value.as < gc::ast::Expression* > ();}
#line 964 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 37:
#line 178 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < gc::ast::Constant* > () = new gc::ast::Constant(yystack_[0].value.as < int > ()); }
#line 970 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 38:
#line 182 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = {yystack_[0].value.as < std::string > ()}; }
#line 976 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;

  case 39:
#line 183 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = enlist(yystack_[1].value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 982 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"
    break;


#line 986 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"

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


  const signed char gc_parser::yypact_ninf_ = -24;

  const signed char gc_parser::yytable_ninf_ = -1;

  const short
  gc_parser::yypact_[] =
  {
      43,    43,    -2,    -2,   -23,    12,    13,   -24,    24,     7,
      -2,    -2,   -19,   -19,   -24,   -24,   -24,   -24,   105,   -24,
      -1,   106,   -24,   108,     0,   -24,    43,   -24,   -24,     7,
     127,    72,    93,    22,   -24,   -15,     6,    -2,    -2,   -24,
      -2,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   -24,   -24,    43,    79,   -24,   -24,    -2,
     -24,    -2,    -7,   112,   112,    71,   127,   127,    11,    11,
     133,   133,   133,   133,   133,   133,   133,   112,   112,   -24
  };

  const unsigned char
  gc_parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,    17,    18,    26,    37,     0,    10,
      27,     0,    29,     0,     0,     1,     0,     4,     9,     0,
      30,     0,     0,    11,    38,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     5,     0,    19,    36,     0,
      39,     0,    12,    13,    14,     0,    31,    32,    33,    34,
      35,    20,    21,    22,    23,    24,    25,    15,    16,    28
  };

  const signed char
  gc_parser::yypgoto_[] =
  {
     -24,   -24,     3,    -5,    -3,   -24,    32,    18,   -24,    33
  };

  const signed char
  gc_parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    18,    19,    20,    21,    22,    35
  };

  const unsigned char
  gc_parser::yytable_[] =
  {
      23,    27,     9,    27,     8,    59,    10,    31,    33,    16,
      37,     9,    25,    34,    11,    29,    40,    60,    46,    54,
      41,     1,    12,    13,    14,    15,    61,    30,    32,    55,
      16,    17,     1,    28,    62,    63,    24,    64,    60,    16,
      17,     2,     3,     4,    26,    40,    36,    56,     0,     0,
      27,     1,     2,     3,     4,    26,    77,     0,    78,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     2,     3,     4,    42,    43,    44,    45,    46,     0,
       0,    57,    42,    43,    44,    45,    46,     0,    58,    37,
      38,     0,     0,    79,     0,    40,    42,    43,    44,    45,
      46,     0,    58,    47,    48,    49,    50,    51,    52,    42,
      43,    44,    45,    46,     0,     0,    47,    48,    49,    50,
      51,    52,    37,    38,    39,    37,    38,    53,    40,    37,
      38,    40,    44,    45,    46,    40,    42,    43,    44,    45,
      46
  };

  const signed char
  gc_parser::yycheck_[] =
  {
       3,     6,     4,     8,     1,    20,     8,    10,    11,    32,
      17,     4,     0,    32,    16,     8,    23,    32,     7,    19,
      21,     8,    24,    25,    26,    27,    20,     9,    10,    26,
      32,    33,     8,     9,    37,    38,     4,    40,    32,    32,
      33,    28,    29,    30,    31,    23,    13,    29,    -1,    -1,
      55,     8,    28,    29,    30,    31,    59,    -1,    61,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    28,    29,    30,     3,     4,     5,     6,     7,    -1,
      -1,     9,     3,     4,     5,     6,     7,    -1,     9,    17,
      18,    -1,    -1,    22,    -1,    23,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,     3,
       4,     5,     6,     7,    -1,    -1,    10,    11,    12,    13,
      14,    15,    17,    18,    19,    17,    18,    19,    23,    17,
      18,    23,     5,     6,     7,    23,     3,     4,     5,     6,
       7
  };

  const unsigned char
  gc_parser::yystos_[] =
  {
       0,     8,    28,    29,    30,    35,    36,    37,    36,     4,
       8,    16,    24,    25,    26,    27,    32,    33,    38,    39,
      40,    41,    42,    38,    40,     0,    31,    37,     9,     8,
      41,    38,    41,    38,    32,    43,    43,    17,    18,    19,
      23,    21,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    19,    19,    36,    41,     9,     9,    20,
      32,    20,    38,    38,    38,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    38,    38,    22
  };

  const unsigned char
  gc_parser::yyr1_[] =
  {
       0,    34,    35,    36,    36,    36,    37,    37,    37,    37,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    39,    39,    40,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    42,    43,    43
  };

  const unsigned char
  gc_parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     3,     3,     3,     3,     3,
       1,     2,     3,     3,     3,     4,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     4,     1,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const gc_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"(\"", "\")\"", "\"=\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"<\"", "\">\"", "\"!\"", "\"||\"", "\"&&\"", "\";\"",
  "\",\"", "\"[\"", "\"]\"", "\"==>\"", "\"forall\"", "\"exists\"",
  "\"true\"", "\"false\"", "\"assume\"", "\"assert\"", "\"havoc\"",
  "\"[]\"", "\"identifier\"", "\"number\"", "$accept", "prog", "commands",
  "command", "assertion", "comparison", "location", "expression",
  "constant", "identifiers", YY_NULLPTR
  };

#if GCDEBUG
  const unsigned char
  gc_parser::yyrline_[] =
  {
       0,   123,   123,   127,   128,   129,   133,   134,   135,   136,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     154,   155,   156,   157,   158,   159,   162,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   178,   182,   183
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
#endif // GCDEBUG


#line 8 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"
} // gc
#line 1429 "/home/ferhat/git/vc-gen/gc/recognizer/gc-parser.cpp"

#line 185 "/home/ferhat/git/vc-gen/gc/gc-parser.yy"


void
gc::gc_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
