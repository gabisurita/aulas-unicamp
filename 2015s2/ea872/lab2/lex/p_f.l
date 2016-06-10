
Var     $.*[ ]
Comment #.*\n

%%
{Var}           ECHO;
{Comment}       {if(yytext[1]=='!')printf("%s",yytext);}
.               ECHO;
%%
