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
# include <string>
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
}

%define api.token.prefix {TOK_}

%token
  END  0  "end of file"

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
  ENDSTMT   "end"
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

%token <std::string>        IDENTIFIER "identifier"
%token <int>                NUMBER "number"
%type  <int>                aexp

%type <ast::FunctionOf>             determ_depen
%type <ast::Expression>             inform_expr
%type <ast::Term>                     inform_term

%printer { yyoutput << $$; } <*>;

%%

%start prog;
unit: assignments aexp          { driver.result = $2; };

assignments:
  %empty                        {}
| assignments assignment        {};

assignment:
  "identifier" ":=" aexp        { driver.variables[$1] = $3; };

%precedence "!";
%precedence "&&";
%precedence "||";
%left "+" "-";
%left "*" "/";

aexp:
      "identifier"              { $$ = driver.variables[$1]; }
    | "number"                  { std::swap ($$, $1); };
    | "identifier" "[" aexp "]" {}
    | "-" aexp {}
    | aexp "+" aexp             { $$ = $1 + $3; }
    | aexp "-" aexp             { $$ = $1 - $3; }
    | aexp "*" aexp             { $$ = $1 * $3; }
    | aexp "/" aexp             { $$ = $1 / $3; }
    | aexp "%" aexp             { $$ = $1 / $3; }
    | "(" aexp ")"              { std::swap ($$, $2); }
    ;

comp:
      aexp "="  aexp
    | aexp "!=" aexp
    | aexp "<=" aexp
    | aexp ">=" aexp
    | aexp "<"  aexp
    | aexp ">"  aexp
    ;

bexp:
      comp
    | "!" bexp
    | bexp "||" bexp
    | bexp "&&" bexp
    | "(" bexp ")"
    ;

stmt:
      "identifier" ":=" aexp ";"
    | "identifier" "," "identifier" ":=" aexp "," aexp ";"
    | "identifier" "[" aexp "]" ":=" aexp ";"
    | "if" bexp "then" block "else" block "end"
    | "if" bexp "then" block "end"
    | "while" bexp inv_list "do" block "end"
    ;

inv:
      "inv" assn
    ;

inv_list:
      inv
    | inv_list inv
    ;

block:
      stmt_list
    ;

stmt_list:
      stmt
    | stmt_list stmt
    ;

prog: "program" "identifier" pre_list post_list "is" block "end"
    ;

pre: "pre" assn
    ;

pre_list:
      pre
    | pre_list pre
    ;

post: "post" assn
    ;

post_list:
      post
    | post_list post
    ;

assn:
      comp
    | "!" assn
    | assn "||" assn
    | assn "&&" assn
    | assn "==>" assn
    | "forall" identifier_list "," assn
    | "exists" identifier_list "," assn
    | "(" assn ")"
    ;

identifier_list:
      "identifier"
    | identifier_list "identifier"
    ;
%%

void
yy::vcgen_parser::error (const location_type& l, const std::string& m)
{
  driver.error (l, m);
}
