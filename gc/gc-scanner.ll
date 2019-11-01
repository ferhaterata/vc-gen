%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include "../gc-driver.hpp"
# include "gc-parser.hpp"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static gc::location loc;
%}
%option noyywrap nounput batch debug noinput

%option prefix="gc"

id    [a-zA-Z][a-zA-Z_0-9]*"!"?[a-zA-Z_0-9]*
int   [0-9]+
blank [ \t]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}

{blank}+    loc.step ();
[\n]+       loc.lines (yyleng); loc.step ();
"-"         return gc::gc_parser::make_MINUS(loc);
"+"         return gc::gc_parser::make_PLUS(loc);
"*"         return gc::gc_parser::make_STAR(loc);
"%"         return gc::gc_parser::make_MOD(loc);
"/"         return gc::gc_parser::make_SLASH(loc);
"("         return gc::gc_parser::make_LPAREN(loc);
")"         return gc::gc_parser::make_RPAREN(loc);
"="         return gc::gc_parser::make_EQUAL(loc);
"!="        return gc::gc_parser::make_NEQUAL(loc);
"<="        return gc::gc_parser::make_LEQ(loc);
">="        return gc::gc_parser::make_GEQ(loc);
"<"         return gc::gc_parser::make_LT(loc);
">"         return gc::gc_parser::make_GT(loc);
"!"         return gc::gc_parser::make_NOT(loc);
"||"        return gc::gc_parser::make_OR(loc);
"&&"        return gc::gc_parser::make_AND(loc);
";"         return gc::gc_parser::make_SEMICOLON(loc);
","         return gc::gc_parser::make_COMMA(loc);
"["         return gc::gc_parser::make_LSQUARE(loc);
"]"         return gc::gc_parser::make_RSQUARE(loc);
"==>"       return gc::gc_parser::make_IMPLY(loc);
"forall"    return gc::gc_parser::make_ALL(loc);
"exists"    return gc::gc_parser::make_SOME(loc);
"true"      return gc::gc_parser::make_TRUE(loc);
"false"     return gc::gc_parser::make_FALSE(loc);
"assume"    return gc::gc_parser::make_ASSUME(loc);
"assert"    return gc::gc_parser::make_ASSERT(loc);
"havoc"     return gc::gc_parser::make_HAVOC(loc);
"[]"        return gc::gc_parser::make_CHOICE(loc);
"{"         driver.error (loc, "invalid character");
"}"         driver.error (loc, "invalid character");

{int}      {
  errno = 0;
  long n = strtol (yytext, NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    driver.error (loc, "integer is out of range");
  return gc::gc_parser::make_NUMBER(n, loc);
}

{id}       return gc::gc_parser::make_IDENTIFIER(yytext, loc);
.          driver.error (loc, "invalid character");
<<EOF>>    {return gc::gc_parser::make_EOF(loc);}
%%

void
gc_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}


void
gc_driver::scan_end ()
{
  fclose (yyin);
}

