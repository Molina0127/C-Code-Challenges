#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* String Manipulation Part 1 - Exercise 3 */
#define MAX_CHARS 100

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[10];
    while(1) {
        printf("\nDeseja verificar a ocorrencia de cada vogal em alguma outra frase? (1 - sim/2 - nao)\n");
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

void countVowels() {
    char inputPhrase[MAX_CHARS + 2];
    
    while(1) {
        printf("Digite uma frase (maximo 100 caracteres): ");
        fgets(inputPhrase, sizeof(inputPhrase), stdin);

        // Verify if the input exceeds MAX_CHARS
        if (strlen(inputPhrase) > MAX_CHARS + 1 || (strlen(inputPhrase) == MAX_CHARS + 1 && inputPhrase[MAX_CHARS] != '\n')) {
            clearInputBuffer();
            printf("A frase deve conter no maximo 100 caracteres. Por favor, tente novamente.\n");
            continue;
        }
        // Remove newline character
        inputPhrase[strcspn(inputPhrase, "\n")] = 0;
        break;
    }

    int vowelsCounts[] = {0, 0, 0, 0, 0};
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; inputPhrase[i]; i++) {
        inputPhrase[i] = toupper(inputPhrase[i]);
        switch (inputPhrase[i]) {
            case 'A':
                vowelsCounts[0]++;
                break;
            case 'E':
                vowelsCounts[1]++;
                break;
            case 'I':
                vowelsCounts[2]++;
                break;
            case 'O':
                vowelsCounts[3]++;
                break;
            case 'U':
                vowelsCounts[4]++;
                break;
        }
    }

    int totalVowels = 0;

    for (int i = 0; i < 5; i++) {
        totalVowels += vowelsCounts[i];
        printf("O numero de ocorrencias da vogal '%c' na frase eh %d\n", vowels[i], vowelsCounts[i]);
    }
    printf("O numero total de ocorrencias de vogais na frase eh %d\n", totalVowels);
}

int main() {
    do {
        countVowels();
    } while(shouldRepeat() == 1);
    
    return 0;
}
