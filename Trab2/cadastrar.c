#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cod[8];
    char descricao[60];
    int qtd;
    float preco;
    char categoria[20];
    Data validade;
} Item;

void cadastrar(item *cadastro) {
    printf("Inserir codigo de produto: ")ç
    scanf("%i", cadastro->cod);
    system("clear");
    
    printf("Inserir descricao: ");
    fgets(cadastro.descricao,60,stdin);
    system("clear");
    
    printf("Inserir quantidade de itens: ");
    scanf("%i",cadastro->qtd);
    system("clear");
    
    printf("Inserir preco: ");
    scanf("%.2f",cadastro->preco);
    system("clear");
    
    printf("Inserir categoria: ");
    fgets(cadastro.categoria,20,stdin);
    system("clear");
    
    
    
    int main(){
        item cadastro;
        FILE *arquivo = fopen ("registros.bin","w+b");
        if(!arquivo){
            printf("arquivo nao encontrado!");
            exit;
        }
        
        
        cadastrar(estoque);
        return 0;
    }
