#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[10];
    do {
        printf("Deseja substituir as vogais de uma outra frase por '*'? (1 - sim/2 - nao)\n");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &userOption);
        if ((userOption == 1) || (userOption == 2)) { 
            break;
        }
        else {
            clearInputBuffer();
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
        }
    } while(userOption != 1 && userOption != 2);
    
    return userOption;
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

char replaceVowelByAsterisk(char inputPhrase[100]) {
    printf("Escreva uma frase: ");
    fgets(inputPhrase, 100, stdin);
    fflush(stdin);
    
    for(int i = 0; inputPhrase[i]; i++) {
       if (verifyVowel(inputPhrase[i])) {
            inputPhrase[i] = '*';
       }
    }
}

int main() {
    char inputPhrase[100];
    do {
        replaceVowelByAsterisk(inputPhrase);
        printf("%s", inputPhrase);
    } while(shouldRepeat() == 1);

    return 0;
}