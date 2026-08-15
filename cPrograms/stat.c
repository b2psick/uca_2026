#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    struct stat fileStat;
    if(argc != 2) {
        printf("usage: ./fileinfo <file>\n");
        exit(-1);
    }

    if(stat(argv[1], &fileStat) == -1) {
        printf("error getting info file information");
        exit(-1);
    }

    printf("=== File attributes for: %s ===\n\n", argv[1]);

    if (S_ISREG(fileStat.st_mode)) {
        printf("File Type:            Regular File\n");
    }
    else if (S_ISDIR(fileStat.st_mode)) {
        printf("File Type:            Directory\n");
    }
    else if (S_ISLNK(fileStat.st_mode)) {
        printf("File Type:            Symbolic Link\n");
    }
    else if (S_ISCHR(fileStat.st_mode)) {
        printf("File Type:            Character Device\n");
    }
    else if (S_ISBLK(fileStat.st_mode)) {
        printf("File Type:            Block Device\n");
    }
    else if (S_ISFIFO(fileStat.st_mode)) {
        printf("File Type:            FIFO\n");
    }
    else if (S_ISSOCK(fileStat.st_mode)) {
        printf("File Type:            Socket\n");
    }

    printf("Permissions:          %04o\n", fileStat.st_mode & 0777); // we use 0777 to get the last three octal digits representing the permissions bcoz the first digit represents the file type and special permissions, which we don't want to display here. as st_mode gives us both the file type and permissions, we use bitwise AND with 0777 to extract only the permission bits.

    printf("File Size:            %ld bytes\n", fileStat.st_size);

    printf("Hard Links Count:     %ld\n", fileStat.st_nlink);

    printf("Owner (UID):          %d\n", fileStat.st_uid);

    printf("Group (GID):          %d\n", fileStat.st_gid);

    printf("Last Access Time:     %s", ctime(&fileStat.st_atime));

    printf("Last Modification:    %s", ctime(&fileStat.st_mtime));

    printf("Status Change Time:   %s", ctime(&fileStat.st_ctime));

    return 0;
}