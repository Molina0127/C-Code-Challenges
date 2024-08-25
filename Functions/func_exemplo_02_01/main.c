#include <stdio.h>
int messages(int op) {
    switch(op) {
        case 1:
            printf("Deseja somar mais algum numero real? (1 - sim || 2 - nao)\n");
            break;
        case 2:
            printf("Deseja limpar a calculadora ou quer adicionar mais um número a soma?\n1 - Limpar a Calculadora || 2 - Adicionar mais um número a soma\n");
            break;
        case 3:
            printf("\nDigite um numero real: ");
            break;
        case 4:
            printf("\nDigite mais um numero real: ");
            break;
    }
}

int reprocessing() {
    int op;
    do {
        // message
        scanf("%d", &op);
    } while (op != 1 && op != 2);
    return op;
}

float sum(float total, int num_exec) {
    float num1, num2;
    int op = 0;
    
    if(num_exec > 0) {
        messages(2);
        op = reprocessing();
    }
    
    if (op == 2) {
        num1 = total;
    }
    else {
        total = 0;
        messages(3);
        scanf("%f", &num1);
    }
    
    messages(4);
    scanf("%f", &num2);
    
    return num1+num2;
}

int main() {
    float total = 0;
    int cont = 0;
    do {
        total = sum(total, cont);
        printf("\nTotal: %.2f\n", total);
        messages(1);
        cont++;
    } while (reprocessing() == 1);
    return 0;
}