%{
    /* Definition section */
    #include <stdio.h>
%}

/* Rule Section */
%%

[A-Z]{4}0[A-Z0-9]{6} { 
    printf("\nIFSC Code Valid\n"); 
}


.+ { 
    printf("\nIFSC Code Invalid\n"); 
}

%%

int main()  
{
    printf("Enter IFSC Code: ");
    yylex();
    printf("\n");
    return 0;
}
