%{
#include <stdio.h>
#include "limbaj.tab.h"

%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {yylval.string = strdup(yytext);return TYPE;}
"const" {return CONST;}
"eval" {return EVAL;}
"typeOf" {return TOF;}
"true" {yylval.bool_value = true; return BOO;}
"false" {yylval.bool_value = false; return BOO;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"return" {return RETURN;}
"void" {return VOID;}
"class" {return CLASS;}
"new" {return NEW;}
\+ {return PLU;}
\- {return MIN;}
\* {return TIM;}
\/ {return DVD;}
\< {return LT;}
\> {return GT;}
\<= {return LET;}
\>= {return GET;}
\!= {return NOE;}
\! {return NEG;}
(==) {return BEQ;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
"{" {return OPENBRK;}
"}" {return CLOSEDBRK;}
[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
":=" {return ASSIGN;}
\"([^"]*)\" {yylval.string = strdup(yytext); return STR;}
\'([^'])\' {yylval.char_value = yytext[1]; return CHR;}
0|([1-9][0-9]*) {yylval.integer_value = atoi(yytext); return NR;}
(([0-9]|[1-9][0-9]+)\.([0-9][0-9]*)) {yylval.float_value = atof(yytext); return FLT;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 