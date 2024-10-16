#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 7 */
void excludeVowels(char *sentence) {
    int length = strlen(sentence);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int find = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 10 && find == 0; j++) {
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