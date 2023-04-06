%{
#include <stdio.h>
#include <y.tab.h>
%}
%%
"0" { return D0; }
"1" { return D1; }
"2" { return D2; }
"3" { return D3; }
"4" { return D4; }
"5" { return D5; }
"6" { return D6; }
"7" { return D7; }
"8" { return D8; }
"9" { return D9; }
"+" { return SUM; }
"-" { return RES; }
"*" { return MUL; }
"/" { return DIV; }
"(" { return PARIZQ; }
")" { return PARDER; }
";" { return COMA; }
%%
