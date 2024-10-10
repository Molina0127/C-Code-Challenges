#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define KEY_F1 59 // Código da tecla F1
#define CHAVE_CRIPTOGRAFIA "SuaChaveSecreta" // Chave para criptografia

// String contendo as instruções de ajuda criptografadas
const char *instrucoesCriptografadas = 
    "\x1F\x0A\x15\x04\x0E\x09\x02\x0C\x03\x0C\x0B\x0A\x01\x09\x10\x03"
    "\x19\x07\x08\x14\x05\x10\x00\x01\x04\x1D\x03\x04\x08\x0F\x00\x02"
    "\x00\x14\x13\x0F\x01\x04\x0B\x08\x04\x09\x01\x04\x0E\x11\x02\x0C"
    // ... (resto da string criptografada) ...
;

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
    int existe;
} item;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para criptografar/descriptografar um arquivo de texto (XOR simples)
void criptografarArquivo(const char *nomeArquivoEntrada, const char *nomeArquivoSaida, const char *chave) {
    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "rb");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "wb");
    char ch;
    int i = 0;

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir arquivos para criptografia.\n");
        return;
    }

    while ((ch = fgetc(arquivoEntrada)) != EOF) {
        fputc(ch ^ chave[i], arquivoSaida); 
        i = (i + 1) % strlen(chave);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}

void exibirAjuda(const char *nomeArquivoAjuda, const char *chave) {
    // Descriptografa o arquivo de ajuda temporariamente
    criptografarArquivo(nomeArquivoAjuda, "temp_ajuda.txt", chave);

    FILE *arquivoAjuda = fopen("temp_ajuda.txt", "r");
    if (arquivoAjuda == NULL) {
        printf("Arquivo de ajuda não encontrado.\n");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivoAjuda) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivoAjuda);
    remove("temp_ajuda.txt"); 
}

void cadastrar() {
    int quant;

    printf("Insira quantos cadastros serao feitos: ");
    scanf("%i", &quant);
    limparBuffer();  
    system("clear");

    item cadastro[quant];

    FILE *arquivo = fopen("registros.bin", "ab");
    if (!arquivo) {
        printf("\nErro ao abrir arquivo!\n");
        return;
    }

    for(int i = 0; i < quant; i++) {
        printf("Inserir codigo de produto: ");
        fgets(cadastro[i].cod, 8, stdin);
        strtok(cadastro[i].cod, "\n");
        //limparBuffer(); 
        system("clear");

        printf("Inserir descricao: ");
        fgets(cadastro[i].descricao, 60, stdin);
        strtok(cadastro[i].cod, "\n");
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
        strtok(cadastro[i].cod, "\n");
        system("clear");

        printf("Inserir validade (dd/mm/aaaa): ");
        scanf("%i/%i/%i", &cadastro[i].validade.dia, &cadastro[i].validade.mes, &cadastro[i].validade.ano);
        limparBuffer(); 
        system("clear");

        cadastro[i].existe = 1;
    }
    
    //cadastrar(cadastro,quant);
    fwrite(cadastro, sizeof(item), quant, arquivo);
    fclose(arquivo);
    printf("Arquivos salvos com sucesso!\n");
    
}

int contarRegistros() {
    FILE *arquivo = fopen("registros.bin", "rb");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return 0;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho / sizeof(item);
}

void ler() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    FILE *arquivo = fopen("registros.bin", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    item cadastro;
    int encontrados = 0;

    printf("Registros existentes:\n");
    for (int i = 0; i < quant; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);

        // Verifica se o registro existe logicamente ANTES de exibi-lo
        if (cadastro.existe) { 
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %02i/%02i/%04i\n", 
                   cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, 
                   cadastro.categoria, cadastro.validade.dia, cadastro.validade.mes, 
                   cadastro.validade.ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum registro ativo encontrado.\n");
    }
    fclose(arquivo);
}

void alterar() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    FILE *arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return;
    }

    item cadastro;
    char codBusca[8];
    int novaQtd, encontrado = 0;
    
    printf("Digite o codigo do produto que voce deseja alterar:\n");
    limparBuffer();
    fgets(codBusca, 8, stdin);
    strtok(codBusca, "\n");

    for(int i = 0; i < quant && encontrado == 0; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if(strcmp(cadastro.cod, codBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("Quantidade atual de itens: %i\n", cadastro.qtd);
            printf("Digite a nova quantidade: ");
            scanf("%i", &novaQtd);
            limparBuffer();

            cadastro.qtd = novaQtd;
            fseek(arquivo, -sizeof(item), SEEK_CUR);
            fwrite(&cadastro, sizeof(item), 1, arquivo);
            encontrado = 1;
        }
    }

    if(!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    }
    else {
        printf("Quantidade de itens alterada com sucesso!\n");
    }

    fclose(arquivo);
}

void consultarPorCodigo() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    FILE *arquivo = fopen("registros.bin", "rb");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return;
    }
    
    item cadastro;
    char codBusca[8];
    int encontrado = 0;
    
    printf("Digite o codigo do produto que voce deseja consultar:\n");
    limparBuffer();
    fgets(codBusca, sizeof(codBusca), stdin);
    strtok(codBusca, "\n");
    
    for (int i = 0; i < quant && encontrado == 0; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if(strcmp(cadastro.cod, codBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n", cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, cadastro.categoria, cadastro.validade.dia, cadastro.validade.mes, cadastro.validade.ano);
            
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    }

    fclose(arquivo);
}

void consultarPorQuantidade() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado para consulta.\n");
        return;
    }
    
    FILE *arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return;
    }
    
    item cadastro;
    int quantidade, encontrado = 0;
    
    printf("Digite a quantidade de itens do produto que voce deseja encontrar:\n");
    scanf("%d", &quantidade);
    
    for (int i = 0; i < quant; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if(cadastro.qtd == quantidade) {
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n", cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, cadastro.categoria, cadastro.validade.dia, cadastro.validade.mes, cadastro.validade.ano);
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("Produto com a quantidade de itens %d nao foi encontrado.\n", quantidade);
    }

    fclose(arquivo);
}

void excluirLogicamente() {
    FILE *arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    item cadastro;
    char codExclusao[8];
    int encontrado = 0;

    printf("Digite o codigo do produto a ser excluido logicamente: ");
    limparBuffer();
    fgets(codExclusao, sizeof(codExclusao), stdin);
    strtok(codExclusao, "\n"); // Remover o \n caso o usuário pressione enter

    while (fread(&cadastro, sizeof(item), 1, arquivo) == 1) {
        if (strcmp(cadastro.cod, codExclusao) == 0 && cadastro.existe) {
            encontrado = 1;
            cadastro.existe = 0; // Marcar como excluído logicamente
            fseek(arquivo, -sizeof(item), SEEK_CUR); // Voltar o ponteiro para o início do registro
            fwrite(&cadastro, sizeof(item), 1, arquivo); // Sobrescrever o registro
            printf("Produto com codigo %s excluido logicamente.\n", codExclusao);
            break; // Sair do loop após encontrar e excluir o produto
        }
    }

    if (!encontrado) {
        printf("Produto com codigo %s nao encontrado ou ja excluido logicamente.\n", codExclusao);
    }

    fclose(arquivo);
}

void excluirFisicamente() {
    FILE *arquivoOriginal = fopen("registros.bin", "rb");
    if (!arquivoOriginal) {
        printf("Erro ao abrir arquivo de produtos!\n");
        return;
    }

    FILE *arquivoTemporario = fopen("temp.bin", "wb");
    if (!arquivoTemporario) {
        printf("Erro ao criar arquivo temporario!\n");
        fclose(arquivoOriginal);
        return;
    }

    char codExclusao[8];
    item cadastro;
    int encontrado = 0;

    printf("Digite o codigo do produto a ser excluido fisicamente: ");
    limparBuffer();
    fgets(codExclusao, sizeof(codExclusao), stdin);
    codExclusao[strcspn(codExclusao, "\n")] = 0;

    // Copia os dados para o arquivo temporário, exceto o item a ser excluído
    while (fread(&cadastro, sizeof(item), 1, arquivoOriginal) == 1) {
        if (strcmp(cadastro.cod, codExclusao) != 0) {
            fwrite(&cadastro, sizeof(item), 1, arquivoTemporario);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    if (encontrado) {
        remove("registros.bin");
        rename("temp.bin", "registros.bin");
        printf("Produto com codigo %s excluido fisicamente.\n", codExclusao);
    } else {
        remove("temp.bin"); // Remove o arquivo temporário se o produto não for encontrado
        printf("Produto com codigo %s nao encontrado.\n", codExclusao);
    }
}

void exibirAjuda() {
    FILE *arquivoAjuda = fopen("ajuda.txt", "r");
    if (arquivoAjuda == NULL) {
        printf("Erro ao abrir arquivo de ajuda.\n");
        return;
    }

    printf("\n--- Arquivo de Ajuda ---\n");
    char linhaCriptografada[256];
    while (fgets(linhaCriptografada, sizeof(linhaCriptografada), arquivoAjuda) != NULL) {
        int tamanhoLinha = strlen(linhaCriptografada);

        // Descriptografa a linha lida do arquivo
        for (int i = 0; i < tamanhoLinha; i++) {
            putchar(linhaCriptografada[i] ^ CHAVE_CRIPTOGRAFIA[i % strlen(CHAVE_CRIPTOGRAFIA)]); 
        }
    }

    fclose(arquivoAjuda);
}

int main() {
    int op;

    // Grava as instruções criptografadas no arquivo ajuda.txt no início do programa
    FILE *arquivoAjuda = fopen("ajuda.txt", "w");
    if (arquivoAjuda == NULL) {
        printf("Erro ao criar arquivo de ajuda.\n");
        return 1;
    }
    fprintf(arquivoAjuda, "%s", instrucoesCriptografadas);
    fclose(arquivoAjuda);

    do {
        printf("Escolha entre as seguintes opcoes:\n");
        printf("1 - Cadastrar Item\n2 - Ler Itens\n3 - Alterar Item\n4 - Consultar item por codigo\n5 - Consultar item por quantidade\n6 - Excluir item logicamente\n7 - Excluir item fisicamente\n0 - Sair\nPressione F1 para ajuda\n");
        scanf("%d", &op);
        limparBuffer();
        
        
        // Verifica se a tecla F1 foi pressionada
        if (kbhit()) {
            int ch = getch();
            if (ch == 224) { // Primeiro código das teclas estendidas (teclas de função)
                ch = getch(); // Obtém o código real da tecla
                if (ch == KEY_F1) {
                    exibirAjuda();
                }
            }
        }
        else {
            switch (op) {
                case 1:
                cadastrar();
                break;
            case 2:
                ler();
                break;
            case 3:
                alterar();
                break;
            case 4:
                consultarPorCodigo();
                break;
            case 5:
                consultarPorQuantidade();
                break;
            case 6:
                excluirLogicamente();
                break;
            case 7:
                excluirFisicamente();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
        }
        
    } while (op != 0);

    return 0;
}