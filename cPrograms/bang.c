#include <stdio.h>

int bang(int a) {
    return ~((a >> 31 | (~a + 1) >> 31)) & 0x00000001;
}

int main() {

    int a;
    scanf("%x", &a);

    printf("%x", bang(a));
    
    return 0; 
}