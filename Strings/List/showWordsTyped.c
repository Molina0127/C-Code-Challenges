#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 14 */
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
}

int main() {
    char sentence[50];
    char word[30];
    
    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);
    
    treatSentence(sentence);
    
    printf("\nAs palavras digitadas nessa frase sao:\n\n");
    showWordsTyped(sentence);
    

    return 0;
}