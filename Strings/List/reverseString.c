#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 6 */
void treatWord(char *word) {
    char *p;

    if(p=strchr(word, '\n')) {
        *p = 0;
    }
    else {
        scanf("%[^\n]");
        scanf("%*c");
    }

}

void reverseString(char *word) {
    int length = strlen(word);
    char aux;

    for (int i = 0; i < length / 2; i++) {
        aux = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = aux;
    }
}


int main() {
    char word[30];

    printf("Digite uma palavra: ");
    fgets(word, 30, stdin);

    treatWord(word);
    reverseString(word);

    printf("Palavra de tras para frente: %s", word);

    return 0;
}