#include <stdio.h>
/* Function Part 1 - Exercise 5 */

// receber a nota de três alunos
// receber o peso de cada uma das notas
// retornar a média ponderada

float calculatingAverage(float test1, float value1, float test2, float value2, float test3, float value3) {
    float average;
    average = ((test1 * value1) + (test2 * value2) + (test3 * value3))/(value1 + value2 + value3);
    
    return average;
}

float getWeight(int num_weight) {
    float result = 0;
    printf("Digite o peso da prova %d: ", num_weight);
    scanf("%f", &result);
    
    return result;
}

float getTestScore(int test) {
    float result = 0;
    
    do {
        printf("Digite o valor da prova %d: ", test);
        scanf("%f", &result);
    } while (result < 0 || result > 10);
    
    return result;
}

int reprocessing() {
    int op;
    do {
        printf("Deseja calcular as notas do aluno novamente? (1 - sim || 2 - nao) ");
        scanf("%d", &op);    
    } while (op != 1 && op != 2);
    
}

int main() {
    float test1, test2, test3;
    float value1, value2, value3;
    float average;
    
    do {
        test1 = getTestScore(1);
        test2 = getTestScore(2);
        test3 = getTestScore(3);
        
        value1 = getWeight(1);
        value2 = getWeight(2);
        value3 = getWeight(3);
     
        average = calculatingAverage(test1, value1, test2, value2, test3, value3);
        printf("\nA media ponderada do aluno eh = %.2f\n", average);
        
    }while (reprocessing() == 1);
    
    
    return 0;
}