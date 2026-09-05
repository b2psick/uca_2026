#include <stdio.h>

int fitBits(int a, int b) {
    return !(a ^ ((a << (32 - b)) >> (32 - b)));
}

int main() {

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", fitBits(a, b));

    return  0;
}