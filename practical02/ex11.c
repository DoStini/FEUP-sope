#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

size_t read_wrapper(char **buffer, int fd)
{
    size_t read_chars = 16;
    *buffer = malloc(read_chars);
    off_t curr_bytes = 0;
    size_t curr_read;
    while ((curr_read = read(fd, (*buffer + curr_bytes), read_chars)) == read_chars)
    {
        curr_bytes += (off_t)read_chars;
        *buffer = realloc(*buffer, (size_t)(curr_bytes + read_chars));
    }
    *buffer = realloc(*buffer, (size_t)(curr_bytes + curr_read));
    close(fd);
    return curr_bytes + curr_read;
}

int main(int argc, char *argv[])
{
    if (!(argc >= 2 && argc <= 3))
        fprintf(stderr, "Incorrect number of arguments");

    int fd_read = open(argv[1], O_RDONLY);

    if (fd_read == -1)
    {
        perror("file error");
        return errno;
    }

    char *buffer;
    size_t size = read_wrapper(&buffer, fd_read);

    if (argc == 2)
    {
        printf("Content of %s:\n\n%s", argv[1], buffer);
    }
    else
    {
        int fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd_write == -1)
        {
            free(buffer);
            printf("errno: %d\n", errno);
            perror("file error");
            return errno;
        }
        printf("fd: %d\n", fd_write);
        size_t written = write(fd_write, buffer, size);
        if (written == -1)
        {
            free(buffer);
            perror("write error");
            return errno;
        }
        close(fd_write);
    }

    free(buffer);
}
