#include <stdio.h>
#include <string.h>
int main() {
    char str1[40], str2[40];
    
    int length = strlen(str1);
    
    printf("%d\n", length);
    
    int contador = 0;
    
    for(contador; str1[contador]!='\0'; contador++);
    
    printf("O tamanho da string eh: %d\n", contador);
    
    for(contador = 0; contador<39; contador++) {
        str1[contador] = 'a';
        printf("%d %c\n", contador+1, str1[contador]);
    }
    
    for(contador = 0; str1[contador]!='\0'; contador++);
    
    printf("O tamanho da string eh: %d\n", contador);
    
    return 0;
}