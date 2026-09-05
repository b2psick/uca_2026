#include <stdio.h>
#include <stdbool.h>

bool isPowerOf2(int x) {

    int a = x - 1;
    
    if((a & x) == 0) return true;

    return false;
}

int main() {
    int x;

    scanf("%d", &x);

    if(isPowerOf2(x)) {
        printf("true\n");
    }else {
        printf("false\n");
    }

    return 0;
}