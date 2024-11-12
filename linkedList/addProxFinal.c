#include <stdlib.h>
typedef struct reg *no;
struct reg {
    int info;
    struct reg *prox;
};
//----------------------------------------------------   
// Cria uma lista vazia
//----------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
} 
//----------------------------------------------------
// Inclui um elemento no inicio da lista
//----------------------------------------------------
void inclui_inicio (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  p->prox = *lista;
  *lista = p;
}
//----------------------------------------------------
// Mostra os elementos da lista
//----------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {   // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//----------------------------------------------------
// Remove o primeiro elemento da lista
//----------------------------------------------------
void remover_primeiro (no lista) {
    no p = lista;
    p->prox = lista;
}
//----------------------------------------------------
// Programa Principal
//----------------------------------------------------
int main () {
  int info;
  no lista;    
  char resp;
  cria_lista (&lista);   // lista = NULL;
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_inicio (&lista,info);
    mostra_lista (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
}