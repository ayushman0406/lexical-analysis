%{
    /* Definition section */
    #include <stdio.h>
%}


%%

([0-9A-Fa-f]{2}([-:])){5}[0-9A-Fa-f]{2} { 
    printf("\nMAC Address Valid\n"); 
}


([0-9A-Fa-f]{4}\.){2}[0-9A-Fa-f]{4} { 
    printf("\nMAC Address Valid\n"); 
}


.+ { 
    printf("\nMAC Address Invalid\n"); 
}

%%

int main() 
{
    printf("Enter MAC Address: ");
    yylex();
    printf("\n");
    return 0;
}
