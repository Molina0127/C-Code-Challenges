#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

// Declarando a estrutura
struct reg {
    int info;
    no ant, prox;
};

// Criando a lista
void criarLista(no *lista) {
    lista = NULL;
}

// Recebendo a lista
void recebeLista(no *lista) {
    no p, q;
    if (!lista) {
        printf("A lista fornecida eh nula\n");
    }
    else {
        p = *lista;
        while(p != NULL) {
            q = (no) malloc(sizeof(struct reg));
            q->ant = p->ant;
            q->info = p->info;
            q->prox = p->prox;
            p = p->prox;
            printf("%d\n", p->prox);
        }
        while (q != NULL) {
            q = q->ant;
        }
        *lista = q;
    }
}
