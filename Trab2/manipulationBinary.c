#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char cod[8];
    char descricao[60];
    int qtd;
    float preco;
    char categoria[20];
    Data validade;
} Item;

void cadastrar() {
    
}

void alterar() {

}

void excluirLogicamente() {

}

void excluirFisicamente() {

}

void consultarCampoNumerico() {

}

void consultarCampoAlfaNumerico() {

}

int main() {
    int op;
    printf("Escolha entre as seguintes opcoes:\n1 - Cadastrar\n2 - Alterar\n3 - Excluir Logicamente\n4 - Excluir Fisicamente\n5 - Consultar Campo Numerico\n6 - Consultar Campo Alfa Numerico\n7 - Sair");
    scanf("%d", &op);

    switch (op) {
        case 1:
            cadastrar();
            break;
        case 2:
            alterar();
            break;
        case 3:
            excluirLogicamente();
            break;
        case 4:
            excluirFisicamente();
            break;
        case 5:
            consultarCampoAlfaNumerico();
            break;
        case 6:
            consultarCampoNumerico();
            break;
        case 7:
            printf("Saindo ...");
            break;
        default:
            printf("Opcao invalida");
            break;
    }

    return 0;
}