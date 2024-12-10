/*
Trabalho Realizado Por Guilherme Molina Trindade

A justificativa para ter utilizado uma lista duplamente encadeada eh porque acredito que isso facilita tarefas de remocao, assim como tambem facilita percorrer a lista em qualquer uma das direcoes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto *no;

struct produto {
    char nome[50];
    int cod, qtd;
    float preco;
    no ant, prox;
};

void criaLLDE(no *lista) {
    *lista = NULL;
}

void addProdutoFinal(no *lista, char nome[], int cod, int qtd, float preco) {
    no p = (no) malloc (sizeof(struct produto));
    strcpy(p->nome, nome);
    p->cod = cod;
    p->qtd = qtd;
    p->preco = preco;
    p->prox = NULL;

    if(*lista == NULL) {
        p->ant = NULL;
        *lista = p;
    }
    else {
        no q = *lista;
        while (q->prox != NULL) {
            q = q->prox;
        }
        q->prox = p;
        p->ant = q;
    }
}

void atualizarEstoque(no *lista, int cod) {
    if(*lista == NULL) {
        printf("\n[AVISO] O inventario esta vazio. Nenhum produto para atualizar.\n");
    }
    else {
        no p = *lista;
        int achou = 0;
        while(p != NULL && achou == 0) {
            if(p->cod == cod) {
                int novaQtd;
                printf("\n[ENCONTRADO] Detalhes do produto:\n");
                printf("   Nome: %s\n", p->nome);
                printf("   Codigo: %d\n", p->cod);
                printf("   Estoque atual: %d unidades\n", p->qtd);
                printf("\n[ATUALIZAR ESTOQUE]:\n");
                printf("   Para adicionar itens, digite um numero positivo\n");
                printf("   Para remover itens, digite um numero negativo\n");
                achou = 1;
                do {
                    printf("   Quantidade para adicionar/remover: ");
                    scanf("%d", &novaQtd);
                    if (p->qtd + novaQtd >= 0) {
                        p->qtd = p->qtd + novaQtd;
                        printf("   [SUCESSO] Estoque atualizado com sucesso!\n");
                        printf("   Novo estoque: %d unidades\n", p->qtd);
                        break;
                    }
                    else {
                        printf("   [ERRO] Nao e possivel ter estoque negativo.\n");
                        printf("   Tente novamente.\n");
                    }
                } while(p->qtd + novaQtd < 0);
            }
            p = p->prox;
        }
        if (!achou) {
            printf("\n[ERRO] Produto com codigo %d nao encontrado no inventario.\n", cod);
        }
    }
}

void removerProduto(no *lista, int cod) {
    if(*lista == NULL) {
        printf("\n[INVENTARIO] Inventario vazio\n");
        printf("Nenhum produto registrado no momento.\n");
    }
    else {
        no p = *lista;
        int encontrado = 0;
        
        while(p != NULL && encontrado == 0) {
            if (p->cod == cod) {
                encontrado = 1;
            }
            else {
                p = p->prox;
            }
        }

        if(!encontrado) {
            printf("\n[ERRO] Produto com codigo %d nao encontrado no inventario.\n", cod);
        }
        else {
            if(p == *lista) {
                *lista = p->prox;
                if(*lista != NULL) {
                    (*lista)->ant = NULL;
                }
            }
            else {
                p->ant->prox = p->prox;
                if (p->prox != NULL) {
                    p->prox->ant = p->ant;
                }
            }
            free(p);
            printf("\n[SUCESSO] Produto removido com sucesso!\n");
        }
    }
}

void buscarProdutoNome(no lista, char nome[]) {
    if(lista == NULL) {
        printf("\n[INVENTARIO] Inventario vazio\n");
        printf("Nenhum produto registrado no momento.\n");
    }
    else {
        no p = lista;
        int achou = 0;
        do {
            if (strcmp(p->nome, nome) == 0) {
                printf("%-30s %-10s %-15s %-10s\n", "Nome do Produto", "Codigo", "Quantidade", "Preco ($)");
                printf("%-30s %-10d %-15d %-10.2f\n", p->nome, p->cod, p->qtd, p->preco);
                achou = 1;
            }
            else {
                p = p->prox;
            }
        } while (p != NULL && achou == 0);
        if(!achou) {
            printf("\n[ERRO] Produto com nome %s nao encontrado no inventario.\n", nome);
        }
    }
}

void calcularValorTotalEstoque(no lista) {
    if(lista == NULL) {
        printf("\n[INVENTARIO] Inventario vazio\n");
        printf("Nenhum produto registrado no momento.\n");
    }
    else {
        no p = lista;
        float total = 0;
        printf("\n==================== TOTAL EM ESTOQUE ====================\n");
        printf("%-30s %-10s %-15s %-10s\n", "Nome do Produto", "Codigo", "Quantidade", "Preco (R$)");
        printf("----------------------------------------------------\n");
        do {
            printf("%-30s %-10d %-15d %-10.2f\n", p->nome, p->cod, p->qtd, p->preco);
            total += p->qtd * p->preco;
            p = p->prox;
        } while (p != NULL);
        printf("---------------------------------------------------------\n");
        printf("Valor total em estoque: R$ %.2f\n", total);
        printf("=========================================================\n");
    }
}

void exibirInventario(no lista) {
    if(lista == NULL) {
        printf("\n[INVENTARIO] Inventario vazio\n");
        printf("Nenhum produto registrado no momento.\n");
    }
    else {
        no p = lista;
        printf("\n==================== INVENTARIO ====================\n");
        printf("%-30s %-10s %-15s %-10s\n", "Nome do Produto", "Codigo", "Quantidade", "Preco (R$)");
        printf("----------------------------------------------------\n");
        do {
            printf("%-30s %-10d %-15d %-10.2f\n", p->nome, p->cod, p->qtd, p->preco);
            p = p->prox;
        } while (p != NULL);
        printf("====================================================\n");
    }
}

void filtrarPorQtdBaixa(no lista, int qtd) {
    if(lista == NULL) {
        printf("\n[INVENTARIO] Inventario vazio\n");
        printf("Nenhum produto registrado no momento.\n");
    }
    else {
        no p = lista;
        int encontrado = 0;
        
        while(p != NULL && encontrado == 0) {
            if (p->qtd < qtd) {
                encontrado = 1;
            }
            else {
                p = p->prox;
            }
        }
        if(!encontrado) {
            printf("\n[ERRO] Nao ha produtos com menos que %d no inventario.\n", qtd);
        }
        else {
            no p = lista;
            printf("\n==================== PRODUTOS COM MENOS QUE %d UNIDADES ====================\n", qtd);
            printf("%-30s %-10s %-15s %-10s\n", "Nome do Produto", "Codigo", "Quantidade", "Preco (R$)");
            printf("----------------------------------------------------\n");
            do {
                if (p->qtd < qtd) {
                    printf("%-30s %-10d %-15d %-10.2f\n", p->nome, p->cod, p->qtd, p->preco);
                }
                p = p->prox;
            } while (p != NULL);
            printf("====================================================\n");
        }
    }
}

void salvarInventario(no lista) {
    FILE *arquivo = fopen("inventario.txt", "w");
    if (arquivo == NULL) {
        printf("\n[ERRO] Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    no p = lista;
    while (p != NULL) {
        fprintf(arquivo, "%s;%d;%d;%.2f\n", 
                p->nome, p->cod, p->qtd, p->preco);
        p = p->prox;
    }

    fclose(arquivo);
    printf("\n[SUCESSO] Inventario salvo em 'inventario.txt'.\n");
}

void carregarInventario(no *lista) {
    FILE *arquivo = fopen("inventario.txt", "r");
    if (arquivo == NULL) {
        printf("\n[AVISO] Arquivo de inventario nao encontrado.\n");
        return;
    }

    while (*lista != NULL) {
        no temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }

    char linha[200];
    char nome[50];
    int cod, qtd;
    float preco;

    while (fgets(linha, sizeof(linha), arquivo)) {

        linha[strcspn(linha, "\n")] = 0;

        if (sscanf(linha, "%49[^;];%d;%d;%f", 
                    nome, &cod, &qtd, &preco) == 4) {
            addProdutoFinal(lista, nome, cod, qtd, preco);
        }
    }

    fclose(arquivo);
    printf("\n[SUCESSO] Inventario carregado de 'inventario.txt'.\n");
}

int main() {
    int op = 0;
    char nome[50];
    int qtd, cod;
    float preco;
    no lista;
    criaLLDE(&lista); // Cria uma lista no main

    printf("Sistema de Gerenciamento de Inventario\n");

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("01. Adicionar Produto\n");
        printf("02. Atualizar Estoque\n");
        printf("03. Remover Produto\n");
        printf("04. Buscar Produto pelo Nome\n");
        printf("05. Mostrar Inventario Completo\n");
        printf("06. Calcular Valor Total em Estoque\n");
        printf("07. Filtrar Produtos por Unidades\n");
        printf("08. Salvar Inventario em Disco\n");
        printf("09. Carregar Inventario do Disco\n");
        printf("10. Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("\nRegistro de Novo Produto\n");
                printf("Nome do produto: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove \n

                printf("Codigo do produto: ");
                scanf("%d", &cod);

                no v = lista;
                while(v) {
                    if(v->cod == cod) {
                        printf("[ERRO] Codigo ja existente. Digite um codigo diferente: ");
                        scanf("%d", &cod);
                        v = lista;
                    }
                    else {
                        v = v->prox;
                    }
                }
                printf("Quantidade disponivel: ");
                scanf("%d", &qtd);
                printf("Preco unitario ($): ");
                scanf("%f", &preco);

                addProdutoFinal(&lista, nome, cod, qtd, preco);
                printf("\n[SUCESSO] Produto adicionado com sucesso!\n");
                break;
            case 2:
                printf("\nAtualizacao de Estoque\n");
                printf("Codigo do produto: ");
                scanf("%d", &cod);
                atualizarEstoque(&lista, cod);
                break;
            case 3:
                printf("\nRemocao do Produto\n");
                printf("Digite o codigo do produto: ");
                scanf("%d", &cod);
                removerProduto(&lista, cod);
                break;
            case 4:
                printf("\nBuscar Produto por Nome\n");
                printf("Digite o nome do produto: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove \n
                buscarProdutoNome(lista, nome);
                break;
            case 5:
                exibirInventario(lista);
                break;
            case 6:
                calcularValorTotalEstoque(lista);
                break;
            case 7:
                printf("\nFiltrar Produtos por Unidades Disponiveis\n");
                printf("Digite a quantidade de itens: ");
                scanf("%d", &qtd);
                filtrarPorQtdBaixa(lista, qtd);
                break;
            case 8:
                salvarInventario(lista);
                break;
            case 9:
                carregarInventario(&lista);
                break;
            case 10:
                printf("\nEncerrando Sistema de Gerenciamento de Inventario. Ate logo!\n");
                return 0;
            default:
                printf("\n[ERRO] Opcao invalida! Por favor, escolha uma opcao valida do menu.\n");
        }
    } while(op != 10);
        
    return 0;
}
