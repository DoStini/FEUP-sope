#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int list(char *base_path) {
    DIR *directory = opendir(base_path);
    if (!directory) {
        return 0;
    }
    size_t num_files = 0;
    struct dirent *dir;
    while ((dir = readdir(directory))) {
        char path[PATH_MAX + 1];
        sprintf(path, "%s/%s", base_path, dir->d_name);
        if (dir->d_type == DT_REG) {
            fflush(stdout);
            FILE *file = fopen(path, "r");
            fseek(file, 0, SEEK_END);
            size_t size = ftell(file);
            printf("File: '%s/%s' Size: %d\n", base_path, dir->d_name, size);
            fclose(file);
        } else if (dir->d_type == DT_DIR &&
                   strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")) {
            int id = fork();
            if (id < 0)
                return 1;
            if (id == 0) {
                list(path);
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments");
        return 1;
    }

    list(argv[1]);

    return 0;
}