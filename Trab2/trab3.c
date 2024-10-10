#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // Para usar getch() e kbhit()

#define KEY_F1 13  // Código ASCII estendido para a tecla F1

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    char cod[8];
    char descricao[60];
    int qtd;
    int existe;
    float preco;
    char categoria[20];
    data validade;
} item;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para criptografar/descriptografar um arquivo de texto
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
        fputc(ch ^ chave[i], arquivoSaida); // Operação XOR para criptografar
        i = (i + 1) % strlen(chave);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}

// Função para exibir o arquivo de ajuda criptografado
void exibirAjuda(const char *nomeArquivoAjuda, const char *chave) {
    // Descriptografa o arquivo de ajuda temporariamente
    criptografarArquivo(nomeArquivoAjuda, "temp_ajuda.txt", chave);

    // Abre o arquivo de ajuda descriptografado
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

    // Exclui o arquivo de ajuda temporário
    remove("temp_ajuda.txt");
}

// Função para cadastrar um novo item no arquivo
void cadastrar() {
    int quant;

    printf("Insira quantos cadastros serao feitos: ");
    scanf("%i", &quant);
    limparBuffer();
    system("clear");

    item cadastro;

    FILE *arquivo = fopen("registros.bin", "ab");
    if (!arquivo) {
        printf("\nErro ao abrir arquivo!\n");
        return;
    }

    for (int i = 0; i < quant; i++) {
        printf("Inserir codigo de produto: ");
        fgets(cadastro.cod, 8, stdin);
        strtok(cadastro.cod, "\n");
        system("clear");

        printf("Inserir descricao: ");
        fgets(cadastro.descricao, 60, stdin);
        strtok(cadastro.descricao, "\n"); 
        system("clear");

        printf("Inserir quantidade de itens: ");
        scanf("%i", &cadastro.qtd);
        limparBuffer();
        system("clear");

        cadastro.existe = 1;

        printf("Inserir preco: ");
        scanf("%f", &cadastro.preco);
        limparBuffer();
        system("clear");

        printf("Inserir categoria: ");
        fgets(cadastro.categoria, 20, stdin);
        strtok(cadastro.categoria, "\n"); 
        system("clear");

        printf("Inserir validade (dd/mm/aaaa): ");
        scanf("%i/%i/%i", &cadastro.validade.dia, &cadastro.validade.mes, &cadastro.validade.ano);
        limparBuffer();
        system("clear");

        fwrite(&cadastro, sizeof(item), 1, arquivo);
    }

    fclose(arquivo);
    printf("Arquivos salvos com sucesso!\n");
}

// Função para contar a quantidade de registros no arquivo
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

// Função para ler e exibir todos os itens do arquivo
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
    int exibidos = 0;

    for (int i = 0; i < quant; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if (cadastro.existe) {
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %02i/%02i/%04i\n",
                   cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, cadastro.categoria,
                   cadastro.validade.dia, cadastro.validade.mes, cadastro.validade.ano);
            exibidos++;
        }
    }

    if (exibidos == 0) {
        printf("Nenhum registro ativo encontrado.\n");
    }

    fclose(arquivo);
}

// Função para alterar a quantidade de um item no arquivo
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

    for (int i = 0; i < quant && !encontrado; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if (strcmp(cadastro.cod, codBusca) == 0 && cadastro.existe) {
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

    fclose(arquivo);

    if (!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    } else {
        printf("Quantidade de itens alterada com sucesso!\n");
    }
}

// Função para consultar um item por código
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

    for (int i = 0; i < quant && !encontrado; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if (strcmp(cadastro.cod, codBusca) == 0 && cadastro.existe) {
            printf("Produto encontrado!\n");
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n",
                   cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, cadastro.categoria,
                   cadastro.validade.dia, cadastro.validade.mes, cadastro.validade.ano);
            encontrado = 1;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codBusca);
    }
}

// Função para consultar um item por quantidade
void consultarPorQuantidade() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado para consulta.\n");
        return;
    }

    FILE *arquivo = fopen("registros.bin", "rb");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    item cadastro;
    int quantidade, encontrado = 0;

    printf("Digite a quantidade de itens do produto que voce deseja encontrar:\n");
    scanf("%d", &quantidade);
    limparBuffer(); // Limpar o buffer após a leitura do inteiro

    for (int i = 0; i < quant; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if (cadastro.qtd == quantidade && cadastro.existe) {
            printf("\nCodigo do Produto: %s\nDescricao: %s\nQuantidade de Itens: %i\nPreco: %.2f\nCategoria: %s\nData de validade: %i/%i/%i\n",
                   cadastro.cod, cadastro.descricao, cadastro.qtd, cadastro.preco, cadastro.categoria,
                   cadastro.validade.dia, cadastro.validade.mes, cadastro.validade.ano);
            encontrado = 1;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Produto com a quantidade de itens %d nao foi encontrado.\n", quantidade);
    }
}


// Função para excluir logicamente um item no arquivo
void excluirLogicamente() {
    int quant = contarRegistros();
    if (quant == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    FILE *arquivo = fopen("registros.bin", "r+b");
    if (!arquivo) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    item cadastro;
    char codDelecao[8];
    int encontrado = 0;

    printf("Digite o codigo do produto que voce deseja excluir:\n");
    limparBuffer();
    fgets(codDelecao, sizeof(codDelecao), stdin);
    strtok(codDelecao, "\n");

    for (int i = 0; i < quant && !encontrado; i++) {
        fread(&cadastro, sizeof(item), 1, arquivo);
        if (strcmp(cadastro.cod, codDelecao) == 0) {
            printf("Produto encontrado!\n");
            cadastro.existe = 0;
            fseek(arquivo, -sizeof(item), SEEK_CUR);
            fwrite(&cadastro, sizeof(item), 1, arquivo);
            encontrado = 1;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Produto com codigo %s nao encontrado.\n", codDelecao);
    } else {
        printf("Produto excluído logicamente com sucesso!\n");
    }
}

// Função para excluir fisicamente os itens marcados para exclusão
void excluirFisicamente() {
    FILE *arquivo = fopen("registros.bin", "rb");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    item cadastro;
    int encontrado = 0;

    while (fread(&cadastro, sizeof(item), 1, arquivo) == 1) {
        if (cadastro.existe) {
            fwrite(&cadastro, sizeof(item), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("registros.bin");
        rename("temp.bin", "registros.bin");
        printf("Itens excluidos fisicamente com sucesso!\n");
    } else {
        remove("temp.bin");
        printf("Nenhum item marcado para exclusao.\n");
    }
}

int main() {
    int op;

    // Criptografa o arquivo de ajuda (apenas uma vez no início)
    criptografarArquivo("ajuda.txt", "ajuda.enc", "MinhaChaveSecreta"); 

    do {
        printf("Escolha entre as seguintes opcoes:\n");
        printf("1 - Cadastrar Item\n2 - Ler Itens\n3 - Alterar Item\n");
        printf("4 - Consultar item por codigo\n5 - Consultar item por quantidade\n");
        printf("6 - Excluir item logicamente\n7 - Excluir item fisicamente\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        limparBuffer();

        // Verifica se a tecla F1 foi pressionada
        if (kbhit() && getch() == KEY_F1) {
            exibirAjuda("ajuda.enc", "MinhaChaveSecreta");
        } else {
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