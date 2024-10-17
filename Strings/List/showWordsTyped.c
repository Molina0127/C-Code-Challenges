#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 14 */
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

void showWordsTyped(char *sentence) {
    int length1 = strlen(sentence);
    int j;
        
    for (j = 0; j < length1; j++) {
        if (sentence[j] != ' ') {
            printf("%c", sentence[j]);
        }
        else if (sentence[j] == ' ' && sentence[j-1] != ' ') {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char sentence[50];
    
    do {
        printf("Digite uma frase: ");
        fgets(sentence, 50, stdin);
        
        treatSentence(sentence);
        
        printf("\nAs palavras digitadas nessa frase sao:\n");
        
        showWordsTyped(sentence);

        sentence[0] = '\0';
    } while (shouldRepeat() == 1);

    return 0;
}