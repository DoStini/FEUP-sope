#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

size_t read_wrapper(char **buffer, FILE *file)
{
    size_t read_chars = 16;
    *buffer = malloc(read_chars);
    off_t curr_bytes = 0;
    size_t curr_read;
    while ((curr_read = fread((*buffer + curr_bytes), 1, read_chars, file)) == read_chars)
    {
        curr_bytes += (off_t)read_chars;
        *buffer = realloc(*buffer, (size_t)(curr_bytes + read_chars));
    }
    *buffer = realloc(*buffer, (size_t)(curr_bytes + curr_read));
    fclose(file);
    return curr_bytes + curr_read;
}

int main(int argc, char *argv[])
{
    if (!(argc >= 2 && argc <= 3))
        fprintf(stderr, "Incorrect number of arguments");

    FILE *read_file = fopen(argv[1], "r");

    char *buf;

    size_t size = read_wrapper(&buf, read_file);

    printf("%d : %s", size, buf);

    free(buf);
}
