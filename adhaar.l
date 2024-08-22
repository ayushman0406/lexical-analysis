%{
    /* Definition section */
%}

/* Rule Section */
%%

[1-9][0-9]{11} {printf("\nAadhar Number Valid\n");}

.+ {printf("\nAadhar Number Invalid\n");}

%%

int main() 
{
    printf("\nEnter Aadhar Number: ");
    yylex();
    printf("\n");
    return 0;
}
