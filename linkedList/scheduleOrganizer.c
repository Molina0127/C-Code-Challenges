#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_COMPROMISSOS 20
#define MAX_TEXTO 200

// Estrutura para data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para horário
typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

// Estrutura para compromisso
typedef struct {
    char texto[MAX_TEXTO];
    Data data;
    Horario horario;
} Compromisso;

// Função para gerar número aleatório dentro de um intervalo
int numero_aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Função para inicializar compromisso com dados aleatórios
void inicializa_compromisso(Compromisso *comp) {
    // Gera data aleatória
    comp->data.dia = numero_aleatorio(1, 20);
    comp->data.mes = numero_aleatorio(1, 12);
    comp->data.ano = numero_aleatorio(2016, 2024);
    
    // Gera horário aleatório
    comp->horario.hora = numero_aleatorio(0, 23);
    comp->horario.minuto = numero_aleatorio(0, 59);
    comp->horario.segundo = numero_aleatorio(0, 59);
    
    // Define o texto padrão
    strcpy(comp->texto, "Compromisso de teste gerado aleatoriamente.");
}

// Função para imprimir um compromisso
void imprime_compromisso(int indice, Compromisso comp) {
    printf("\nCompromisso %d:\n", indice + 1);
    printf("Data: %02d/%02d/%04d\n", 
           comp.data.dia, 
           comp.data.mes, 
           comp.data.ano);
    printf("Horario: %02d:%02d:%02d\n", 
           comp.horario.hora, 
           comp.horario.minuto, 
           comp.horario.segundo);
    printf("Texto: %s\n", comp.texto);
}

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Cria vetor de compromissos
    Compromisso compromissos[MAX_COMPROMISSOS];
    
    // Inicializa todos os compromissos com dados aleatórios
    for(int i = 0; i < MAX_COMPROMISSOS; i++) {
        inicializa_compromisso(&compromissos[i]);
    }
    
    // Imprime todos os compromissos
    printf("========Lista de Compromissos========\n");
    for(int i = 0; i < MAX_COMPROMISSOS; i++) {
        imprime_compromisso(i, compromissos[i]);
    }
    
    return 0;
}
