#include <stdio.h>
int sqr(int x);
int main() {
    int square;
    
    printf("Digite um numero inteiro que voce deseja obter o quadrado: ");
    scanf("%d", &square);
    
    printf("\n%d = %d^2",sqr(square),square);
}
int sqr(int x) {
    return(x*x);
}