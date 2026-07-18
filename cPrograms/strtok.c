#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "C,C++,Java,Python,Rust";
    
    char delim[] = ",";

    char* token = strtok(str, delim);

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}