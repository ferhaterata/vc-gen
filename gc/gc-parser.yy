%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

%verbose                            /* Generate the parser description file. */

%defines
%define api.namespace {gc}
%define api.prefix {gc}
%define api.parser.class {gc_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert                /* assert correct cleanup of semantic value objects */


%code requires
{
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include "../ast/gc.hpp"
class gc_driver;
}

%param { gc_driver& driver }        /* The parsing context. */

%locations                          /* we request location tracking. */

%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace                 /* enable parser tracing */
%define parse.error verbose         /* increase usefulness of error messages */

%code
{
# include "../gc-driver.hpp"

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

}

%define api.token.prefix {TOK_}

%token
  EOF  0  "end of file"
  PLUS      "+"
  MINUS     "-"
  STAR      "*"   /* MULT */
  SLASH     "/"   /* DIV */
  MOD       "%"
  LPAREN    "("
  RPAREN    ")"
  EQUAL     "="
  NEQUAL    "!="
  LEQ       "<="
  GEQ       ">="
  LT        "<"
  GT        ">"
  NOT       "!"
  OR        "||"
  AND       "&&"
  SEMICOLON ";"
  COMMA     ","
  LSQUARE   "["
  RSQUARE   "]"
  IMPLY     "==>"
  ALL       "forall"
  SOME      "exists"
  TRUE      "true"
  FALSE     "false"
  WRITE     "write"
  READ      "read"
  ASSUME    "assume"
  ASSERT    "assert"
  HAVOC     "havoc"
  CHOICE    "[]"
;

%token <std::string>    IDENTIFIER "identifier"
%token <int>            NUMBER "number"

%type <gc::ast::Program*>                   prog
%type <gc::ast::Command*>                   command
%type <gc::ast::Assertion*>                 assertion
%type <gc::ast::Location*>                  location
%type <gc::ast::Expression*>                expression
%type <gc::ast::Comparison*>                comparison
%type <gc::ast::Constant*>                  constant

%type <std::vector<gc::ast::Command*>>      commands;
%type <std::vector<std::string>>            identifiers;

//%printer { yyoutput << $$; } <*>;

%%

%start prog;


%precedence "==>";
%precedence "||";
%precedence "&&";
%precedence "!";
%left "+" "-";
%left "*" "/";
%right "[]";

prog: commands                              { $$ = new gc::ast::Program($1); driver.program = $$;}
    ;

commands:
      command                               { $$ = {$1}; }
    | commands command                      { $$ = enlist($1, $2); }
    | commands "[]" commands                { $$ = {new gc::ast::Select($1, $3)}; }
    ;

command:
      "assume" assertion ";"                { $$ = new gc::ast::Assume(*$2); }
    | "assert" assertion ";"                { $$ = new gc::ast::Assert(*$2); }
    | "havoc" location   ";"                { $$ = new gc::ast::Havoc(*$2);}
    | "(" commands ")"                      { $$ = new gc::ast::List($2); }

    ;

assertion:
      comparison                            { $$ = $1; }
    | "!" assertion                         { $$ = new gc::ast::Negation(*$2); }
    | assertion "||" assertion              { $$ = new gc::ast::Disjunction(*$1, *$3); }
    | assertion "&&" assertion              { $$ = new gc::ast::Conjunction(*$1, *$3); }
    | assertion "==>" assertion             { $$ = new gc::ast::Implication(*$1, *$3); }
    | "forall" identifiers "," assertion    { $$ = new gc::ast::UniversalQuantifier($2, *$4); /*print<std::string>($2);*/ }
    | "exists" identifiers "," assertion    { $$ = new gc::ast::ExistentialQuantifier($2, *$4); /*print<std::string>($2);*/ }
    | "true"                                { $$ = new gc::ast::True(); }
    | "false"                               { $$ = new gc::ast::False(); }
    | "(" assertion ")"                     { $$ = $2; }
    ;

comparison:
      expression "="  expression            { $$ = new gc::ast::EqualComparison(*$1, *$3); }
    | expression "!=" expression            { $$ = new gc::ast::NotEqualComparison(*$1, *$3); }
    | expression "<=" expression            { $$ = new gc::ast::LeqComparison(*$1, *$3); }
    | expression ">=" expression            { $$ = new gc::ast::GeqComparison(*$1, *$3); }
    | expression "<"  expression            { $$ = new gc::ast::LtComparison(*$1, *$3); }
    | expression ">"  expression            { $$ = new gc::ast::GtComparison(*$1, *$3); }
    ;

location: "identifier"                      { $$ = new gc::ast::Location($1); }
    ;

expression:
      location                                                  { $$ = $1; }
    | constant                                                  { $$ = $1; }
    | "-" expression                                            { $$ = new gc::ast::Negate(*$2); }
    | expression "+" expression                                 { $$ = new gc::ast::Sum(*$1, *$3);}
    | expression "-" expression                                 { $$ = new gc::ast::Subtract(*$1, *$3); }
    | expression "*" expression                                 { $$ = new gc::ast::Multiply(*$1, *$3); }
    | expression "/" expression                                 { $$ = new gc::ast::Divide(*$1, *$3); }
    | expression "%" expression                                 { $$ = new gc::ast::Mod(*$1, *$3); }
    | "read"  "(" location "," expression ")"                   { $$ = new gc::ast::Read(*$3, *$5); }
    | "write" "(" location "," expression "," expression ")"    { $$ = new gc::ast::Write(*$3, *$5, *$7); }
    | "(" expression ")"                                        { $$ = $2;}
    ;

constant: "number"                          { $$ = new gc::ast::Constant($1); }
    ;

identifiers:
      "identifier"                          { $$ = {$1}; }
    | identifiers "identifier"              { $$ = enlist($1, $2); }
    ;
%%

void
gc::gc_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
