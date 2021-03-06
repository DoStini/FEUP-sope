#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

struct data
{
    bool *ready;
    const char *str;
    char id;
};

void *func(void *param)
{
    struct data *dat = (struct data *)param;

    if (dat->id == 0)
    {
        printf(dat->str);
        *dat->ready = true;
    }
    else
    {
        while (!(*dat->ready))
            continue;
        printf(dat->str);
    }
    pthread_exit(NULL);
}

int main()
{
    bool ready = false;

    struct data d1, d2;
    d1.id = 0;
    d1.ready = &ready;
    d1.str = "Operating ";

    d2.id = 1;
    d2.ready = &ready;
    d2.str = "Systems!";

    pthread_t t1, t2;

    pthread_create(&t1, NULL, func, &d1);
    pthread_create(&t2, NULL, func, &d2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}