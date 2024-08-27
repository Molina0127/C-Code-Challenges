#include <stdio.h>
#include <string.h>
int main() {
    char str[50];
    strcpy(str, "Tamanho de caracteres da frase\n");
    //printf("%d\n", strlen(str));
    printf("%ld\n", strlen(str));
    return 0;
}