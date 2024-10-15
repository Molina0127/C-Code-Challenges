#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 5 */
char parameter = '1';
char value = '0';

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

void replaceValuesByParameter(char *sentence) {
    int length = strlen(sentence);

    for(int i = 0; i < length; i++) {
        if (sentence[i] == value) {
            sentence[i] = parameter;
        }
    }
}

int main() {
    char sentence[50];

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    treatSentence(sentence);
    replaceValuesByParameter(sentence);

    printf("\nA frase depois de substituir o(s) '%c'(s) pelo parametro %c eh igual a:\n\n%s", value, parameter, sentence);

    return 0;
}