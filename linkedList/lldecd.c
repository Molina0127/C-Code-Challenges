// Operacoes em uma Lista Linear Duplamente Encadeada com descritor - LLDECD
#include <stdlib.h>
#include <stdio.h>

typedef struct reg *no;
struct reg {
    int info;
    no ant, prox;  //struct reg *ant, *prox;
};
typedef struct {
   	no prim, ult;
   	int qte;
 } Descritor;
//----------------------------------------------------   
// Cria uma lista linear duplamente encadeada com descritor- LLDECD
//----------------------------------------------------
void cria_LLDECD (Descritor *lista) {
  (*lista).prim = (*lista).ult = NULL;
  (*lista).qte = 0;
} 
//------------------------------------------------------------------------------
// Mostra os elementos da LLDECD
//------------------------------------------------------------------------------
void mostra_LLDECD (Descritor lista){
  if (lista.qte == 0) {
    printf ("\n\nLista vazia");
    return;
  }
  no p = lista.prim;
  printf ("\n\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != NULL);
}
//------------------------------------------------------------------------------
// Mostra os elementos da LLDECD ao contrario
//------------------------------------------------------------------------------
void mostra_LLDECD_contrario (Descritor lista){
  if (lista.qte == 0) {
    printf ("\nLista vazia");
    return;
  }
  // posicionar p no último no da lista
  no p = lista.ult;
  printf ("\nElementos da lista ao contrario: ");
  do {
    printf ("%d ",p->info);
    p = p->ant;
  } while (p != NULL);
}
//------------------------------------------------------------------------------
// Inclui um elemento no inicio da LLDECD
//------------------------------------------------------------------------------
void inclui_inicio_LLDECD (Descritor *lista, int info) {
  no p = (no) malloc(sizeof(struct reg ));
  p->ant = NULL;  
  p->info = info;
  p->prox = (*lista).prim;
  if ((*lista).prim) 
    (*lista).prim->ant = p;
  else
    (*lista).ult = p;
  (*lista).prim = p;
  (*lista).qte++;
}
//------------------------------------------------------------------------------
// Programa Principal
//------------------------------------------------------------------------------
int main () {
  Descritor lista;    
  int info;
  char resp;
  cria_LLDECD (&lista);  
  do {
     printf ("\nDigite um numero inteiro: ");
     scanf ("%d",&info);
     inclui_inicio_LLDECD (&lista,info);
     mostra_LLDECD (lista);
     mostra_LLDECD_contrario (lista);            
     printf ("\nContinua (S/N)? \n");   
     do {
        resp = toupper(getch());
     } while (resp!='N' && resp!='S');
  } while (resp!='N');
  return 0;
}   