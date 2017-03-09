%{
#include "parser.tab.h"
%}
%%
[a]			   {return 'a';}
[b]			   {return 'b';}
[ \t\n]			return 0;
\*                      return MULT;
\+                      return PLUS;
"("			return OPEN;
")"			return CLOSE;
%%
int yywrap (void) {return 1;}
