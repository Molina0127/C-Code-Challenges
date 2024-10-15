#include <stdio.h>
#include <string.h>

char parameter = '1';

void treatSentence(char *sentence) {
    char *p;

    if(p=strchr(sentence, '\n')) {
        *p = 0;
    }
    else {
        scanf("%[^\n]");
        scanf("%*c");
    }
}

int countNumberOfOccurrences(char *sentence) {
    int count = 0;
    int length = strlen(sentence);

    for(int i = 0; i < length; i++) {
        if (sentence[i] == parameter) {
            count++;
        }
    }

    return count;
}

int main() {
    char sentence[50];

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    treatSentence(sentence);
    int ocurrence = countNumberOfOccurrences(sentence);

    printf("O numero de ocorrencias de %c na frase eh igual a %d", parameter, ocurrence);

    return 0;
}