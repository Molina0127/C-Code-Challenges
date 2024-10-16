#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 8 */
int countVowelOccurrences(char *sentence) {
    int length = strlen(sentence);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || 
        sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U'
        ) {
            count++;        
        }
    }

    return count;
}

int main () {
    char sentence[50];
    int occurrences;

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    occurrences = countVowelOccurrences(sentence);
    printf("O numero de ocorrencias de vogais na frase eh igual a %d", occurrences);
}