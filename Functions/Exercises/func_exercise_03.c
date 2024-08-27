// recebe três números inteiros a b c 
// a > 1; 
// retorne a soma de todos o n inteiros de b - c, divisivel por a
#include <stdio.h>

int verifyDivisibility(int a, int b, int c) {
    int soma = 0;
    for (b+=1; b < c; b++) {
        if (b % a == 0) {
            printf("%d ", b);
            soma += b;
            
            if (b < c-2) {
                printf("+ ");
            }
            
        }
    }
    if (soma != 0 ) {
        printf("= %d", soma);
    }
    else {
        printf("Nao ha valores nesssa sequencia");
    }
}

int validatingData(char letter, int a_value) {
    int op;
    
    if (letter == 'a') {
        do {
            printf("Digite o valor de a (a > 1): ");
            scanf("%d", &op);
        }  while (op <= 1);
    }
    else {
        do {
            printf("Digite o valor de %c (%c > %d): ", letter, letter, a_value);
            scanf("%d", &op);
        } while (op < a_value);
    }
    
    return op;
}

int reprocessing() {
    int op;
    do {
        printf("\nDeseja calcular outra sequencia? (1 - sim || 2 - nao) ");
        scanf("%d", &op);
    } while (op != 1 && op != 2);
}

int main() {
    int a, b, c;
    do {
        //printf("Digite o valor de a (a > 1): ");
        a = validatingData('a', 0);
        //printf("%d", a);
        b = validatingData('b', a);
        //scanf("%d", &b);
        //printf("Digite o valor de c: (c > 1)");
        c = validatingData('c', a);
        
        verifyDivisibility(a, b, c);
        a = b = c = 0;
    } while(reprocessing() == 1);
    
    
    return 0;
}