#include <stdio.h>
#include <string.h>
/* Function Part 1 - Example 1 More Robust */
void message() {
    printf("Sou uma funcao!\n");
}

void message1() {
    printf("Sou uma outra funcao!\n");
}

void traits() {
    int i;
    printf("\n");
    for(i = 1; i <= 40; i++) {
        printf("-");
    }
    printf("\n");
}

/* Extra */
int centralize(int len) {
    int center = (38 - (len));
    int start = 0;
    
    start = (center / 2);
    
    if (center % 2 == 1) {
        start+=1;
    }
    
    return start;
}

void rectangle(char* text) {
    char message[40];
    int len;
    int final, start;
    
    strcpy(message, text);
     
    len = strlen(message);
    
    start = centralize(len);
    
    if (start * 2 + (len-1) == 38) {
        final = start + (len-1);
    }
    else {
        final = start-1 + (len-1);
    }
    
    traits();
    
    printf("|");
    
    int i;
    
    for(i = 0; i<39; i++) {
        if (i < start) {
            printf(" ");
        }
        if ((i >= start) && (i < start+(len-1))) {
            printf("%c", message[i - start]);
        }
        if (i >= start+len) {
            printf(" ");
        }
    }
    
    printf("|");
    
    traits();
    
}

int main() {
    char text[100];
    
    printf("Digite uma mensagem:\n");
    fgets(text, sizeof(text), stdin);

    rectangle(text);
    
    return 0;
}