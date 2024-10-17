#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 13 */
int shouldRepeat() {
    int op = 1;
    
    do {
        printf("\nDeseja digitar uma frase novamente?\n");
        printf("0 - nao | 1 - sim\n");        
        scanf("%d", &op);
        
        if (op != 0 && op != 1) {
            printf("Opcao invalida.\n"); 
        }
        getchar();
        
    } while (op != 0 && op != 1);
    
    return op;
}

void treatSentence(char *sentence) {
    char *p;
    if (p=(strchr(sentence, '\n'))) {
        *p = 0;
    }
    else {
        scanf("%[^\n]");
        scanf("%*c");
    }
}

int countNumberOfWords(char *sentence) {
    int length1 = strlen(sentence);
    int count = 0;
    int inWord = 0;

    int j, k;
        
    for (j = 0; j < length1; j++) {
        if (sentence[j] != ' ' && inWord == 0) {
            inWord = 1;
            count++;
        }
        else if (sentence[j] == ' ' && inWord == 1) {
            inWord = 0;
        }
    }
    return count;
}

int main() {
    char sentence[50];
    
    do {
        printf("Digite uma frase: ");
        fgets(sentence, 50, stdin);
        
        treatSentence(sentence);
        
        int count = countNumberOfWords(sentence);
        
        printf("\nO numero de palavras na frase eh igual a %d", count);

        sentence[0] = '\0';
    } while (shouldRepeat() == 1);


    return 0;
}