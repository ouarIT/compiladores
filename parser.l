%{
#include <stdio.h>
%}

%%
(DO|WHILE|FOR|IF)       printf("keyword: [%s] ", yytext);
(SCAN|PRINT)            printf("Function: [%s] ", yytext);
(INT)                printf("Type: [%s] ", yytext);
(<|>)         printf("Condicion: [%s] ", yytext);
(=|\+)         printf("Aritmetico: [%s] ", yytext);
[0-9]+                  printf("numero: [%s] ", yytext);
%%
int yywrap() { return 1; }

int main(int argc, char **argv) {
    extern FILE *yyin;
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
    yylex();
    fclose(yyin);
    return 0;
}
