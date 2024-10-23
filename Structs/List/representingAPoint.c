#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
/* Structs - List 2 - Exercise 2 */
struct point {
    int x;
    int y;
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

void verifyInRectangle(struct point v1, struct point v2, struct point p) {
    struct point v3, v4;

    v3.x = v1.x;
    v3.y = v2.y;
    v4.x = v2.x;
    v4.y = v1.y;

    if (p.x <= v2.x && p.x >= v1.x && p.y <= v2.y && p.y >= v1.y) {
        printf("O ponto (%d, %d) esta dentro do retangulo", p.x, p.y);
    }
    else {
        printf("O ponto (%d, %d) nao esta dentro do retangulo '-'", p.x, p.y);
    }

}

int main() {
    struct point v1, v2, p;
    
    printf("Vamos primeiramente definir os limites do retangulo\n");
    printf("Coordenadas do vertice1 (Canto inferior esquerdo)\n");
    printf("Digite o x do vertice1:\n");
    scanf("%d", &v1.x);
    printf("Digite o y do vertice1:\n");
    scanf("%d", &v1.y);
    printf("Coordenadas do vertice2 (Canto superior direito)\n");
    printf("Digite o x do vertice2:\n");
    scanf("%d", &v2.x);
    printf("Digite o y do vertice2:\n");
    scanf("%d", &v2.y);

    printf("Agora digite as coordenadas do ponto\n");
    printf("Digite o x do ponto:\n");
    scanf("%d", &p.x);
    printf("Digite o y do vertice1:\n");
    scanf("%d", &p.y);

    verifyInRectangle(v1, v2, p);

    return 0;
}
