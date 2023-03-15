%{
#include <stdio.h>
#include <y.tab.h>
%}
%%
[0-9] {yylval = atoi(yytext); return NUM;}
";" {return COMA;}
"+" {return SUMA;}
"-" {return RES;}
"*" {return MUL;}
"/" {return DIV;}
"(" {return PARIZQ;}
")" {return PARDER;}
%%
