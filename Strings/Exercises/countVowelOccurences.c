#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clearInputBuffer() {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int shouldRepeat() {
    int userOption;
    char input[3];
    do {
        printf("Deseja verificar o numero de vogais em alguma outra frase? (1 - sim/2 - nao)\n");
        fgets(input, sizeof(input), stdin);
        //input[strcspn(input, "\n")] = 0;
        sscanf(input, "%d", &userOption);
        if ((userOption == 1) || (userOption == 2)) { 
            break;
        }
        else {
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
            clearInputBuffer();
        }
    } while(userOption != 1 && userOption != 2);
    
    return userOption;
}

void countVowels() {
    char inputPhrase[100];
    printf("Digite uma frase: ");
    fgets(inputPhrase, 100, stdin);
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
