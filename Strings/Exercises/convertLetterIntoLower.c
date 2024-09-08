#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* String Manipulation Part 1 - Exercise 7 */
#define MAX_CHARS 100

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[3];
    while(1) {
        printf("\nDeseja converter as letras maiusculas em letras minusculas em alguma outra frase? (1 - sim/2 - nao)\n");
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

    }
}

void convertLowerIntoUpper() {
    char inputPhrase[MAX_CHARS + 2];

    while (1) {
        printf("Digite uma frase (maximo de 100 caracteres): ");
        fgets(inputPhrase, sizeof(inputPhrase), stdin);

        // Verify if the input exceeds MAX_CHARS
        if ((strlen(inputPhrase) > MAX_CHARS + 1) || (strlen(inputPhrase) == MAX_CHARS + 1 && inputPhrase[MAX_CHARS] != '\n')) {
            clearInputBuffer();
            printf("A frase deve conter no maximo 100 caracteres. Por favor, tente novamente.\n");
            continue;
        }
        // Remove newline character
        inputPhrase[strcspn(inputPhrase, "\n")] = 0;
        break;
    }

    for (int i = 0; inputPhrase[i]; i++) {
        if (inputPhrase[i] >= 65 && inputPhrase[i] <= 90) {
            inputPhrase[i] = tolower(inputPhrase[i]);
        }
    }
    printf("A frase apos transformar as letras minusculas em minusculas fica assim: %s\n", inputPhrase);
}

int main() {
    do {
        convertLowerIntoUpper();
    } while(shouldRepeat() == 1);

    return 0;
}