#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define OPEN_ERR -1

int main(int argc, char *argv[], char *envp[])
{

    if (argc != 3)
    {
        printf("Incorrect number of arguments");
        return 1;
    }

    int fd;

    if ((fd = open(argv[1], O_RDONLY)) == OPEN_ERR)
    {
        printf("Error code: %d\n", errno);
        fprintf(stderr, "Error code: %d\n", errno);
        perror("Error");
        return errno;
    }

    size_t bytes_to_read = (size_t)(atoi(argv[2]));

    printf("Size: %d\n", (int)bytes_to_read);

    void *file_buffer = malloc(bytes_to_read);

    size_t num_read = read(fd, file_buffer, bytes_to_read);

    for (size_t i = 0; i < num_read; i++)
    {
        printf("%c", ((char *)file_buffer)[i]);
    }

    return 0;
}