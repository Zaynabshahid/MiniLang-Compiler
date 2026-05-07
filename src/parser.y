%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

class ASTNode;   

extern int yylex();
void yyerror(const char *s);

ASTNode* root;
%}

%union
{
    int intVal;
    float floatVal;
    char* strVal;
    struct ASTNode* node; 
}

%token INT_KW FLOAT_KW IF_KW ELSE_KW WHILE_KW RETURN_KW FUNCTION_KW
%token PRINT
%token PLUS MINUS MULT DIV MOD ASSIGN EQ NEQ LT GT LTE GTE
%token LPAREN RPAREN LBRACE RBRACE
%token SEMICOLON COMMA

%token <intVal> NUMBER
%token <floatVal> FLOATNUM
%token <strVal> ID

%type <node> program statements statement expr term factor comparison logical_or logical_and
%type <node> decl_stmt assignment print_stmt if_stmt else_part while_stmt block func_decl func_call return_stmt
%type <node> param_list arg_list

%%

program:
    statements
    {
        root = $1;
    }
;

statements:
      statements statement
      {
          $$ = $1;
          $$->addChild($2);
      }
    | statement
      {
          $$ = new ASTNode("STATEMENTS");
          $$->addChild($1);
      }
;

statement:
      decl_stmt
      {
          $$ = $1;
      }
    | assignment
      {
          $$ = $1;
      }
    | print_stmt
      {
          $$ = $1;
      }
    | if_stmt
      {
          $$ = $1;
      }
    | while_stmt
      {
          $$ = $1;
      }
    | func_decl
      {
          $$ = $1;
      }
    | return_stmt
      {
          $$ = $1;
      }
;

decl_stmt:
    INT_KW ID SEMICOLON
    {
        ASTNode* node = new ASTNode("DECL_INT");
        node->addChild(new ASTNode("ID", $2));
        $$ = node;
    }
    | INT_KW ID ASSIGN expr SEMICOLON
    {
        ASTNode* node = new ASTNode("DECL_INT");
        node->addChild(new ASTNode("ID", $2));
        node->addChild($4);
        $$ = node;
    }
    | FLOAT_KW ID SEMICOLON
    {
        ASTNode* node = new ASTNode("DECL_FLOAT");
        node->addChild(new ASTNode("ID", $2));
        $$ = node;
    }
    | FLOAT_KW ID ASSIGN expr SEMICOLON
    {
        ASTNode* node = new ASTNode("DECL_FLOAT");
        node->addChild(new ASTNode("ID", $2));
        node->addChild($4);
        $$ = node;
    }
;

assignment:
    ID ASSIGN expr SEMICOLON
    {
        ASTNode* node = new ASTNode("ASSIGN");
        node->addChild(new ASTNode("ID", $1));
        node->addChild($3);
        $$ = node;
    }
;

print_stmt:
    PRINT LPAREN expr RPAREN SEMICOLON
    {
        ASTNode* node = new ASTNode("PRINT");
        node->addChild($3);
        $$ = node;
    }
;

if_stmt:
    IF_KW LPAREN logical_or RPAREN block else_part
    {
        ASTNode* node = new ASTNode("IF");
        node->addChild($3);
        node->addChild($5);
        if($6) node->addChild($6);
        $$ = node;
    }
    | IF_KW LPAREN logical_or RPAREN statement
    {
        ASTNode* node = new ASTNode("IF");
        node->addChild($3);
        node->addChild($5);
        $$ = node;
    }
;

else_part:
    ELSE_KW block
    {
        ASTNode* node = new ASTNode("ELSE");
        node->addChild($2);
        $$ = node;
    }
    | ELSE_KW statement
    {
        ASTNode* node = new ASTNode("ELSE");
        node->addChild($2);
        $$ = node;
    }
    |
    {
        $$ = nullptr;
    }
;

while_stmt:
    WHILE_KW LPAREN logical_or RPAREN block
    {
        ASTNode* node = new ASTNode("WHILE");
        node->addChild($3);
        node->addChild($5);
        $$ = node;
    }
    | WHILE_KW LPAREN logical_or RPAREN statement
    {
        ASTNode* node = new ASTNode("WHILE");
        node->addChild($3);
        node->addChild($5);
        $$ = node;
    }
;

block:
    LBRACE statements RBRACE
    {
        ASTNode* node = new ASTNode("BLOCK");
        node->addChild($2);
        $$ = node;
    }
    | LBRACE RBRACE
    {
        ASTNode* node = new ASTNode("BLOCK");
        $$ = node;
    }
;

func_decl:
    FUNCTION_KW ID LPAREN param_list RPAREN block
    {
        ASTNode* node = new ASTNode("FUNC_DECL");
        node->addChild(new ASTNode("ID", $2));
        if($4) node->addChild($4);
        node->addChild($6);
        $$ = node;
    }
    | FUNCTION_KW ID LPAREN RPAREN block
    {
        ASTNode* node = new ASTNode("FUNC_DECL");
        node->addChild(new ASTNode("ID", $2));
        node->addChild($5);
        $$ = node;
    }
;

param_list:
    INT_KW ID
    {
        ASTNode* node = new ASTNode("PARAMS");
        ASTNode* param = new ASTNode("PARAM_INT");
        param->addChild(new ASTNode("ID", $2));
        node->addChild(param);
        $$ = node;
    }
    | FLOAT_KW ID
    {
        ASTNode* node = new ASTNode("PARAMS");
        ASTNode* param = new ASTNode("PARAM_FLOAT");
        param->addChild(new ASTNode("ID", $2));
        node->addChild(param);
        $$ = node;
    }
    | param_list COMMA INT_KW ID
    {
        ASTNode* param = new ASTNode("PARAM_INT");
        param->addChild(new ASTNode("ID", $4));
        $1->addChild(param);
        $$ = $1;
    }
    | param_list COMMA FLOAT_KW ID
    {
        ASTNode* param = new ASTNode("PARAM_FLOAT");
        param->addChild(new ASTNode("ID", $4));
        $1->addChild(param);
        $$ = $1;
    }
;

return_stmt:
    RETURN_KW expr SEMICOLON
    {
        ASTNode* node = new ASTNode("RETURN");
        node->addChild($2);
        $$ = node;
    }
    | RETURN_KW SEMICOLON
    {
        ASTNode* node = new ASTNode("RETURN");
        $$ = node;
    }
;

func_call:
    ID LPAREN arg_list RPAREN
    {
        ASTNode* node = new ASTNode("FUNC_CALL");
        node->addChild(new ASTNode("ID", $1));
        if($3) node->addChild($3);
        $$ = node;
    }
    | ID LPAREN RPAREN
    {
        ASTNode* node = new ASTNode("FUNC_CALL");
        node->addChild(new ASTNode("ID", $1));
        $$ = node;
    }
;

arg_list:
    expr
    {
        ASTNode* node = new ASTNode("ARGS");
        node->addChild($1);
        $$ = node;
    }
    | arg_list COMMA expr
    {
        $1->addChild($3);
        $$ = $1;
    }
;

logical_or:
    logical_and
    {
        $$ = $1;
    }
    | logical_or EQ logical_and
    {
        ASTNode* node = new ASTNode("LOGI_OR");
        node->addChild($1);
        node->addChild($3);
        $$ = node;
    }
;

logical_and:
    comparison
    {
        $$ = $1;
    }
    | logical_and EQ comparison
    {
        ASTNode* node = new ASTNode("LOGI_AND");
        node->addChild($1);
        node->addChild($3);
        $$ = node;
    }
;

comparison:
      expr
      {
          $$ = $1;
      }
;

expr:
      expr PLUS term
      {
          ASTNode* node = new ASTNode("ADD");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | expr MINUS term
      {
          ASTNode* node = new ASTNode("SUB");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | term
      {
          $$ = $1;
      }
;

term:
      term MULT factor
      {
          ASTNode* node = new ASTNode("MUL");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | term DIV factor
      {
          ASTNode* node = new ASTNode("DIV");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | term MOD factor
      {
          ASTNode* node = new ASTNode("MOD");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor
      {
          $$ = $1;
      }
;

factor:
      NUMBER
      {
          $$ = new ASTNode("NUMBER", std::to_string($1));
      }
    | FLOATNUM
      {
          char buffer[32];
          snprintf(buffer, sizeof(buffer), "%f", $1);
          $$ = new ASTNode("FLOATNUM", buffer);
      }
    | ID
      {
          $$ = new ASTNode("ID", $1);
      }
    | func_call
      {
          $$ = $1;
      }
    | LPAREN expr RPAREN
      {
          $$ = $2;
      }
    | factor LT factor
      {
          ASTNode* node = new ASTNode("LT");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor GT factor
      {
          ASTNode* node = new ASTNode("GT");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor LTE factor
      {
          ASTNode* node = new ASTNode("LTE");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor GTE factor
      {
          ASTNode* node = new ASTNode("GTE");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor EQ factor
      {
          ASTNode* node = new ASTNode("EQ");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
    | factor NEQ factor
      {
          ASTNode* node = new ASTNode("NEQ");
          node->addChild($1);
          node->addChild($3);
          $$ = node;
      }
;

%%

void yyerror(const char *s)
{
    printf("Syntax Error: %s\n", s);
}