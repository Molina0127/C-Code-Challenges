#include <stdio.h>
#include <string.h>
#include <ctype.h>

int reprocessing() {
    int op;
    do {
        printf("Deseja substituir as vogais de uma outra frase por '*'? (1 - sim/2 - nao)\n");
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

char replaceVowelByAsterisk(char sentence[100]) {
    printf("Escreva uma frase: ");
    fgets(sentence, 100, stdin);
    fflush(stdin);
    
    for(int i = 0; sentence[i]; i++) {
       if (verifyVowel(sentence[i])) {
            sentence[i] = '*';
       }
    }
}

int main() {
    char sentence[100];
    do {
        replaceVowelByAsterisk(sentence);
        printf("%s", sentence);
    } while(reprocessing() == 1);

    return 0;
}