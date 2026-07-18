#include <stdio.h>
#include <string.h>

int my_strlen(char* p) {
    int len = 0;
    while(*p != '\0') {
        len++;
        p++;
    }
    return len;
}

int main() {
    char str[100];

    scanf("%s", str);

    int len = my_strlen(str);

    printf("%d", len);

    return 0;
}