#include <stdio.h>
#include <ctype.h>
int reprocessing() {
    int op;
    do {
        printf("Deseja verificar o numero de cada vogal novamente? (1 - sim/2 - nao)\n");
        getchar();
        scanf("%d", &op);
    } while(op != 1 && op != 2);
}

char verifyVowel() {
    char sentence[100];
    printf("Digite uma frase: ");
    fgets(sentence, 100, stdin);
    fflush(stdin);
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

    for(int i = 0; i<5; i++) {
        printf("O numero de ocorrencias da vogal '%c' na frase eh %d\n", letters[i], vowels[i]);
    }

}

int main() {
    do {
        verifyVowel();
    } while(reprocessing() == 1);
    
    return 0;
}