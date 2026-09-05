#include <stdio.h>

int getByte(int a, int b) {
    return (a >> (b << 3)) & 0x000000FF;
}

int main() {

    int a, b;
    scanf("%x", &a);
    scanf("%d", &b);

    printf("%x", getByte(a, b));
    
    return 0; 
}