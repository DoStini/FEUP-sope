#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sighandler(int signo)
{
}

int main()
{
    struct sigaction new, old;
    sigset_t smask;

    if (sigemptyset(&smask) == -1)
        perror("mask");

    new.sa_handler = sighandler;
    new.sa_mask = smask;
    new.sa_flags = 0;

    if (sigaction(SIGUSR1, &new, &old) == -1)
        perror("sigaction");


    pid_t id = fork(), wstatus;
    switch (id)
    {
    case -1:
        perror("fork error");
        printf("World!");
        break;
    case 0:
    {
        pause();
        break;
    }

    default:
    {
        printf("Hello ");
        kill(id, SIGUSR1);
        break;
    }
    }
}
