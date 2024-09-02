#include <stdio.h>
#include <ctype.h>
int vowel = 0, consonant = 0;
int reprocessing() {
    int op;
    do {
        printf("Deseja contar o numero de vogais e consoantes de outra frase? (1 - sim/2 - nao) ");
        scanf("%d", &op);
        getchar();
    } while(op != 1 && op != 2);
}

int verifyLetter(char letter) {
    letter = toupper(letter);
    if (letter >= 65 && letter <= 90) {
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        return 0;
    }
}

void countVowel() {
    vowel++;
}

void countConsonant() {
    consonant++;
}

char countLetters() {
    char sentence[100];
    printf("Escreva uma frase: ");
    fgets(sentence, 100, stdin);
    fflush(stdin);
    
    for(int i = 0; sentence[i]; i++) {
        if (verifyLetter(sentence[i]) == 1) {
            countVowel();   
        }
        if (verifyLetter(sentence[i]) == -1) {
            countConsonant();
        }
    }
}

int main() {
    do {
        countLetters();
        printf("O numero de vogais na frase eh: %d\n", vowel);
        printf("O numero de consoantes na frase eh: %d\n", consonant);
        vowel = 0;
        consonant = 0;
    } while(reprocessing() == 1);

    return 0;
}