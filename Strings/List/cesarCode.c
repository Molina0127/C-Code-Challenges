#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 18 */
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

void modifyString(char *sentence) {
    int length = strlen(sentence);
    
    for (int i = 0; i < length; i++) {
        sentence[i] += 3;
    }
}


int main() {
    char sentence[50];
    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);

    treatSentence(sentence);
    modifyString(sentence);

    printf("Esse eh o resultado da string, depois de aplicar o codigo de cesar:\n%s", sentence);

    return 0;
}