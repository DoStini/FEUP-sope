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
    pid_t id = fork(), wstatus;
    switch (id)
    {
    case -1:
        perror("fork error");
        break;
    case 0:
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

        kill(getppid(), SIGUSR1);

        pause();

        printf("World!");
        break;
    }

    default:
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

        pause();

        printf("Hello ");
        kill(id, SIGUSR1);
        break;
    }
    }
}
