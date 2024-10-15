#include <stdio.h>
#include <string.h>

int compareTwoStrings(char *str1, char *str2) {
    int comparison = 0;
    for (int i = 0; i < 50 && comparison == 0; i++) {
        if (str1[i] > str2[i]) {
            comparison = 1;
        }
        else if (str1[i] < str2[i]) {
            comparison = -1;
        }
    }
    return comparison;
}

char treatSentence(char *sentence) {
    char *p;
    if(p=strchr(sentence, '\n')) {
        *p = 0;
    }
    else {
        scanf("%*[^\n]");
        scanf("%*c"); // clear buffer upto newline
    }

}

int main() {
    char sentence1[50];
    char sentence2[50];

    printf("Digite uma frase: ");
    fgets(sentence1, 50, stdin);
    
    treatSentence(sentence1);

    printf("Digite uma segunda frase: ");
    fgets(sentence2, 50, stdin);

    treatSentence(sentence2);

    int comparison = compareTwoStrings(sentence1, sentence2);

    printf("O resultado da comparacao eh igual a %d", comparison);

    return 0;
}
