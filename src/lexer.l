%option noyywrap

%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int line_num = 1;

int myHash(char *str)
{
    int h = 0;
    while(*str)
    {
        h = (h * 31 + *str) % 1000;
        str++;
    }
    return h;
}
%}

%%

"int"       { return INT_KW; }
"float"     { return FLOAT_KW; }
"if"        { return IF_KW; }
"else"      { return ELSE_KW; }
"while"     { return WHILE_KW; }
"return"    { return RETURN_KW; }
"function"  { return FUNCTION_KW; }
"print"     { return PRINT; }

"+"  { return PLUS; }
"-"  { return MINUS; }
"*"  { return MULT; }
"/"  { return DIV; }
"%"  { return MOD; }

"="  { return ASSIGN; }
"==" { return EQ; }
"!=" { return NEQ; }
"<"  { return LT; }
">"  { return GT; }
"<=" { return LTE; }
">=" { return GTE; }

"{"  { return LBRACE; }
"}"  { return RBRACE; }
"("  { return LPAREN; }
")"  { return RPAREN; }
";"  { return SEMICOLON; }
","  { return COMMA; }

[0-9]+"."[0-9]+ { 
    yylval.floatVal = atof(yytext); 
    printf("TOKEN FLOAT: %s\n", yytext); 
    return FLOATNUM; 
}

[0-9]+ { 
    yylval.intVal = atoi(yytext); 
    printf("TOKEN NUMBER: %s\n", yytext); 
    return NUMBER; 
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.strVal = _strdup(yytext); 
    printf("TOKEN ID: %s | HASH: %d\n", yytext, myHash(yytext)); 
    return ID; 
}

[ \t]+ ;

\n { line_num++; }

. { printf("Lexical Error at line %d: %s\n", line_num, yytext); }

%%