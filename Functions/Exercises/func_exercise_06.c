// ler cinco valores inteiros
// imprimir o maior
// imprimir o menor também

#include <stdio.h>
int lower, greater;

int lowerValue(int value) {
    if (lower >= value) {
        lower = value;
    }
    return lower;
}

int greaterValue(int value) {
    if (greater <= value) {
        greater = value;
    }
    return greater;
}

int reprocessing() {
    int op;
    do {
        printf("\nDeseja ler cinco valores novamente? (1 - sim || 2 - nao)\n");
        scanf("%d", &op);
    } while(op != 1 && op != 2);
}


int main() {
    int value;
    int smallest;
    int greatest;
    do {
    int i = 1;
    
     printf("Digite o valor [%d] da sequencia: ", i);
     scanf("%d", &lower);
     greater = lower;
    
        for (i += 1; i <= 5; i++) {
            printf("Digite o valor [%d] da sequencia: ", i);
            scanf("%d", &value);
            
            smallest = lowerValue(value);
            greatest = greaterValue(value);
        }
        
        lower = greater = 0;
        
        printf("\nMenor valor: %d\n", smallest);
        printf("Maior valor: %d\n", greatest);
    } while(reprocessing() == 1);
    
    return 0;
}