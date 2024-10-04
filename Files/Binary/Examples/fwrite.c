#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    int dia, mes, ano;
} Contato;

void escrever(char arq[]) {
    Contato c;
    FILE *file = fopen(arq, "ab");

    if(file) {
        printf("Digite o nome e a data de nascimento dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else {
        printf("\nErro ao abrir arquivo!\n");
    }
}

void ler(char arq[]) {
    Contato c;
    FILE *file = fopen(arq, "rb");

    if (file) {
        while(!feof(file)) {
            if(fread(&c, sizeof(Contato), 1, file)) {
                printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
            }
        }
        fclose(file);
    }
    else {
        printf("\nErro ao abrir aquivo!\n");
    }
}

int main() {
    char arquivo[] = {"arquivo.dat"};

    escrever(arquivo);

    ler(arquivo);

    return 0;
}

/*
Em um arquivo texto, qualquer alteração que eu queira fazer
nos dados que foram salvos no arquivo, eu preciso carregar todo
o arquivo para a memória, fazer a alteração e depois escrever todo
esse conteúdo novamente no arquivo.

No arquivo binário é possível fazer a alteração, indo diretamente no
registro desejado, fazer a leitura daquele registro, alterar e escrever
ele na mesma posição que o seu arquivo estava anteriormente, porque quando
se trabalha com arquivos binários, os arquivos são lidos por blocos
de bytes.
*/