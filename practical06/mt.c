#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MB *1024 * 1024

void* arr[2000000000];

int main() {
    for (size_t i = 0; i < 2000000000; i++) {
        arr[i] = malloc(50 MB);
        if (arr[i] == NULL) {
            printf("Null Finally\n");
            break;
        }
        memset(arr[i], 'A', 50 MB);
    }
    printf("Reach\n");
    sleep(5);
    for (size_t i = 0; i < 2000000000; i++) {
        free(arr[i]);
    }
}
