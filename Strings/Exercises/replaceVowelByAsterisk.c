#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* String Manipulation Part 1 - Exercise 4 */
#define MAX_CHARS 100

char inputPhrase[MAX_CHARS + 2];

void clearInputBuffer() {   
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[3];
    do {
        printf("\nDeseja verificar o numero de vogais em alguma outra frase? (1 - sim/2 - nao)\n");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 1) {
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
            clearInputBuffer();
            continue;
        }

        if(sscanf(input, "%d", &userOption) == 1) {    
            if ((userOption == 1) || (userOption == 2)) { 
                return userOption;
            }
            else {
                printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
            }
        }
        else {
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
        }

    } while(userOption != 1 && userOption != 2);
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

char replaceVowelByAsterisk(char inputPhrase[MAX_CHARS + 2]) {
    
    do {
        printf("Escreva uma frase (maximo de 100 caracteres): ");
        fgets(inputPhrase, MAX_CHARS + 2, stdin);
        
        // Verify if the input exceeds MAX_CHARS
        if (strlen(inputPhrase) > MAX_CHARS + 1 || (strlen(inputPhrase) == MAX_CHARS + 1 && inputPhrase[MAX_CHARS] != '\n')) {
            clearInputBuffer();
            printf("A frase deve conter no maximo 100 caracteres. Por favor, tente novamente.\n");
        }
        
    }
    while (strlen(inputPhrase) > MAX_CHARS + 1 || (strlen(inputPhrase) == MAX_CHARS + 1 && inputPhrase[MAX_CHARS] != '\n'));
    
    // Remove newline character
    inputPhrase[strcspn(inputPhrase, "\n")] = 0;
    
    for(int i = 0; inputPhrase[i]; i++) {
       if (verifyVowel(inputPhrase[i])) {
            inputPhrase[i] = '*';
       }
    }
}

int main() {
    do {
        replaceVowelByAsterisk(inputPhrase);
        printf("%s", inputPhrase);
    } while(shouldRepeat() == 1);

    return 0;
}