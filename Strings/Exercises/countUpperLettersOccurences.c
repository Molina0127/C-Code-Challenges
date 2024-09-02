#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 100

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[10];
    while(1) {
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

    }
}

int main() {
    return 0;
}