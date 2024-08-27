// recebe dois numeros inteiros
// retorna a soma do intervalo desses numeros inteiros
#include <stdio.h>
int sumBehindValues(int num1, int num2) {
    int soma = 0;
    if (num1 > num2) {
        int aux;
        aux = num2;
        num2 = num1;
        num1 = aux;
    }
    for (num1 += 1; num1 < num2; num1++) {
        printf("%d ", num1);
            
        if (num1 <= num2-2) {
            printf("+ ");
        }
        soma += num1;
    }
    return soma;
}

int main() {
    int num1, num2, soma;
    
    printf("Digite o primeiro numero do intervalo: ");
    scanf("%d", &num1);
    printf("\nDigite o segundo numero do intervalo: ");
    scanf("%d", &num2);
    
    soma = sumBehindValues(num1, num2);
    printf("= %d", soma);
    
    return 0;
}