#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SOLDADOS 100
#define MAX_NOME 50

typedef struct {
    char nomes[MAX_SOLDADOS][MAX_NOME];
    int quantidade;
} Lista;

// Inicializa a lista
void inicializa_lista(Lista *lista) {
    lista->quantidade = 0;
}

// Adiciona soldado na lista
void adiciona_soldado(Lista *lista, char *nome) {
    if (lista->quantidade < MAX_SOLDADOS) {
        strcpy(lista->nomes[lista->quantidade], nome);
        lista->quantidade++;
    }
}

// Remove soldado da lista
void remove_soldado(Lista *lista, int posicao) {
    if (posicao < lista->quantidade) {
        printf("Soldado eliminado: %s\n", lista->nomes[posicao]);
        for (int i = posicao; i < lista->quantidade - 1; i++) {
            strcpy(lista->nomes[i], lista->nomes[i + 1]);
        }
        lista->quantidade--;
    }
}

// Encontra posição do soldado pelo nome
int encontra_soldado(Lista *lista, char *nome) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->nomes[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Executa o processo de Josephus
void executa_josephus(Lista *lista, int opcao, char *nome_inicio) {
    if (lista->quantidade == 0) return;
    
    int posicao_atual;
    
    // Define a posição inicial baseada na opção escolhida
    switch(opcao) {
        case 1: // Primeiro soldado
            posicao_atual = 0;
            break;
            
        case 2: // Soldado aleatório
            posicao_atual = rand() % lista->quantidade;
            printf("Soldado sorteado para início: %s\n", lista->nomes[posicao_atual]);
            break;
            
        case 3: // Soldado específico
            posicao_atual = encontra_soldado(lista, nome_inicio);
            if (posicao_atual == -1) {
                printf("Soldado não encontrado!\n");
                return;
            }
            break;
            
        default:
            printf("Opção inválida!\n");
            return;
    }
    
    // Sorteia o número para contagem
    int numero_sorteado = rand() % 10 + 1;
    printf("Número sorteado: %d\n\n", numero_sorteado);
    
    // Processo de eliminação
    while (lista->quantidade > 1) {
        // Calcula a próxima posição a ser eliminada
        posicao_atual = (posicao_atual + numero_sorteado - 1) % lista->quantidade;
        remove_soldado(lista, posicao_atual);
    }
    
    printf("\nSoldado sobrevivente: %s\n", lista->nomes[0]);
}

int main() {
    srand(time(NULL));
    Lista lista;
    inicializa_lista(&lista);
    
    // Menu para adicionar soldados
    printf("Digite os nomes dos soldados (digite 'fim' para encerrar):\n");
    char nome[MAX_NOME];
    while (1) {
        printf("Nome do soldado: ");
        scanf("%s", nome);
        if (strcmp(nome, "fim") == 0) break;
        adiciona_soldado(&lista, nome);
    }
    
    // Menu de opções
    printf("\nEscolha a opção de início de contagem:\n");
    printf("1 - Iniciar pelo primeiro soldado\n");
    printf("2 - Iniciar por um soldado aleatório\n");
    printf("3 - Informar o soldado para início\n");
    
    int opcao;
    char nome_inicio[MAX_NOME] = "";
    scanf("%d", &opcao);
    
    if (opcao == 3) {
        printf("Digite o nome do soldado para início: ");
        scanf("%s", nome_inicio);
    }
    
    printf("\nIniciando processo de eliminação...\n\n");
    executa_josephus(&lista, opcao, nome_inicio);
    
    return 0;
}
