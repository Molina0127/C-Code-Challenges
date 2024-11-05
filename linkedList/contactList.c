#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PESSOAS 100
#define MAX_STRING 100

// Estrutura para endereço
typedef struct {
    char rua[MAX_STRING];
    int numero;
    char complemento[MAX_STRING];
    char bairro[MAX_STRING];
    char cep[10];
    char cidade[MAX_STRING];
    char estado[3];
    char pais[MAX_STRING];
} Endereco;

// Estrutura para telefone
typedef struct {
    int ddd;
    char numero[10];
} Telefone;

// Estrutura para data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura principal para pessoa
typedef struct {
    char nome[MAX_STRING];
    char email[MAX_STRING];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
} Pessoa;

// Variável global para a agenda
Pessoa agenda[MAX_PESSOAS];
int total_pessoas = 0;

// Protótipos das funções
void busca_por_primeiro_nome(char *nome);
void busca_por_mes_aniversario(int mes);
void busca_por_dia_mes_aniversario(int dia, int mes);
void insere_pessoa(Pessoa p);
void retira_pessoa(char *nome);
void imprime_agenda(int tipo);
void menu();
void imprime_pessoa(Pessoa p, int tipo);

// Função principal
int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch(opcao) {
            case 1: {
                Pessoa p;
                printf("\nNome: ");
                fgets(p.nome, MAX_STRING, stdin);
                p.nome[strcspn(p.nome, "\n")] = 0;
                
                printf("Email: ");
                fgets(p.email, MAX_STRING, stdin);
                p.email[strcspn(p.email, "\n")] = 0;
                
                printf("Endereço:\n");
                printf("Rua: ");
                fgets(p.endereco.rua, MAX_STRING, stdin);
                p.endereco.rua[strcspn(p.endereco.rua, "\n")] = 0;
                
                printf("Número: ");
                scanf("%d", &p.endereco.numero);
                getchar();
                
                printf("Complemento: ");
                fgets(p.endereco.complemento, MAX_STRING, stdin);
                p.endereco.complemento[strcspn(p.endereco.complemento, "\n")] = 0;
                
                printf("Bairro: ");
                fgets(p.endereco.bairro, MAX_STRING, stdin);
                p.endereco.bairro[strcspn(p.endereco.bairro, "\n")] = 0;
                
                printf("CEP: ");
                fgets(p.endereco.cep, 10, stdin);
                p.endereco.cep[strcspn(p.endereco.cep, "\n")] = 0;
                
                printf("Cidade: ");
                fgets(p.endereco.cidade, MAX_STRING, stdin);
                p.endereco.cidade[strcspn(p.endereco.cidade, "\n")] = 0;
                
                printf("Estado (UF): ");
                fgets(p.endereco.estado, 3, stdin);
                getchar();
                
                printf("País: ");
                fgets(p.endereco.pais, MAX_STRING, stdin);
                p.endereco.pais[strcspn(p.endereco.pais, "\n")] = 0;
                
                printf("Telefone (DDD): ");
                scanf("%d", &p.telefone.ddd);
                getchar();
                
                printf("Número: ");
                fgets(p.telefone.numero, 10, stdin);
                p.telefone.numero[strcspn(p.telefone.numero, "\n")] = 0;
                
                printf("Data de aniversário:\n");
                printf("Dia: ");
                scanf("%d", &p.aniversario.dia);
                printf("Mês: ");
                scanf("%d", &p.aniversario.mes);
                printf("Ano: ");
                scanf("%d", &p.aniversario.ano);
                
                insere_pessoa(p);
                break;
            }
            case 2: {
                char nome[MAX_STRING];
                printf("Digite o primeiro nome: ");
                fgets(nome, MAX_STRING, stdin);
                nome[strcspn(nome, "\n")] = 0;
                busca_por_primeiro_nome(nome);
                break;
            }
            case 3: {
                int mes;
                printf("Digite o mês (1-12): ");
                scanf("%d", &mes);
                busca_por_mes_aniversario(mes);
                break;
            }
            case 4: {
                int dia, mes;
                printf("Digite o dia: ");
                scanf("%d", &dia);
                printf("Digite o mês: ");
                scanf("%d", &mes);
                busca_por_dia_mes_aniversario(dia, mes);
                break;
            }
            case 5: {
                char nome[MAX_STRING];
                printf("Digite o nome da pessoa a ser removida: ");
                fgets(nome, MAX_STRING, stdin);
                nome[strcspn(nome, "\n")] = 0;
                retira_pessoa(nome);
                break;
            }
            case 6:
                imprime_agenda(1); // Resumido
                break;
            case 7:
                imprime_agenda(2); // Completo
                break;
        }
    } while(opcao != 0);
    
    return 0;
}

void menu() {
    printf("\n=== AGENDA TELEFÔNICA ===\n");
    printf("1. Inserir pessoa\n");
    printf("2. Buscar por primeiro nome\n");
    printf("3. Buscar por mês de aniversário\n");
    printf("4. Buscar por dia e mês de aniversário\n");
    printf("5. Remover pessoa\n");
    printf("6. Imprimir agenda (resumido)\n");
    printf("7. Imprimir agenda (completo)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

void imprime_pessoa(Pessoa p, int tipo) {
    if (tipo == 1) {
        printf("\nNome: %s\n", p.nome);
        printf("Telefone: (%d) %s\n", p.telefone.ddd, p.telefone.numero);
        printf("Email: %s\n", p.email);
    } else {
        printf("\nNome: %s\n", p.nome);
        printf("Email: %s\n", p.email);
        printf("Endereço: %s, %d, %s\n", p.endereco.rua, p.endereco.numero, p.endereco.complemento);
        printf("Bairro: %s\n", p.endereco.bairro);
        printf("CEP: %s\n", p.endereco.cep);
        printf("Cidade: %s/%s\n", p.endereco.cidade, p.endereco.estado);
        printf("País: %s\n", p.endereco.pais);
        printf("Telefone: (%d) %s\n", p.telefone.ddd, p.telefone.numero);
        printf("Aniversário: %d/%d/%d\n", p.aniversario.dia, p.aniversario.mes, p.aniversario.ano);
    }
}

void busca_por_primeiro_nome(char *nome) {
    int encontrou = 0;
    for(int i = 0; i < total_pessoas; i++) {
        char primeiro_nome[MAX_STRING];
        sscanf(agenda[i].nome, "%s", primeiro_nome);
        if(strcmp(primeiro_nome, nome) == 0) {
            imprime_pessoa(agenda[i], 2);
            encontrou = 1;
        }
    }
    if(!encontrou) printf("Nenhuma pessoa encontrada com esse nome.\n");
}

void busca_por_mes_aniversario(int mes) {
    int encontrou = 0;
    for(int i = 0; i < total_pessoas; i++) {
        if(agenda[i].aniversario.mes == mes) {
            imprime_pessoa(agenda[i], 2);
            encontrou = 1;
        }
    }
    if(!encontrou) printf("Nenhuma pessoa faz aniversário nesse mês.\n");
}

void busca_por_dia_mes_aniversario(int dia, int mes) {
    int encontrou = 0;
    for(int i = 0; i < total_pessoas; i++) {
        if(agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes) {
            imprime_pessoa(agenda[i], 2);
            encontrou = 1;
        }
    }
    if(!encontrou) printf("Nenhuma pessoa faz aniversário nessa data.\n");
}

void insere_pessoa(Pessoa p) {
    if(total_pessoas >= MAX_PESSOAS) {
        printf("Agenda cheia!\n");
        return;
    }
    
    int pos = total_pessoas;
    for(int i = 0; i < total_pessoas; i++) {
        if(strcmp(p.nome, agenda[i].nome) < 0) {
            pos = i;
            break;
        }
    }
    
    for(int i = total_pessoas; i > pos; i--) {
        agenda[i] = agenda[i-1];
    }
    
    agenda[pos] = p;
    total_pessoas++;
    printf("Pessoa inserida com sucesso!\n");
}

void retira_pessoa(char *nome) {
    int pos = -1;
    for(int i = 0; i < total_pessoas; i++) {
        if(strcmp(nome, agenda[i].nome) == 0) {
            pos = i;
            break;
        }
    }
    
    if(pos == -1) {
        printf("Pessoa não encontrada!\n");
        return;
    }
    
    for(int i = pos; i < total_pessoas-1; i++) {
        agenda[i] = agenda[i+1];
    }
    
    total_pessoas--;
    printf("Pessoa removida com sucesso!\n");
}

void imprime_agenda(int tipo) {
    if(total_pessoas == 0) {
        printf("Agenda vazia!\n");
        return;
    }
    
    for(int i = 0; i < total_pessoas; i++) {
        imprime_pessoa(agenda[i], tipo);
    }
}
