#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/* Structs - List 2 - Exercise 4 */

typedef struct {
    int num;
    int den;
} frac;

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

// MDC Function
int mdc(int a, int b) {
    a = abs(a); // Absolute a
    b = abs(b); // Absolute b
    while (b != 0) {
        int temp = b; // Temporary b
        b = a % b; // b = rest of a per b
        a = temp; // a is equal old b
    }
    return a;
}

// Simplify Function
frac simplify(frac r) {
    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

    int divisor = mdc(r.num, r.den);
    if (divisor > 1) {
        r.num /= divisor;
        r.den /= divisor;
    }
    return r;
}

void printFrac(frac r) {
    r = simplify(r);
    if (r.den == 1) {
        printf("%d\n", r.num);
    }
    else {
        printf("%d/%d\n", r.num, r.den);
    }
}

frac sumFrac(frac r1, frac r2) {
    frac soma;
    soma.num = (r1.num * r2.den) + (r2.num * r1.den);
    soma.den = r1.den * r2.den;
    return simplify(soma);
}

frac subFrac(frac r1, frac r2) {
    frac sub;
    sub.num = (r1.num * r2.den) - (r2.num * r1.den);
    sub.den = r1.den * r2.den;
    return simplify(sub);
}

frac multFrac(frac r1, frac r2) {
    frac mult;
    mult.num = (r1.num * r2.num);
    mult.den = (r1.den * r2.den);
    return simplify(mult);
}

frac divFrac(frac r1, frac r2) {
    frac div;
    if (r2.num == 0) {
        printf("Erro: Divisao por zero\n");
        div.num = 0;
        div.den = 1;
        return div;
    }
    div.num = r1.num * r2.den;
    div.den = r1.den * r2.num;
    return simplify(div);
}

int main()
{
    frac r1, r2;
    frac soma, sub, mult, div;

    printf("Digite o numerador do 1° numero racional:\n");
    scanf("%d", &r1.num);
    printf("Digite o denominador do 1° numero racional:\n");
    scanf("%d", &r1.den);
    printf("Digite o numerador do 2° numero racional:\n");
    scanf("%d", &r2.num);
    printf("Digite o denominador do 2° numero racional:\n");
    scanf("%d", &r2.den);

    clearBuffer();

    printf("\n");

    soma = sumFrac(r1, r2);
    printf("Soma: ");
    printFrac(soma);
    
    sub = subFrac(r1, r2);
    printf("Subtracao: ");
    printFrac(sub);
    
    mult = multFrac(r1, r2);
    printf("Multiplicacao: ");
    printFrac(mult);

    div = divFrac(r1, r2);
    printf("Divisao: ");
    printFrac(div);

    return 0;
}
