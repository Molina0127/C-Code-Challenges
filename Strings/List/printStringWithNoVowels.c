#include <stdio.h>
#include <string.h>

void excludeVowels(char *sentence) {
    int length = strlen(sentence);

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int find = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 5 && find == 0; j++) {
            if(sentence[i] == vowels[j]) {
                find++;
            }
        }
        if (find == 0) {
            printf("%c", sentence[i]);
        }
        find = 0;
    }
}

int main () {
    char sentence[50];

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    excludeVowels(sentence);
}