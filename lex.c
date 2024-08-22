#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "printf"
};


int isKeyword(const char *str) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


void categorize(const char *code) {
    char buffer[100];
    int i = 0, j = 0;


    printf("Keywords: ");
    while (i < strlen(code)) {
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';
            if (isKeyword(buffer)) {
                printf("%s ", buffer);
            }
        } else {
            i++;
        }
    }


    i = 0;
    printf("\nIdentifiers: ");
    while (i < strlen(code)) {
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';
            if (!isKeyword(buffer)) {
                printf("%s ", buffer);
            }
        } else {
            i++;
        }
    }


    i = 0;
    printf("\nOperators: ");
    while (i < strlen(code)) {
        if (strchr("+-*/%=<>!&|", code[i])) {
            printf("%c", code[i]);

            if ((code[i] == '+' && code[i + 1] == '+') || (code[i] == '-' && code[i + 1] == '-') ||
                (code[i] == '&' && code[i + 1] == '&') || (code[i] == '|' && code[i + 1] == '|') ||
                (code[i] == '=' && code[i + 1] == '=') || (code[i] == '!' && code[i + 1] == '=')) {
                printf("%c", code[++i]);
            }
            printf(" ");
        }
        i++;
    }


    i = 0;
    printf("\nConstants: ");
    while (i < strlen(code)) {
        if (isdigit(code[i])) {
            j = 0;
            while (isdigit(code[i])) {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';
            printf("%s ", buffer);
        } else {
            i++;
        }
    }


    i = 0;
    printf("\nSpecial Characters: ");
    while (i < strlen(code)) {
        if (strchr("(){}[],;\"", code[i])) {
            printf("%c ", code[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("lab.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    char code[1024];
    fread(code, sizeof(char), 1024, file);
    fclose(file);

    categorize(code);

    return 0;
}
