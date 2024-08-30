#include <stdio.h>
#include <ctype.h>
int reprocessing() {
    int op;
    do {
        printf("Deseja contar o numero de vogais de outra frase? (1 - sim/2 - nao)\n");
        scanf("%d", &op);
        getchar();
    } while(op != 1 && op != 2);
}

int verifyVogal(char letter) {
    letter = toupper(letter);
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
        return 1;
    }
    else {
        return 0;
    }
}

char countVogals() {
    char frase[100];
    int cont = 0;
    printf("Escreva uma frase: ");
    fgets(frase, 100, stdin);
    fflush(stdin);
    
    for(int i = 0; frase[i]; i++) {
       if (verifyVogal(frase[i])) {
            cont++;
       }
    }
    return cont;
}

int main() {
    int cont;
    do {
        cont = countVogals();
        printf("O numero de vogais na frase eh: %d\n", cont);
    } while(reprocessing() == 1);

    return 0;
}