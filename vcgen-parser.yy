%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%language "c++"

%verbose                            /* Generate the parser description file. */

%defines
%define api.parser.class {vcgen_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert                /* assert correct cleanup of semantic value objects */


%code requires
{
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include "ast.hpp"
class vcgen_driver;
}

%param { vcgen_driver& driver }     /* The parsing context. */

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

template <typename T> ostream& operator<<(ostream& out, const vector<T*>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

ast::Program *program; /* the top level root node of our final AST */

void clear_stack ();
stack <ast::Node*> nodes;
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

%type <ast::ArithmeticExpression*>       aexp
%type <ast::Comparison*>                 comp
%type <ast::BooleanExpression*>          bexp
%type <ast::Statement*>                  stmt
%type <ast::Invariant*>                  inv
%type <ast::Block*>                      block
%type <ast::Program*>                    prog
%type <ast::PreCondition*>               pre
%type <ast::PostCondition*>              post
%type <ast::Assertion*>                  assertion
%type <ast::Location*>                   location
%type <ast::Reference*>                  reference
%type <ast::Constant*>                   constant

%type <std::vector<ast::Invariant*>>     inv_list;
%type <std::vector<ast::Statement*>>     stmt_list;
%type <std::vector<ast::PreCondition*>>  pre_list;
%type <std::vector<ast::PostCondition*>> post_list;
%type <std::vector<std::string>>         identifier_list;


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
    | reference "[" aexp "]"    { $$ = new ast::ArrayReference(*$1, *$3); }
    | constant                  { $$ = $1; }
    | "-" aexp                  { $$ = new ast::Negate(*$2); }
    | aexp "+" aexp             { $$ = new ast::Sum(*$1, *$3);}
    | aexp "-" aexp             { $$ = new ast::Subtract(*$1, *$3); }
    | aexp "*" aexp             { $$ = new ast::Multiply(*$1, *$3); }
    | aexp "/" aexp             { $$ = new ast::Divide(*$1, *$3); }
    | aexp "%" aexp             { $$ = new ast::Mod(*$1, *$3); }
    | "(" aexp ")"              { $$ = $2;}
    ;

reference: "identifier"         { $$ = new ast::Reference($1); }
    ;

constant: "number"              { $$ = new ast::Constant($1); }
    ;

bexp:
      comp                      { $$ = $1; }
    | "!" bexp                  { $$ = new ast::NotExpression(*$2); }
    | bexp "||" bexp            { $$ = new ast::OrExpression(*$1, *$3); }
    | bexp "&&" bexp            { $$ = new ast::AndExpression(*$1, *$3); }
    | "(" bexp ")"              { $$ = $2;}
    ;

comp:
      aexp "="  aexp            { $$ = new ast::EqualComparison(*$1, *$3); }
    | aexp "!=" aexp            { $$ = new ast::NotEqualComparison(*$1, *$3); }
    | aexp "<=" aexp            { $$ = new ast::LeqComparison(*$1, *$3); }
    | aexp ">=" aexp            { $$ = new ast::GeqComparison(*$1, *$3); }
    | aexp "<"  aexp            { $$ = new ast::LtComparison(*$1, *$3); }
    | aexp ">"  aexp            { $$ = new ast::GtComparison(*$1, *$3); }
    ;

stmt:
      location ":=" aexp ";"                        { $$ = new ast::AssignmentStatement(*$1, *$3);}
    | location "," location ":=" aexp "," aexp ";"  { $$ = new ast::MultipleAssignmentStatement(*$1, *$3, *$5, *$7);}
    | location "[" aexp "]" ":=" aexp ";"           { $$ = new ast::ArrayAssignmentStatement(*$1, *$3, *$6);}
    | "if" bexp "then" block "else" block "end"     { $$ = new ast::IfThenElseStatement(*$2, *$4, *$6);}
    | "if" bexp "then" block "end"                  { $$ = new ast::IfThenStatement(*$2, *$4);}
    | "while" bexp inv_list "do" block "end"        { $$ = new ast::WhileStatement(*$2, $3, *$5);}
    ;

location: "identifier"  { $$ = new ast::Location($1); }
    ;

inv_list:
      inv               { $$ = {$1}; }
    | inv_list inv      { $$ = enlist($1, $2); }
    ;

inv: "inv" assertion   { $$ = new ast::Invariant(*$2); }
    ;

block: stmt_list        { $$ = new ast::Block($1); /*print<ast::Statement>($1);*/}
    ;

stmt_list:
      stmt              { $$ = {$1};}
    | stmt_list stmt    { $$ = enlist($1, $2); }
//  | error "\n"        { }
    ;

prog: "program" "identifier" pre_list post_list "is" block "end"
      { $$ = new ast::Program($2, $3, $4, *$6); driver.program = $$;}
    | error "\n"
      { clear_stack (); }
    ;

pre_list:
      pre                   { $$ = {$1}; }
    | pre_list pre          { $$ = enlist($1, $2); }
    ;

pre: "pre" assertion        { $$ = new ast::PreCondition(*$2); }
    ;

post_list:
      post                  { $$ = {$1}; }
    | post_list post        { $$ = enlist($1, $2); }
    ;

post: "post" assertion      { $$ = new ast::PostCondition(*$2); }
    ;

assertion:
      comp                                      { $$ = $1; }
    | "!" assertion                             { $$ = new ast::Negation(*$2); }
    | assertion "||" assertion                  { $$ = new ast::Disjunction(*$1, *$3); }
    | assertion "&&" assertion                  { $$ = new ast::Conjunction(*$1, *$3); }
    | assertion "==>" assertion                 { $$ = new ast::Implication(*$1, *$3); }
    | "forall" identifier_list "," assertion    { $$ = new ast::UniversalQuantification($2, *$4); print<std::string>($2); }
    | "exists" identifier_list "," assertion    { $$ = new ast::ExistentialQuantification($2, *$4); print<std::string>($2); }
    | "(" assertion ")"                         { $$ = $2; }
    | "(" error ")"                             {  }
    ;

identifier_list:
      "identifier"                              { $$ = {$1}; }
    | identifier_list "identifier"              { $$ = enlist($1, $2); }
    ;
%%

void
yy::vcgen_parser::error (const location_type& l, const std::string& m)
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