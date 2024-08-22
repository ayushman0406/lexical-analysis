%{
#include <stdio.h>
%}

letter [a-zA-Z]
digit [0-9]
id {letter}({letter}|{digit})*
numbers {digit}+.{digit}+?(E[-+]?{digit}+)? 

%%

id                       {printf("\n%s is an identifier",yytext);}
if|else|printf|#include|<stdio.h>|main|int|float|char  {printf("\n%s is a keyword",yytext);}
"=="|"!="|"<="|">="|"<"|">"  {printf("\n%s is a relational operator",yytext);}
{numbers}                 {printf("\n %s is a number or constant",yytext);}
"+"|"-"|"*"|"/"|"|"|"%"   {printf("\n %s is an operator",yytext);}
"("|")"|"{"|"}"|"["|"]"   {printf("\n %s is a separator",yytext);}

%%

int main(int argc, char** argv)
{
    FILE* file = fopen("add.c","r");
    if (!file) {
        printf("Error: cannot open file %s\n", "sample.c");
        return 1;
    }
    yyin = file;
    yylex();
    printf("\n\n");
    fclose(file);
    return 0;
}

int yywrap() {
    return 1;
}
