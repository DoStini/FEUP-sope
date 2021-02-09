#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{

    if (argc != 2)
    {
        printf("Incorrect number of arguments");
        return 1;
    }

    if (open(argv[1], O_RDONLY) == -1)
    {
        printf("Error code: %d\n", errno);
        fprintf(stderr, "Error code: %d\n", errno);
        perror("Error");
        return errno;
    }

    printf("Success");

    return 0;
}