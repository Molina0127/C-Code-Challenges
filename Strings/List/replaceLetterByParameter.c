#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 10 */
void replaceLetterByParameter(char letter, char parameter, char *sentence) {
    
    int length = strlen(sentence);
    
    for (int i = 0; i < length; i++) {
        if(sentence[i] == letter) {
            sentence[i] = parameter;
        }
    }

}

int main() {
    char sentence[50], l1, l2;

    printf("Digite uma frase: ");
    fgets(sentence, 50, stdin);
    
    printf("Digite uma letra para ser substituida: ");
    scanf(" %c", &l1);

    printf("Digite a letra que vai substitui-la: ");
    scanf(" %c", &l2);

    replaceLetterByParameter(l1, l2, sentence);

    printf("\nA frase depois de trocar a letra '%c' pela letra '%c', ficou da seguinte maneira:\n%s", l1, l2, sentence);

    return 0;
}