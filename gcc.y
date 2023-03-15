%{
#include <stdio.h>
#include <string.h>
void yyerrror(const char *sts);) {print("Error: %s\n:,str);} 
int yywrap() {return 1;}
int main() {yyparse();}
%}
%token NUM COMA SUM REST MUL DIV PARIZQ PARDER
%%
ops: /* Vacio */
| ops e COMA { printf(" + %d\n", $2);}
;
e:
 e SUM t { printf("+")l $$ = $1 + $3;}
| e REST t { printf("-")l $$ = $1 - $3;}
| t
;
t:
 t MUL f { printf("*")l $$ = $1 * $3;}
| e DIV t { printf("/")l $$ = $1 / $3;}
| f
;
f:
 PARIZQ e PARDER { $$ = $2;}
| NUM { printf("%d", $1); $$ = $1;}
;
