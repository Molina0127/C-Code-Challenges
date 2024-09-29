#include <stdio.h>
/* String Manipulation - List 1 - Exercise 2 */
char convertLowerIntoUpper(char letter) {
    if (letter >= 97 && letter <= 122) {
        letter = letter - 32;
    }
    
    return letter;
}

int main() {
    char sentence[50];
    
    printf("Digite uma frase: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    for(int i = 0; i < 50; i++) {
        sentence[i] = convertLowerIntoUpper(sentence[i]);
    }
    
    printf("A frase digitada em maiusculo: %s", sentence);
    
    return 0;
}