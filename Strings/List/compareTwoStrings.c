#include <stdio.h>

char compareTwoStrings(char str1, char str2) {
    
}

int main() {
    char sentence1[50];
    char sentence2[50];

    printf("Digite uma frase: ");
    fgets(sentence1, sizeof(sentence1), stdin);

    printf("Digite uma segunda frase: ");
    fgets(sentence2, sizeof(sentence2), stdin);

    compareTwoStrings(sentence1, sentence2);

    return 0;
}

// separar a roupa e o monitor

