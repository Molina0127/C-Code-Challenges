#include <stdio.h>
/* String Manipulation - List 1 - Exercise 1 */
char convertUpperIntoLower(char letter) {
    if (letter >= 65 && letter <= 90) {
        letter = letter + 32;
    }
    
    return letter;
}

int main() {
    char sentence[50];

    printf("Digite uma frase: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    for(int i = 0; i < 50; i++) {
        sentence[i] = convertUpperIntoLower(sentence[i]);
    }
    
    printf("A frase digitada em minusculo: %s", sentence);

    return 0;
}