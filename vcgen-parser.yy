%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

/* Generate the parser description file. */
%verbose

%defines
%define api.parser.class {vcgen_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert


%code requires
{
#include <string>
#include <vector>
#include <iterator>
#include "ast.hpp"
class vcgen_driver;
}

// The parsing context.
%param { vcgen_driver& driver }
%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace
%define parse.error verbose

%code
{
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



}

%define api.token.prefix {TOK_}

%token
  EOF  0  "end of file"

/* Arithmetic Expressions (AEXP)*/

  PLUS      "+"
  MINUS     "-"
  STAR      "*"   /* MULT */
  SLASH     "/"   /* DIV */
  MOD       "%"
  LPAREN    "("
  RPAREN    ")"

/* Program Conditions (COMP)*/

  EQUAL     "="
  NEQUAL    "!="
  LEQ       "<="
  GEQ       ">="
  LT        "<"
  GT        ">"

/* Boolean Expressions (BEXP)*/

  NOT       "!"
  OR        "||"
  AND       "&&"

/* Program Statements (STMT) */

  ASSIGN    ":="
  SEMICOLON ";"
  COMMA     ","
  IF        "if"
  THEN      "then"
  ELSE      "else"
  END       "end"
  WHILE     "while"
  DO        "do"
  INV       "inv"
  LSQUARE   "["
  RSQUARE   "]"

/* Program */

  PROGRAM   "program"
  PRE       "pre"
  POST      "post"
  IS        "is"

/* Assertions */

  IFF       "==>"
  ALL       "forall"
  SOME      "exists"

;

%token <std::string>    IDENTIFIER "identifier"
%token <int>            NUMBER "number"

%type <ast::ArithmeticExpression>       aexp
%type <ast::Comparison>                 comp
%type <ast::BooleanExpression>          bexp
%type <ast::Statement>                  stmt
%type <ast::Invariant>                  inv
%type <ast::Block>                      block
%type <ast::Program>                    prog
%type <ast::PreCondition>               pre
%type <ast::PostCondition>              post
%type <ast::Assertion>                  assertion

%type <std::vector<ast::Invariant>>     inv_list;
%type <std::vector<ast::Statement>>     stmt_list;
%type <std::vector<ast::PreCondition>>  pre_list;
%type <std::vector<ast::PostCondition>> post_list;
%type <std::vector<std::string>>        identifier_list;


//%printer { yyoutput << $$; } <*>;

%%

%start prog;

%precedence "!";
%precedence "&&";
%precedence "||";
%left "+" "-";
%left "*" "/";

aexp:
      "identifier"              { }
    | "number"                  { }
    | "identifier" "[" aexp "]" { }
    | "-" aexp                  { }
    | aexp "+" aexp             { }
    | aexp "-" aexp             { }
    | aexp "*" aexp             { }
    | aexp "/" aexp             { }
    | aexp "%" aexp             { }
    | "(" aexp ")"              { $$ = $2;}
    ;

bexp:
      comp                      { }
    | "!" bexp                  { }
    | bexp "||" bexp            { }
    | bexp "&&" bexp            { }
    | "(" bexp ")"              { $$ = $2;}
    ;

comp:
      aexp "="  aexp            { }
    | aexp "!=" aexp            { }
    | aexp "<=" aexp            { }
    | aexp ">=" aexp            { }
    | aexp "<"  aexp            { }
    | aexp ">"  aexp            { }
    ;

stmt:
      "identifier" ":=" aexp ";"                            { }
    | "identifier" "," "identifier" ":=" aexp "," aexp ";"  { }
    | "identifier" "[" aexp "]" ":=" aexp ";"               { }
    | "if" bexp "then" block "else" block "end"             { }
    | "if" bexp "then" block "end"                          { }
    | "while" bexp inv_list "do" block "end"                { }
    ;

inv:
      "inv" assertion        { }
    ;

inv_list:
      inv               { }
    | inv_list inv      { }
    ;

block:
      stmt_list         { }
    ;

stmt_list:
      stmt              { }
    | stmt_list stmt    { }
    ;

prog: "program" "identifier" pre_list post_list "is" block "end"
                            { }
    ;

pre: "pre" assertion        { }
    ;

pre_list:
      pre                   { }
    | pre_list pre          { }
    ;

post: "post" assertion      { }
    ;

post_list:
      post                  { }
    | post_list post        { }
    ;

assertion:
      comp                                      { }
    | "!" assertion                             { }
    | assertion "||" assertion                  { }
    | assertion "&&" assertion                  { }
    | assertion "==>" assertion                 { }
    | "forall" identifier_list "," assertion    { print<std::string>($2);}
    | "exists" identifier_list "," assertion    { print<std::string>($2);}
    | "(" assertion ")"                         { $$ = $2;}
    ;

identifier_list:
      "identifier"                      { $$ = {$1};}
    | identifier_list "identifier"      { $$ = enlist($1, $2);}
    ;
%%

void
yy::vcgen_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}