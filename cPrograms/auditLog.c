    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>

    #define BUF_SIZE 1024

    int main(int argc, char* argv[]) {

        int inputFd, outputFd, openFlags;
        mode_t filePerms;
        ssize_t numRead;
        char buf[BUF_SIZE];

        if(argc != 2 && argc != 3) {
            printf("Usage ./auditlog\n");
            exit(-1);
        }

        if(strcmp("--view",argv[1]) == 0) {
            inputFd = open("audit.log", O_RDONLY);

            if(inputFd == -1) {
                printf("error opening file");
                exit(-1);
            }

            int lineCount = 1;
            printf("%d: ", lineCount);
            fflush(stdout);

            while((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {

                for(int i = 0; i < numRead; i++) {

                    write(STDOUT_FILENO, &buf[i], 1); // so the write needs the pointer to the buf element
                    
                    if(buf[i] == '\n') {
                        lineCount++;
                        printf("%d: ", lineCount);
                        fflush(stdout);
                    }
                }

            }

            if(numRead == -1) {
                perror("read");
            }
            
            close(inputFd);
        } else if(strcmp("--add",argv[1]) == 0) {
            outputFd = open("audit.log", O_WRONLY | O_APPEND);

            if(outputFd == -1) {
                printf("error opening file");
                exit(-1);
            }

            write(outputFd, argv[2], strlen(argv[2]));
            write(outputFd, "\n", 1);
            
            close(outputFd);
        } else {
            printf("invalid command");
        }
        
        return 0;
        
    }