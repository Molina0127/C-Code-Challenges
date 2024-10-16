#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 20 */
void excludeVowels(char *sentence) {
    int length = strlen(sentence);
    int find = 0;

    for (int i = 0; i < length; i++) {
        if(sentence[i] == ' ') {
            find++;
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