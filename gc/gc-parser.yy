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
#include "gc.hpp"
class gc_driver;
}

%param { gc_driver& driver }       /* The parsing context. */

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

  IMPLY     "==>"
  ALL       "forall"
  SOME      "exists"

;

%token <std::string>    IDENTIFIER "identifier"
%token <int>            NUMBER "number"

%type <gc::ast::ArithmeticExpression*>       aexp
%type <gc::ast::Comparison*>                 comp
%type <gc::ast::BooleanExpression*>          bexp
%type <gc::ast::Statement*>                  stmt
%type <gc::ast::Invariant*>                  inv
%type <gc::ast::Block*>                      block
%type <gc::ast::Program*>                    prog
%type <gc::ast::PreCondition*>               pre
%type <gc::ast::PostCondition*>              post
%type <gc::ast::Assertion*>                  assertion
%type <gc::ast::Location*>                   location
%type <gc::ast::Reference*>                  reference
%type <gc::ast::Constant*>                   constant

%type <std::vector<gc::ast::Invariant*>>     inv_list;
%type <std::vector<gc::ast::Statement*>>     stmt_list;
%type <std::vector<gc::ast::PreCondition*>>  pre_list;
%type <std::vector<gc::ast::PostCondition*>> post_list;
%type <std::vector<std::string>>             identifier_list;


//%printer { yyoutput << $$; } <*>;

%%

%start prog;

%precedence "!";
%precedence "&&";
%precedence "||";
%left "+" "-";
%left "*" "/";

aexp:
      reference                 { $$ = $1; }
    | reference "[" aexp "]"    { $$ = new gc::ast::ArrayReference(*$1, *$3); }
    | constant                  { $$ = $1; }
    | "-" aexp                  { $$ = new gc::ast::Negate(*$2); }
    | aexp "+" aexp             { $$ = new gc::ast::Sum(*$1, *$3);}
    | aexp "-" aexp             { $$ = new gc::ast::Subtract(*$1, *$3); }
    | aexp "*" aexp             { $$ = new gc::ast::Multiply(*$1, *$3); }
    | aexp "/" aexp             { $$ = new gc::ast::Divide(*$1, *$3); }
    | aexp "%" aexp             { $$ = new gc::ast::Mod(*$1, *$3); }
    | "(" aexp ")"              { $$ = $2;}
    ;

reference: "identifier"         { $$ = new gc::ast::Reference($1); }
    ;

constant: "number"              { $$ = new gc::ast::Constant($1); }
    ;

bexp:
      comp                      { $$ = $1; }
    | "!" bexp                  { $$ = new gc::ast::NotExpression(*$2); }
    | bexp "||" bexp            { $$ = new gc::ast::OrExpression(*$1, *$3); }
    | bexp "&&" bexp            { $$ = new gc::ast::AndExpression(*$1, *$3); }
    | "(" bexp ")"              { $$ = $2;}
    ;

comp:
      aexp "="  aexp            { $$ = new gc::ast::EqualComparison(*$1, *$3); }
    | aexp "!=" aexp            { $$ = new gc::ast::NotEqualComparison(*$1, *$3); }
    | aexp "<=" aexp            { $$ = new gc::ast::LeqComparison(*$1, *$3); }
    | aexp ">=" aexp            { $$ = new gc::ast::GeqComparison(*$1, *$3); }
    | aexp "<"  aexp            { $$ = new gc::ast::LtComparison(*$1, *$3); }
    | aexp ">"  aexp            { $$ = new gc::ast::GtComparison(*$1, *$3); }
    ;

stmt:
      location ":=" aexp ";"                        { $$ = new gc::ast::AssignmentStatement(*$1, *$3);}
    | location "," location ":=" aexp "," aexp ";"  { $$ = new gc::ast::MultipleAssignmentStatement(*$1, *$3, *$5, *$7);}
    | location "[" aexp "]" ":=" aexp ";"           { $$ = new gc::ast::ArrayAssignmentStatement(*$1, *$3, *$6);}
    | "if" bexp "then" block "else" block "end"     { $$ = new gc::ast::IfThenElseStatement(*$2, *$4, *$6);}
    | "if" bexp "then" block "end"                  { $$ = new gc::ast::IfThenStatement(*$2, *$4);}
    | "while" bexp inv_list "do" block "end"        { $$ = new gc::ast::WhileStatement(*$2, $3, *$5);}
    ;

location: "identifier"  { $$ = new gc::ast::Location($1); }
    ;

inv_list:
      inv               { $$ = {$1}; }
    | inv_list inv      { $$ = enlist($1, $2); }
    ;

inv: "inv" assertion   { $$ = new gc::ast::Invariant(*$2); }
    ;

block: stmt_list        { $$ = new gc::ast::Block($1); /*print<gc::ast::Statement>($1);*/}
    ;

stmt_list:
      stmt              { $$ = {$1};}
    | stmt_list stmt    { $$ = enlist($1, $2); }
//  | error "\n"        { }
    ;

prog: "program" "identifier" pre_list post_list "is" block "end"
      { $$ = new gc::ast::Program($2, $3, $4, *$6); driver.program = $$;}
    ;

pre_list:
      pre                   { $$ = {$1}; }
    | pre_list pre          { $$ = enlist($1, $2); }
    ;

pre: "pre" assertion        { $$ = new gc::ast::PreCondition(*$2); }
    ;

post_list:
      post                  { $$ = {$1}; }
    | post_list post        { $$ = enlist($1, $2); }
    ;

post: "post" assertion      { $$ = new gc::ast::PostCondition(*$2); }
    ;

assertion:
      comp                                      { $$ = $1; }
    | "!" assertion                             { $$ = new gc::ast::Negation(*$2); }
    | assertion "||" assertion                  { $$ = new gc::ast::Disjunction(*$1, *$3); }
    | assertion "&&" assertion                  { $$ = new gc::ast::Conjunction(*$1, *$3); }
    | assertion "==>" assertion                 { $$ = new gc::ast::Implication(*$1, *$3); }
    | "forall" identifier_list "," assertion    { $$ = new gc::ast::UniversalQuantification($2, *$4); /*print<std::string>($2);*/ }
    | "exists" identifier_list "," assertion    { $$ = new gc::ast::ExistentialQuantification($2, *$4); /*print<std::string>($2);*/ }
    | "(" assertion ")"                         { $$ = $2; }
    | "(" error ")"                             {  }
    ;

identifier_list:
      "identifier"                              { $$ = {$1}; }
    | identifier_list "identifier"              { $$ = enlist($1, $2); }
    ;
%%

void
gc::gc_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
