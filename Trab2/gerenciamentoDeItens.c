#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

void F1() {
    int condicao = 0;
    initscr();
    keypad(stdscr, TRUE);
    do {
        clear();
        printw("Ajuda do Programa:\n");
        printw("Use as setinhas para escolher uma das opcoes de formatacao do arquivo binario.\n");
        printw("Pressione F1 para sair da ajuda...\n");
        refresh();

        int tecla = getch();
        if (tecla == KEY_F(1)) condicao = 1;

    } while (condicao == 0);

    endwin();
}

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
    char codBusca[8];
    int encontrado = 0;
    
    printf("Digite o codigo do produto que deseja excluir logicamente:\n");
    limparBuffer();
    fgets(codBusca, sizeof(codBusca), stdin);
    strtok(codBusca, "\n");

    while (fread(&cadastro, sizeof(item), 1, arquivo)) {
        if (strcmp(cadastro.cod, codBusca) == 0) {
            if (cadastro.existe == 0) {
                printf("O produto ja foi excluido.\n");
                fclose(arquivo);
                return;
            }
            cadastro.existe = 0; // Exclusão lógica
            fseek(arquivo, -sizeof(item), SEEK_CUR);
            fwrite(&cadastro, sizeof(item), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    } else {
        printf("Produto excluido logicamente com sucesso.\n");
    }

    fclose(arquivo);
}

int main() {
    int escolha;
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    
    do {
        clear();
        printw("Menu Principal:\n");
        printw("1. Cadastrar\n");
        printw("2. Ler\n");
        printw("3. Alterar\n");
        printw("4. Consultar por código\n");
        printw("5. Consultar por quantidade\n");
        printw("6. Excluir logicamente\n");
        printw("0. Sair\n"); // Linha correta para "0. Sair"
        printw("Pressione F1 para ajuda\n"); // Separada corretamente
        refresh();

        int tecla = getch(); 

        if (tecla == KEY_F(1)) {
            F1();
        } else {
            escolha = tecla - '0'; // Converte a tecla para número

            switch(escolha) {
                case 1: /* Função cadastrar */ break;
                case 2: /* Função ler */ break;
                case 3: /* Função alterar */ break;
                case 4: /* Função consultarPorCodigo */ break;
                case 5: /* Função consultarPorQuantidade */ break;
                case 6: /* Função excluirLogicamente */ break;
                case 0: printw("Saindo...\n"); break;
                default: printw("Opcao invalida!\n"); break;
            }
        }

        refresh();
        printw("Pressione qualquer tecla para continuar...\n");
        getch();
    } while (escolha != 0);

    endwin();

    return 0;
}
