#include <stdio.h>
int reprocessing() {
    int op;
    do {
        printf("Deseja contar o numero de vogais e consoantes de outra frase?");
        scanf("%d", &op);
    } while(op != 1 && op != 2);
}

int main() {

}