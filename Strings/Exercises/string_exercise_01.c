#include <stdio.h>
int reprocessing() {
    int op;
    do {
        printf("Deseja contar o numero de vogais da frase novamente? (1 - sim/2 - nao)");
    } while(op != 1 && op != 2);
}

int main() {
    do {

    } while(reprocessing() == 1);

    return 0;
}