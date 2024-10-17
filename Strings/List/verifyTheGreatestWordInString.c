#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 15 */
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

void verifyGreatestWord(char *sentence) {
    int length = strlen(sentence);
    int start = 0, greatestStart = 0, greatest = 0;
    int currentLength = 0;
    int j, k;
    char greatestWord[50] = "";
    
    for (j = 0; j < length; j++) {
        if (sentence[j] == ' ' || sentence[j] == '\n') {
            if (currentLength > greatest) {
                greatest = currentLength;
                greatestStart = start;
            }
        currentLength = 0;
        start = j + 1;
        } else {
            currentLength++;
        }
    }
    for(j = 0; j < greatest; j++) {
        greatestWord[j] = sentence[j + greatestStart];
    }
    greatestWord[greatest] = '\0';
    printf("A maior palavra da frase eh %s", greatestWord);
}

int main() {
    char sentence[50];
    
     do {
        printf("Digite uma frase: ");
        fgets(sentence, 50, stdin);
        
        verifyGreatestWord(sentence);

        sentence[0] = '\0';
    } while (shouldRepeat() == 1);

    return 0;
}