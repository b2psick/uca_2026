#include <stdio.h>

int sign(int a) {
    return (a >> 31) | !!(a);
}

int main() {

    int a;
    scanf("%d", &a);

    printf("%d", sign(a));

    return  0;
}