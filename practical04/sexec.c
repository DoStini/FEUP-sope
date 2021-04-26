/*
*	EXEC: 1st example of typical usage!
*
* Note:	execve is the syscal!
*	execv, execvp, execvpe, execl, execlp, execle are library functions.
*
* Exercise:
* 	change this code to show that USER was changed after the exec.
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// preparation for execve:
char *cmdline[] = {"sleep", "3", (void *)0};
char *newenviron[] = {"USER=Linus", NULL};

int main() {
    pid_t id;
    setbuf(stdout, NULL);  // to make sure printf() have no buffer so, nodelay!

    printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

    id = fork();
    switch (id) {
        case -1:
            perror("fork()");
            exit(1);
        case 0:  // child
            printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));
            printf("\nChild: check that following exec was succeful with: \"ps x | grep sleep\"\n");

            //int fd = open("/bin/sleep", O_EXCL);
            int fd = open("ex2c.o", O_EXCL);
            if (fd < 0) {
                perror("open");
                exit(1);
            }
            return fexecve(fd, cmdline, newenviron);

        default:
            printf("\nParent still: %d. USER=%s", getpid(), getenv("USER"));
            int status;
            wait(&status);
            printf("Status: %d\n", WEXITSTATUS(status));
    }
    return 0;
}
