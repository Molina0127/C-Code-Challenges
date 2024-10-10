#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    char cod[8];
    char descricao[60];
    int qtd;
    float preco;
    char categoria[20];
    data validade;
} item;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar(item cadastro[], int quant){

    for(int i = 0; i < quant; i++) {
        printf("Inserir codigo de produto: ");
        fgets(cadastro[i].cod, 8, stdin);
        //limparBuffer(); 
        system("clear");

        printf("Inserir descricao: ");
        fgets(cadastro[i].descricao, 60, stdin);
        system("clear");

        printf("Inserir quantidade de itens: ");
        scanf("%i", &cadastro[i].qtd);
        limparBuffer(); 
        system("clear");

        printf("Inserir preco: ");
        scanf("%f", &cadastro[i].preco);
        limparBuffer(); 
        system("clear");

        printf("Inserir categoria: ");
        fgets(cadastro[i].categoria, 20, stdin);
        system("clear");

        printf("Inserir validade (dd/mm/aaaa): ");
        scanf("%i/%i/%i", &cadastro[i].validade.dia, &cadastro[i].validade.mes, &cadastro[i].validade.ano);
        limparBuffer(); 
        system("clear");
    }
}

void ler(item cadastro[], FILE *arquivo) {
    int i = 0;

    if(arquivo) {
        while(!feof(arquivo)) {
            if(fread(&cadastro[i], sizeof(item), 1, arquivo)) {
                printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n", cadastro[i].cod, cadastro[i].descricao, cadastro[i].qtd, cadastro[i].preco, cadastro[i].categoria, cadastro[i].validade.dia, cadastro[i].validade.mes, cadastro[i].validade.ano);
                i++;
            }
        }
    }
    else {
        printf("\nArquivo nao encontrado\n");
    }
}

void alterar(item cadastro[], int quant, FILE *arquivo) {
    char codBusca[8];
    int novaQtd, encontrado = 0;
    
    printf("Digite o codigo do produto que voce deseja alterar:\n");
    fgets(codBusca, 8, stdin);

    for(int i = 0; i < quant && encontrado == 0; i++) {
        fread(&cadastro[i], sizeof(item), 1, arquivo);
        if(strcmp(cadastro[i].cod, codBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("Quantidade atual de itens: %i\n", cadastro[i].qtd);
            printf("Digite a nova quantidade: ");
            scanf("%i", &novaQtd);
            limparBuffer();

            cadastro[i].qtd = novaQtd;

            fseek(arquivo, -sizeof(item), SEEK_CUR);

            fwrite(&cadastro[i], sizeof(item), 1, arquivo);
            encontrado = 1;
        }
    }

    if(!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    }
    else {
        printf("Quantidade de itens alterada com sucesso!\n");
    }

}

void consultarPorCodigo(item cadastro[], int quant, FILE *arquivo) {
    char codBusca[8];
    int encontrado = 0;
    
    printf("Digite o codigo do produto que voce deseja consultar:\n");
    fgets(codBusca, 8, stdin);
    
    for (int i = 0; i < quant && encontrado == 0; i++) {
        fread(&cadastro[i], sizeof(item), 1, arquivo);
        if(strcmp(cadastro[i].cod, codBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n", cadastro[i].cod, cadastro[i].descricao, cadastro[i].qtd, cadastro[i].preco, cadastro[i].categoria, cadastro[i].validade.dia, cadastro[i].validade.mes, cadastro[i].validade.ano);
            
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    }
    
}

void consultarPorQuantidade(item cadastro[], int quant, FILE *arquivo) {
    int quantidade, encontrado = 0;
    
    printf("Digite a quantidade de itens do produto que voce deseja encontrar:\n");
    scanf("%d", &quantidade);
    
    for (int i = 0; i < quant; i++) {
        fread(&cadastro[i], sizeof(item), 1, arquivo);
        if(cadastro[i].qtd == quantidade) {
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n", cadastro[i].cod, cadastro[i].descricao, cadastro[i].qtd, cadastro[i].preco, cadastro[i].categoria, cadastro[i].validade.dia, cadastro[i].validade.mes, cadastro[i].validade.ano);
        
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("Produto com a quantidade de itens %d nao foi encontrado.\n", quantidade);
    }
}

int main(){
    int quant;

    printf("Insira quantos cadastros serao feitos: ");
    scanf("%i", &quant);
    limparBuffer();
    system("clear");

    item cadastro[quant];  

    FILE *arquivo = fopen("registros.bin", "w+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }

    cadastrar(cadastro,quant);
    fwrite(cadastro, sizeof(item), quant, arquivo);

    fclose(arquivo);
    printf("Arquivos salvos com sucesso!\n");

    arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }

    ler(cadastro, arquivo);
    fclose(arquivo);

    arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }

    alterar(cadastro, 10, arquivo);
    fclose(arquivo);

    arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }

    consultarPorCodigo(cadastro, 10, arquivo);
    fclose(arquivo);
    
    arquivo = fopen("registros.bin", "r+b");
    if(!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return 1;
    }
    
    consultarPorQuantidade(cadastro, 10, arquivo);
    fclose(arquivo);

    return 0;
}

