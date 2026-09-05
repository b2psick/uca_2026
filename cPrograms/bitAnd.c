#include <stdio.h>

int bitAnd(int a, int b) {
    return ~(~a | ~b);
}

int main() {

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", bitAnd(a, b));

    return 0;
}