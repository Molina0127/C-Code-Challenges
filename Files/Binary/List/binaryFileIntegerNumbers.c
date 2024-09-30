#include <stdio.h>
#include <stdlib.h>
/* Binary File - List 4 - Exercise 1 & 2 */
void addIntegerNumbers(char arq[]) {
    FILE *file = fopen(arq, "ab");    
    int num;

    if(file) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }
    fclose(file);

}

void readIntegerNumbers(char arq[]) {
    FILE *file = fopen(arq, "rb");
    int num;

    if(file) {
        while(!feof(file)) {
            if(fread(&num, sizeof(int), 1, file)) {
                printf("Numero: %d\n", num);
            }
        }
        fclose(file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }

}

void createFile(char arq[]) {
    FILE *file = fopen(arq, "wb");
    int num;

    if(file) {
        printf("Dados do arquivo foram excluidos\n");
        fclose(file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }

}

int main()
{
    int op = 0;
    int num = 0;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Criar arquivo\n");
        printf("2. Adicionar numeros inteiros\n");
        printf("3. Ler os numeros inteiros\n");
        printf("4. Limpar o arquivo\n");
        printf("5. Sair\n");
        scanf("%d", &op);

        char arquivo[] = {"dados.bin"};
        
        switch (op) {
            case 1:
                createFile(arquivo);
                break;
            case 2:
                printf("Digite o numero de inteiros que deseja inserir: ");
                scanf("%d", &num);
                for(int i = 0; i < num; i++) {
                    addIntegerNumbers(arquivo);
                }
                break;
            case 3:
                readIntegerNumbers(arquivo);
                break;
            case 4:
                createFile(arquivo);
                break;
            case 5:
                printf("Saindo ...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

    } while(op != 3);

    return 0;
}
