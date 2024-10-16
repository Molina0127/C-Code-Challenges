#include <stdio.h>
#include <string.h>
/* String Manipulation - List 1 - Exercise 19 */
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

void reverseString(char *word, char *drow, int length) {

    for (int i = 0; i < length; i++) {
        drow[i] = word[length - i - 1];
    }
}

int verifyIfStringIsPalindrome(char *word, char *drow, int length) {
    int check = 1;
    for (int i = 0; i < length && check == 1; i++) {
        if (word[i] != drow[i]) {
            check = 0;
        }
    }
    return check;
}


int main() {
    char word[30];
    char drow[30];

    printf("Digite uma palavra: ");
    fgets(word, 30, stdin);

    treatWord(word);
    
    int length = strlen(word);
    
    reverseString(word, drow, length);

    int palindrome = verifyIfStringIsPalindrome(word, drow, length);

    if (palindrome) {
        printf("A frase %s eh um palindromo\n", word);
    }
    else {
        printf("A frase %s nao eh um palindromo, seu contrario eh %s\n", word, drow);
    }

    return 0;
}