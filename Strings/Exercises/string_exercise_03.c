#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cleanBuffer() {
    int clean;
    while((clean = getchar()) != '\n' && clean != EOF);
}

int reprocessing() {
    int op;
    char input[10];
    do {
        printf("Deseja verificar o numero de cada vogal novamente? (1 - sim/2 - nao)\n");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &op);
        if ((op == 1) || (op == 2)) { 
            break;
        }
        else {
            cleanBuffer();
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
        }
    } while(op != 1 && op != 2);
    
    return op;
}

void verifyVowel() {
    char sentence[100];
    printf("Digite uma frase: ");
    fgets(sentence, 100, stdin);
    int vowels[] = {0, 0, 0, 0, 0};
    char letters[] = {'A', 'E', 'I', 'O', 'U'};

    for(int i = 0; sentence[i]; i++) {
        sentence[i] = toupper(sentence[i]);
        switch (sentence[i]) {
            case 'A':
                vowels[0]++;
                break;
            case 'E':
                vowels[1]++;
                break;
            case 'I':
                vowels[2]++;
                break;
            case 'O':
                vowels[3]++;
                break;
            case 'U':
                vowels[4]++;
                break;
        }
    }

    int sumVowels = 0;

    for(int i = 0; i < 5; i++) {
        sumVowels += vowels[i];
        printf("O numero de ocorrencias da vogal '%c' na frase eh %d\n", letters[i], vowels[i]);
    }
    printf("O numero total de ocorrencias de vogais na frase eh %d\n", sumVowels);
}

int main() {
    do {
        verifyVowel();
    } while(reprocessing() == 1);
    
    return 0;
}
