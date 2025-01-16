#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <File Path> \n", argv[0]);
        return 1;
    }

    struct stat statbuf;
    if (stat(argv[1], &statbuf) == -1) {
        perror("stat fail");
        return 1;
    }

    printf("File size: %lld byte\n", statbuf.st_size);

    return 0;
}
