#include <stdio.h>
int sqr(int x);
int main() {
    int i = 10;
    printf("%d = %d^2",sqr(i),i);
}
int sqr(int x) {
    return(x*x);
}