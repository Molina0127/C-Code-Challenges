#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;
struct reg {
int info;
struct reg *prox;
};

void cria_LCSE (no *lista) {
*lista = NULL;
}

void inclui_inicio_LCSE (no *lista, int info) {
no p;
p = (no) malloc(sizeof(struct reg));
p->info = info;

if(!*lista) {
*lista = p;
p->prox = *lista;
}
else {
no q = *lista;
while (q->prox != *lista) {
q = q->prox;
}
q->prox = p;
p->prox = *lista;
*lista = p;
}
}

void inclui_final_LCSE (no *lista, int info) {
no p;
p = (no) malloc(sizeof(struct reg));

if(!*lista) {
p->prox = *lista;
*lista = p;
}
else {
no q = *lista;
while (q->prox != *lista) {
q = q->prox;
}
q->prox = p;
p->prox = *lista;
}

}

int remove_inicio_LCSE (no *lista) {
  if (!*lista)  // if (*lista==NULL)
    return 0;
  if ((*lista)->prox == *lista) {
    free (*lista);
    *lista = NULL;
  }
  else {
    no q = *lista;
    while (q->prox != *lista)
      q = q->prox;
    no p = *lista;
    *lista = p->prox;
    q->prox = *lista;
    free (p);
  }
  return 1;
}  

int remove_fim_LCSE (no *lista) {
if (!*lista) {
return 0;
}
if ((*lista)->prox == *lista) {
free (*lista);
*lista = NULL;
}
else {
no q = *lista, r;
do {
r = q;
q = q->prox;
}
while (q->prox != *lista);
r->prox = *lista;
free(q);
}
return 1;
}

int main() {
return 0;
}
