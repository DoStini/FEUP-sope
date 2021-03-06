#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int p1()
{
    int proc;
    int pp[2];

    if (pipe(pp) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid_t id;

    if ((id = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if (id == 0)
    {
        close(pp[0]);
        const char *str = "Operating";
        write(pp[1], str, strlen(str));
        close(pp[1]);
    }
    else
    {
        close(pp[1]);
        char str[100];
        int size;
        while (!(size = read(pp[0], str, 100)))
            continue;
        strcat(str, " Systems!");
        printf("%s", str);
    }
}

int p2()
{
    int proc;

    pid_t id;

    if (-1 == mkfifo("/tmp/p1", 0777))
    {
        perror("mkfifo");
        exit(1);
    }

    if ((id = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if (id == 0)
    {
        int fd;
        while ((fd = open("/tmp/p1", O_WRONLY)) < 0)
            ;
        if (fd == -1)
        {
            perror("pipe write");
            exit(1);
        }
        const char *str = "Operating";
        write(fd, str, strlen(str));
        close(fd);
    }
    else
    {
        int fd;
        while ((fd = open("/tmp/p1", O_RDONLY)) < 0)
            ;
        if (fd == -1)
        {
            perror("pipe");
            exit(1);
        }
        char str[100];
        int size;
        while (!(size = read(fd, str, 100)))
            continue;
        strcat(str, " Systems!");
        close(fd);
        printf("%s", str);
    }
}

int p3()
{
    int proc;
    int pp[2];

    if (pipe(pp) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid_t id;

    if ((id = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if (id > 0)
    {
        close(pp[0]);
        const char *str = "";
        write(pp[1], "Operating", 9);
        close(pp[1]);
    }
    else
    {
        close(pp[1]);
        char str[100];
        int size;
        while (!(size = read(pp[0], str, 100)))
            continue;
        printf("%s Systems!", str);
    }
}

int p4()
{
    int proc;

    pid_t id;

    if (-1 == mkfifo("/tmp/p2", 0777))
    {
        perror("mkfifo");
        exit(1);
    }

    if ((id = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if (id > 0)
    {
        int fd;
        while ((fd = open("/tmp/p2", O_WRONLY)) < 0)
            ;
        if (fd == -1)
        {
            perror("pipe write");
            exit(1);
        }
        const char *str = "Systems!";
        write(fd, str, strlen(str));
        close(fd);
    }
    else
    {
        int fd;
        while ((fd = open("/tmp/p2", O_RDONLY)) < 0)
            ;
        if (fd == -1)
        {
            perror("pipe");
            exit(1);
        }
        char str[100];
        int size;
        while (!(size = read(fd, str, 100)))
            continue;
        close(fd);
        printf("Operating %s", str);
    }
}

int main()
{
    p4();
}
