#include <stdio.h>
#include <string.h>
int main() {
    char str1[40], str2[40];
    strcpy(str1,"ALGORITMOS I");
    strcpy(str2,"BSI");
    strcat(str1," - ");
    strcat(str1,str2);
    printf("%s", str1);
}