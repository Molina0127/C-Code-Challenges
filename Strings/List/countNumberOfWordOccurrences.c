#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 12 */
void treatSentence(char *sentence) {
    char *p;
    if (p=(strchr(sentence, '\n'))) {
        *p = 0;
    }
    else {
        scanf("%[^\n]");
        scanf("%*c");
    }
}

int countNumberOfWordOccurrences(char *sentence, char *word) {
    int length1 = strlen(sentence);
    int length2 = strlen(word);
    int count = 0;
    int equal;

    for (int i = 0; i <= length1 - length2; i++) {
        equal = 1;
        for (int j = 0; j < length2 && equal == 1; j++) {
            if (sentence[i + j] != word[j]) {
                equal = 0;
            }
        }
        if (equal) {
            count++;
        }
    }

    return count;

}

int main() {
    char sentence[50];
    char word[30];
    
    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    printf("Digite uma palavra: ");
    fgets(word, 30, stdin);
    
    treatSentence(sentence);
    treatSentence(word);
    
    int count = countNumberOfWordOccurrences(sentence, word);
    
    printf("\nA palavra '%s' ocorre %d vezes na frase.", word, count);

    return 0;
}