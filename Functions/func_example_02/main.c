#include <stdio.h>
float sum() {
    float num1, num2;
    printf("\nDigite um numero real: ");
    scanf("%f", &num1);
    printf("\nDigite um outro numero real: ");
    scanf("%f", &num2);
    return num1+num2;
}
int main() {
    float total;
    total = sum();
    printf("\nTotal: %.2f", total);
    return 0;
}