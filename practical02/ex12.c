#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of arguments");
        return 1;
    }

    DIR *directory = opendir(argv[1]);

    if (!directory)
    {
        fprintf(stderr, "Folder not found");
        return 2;
    }
    size_t num_files = 0;
    struct dirent *dir;
    while ((dir = readdir(directory)))
    {
        if (dir->d_type == DT_REG)
        {
            char path[PATH_MAX + 1];
            sprintf(path, "%s/%s", argv[1], dir->d_name);
            printf("%s", path);
            FILE *file = fopen(path, "r");
            fseek(file, 0, SEEK_END);
            size_t size = ftell(file);
            printf("File: '%s' Size: %d\n", dir->d_name, size);
            num_files++;
            fclose(file);
        }
        else if (dir->d_type == DT_DIR)
            printf("Folder: '%s'\n", dir->d_name);
    }

    printf("Counted files: %d\n", num_files);

    closedir(directory);

    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main_osvaldo(int argc, char *argv[])
{

    if (argc <= 1)
    {
        fprintf(stderr, "Invalid command.");
        return 1;
    }
    DIR *directory_to_search = opendir(argv[1]);
    struct dirent *file_val;

    while ((file_val = readdir(directory_to_search)) != NULL)
    {
        struct stat path_stat;
        char *path = malloc(sizeof(argv[1]) + sizeof('/') + sizeof(file_val->d_name));
        sprintf(path, "%s/%s", argv[1], file_val->d_name);
        stat(path, &path_stat);
        if (S_ISREG(path_stat.st_mode))
        {
            fprintf(stdout, "%s : %d bytes\n", file_val->d_name, path_stat.st_size);
        }
    }

    return 0;
}
