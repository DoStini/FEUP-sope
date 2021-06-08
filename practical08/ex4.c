#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 1234567;
    write(STDOUT_FILENO, &i, sizeof(i));
    printf("\n%d", i);
    return 0;
}
