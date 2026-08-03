#include <stdio.h>

struct cards
{
    
};


int higher(char* a, char* b) {
    if(a[1] > b[1]) {
        return 1;
    }
    return 0;
}

int sameSuit(char* a, char* b) {
    if(a[0] == b[0]) {
        return 1;
    }
    return 0;
}

int main() {

}