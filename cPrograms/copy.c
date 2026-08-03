#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int inputfd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3) {
    	printf("Usage ./copy <file1> <file2>\n");
	    exit(-1);
    }

    inputfd = open(argv[1], O_RDONLY);

    if(inputfd == -1) {
        printf("error opening file %s\n", argv[1]);
        exit(-1);
    }

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    outputFd = open(argv[2], openFlags, filePerms);

    if(outputFd == -1) {
        printf("error opening file %s\n", argv[2]);
        exit(-1);
    }

    while((numRead = read(inputfd, buf, BUF_SIZE)) > 0) {
        if(write(outputFd, buf, numRead) != numRead) {
            printf("error while copying\n");
            exit(-1);
        }
    }

    close(inputfd);
    close(outputFd);

    return 0;
}