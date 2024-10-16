#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 11 */
void reverseString(char *sentence) {
    int length = strlen(sentence);
    char aux;

    for (int i = 0; i < length / 2; i++) {
        aux = sentence[i];
        sentence[i] = sentence[length - i - 1];
        sentence[length - i - 1] = aux;
    }
}

void replaceVowelsByAsterisk(char *sentence) {
    
    int length = strlen(sentence);
    
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 10; j++) {
            if(sentence[i] == vowels[j]) {
                sentence[i] = '*';
            }
        }
    }

}

int main() {
    char sentence1[50];
    char sentence2[50];

    printf("Digite uma frase: ");
    fgets(sentence1, 50, stdin);

    printf("Digite uma outra frase: ");
    fgets(sentence2, 50, stdin);
    
    reverseString(sentence1);
    replaceVowelsByAsterisk(sentence1);

    reverseString(sentence2);
    replaceVowelsByAsterisk(sentence2);

    printf("\nA 1° frase depois de inverte-la e substituir suas vogais por '*' ficou assim:\n%s", sentence1);
    printf("\nA 2° frase depois de inverte-la e substituir suas vogais por '*' ficou assim:\n%s", sentence2);

    return 0;
}