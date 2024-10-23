#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
/* Structs - List 2 - Exercise 1 */
struct band {
    char name[50];
    char musicStyle[30];
    int members;
    int rankingPosition;
};

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void treatSentence(char *sentence) {
    char *p;
    if(p = strchr(sentence, '\n')) {
        *p = 0;
    }
}

void toUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void registerBand(int bandsNumber, struct band bands[]) {
    for(int i = 0; i < bandsNumber; i++) {
        printf("Digite o nome da banda:\n");
        fgets(bands[i].name, 50, stdin);
        treatSentence(bands[i].name);
        
        printf("Digite o estilo musical da banda:\n");
        fgets(bands[i].musicStyle, 30, stdin);
        treatSentence(bands[i].musicStyle);

        printf("Digite o numero de membros da banda:\n");
        scanf("%d", &bands[i].members);
        clearBuffer();  // Aqui sim precisa do clearBuffer após scanf

        printf("Digite a posicao que a banda esta no seu TOP-5 bandas favoritas (Caso nao esteja no seu TOP-5, Digite 0)\n");
        scanf("%d", &bands[i].rankingPosition);
        clearBuffer();  // Aqui também precisa após scanf
    }
}

void showAllBands(int bandsNumber, struct band bands[]) {
    printf("\n");
    for (int i = 0; i < bandsNumber; i++) {
        printf("--------------------------------------\n");
        printf("Nome da banda: %s\n", bands[i].name);
        printf("Estilo musical da banda: %s\n", bands[i].musicStyle);
        printf("Numero de membros da banda: %d\n", bands[i].members);
        printf("Posicao da banda no seu TOP-5: %d\n", bands[i].rankingPosition);
        printf("--------------------------------------\n\n");
    }
}

void searchBand(int bandsNumber, struct band bands[]) {
    int searchRanking;
    int check = 0;
    printf("Vamos encontrar uma banda, de acordo com a sua posicao no seu ranking de bandas\n");
    printf("Digite o ranking da banda que deseja encontrar:\n");
    scanf("%d", &searchRanking);

    for (int i = 0; i < bandsNumber && check == 0; i++) {
        if (bands[i].rankingPosition == searchRanking) {
            printf("A banda com o ranking que voce digitou foi encontrada\n");
            printf("Nome da banda: %s\n", bands[i].name);
            printf("Estilo musical da banda: %s\n", bands[i].musicStyle);
            printf("Numero de membros da banda: %d\n", bands[i].members);
            printf("Posicao da banda no seu TOP-5: %d\n", bands[i].rankingPosition);
            check = 1;
        }
    }
    if (check == 0) {
        printf("\n\nDesculpe, mas parece que nenhuma banda possui o ranking que voce digitou '-'\n");
    }
}

void listBandsByMusicalStyle(int bandsNumber, struct band bands[]) {
    int check = 0;
    char musicStyleCopy[30];
    char bandStyleCopy[30];

    printf("Digite o estilo musical das bandas que quer encontrar:\n");
    fgets(musicStyleCopy, 30, stdin);
    treatSentence(musicStyleCopy);
    toUpper(musicStyleCopy);

    for (int i = 0; i < bandsNumber; i++) {
        strcpy(bandStyleCopy, bands[i].musicStyle);
        toUpper(bandStyleCopy);

        if (strcmp(musicStyleCopy, bandStyleCopy) == 0) {
            check++;
            printf("--------------------------------------\n");
            printf("Nome da banda: %s\n", bands[i].name);
            printf("Estilo musical da banda: %s\n", bands[i].musicStyle);
            printf("Numero de membros da banda: %d\n", bands[i].members);
            printf("Posicao da banda no seu TOP-5: %d\n", bands[i].rankingPosition);
            printf("--------------------------------------\n\n");
        }
    }
    if (check == 0) {
        printf("Desculpe, mas nao ha nenhuma banda, com o estilo que voce pesquisou '-'");
    }
}

void verifyBandInRanking(int bandsNumber, struct band bands[]) {
    int check = 0;
    char bandName[30];
    char bandNameCopy[30];

    printf("Digite o nome da banda que deseja verificar se esta no ranking:\n");
    fgets(bandName, 30, stdin);
    treatSentence(bandName);
    toUpper(bandName);

    for (int i = 0; i < bandsNumber; i++) {
        strcpy(bandNameCopy, bands[i].name);
        toUpper(bandNameCopy);

        if (
            (strcmp(bandNameCopy, bandName) == 0) && 
            (bands[i].rankingPosition == 1) || (bands[i].rankingPosition == 2) || (bands[i].rankingPosition == 3) || (bands[i].rankingPosition == 4) || (bands[i].rankingPosition == 5)
            ) {
            check++;
            printf("--------------------------------------\n");
            printf("Nome da banda: %s\n", bands[i].name);
            printf("Estilo musical da banda: %s\n", bands[i].musicStyle);
            printf("Numero de membros da banda: %d\n", bands[i].members);
            printf("Posicao da banda no seu TOP-5: %d\n", bands[i].rankingPosition);
            printf("--------------------------------------\n\n");
        }
    }
    if (check == 0) {
        printf("Desculpe, mas nao ha nenhuma banda, com o estilo que voce pesquisou '-'");
    }
}

int main() {
    int bandsNumber, op;
    printf("Digite o numero de bandas a serem criadas (MAX 50): ");
    scanf("%d", &bandsNumber);
    clearBuffer();
    
    struct band bands[bandsNumber];
    registerBand(bandsNumber, bands);

    printf("Escolha uma opcao (Digite o numero correspondente para acessa-la)\n");
    printf("1 - Mostrar todas as bandas\n2 - Pesquisar banda por Ranking\n3 - Listar Bandas por estilo musical\n4 - Verificar se a banda esta entre as favoritas\n");
    scanf("%d", &op);
    clearBuffer();

    switch (op) {
        case 1:
            showAllBands(bandsNumber, bands);
            break;
        case 2:
            searchBand(bandsNumber, bands);
            break;
        case 3:
            listBandsByMusicalStyle(bandsNumber, bands);
            break;
        case 4:
            verifyBandInRanking(bandsNumber, bands);
            break;
        default:
            printf("Opcao invalida '-'");
            break;
    }

    return 0;
}
