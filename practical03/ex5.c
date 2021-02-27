#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int id = fork(), wstatus;
    switch (id)
    {
    case -1:
        perror("fork error");
        break;
    case 0:
        printf("Hello ");
        break;
    default:
        wait(&wstatus);
        // sleep(2);
        printf("World!");
        break;
    }
}
