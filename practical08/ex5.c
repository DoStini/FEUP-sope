#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd = open("ex4.log", O_RDONLY);

    int i;

    while (read(fd, &i, sizeof(int)) == sizeof(int)) {
        printf("fd: %d - %d\n", lseek(fd, 0, SEEK_CUR), i);
    }
    close(fd);

    fd = open("ex4.log", O_RDONLY);
    printf("NEXT\n");
    for (size_t idx = 0; idx < 10; idx++) {
        int off = lseek(fd, rand() % 20 * sizeof(int), SEEK_SET);
        read(fd, &i, sizeof(int));
        printf("fd: %d - %d\n", off, i);
    }

    return 0;
}
