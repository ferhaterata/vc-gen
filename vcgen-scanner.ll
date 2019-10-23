%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include "vcgen-driver.hpp"
# include "vcgen-parser.hpp"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static yy::location loc;
%}
%option noyywrap nounput batch debug noinput
id    [a-zA-Z][a-zA-Z_0-9]*
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
"-"         return yy::vcgen_parser::make_MINUS(loc);
"+"         return yy::vcgen_parser::make_PLUS(loc);
"*"         return yy::vcgen_parser::make_STAR(loc);
"/"         return yy::vcgen_parser::make_SLASH(loc);
"("         return yy::vcgen_parser::make_LPAREN(loc);
")"         return yy::vcgen_parser::make_RPAREN(loc);

"="         return yy::vcgen_parser::make_EQUAL(loc);
"!="        return yy::vcgen_parser::make_NEQUAL(loc);
"<="        return yy::vcgen_parser::make_LEQ(loc);
">="        return yy::vcgen_parser::make_GEQ(loc);
"<"         return yy::vcgen_parser::make_LT(loc);
">"         return yy::vcgen_parser::make_GT(loc);

"!"         return yy::vcgen_parser::make_NOT(loc);
"||"        return yy::vcgen_parser::make_OR(loc);
"&&"        return yy::vcgen_parser::make_AND(loc);

":="        return yy::vcgen_parser::make_ASSIGN(loc);
";"         return yy::vcgen_parser::make_SEMICOLON(loc);
","         return yy::vcgen_parser::make_COMMA(loc);
"if"        return yy::vcgen_parser::make_IF(loc);
"then"      return yy::vcgen_parser::make_THEN(loc);
"else"      return yy::vcgen_parser::make_ELSE(loc);
"end"       return yy::vcgen_parser::make_ENDSTMT(loc);
"while"     return yy::vcgen_parser::make_WHILE(loc);
"do"        return yy::vcgen_parser::make_DO(loc);
"inv"       return yy::vcgen_parser::make_INV(loc);
"["         return yy::vcgen_parser::make_LSQUARE(loc);
"]"         return yy::vcgen_parser::make_RSQUARE(loc);

"program"   return yy::vcgen_parser::make_PROGRAM(loc);
"pre"       return yy::vcgen_parser::make_PRE(loc);
"post"      return yy::vcgen_parser::make_POST(loc);
"is"        return yy::vcgen_parser::make_IS(loc);

"==>"       return yy::vcgen_parser::make_IFF(loc);
"forall"    return yy::vcgen_parser::make_ALL(loc);
"exists"    return yy::vcgen_parser::make_SOME(loc);

{int}      {
  errno = 0;
  long n = strtol (yytext, NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    driver.error (loc, "integer is out of range");
  return yy::vcgen_parser::make_NUMBER(n, loc);
}

{id}       return yy::vcgen_parser::make_IDENTIFIER(yytext, loc);
.          driver.error (loc, "invalid character");
<<EOF>>    return yy::vcgen_parser::make_END(loc);
%%

void
vcgen_driver::scan_begin ()
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
vcgen_driver::scan_end ()
{
  fclose (yyin);
}

