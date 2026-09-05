#include <stdio.h>

int conditional(int a, int b, int c) {
    return ((a >> 31 | (~a + 1) >> 31) & b) + (~(a >> 31 | (~a + 1) >> 31) & c);
}

int main() {

    int a, b, c;
    scanf("%x", &a);
    scanf("%x", &b);
    scanf("%x", &c);

    printf("%x", conditional(a, b, c));
    
    return 0; 
}