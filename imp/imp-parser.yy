%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

%verbose                            /* Generate the parser description file. */

%defines
%define api.parser.class {imp_parser}
%define api.namespace {imp}
%define api.prefix {imp}
%define api.token.constructor
%define api.value.type variant
%define parse.assert                /* assert correct cleanup of semantic value objects */


%code requires
{
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include "../ast/imp.hpp"
class imp_driver;
}

%param { imp_driver& driver }       /* The parsing context. */

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
# include "../imp-driver.hpp"

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
  EQUAL     "="
  NEQUAL    "!="
  LEQ       "<="
  GEQ       ">="
  LT        "<"
  GT        ">"
  NOT       "!"
  OR        "||"
  AND       "&&"
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
  PROGRAM   "program"
  PRE       "pre"
  POST      "post"
  IS        "is"
  IMPLY     "==>"
  ALL       "forall"
  SOME      "exists"

;

%token <std::string>    IDENTIFIER "identifier"
%token <int>            NUMBER "number"

%type <imp::ast::ArithmeticExpression*>       aexp
%type <imp::ast::Comparison*>                 comp
%type <imp::ast::BooleanExpression*>          bexp
%type <imp::ast::Statement*>                  stmt
%type <imp::ast::Invariant*>                  inv
%type <imp::ast::Block*>                      block
%type <imp::ast::Program*>                    prog
%type <imp::ast::PreCondition*>               pre
%type <imp::ast::PostCondition*>              post
%type <imp::ast::Assertion*>                  assertion
%type <imp::ast::Location*>                   location
%type <imp::ast::Reference*>                  reference
%type <imp::ast::Constant*>                   constant

%type <std::vector<imp::ast::Invariant*>>     inv_list;
%type <std::vector<imp::ast::Statement*>>     stmt_list;
%type <std::vector<imp::ast::PreCondition*>>  pre_list;
%type <std::vector<imp::ast::PostCondition*>> post_list;
%type <std::vector<std::string>>              identifier_list;


//%printer { yyoutput << $$; } <*>;

%%

%start prog;

//%precedence "then";
//%precedence "else";
//%right "then" "else";

%precedence "==>";
%precedence "||";
%precedence "&&";
%precedence "!";
//%left "<" ">" "=" "!=" "<=" ">=";
%left "+" "-";
%left "*" "/";

aexp:
      reference                 { $$ = $1; }
    | reference "[" aexp "]"    { $$ = new imp::ast::ArrayReference(*$1, *$3); }
    | constant                  { $$ = $1; }
    | "-" aexp                  { $$ = new imp::ast::Negate(*$2); }
    | aexp "+" aexp             { $$ = new imp::ast::Sum(*$1, *$3);}
    | aexp "-" aexp             { $$ = new imp::ast::Subtract(*$1, *$3); }
    | aexp "*" aexp             { $$ = new imp::ast::Multiply(*$1, *$3); }
    | aexp "/" aexp             { $$ = new imp::ast::Divide(*$1, *$3); }
    | aexp "%" aexp             { $$ = new imp::ast::Mod(*$1, *$3); }
    | "(" aexp ")"              { $$ = $2;}
    ;

reference: "identifier"         { $$ = new imp::ast::Reference($1); }
    ;

constant: "number"              { $$ = new imp::ast::Constant($1); }
    ;

bexp:
      comp                      { $$ = $1; }
    | "!" bexp                  { $$ = new imp::ast::NotExpression(*$2); }
    | bexp "||" bexp            { $$ = new imp::ast::OrExpression(*$1, *$3); }
    | bexp "&&" bexp            { $$ = new imp::ast::AndExpression(*$1, *$3); }
    | "(" bexp ")"              { $$ = $2;}
    ;

comp:
      aexp "="  aexp            { $$ = new imp::ast::EqualComparison(*$1, *$3); }
    | aexp "!=" aexp            { $$ = new imp::ast::NotEqualComparison(*$1, *$3); }
    | aexp "<=" aexp            { $$ = new imp::ast::LeqComparison(*$1, *$3); }
    | aexp ">=" aexp            { $$ = new imp::ast::GeqComparison(*$1, *$3); }
    | aexp "<"  aexp            { $$ = new imp::ast::LtComparison(*$1, *$3); }
    | aexp ">"  aexp            { $$ = new imp::ast::GtComparison(*$1, *$3); }
    ;

stmt:
      location ":=" aexp ";"                        { $$ = new imp::ast::AssignmentStatement(*$1, *$3);}
    | location "," location ":=" aexp "," aexp ";"  { $$ = new imp::ast::MultipleAssignmentStatement(*$1, *$3, *$5, *$7);}
    | location "[" aexp "]" ":=" aexp ";"           { $$ = new imp::ast::ArrayAssignmentStatement(*$1, *$3, *$6);}
    | "if" bexp "then" block "else" block "end"     { $$ = new imp::ast::IfThenElseStatement(*$2, *$4, *$6);}
    | "if" bexp "then" block "end"                  { $$ = new imp::ast::IfThenStatement(*$2, *$4);}
    | "while" bexp inv_list "do" block "end"        { $$ = new imp::ast::WhileStatement(*$2, $3, *$5);}
    | "while" bexp "do" block "end"                 { std::vector<imp::ast::Invariant*> inv;
                                                      $$ = new imp::ast::WhileStatement(*$2, inv, *$4);}
    ;

location: "identifier"  { $$ = new imp::ast::Location($1, driver.fresh($1));}
    ;

inv_list:
      inv               { $$ = {$1}; }
    | inv_list inv      { $$ = enlist($1, $2); }
    ;

inv: "inv" assertion    { $$ = new imp::ast::Invariant(*$2); }
    ;

block: stmt_list        { $$ = new imp::ast::Block($1); /*print<imp::ast::Statement>($1);*/}
    ;

stmt_list:
      stmt              { $$ = {$1};}
    | stmt_list stmt    { $$ = enlist($1, $2); }
//  | error "\n"        { }
    ;

prog: "program" "identifier" pre_list post_list "is" block "end"
      { $$ = new imp::ast::Program($2, $3, $4, *$6); driver.program = $$;}
    | "program" "identifier" post_list "is" block "end"
      { std::vector<imp::ast::PreCondition*> pre;
        $$ = new imp::ast::Program($2, pre, $3, *$5); driver.program = $$;}
    | "program" "identifier" pre_list "is" block "end"
      { std::vector<imp::ast::PostCondition*> post;
        $$ = new imp::ast::Program($2, $3, post, *$5); driver.program = $$;}
    | "program" "identifier" "is" block "end"
      { std::vector<imp::ast::PreCondition*> pre;
        std::vector<imp::ast::PostCondition*> post;
        $$ = new imp::ast::Program($2, pre, post, *$4); driver.program = $$;}
    ;

pre_list:
      pre                   { $$ = {$1}; }
    | pre_list pre          { $$ = enlist($1, $2); }
    ;

pre: "pre" assertion        { $$ = new imp::ast::PreCondition(*$2); }
    ;

post_list:
      post                  { $$ = {$1}; }
    | post_list post        { $$ = enlist($1, $2); }
    ;

post: "post" assertion      { $$ = new imp::ast::PostCondition(*$2); }
    ;

assertion:
      comp                                      { $$ = $1; }
    | "!" assertion                             { $$ = new imp::ast::Negation(*$2); }
    | assertion "||" assertion                  { $$ = new imp::ast::Disjunction(*$1, *$3); }
    | assertion "&&" assertion                  { $$ = new imp::ast::Conjunction(*$1, *$3); }
    | assertion "==>" assertion                 { $$ = new imp::ast::Implication(*$1, *$3); }
    | "forall" identifier_list "," assertion    { $$ = new imp::ast::UniversalQuantifier($2, *$4); /*print<std::string>($2);*/ }
    | "exists" identifier_list "," assertion    { $$ = new imp::ast::ExistentialQuantifier($2, *$4); /*print<std::string>($2);*/ }
    | "(" assertion ")"                         { $$ = $2; }
    | "(" error ")"                             {  }
    ;

identifier_list:
      "identifier"                              { $$ = {$1}; }
    | identifier_list "identifier"              { $$ = enlist($1, $2); }
    ;
%%

void
imp::imp_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}