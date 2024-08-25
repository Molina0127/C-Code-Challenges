// 1 se o numero for positivo
// 0 se o numero for nulo
// -1 se o numero for negativo

#include <stdio.h>
float verifyNumber(float num) {
    if (num < 0) {
        num = -1;
    }
    if (num > 0) {
        num = 1;
    }
    return num;
}

int main(){
    float num;
    int result;
    printf("Digite um numero real: ");
    scanf("%f", &num);
    
    result = verifyNumber(num);
    printf("O numero digitado foi %.2f e o resultado foi %d", num, result);
}