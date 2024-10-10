#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para usar a função toupper()

typedef struct {
    char original[200];
    char traducao[200];
} texto;

int contalinhas(char dicfilename[]);
void leitura(texto dicionario[], char dicfilename[], int linhas);
void reescrita(texto dicionario[], char filename[], int linhas);

int main() {
    texto dicionario[100];
    char dicfilename[20], filename[20];
    int linhas;

    printf("Insira o nome do arquivo de dicionario: ");
    scanf("%s", dicfilename);

    system("clear");

    linhas = contalinhas(dicfilename);
    leitura(dicionario, dicfilename, linhas);

    printf("Insira o nome do arquivo para ser traduzido: ");
    scanf("%s", filename);

    reescrita(dicionario, filename, linhas);
    printf("Arquivo traduzido com sucesso!\n");

    return 0;
}

////////////////////////////////////////funções/////////////////////////////////////////////////////////////////

int contalinhas(char dicfilename[]) {
    FILE *arquivo = fopen(dicfilename, "r");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        exit(1);
    }

    int linhas = 0;
    char letra;

    while ((letra = fgetc(arquivo)) != EOF) {
        if (letra == '\n') linhas++;
    }

    fclose(arquivo);
    return linhas + 1;
}

void leitura(texto dicionario[], char dicfilename[], int linhas) {
    int i = 0;
    FILE *arquivo = fopen(dicfilename, "r");
    if (!arquivo) {
        printf("Arquivo de dicionario nao encontrado!\n");
        exit(1);
    }

    while (i < linhas && fscanf(arquivo, "%s %s", dicionario[i].original, dicionario[i].traducao) == 2) {
        i++;
    }

    fclose(arquivo);
}

void reescrita(texto dicionario[], char filename[], int linhas) {
    char palavra[200];
    int encontrou;

    FILE *arquivo_original = fopen(filename, "r");
    if (!arquivo_original) {
        printf("Arquivo a ser traduzido nao encontrado!\n");
        exit(1);
    }

    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (!arquivo_saida) {
        printf("Erro ao criar arquivo de saída!\n");
        exit(1);
    }

    while (fscanf(arquivo_original, "%s", palavra) != EOF) {
        encontrou = 0;

        // Verifica se a primeira letra é maiúscula
        int primeiraLetraMaiuscula = isupper(palavra[0]); 

        for (int i = 0; i < linhas; i++) {
            if (strcmp(palavra, dicionario[i].original) == 0) {
                // Se a palavra original era maiúscula, converte a tradução
                if (primeiraLetraMaiuscula) { 
                    dicionario[i].traducao[0] = toupper(dicionario[i].traducao[0]);
                }

                fprintf(arquivo_saida, "%s ", dicionario[i].traducao);
                encontrou = 1;
                break;
            }
        }

        if (!encontrou) {
            fprintf(arquivo_saida, "%s ", palavra);
        }
    }

    fclose(arquivo_original);
    fclose(arquivo_saida);
}

