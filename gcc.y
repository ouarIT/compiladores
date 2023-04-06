%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *s) { printf("Error: %s\n", s); };
int yywrap() {return 1;}
int main() { yyparse(); }
%}
%token D0 D1 D2 D3 D4 D5 D6 D7 D8 D9
%token SUM RES MUL DIV PARIZQ PARDER COMA
%%
ops:
    | ops e COMA
    ;
e:
    e SUM { printf(" + "); } t
    | e RES { printf(" - "); } t
    | t
    ;
t:
    t MUL { printf(" * "); } f
    | t DIV { printf(" / "); } f
    | f
    ;
f:
    PARIZQ e PARDER
    | n
    ;
n:
    D0 { printf("0"); }
    | D1 { printf("1"); }
    | D2 { printf("2"); }
    | D3 { printf("3"); }
    | D4 { printf("4"); }
    | D5 { printf("5"); }
    | D6 { printf("6"); }
    | D7 { printf("7"); }
    | D8 { printf("8"); }
    | D9 { printf("9"); }
    ;
