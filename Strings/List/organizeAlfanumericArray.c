#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 17 */
void organizeString(char *sentence) {
    int length = strlen(sentence);
    char aux;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (sentence[i] > sentence[j]) {
                aux = sentence[i];
                sentence[i] = sentence[j];
                sentence[j] = aux;
            }
        }
    }
}

int main() {
    char sentence[50];
    printf("Digite varios elementos entre leteras e numeros sem espaco entre eles (MAX 45 CARACTERES): ");
    fgets(sentence, 50, stdin);

    organizeString(sentence);

    printf("\nVeteor alfanumerico ordenado:\n%s", sentence);

    return 0;
}