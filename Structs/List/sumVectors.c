#include <stdio.h>
/* Structs - List 2 - Exercise 7 */
struct vector {
    float x;
    float y;
    float z;
};

struct vector sum_vectors(struct vector v1, struct vector v2) {
    struct vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
};

int main() {
    struct vector vector1, vector2, sum;

    printf("Digite as componentes do primeiro vetor (x y z): ");
    scanf("%f %f %f", &vector1.x, &vector1.y, &vector1.z);

    printf("Digite as componentes do segundo vetor (x y z): ");
    scanf("%f %f %f", &vector2.x, &vector2.y, &vector2.z);

    sum = sum_vectors(vector1, vector2);

    printf("A soma dos vetores eh: (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);

    return 0;
}