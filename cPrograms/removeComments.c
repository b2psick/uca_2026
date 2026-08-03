#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    int inputFd;
    ssize_t numRead;

    if(argc != 2) {
        printf("invalid no of arguments\n");
        exit(-1);
    }

    inputFd = open(argv[1], O_RDONLY);

    if(inputFd == -1) {
        perror("opne");
        exit(EXIT_FAILURE);
    }

    char ch;

    char curr = 'd';

    int prev;

    while((numRead = read(inputFd, &ch, 1)) > 0) {
    
        if(curr == 'd') {
            if(ch == '"') {
                curr = 's';
                printf("%c", ch);
            }else if(ch == '\'') {
                curr = 'c';
                printf("%c", ch);
            }else if(ch == '/') {
                curr = '/';
            }else {
                printf("%c", ch);
            }
        }else if(curr == 's') {
            printf("%c", ch);
            if(ch == '"' && prev != '\\') curr = 'd';
        }else if(curr == 'c') {
            printf("%c", ch);
            if(ch == '\'' && prev != '\\') curr = 'd';
        }else if(curr == '/') {
            if(ch == '/') curr = 'p';
            else if(ch == '*') curr = 'm';
            else {
                printf("/");
                printf("%c", ch);
                curr = 'd';
            }
        }else if(curr == 'p' && ch == '\n') {
            printf("%c", ch);
            curr = 'd';
        }
        else if(curr == 'm') {
            if(ch == '*') curr = '*';
        }else if(curr == '*') {
            if(ch == '/') curr = 'd';
            else curr = 'm';
        }

        prev = ch;
    }

    if(curr == '/') printf("/");

    close(inputFd);

    return 0;
}