#include <stdio.h>
#include <string.h>

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
    char word[30];
    
    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);
    
    treatSentence(sentence);
    
    int count = countNumberOfWords(sentence);
    
    printf("\nO numero de palavras na frase eh igual a %d", count);

    return 0;
}