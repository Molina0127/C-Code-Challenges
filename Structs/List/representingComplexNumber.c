#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
/* Structs - List 2 - Exercise 2 */
typedef struct {
    float real; // Real part
    float imag; // Imaginary part
} complex;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void treatSentence(char *sentence) {
    char *p;
    if(p = strchr(sentence, '\n')) {
        *p = 0;
    }
}

void toUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void imprimirComplexos(complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    }
    else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

complex somarComplexos(complex c1, complex c2) {
    complex soma;
    soma.real = c1.real + c2.real;
    soma.imag = c1.imag + c2.imag;
    return soma;
}

complex subtrairComplexos(complex c1, complex c2) {
    complex sub;
    sub.real = c1.real - c2.real;
    sub.imag = c1.imag - c2.imag;
    return sub;
}

complex multiplicarComplexos(complex c1, complex c2) {
    complex mult;
    mult.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    mult.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return mult;
}

int main() {
    complex c1, c2;
    complex soma, sub, mult;

    printf("Digite a parte real do 1° numero complexo:\n");
    scanf("%f", &c1.real);
    printf("Digite a parte imaginaria do 1° numero complexo:\n");
    scanf("%f", &c1.imag);

    printf("Digite a parte real do 2° numero complexo:\n");
    scanf("%f", &c2.real);
    printf("Digite a parte imaginaria do 2° numero complexo:\n");
    scanf("%f", &c2.imag);
    clearBuffer();
    
    printf("\n");
    
    soma = somarComplexos(c1, c2);
    printf("Soma: ");
    imprimirComplexos(soma);
    
    sub = subtrairComplexos(c1, c2);
    printf("Subtracao: ");
    imprimirComplexos(sub);
    
    mult = multiplicarComplexos(c1, c2);
    printf("Multiplicacao: ");
    imprimirComplexos(mult);


    return 0;
}
