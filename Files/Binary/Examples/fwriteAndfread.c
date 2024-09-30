#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int dia, mes, ano;
} Cadastro;

void escrever(char arq[]) {
    Cadastro cad;
    FILE *file = fopen(arq, "ab");

    if(file) {
        printf("Digite o nome e a data de inicio na empresa: ");
        getchar();
        scanf("%49[^\n] %d %d %d", cad.nome, &cad.dia, &cad.mes, &cad.ano);
        fwrite(&cad, sizeof(Cadastro), 1, file);
        fclose(file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }
}

void ler(char arq[]) {
    Cadastro cad;
    FILE *file = fopen(arq, "rb");

    printf("\n");

    if(file) {
        while(!feof(file)) {
            if(fread(&cad, sizeof(Cadastro), 1, file)) {
                printf("Nome: %s\nData de admissao: %d/%d/%d\n", cad.nome, cad.dia, cad.mes, cad.ano);
            }
        }
        fclose(file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }

    printf("\n");

}

int main() {

    int op = 0;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Adicionar um cadastro\n");
        printf("2. Ler os cadastros\n");
        printf("3. Sair\n");
        scanf("%d", &op);

        char arquivo[] = {"arquivo.dat"};

        switch (op) {
            case 1:
                escrever(arquivo);
                break;
            case 2:
                ler(arquivo);
                break;
            case 3:
                printf("Saindo ...\n");
                break;
            default:
                printf("Opcao invalida");
                break;
        }

    } while(op != 3);

    return 0;
}