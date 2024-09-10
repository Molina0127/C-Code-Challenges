#include <stdio.h>
/* Function Part 1 - Example 1 */
void message() {
    printf("Sou uma funcao!\n");
}
void message1() {
    printf("Sou uma outra funcao!\n");
}
void traits() {
    int i;
    printf("\n");
    for (i = 1; i <= 40; i++) {
        printf("-");
    }
    printf("\n");
}
int main() {
    message();
    traits();
    message1();
    return 0;
}
