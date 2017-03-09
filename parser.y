%{
void yyerror(const char *str){fprintf(stderr,"Ooops! -> %s\n",str);}
#include <stdio.h>     
#include <stdlib.h>
std::string postfix  =  "";
bool Snoop = false;
%}
%token PLUS MULT OPEN CLOSE
%%
S:E 
;
E:E PLUS T  {postfix+="+";}
| 
T
; 
T:T MULT F    {postfix+="*";}
|
F
;
F:'a' {postfix+="a";}
|
'b' {postfix+="b";}
|
OPEN E CLOSE {Snoop = true;}
;
%%                   

