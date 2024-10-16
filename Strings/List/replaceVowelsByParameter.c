#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 9 */
void replaceVowelsByParameter(char ch, char *sentence) {
    int length = strlen(sentence);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < length; i++) {
        for(int j = 0; j < 10; j++) {
            if (sentence[i] == vowels[j]) {
                sentence[i] = ch;
            }
        }
    }

}

int main() {
    char sentence[50];
    char ch;

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    replaceVowelsByParameter(ch, sentence);

    printf("A frase depois de substituir as vogais pelo parametro, ficou assim:\n%s", sentence);

    return 0;
}