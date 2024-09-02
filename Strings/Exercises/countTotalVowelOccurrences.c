#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* String Manipulation Part 1 - Exercise 1 */
#define MAX_CHARS 100

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int reprocessing() {
    int op;
    do {
        printf("Deseja contar o numero de vogais de outra frase? (1 - sim/2 - nao)\n");
        scanf("%d", &op);
        getchar();
    } while(op != 1 && op != 2);
}

int verifyVowel(char letter) {
    letter = toupper(letter);
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
        return 1;
    }
    else {
        return 0;
    }
}

char countVowel() {
    char sentence[100];
    int cont = 0;
    printf("Escreva uma frase: ");
    fgets(sentence, 100, stdin);
    fflush(stdin);
    
    for(int i = 0; sentence[i]; i++) {
       if (verifyVowel(sentence[i])) {
            cont++;
       }
    }
    return cont;
}

int main() {
    int cont;
    do {
        cont = countVowel();
        printf("O numero de vogais na frase eh: %d\n", cont);
    } while(reprocessing() == 1);

    return 0;
}