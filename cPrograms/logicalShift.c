#include <stdio.h>

int logicalShift(int a, int b) {
    return ~(((1 << 31) >> b) << 1) & (a >> b);
}

int main() {

    int a, b;
    scanf("%x", &a);
    scanf("%d", &b);

    printf("%x", logicalShift(a, b));
    
    return 0; 
}