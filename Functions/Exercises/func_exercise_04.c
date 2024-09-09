#include <stdio.h>
#include <ctype.h>
/* Function Part 1 - Exercise 4 */

char validatingLetter() {
    char letter;
    
    do {
        printf("Digite qual operacao voce quer realizar\n");
        printf("A ou a - Para media aritmetica || P ou p - Para media ponderada: ");
        scanf(" %c", &letter);
        letter = toupper(letter);
    } while (letter != 'A' && letter != 'P');
    
    return letter;
}

float validatingTest(char test) {
    float result;
    
    do {
        printf("Digite o resultado do teste%c: ", test);
        scanf("%f", &result);
    } while (result < 0  || result > 10);

    return result;
}

int calculatingTests(char letter, float test1, float test2, float test3) {
    float average = 0;
    if (letter == 'A') {
        average = (test1 + test2 + test3)/3;
    }
    else if (letter == 'P') {
        average = (test1 + test2*2 + test3*3)/(1+2+3);
    }
    
    printf("Media Final = %.2f", average);
}

int reprocessing() {
    int op;
    
    do {
        printf("\nDeseja calcular novamente? (1 - sim || 2 - nao)");
        scanf("%d", &op);
    } while (op != 1 && op != 2);
}

int main() {
    char letter; 
    float test1, test2, test3;
    
    letter = validatingLetter();
    
    test1 = validatingTest('1');
    test2 = validatingTest('2');
    test3 = validatingTest('3');
    
    calculatingTests(letter, test1, test2, test3);
    
}