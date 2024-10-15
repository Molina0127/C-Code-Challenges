#include <stdio.h>
#include <string.h>

int main() {
    char first_str[10];
    char second_str[10];
    
    printf("Digite a primeira string (MAX 9 CARACTERES):\n");
    fgets(first_str, 10, stdin);
    char *p;
    if (p=strchr(first_str, '\n')) {
        *p = 0;
    }
    else {
        scanf("%*[^\n]");
        scanf("%*c"); // clear buffer upto newline
    }
    
    printf("Digite a segunda string (MAX 9 CARACTERES):\n");
    fgets(second_str, 10, stdin);
    if (p=strchr(second_str, '\n')) {
        *p = 0;
    }
    else {
        scanf("%*[^\n]");
        scanf("%*c"); // clear buffer upto newline
    }
    
    int comparison = strcmp(first_str, second_str);
    
    printf("O resultado da comparacao eh igual a %d", comparison);
    
    return 0;
}