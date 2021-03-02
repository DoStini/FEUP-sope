/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 3

void *rot(void *a)
{
	printf("\n\t In thread PID: %d ; TID: %lu.", getpid(), (unsigned long)pthread_self());
    int val = *((int *)a);
    *((int *) a) = val*val;

	int *ret = malloc(sizeof(int));
    *((int *) ret) = (*(int *)a);
	pthread_exit(ret); // no termination code
}

int main()
{
	int i;					 // thread counter
	pthread_t ids[NTHREADS]; // storage of (system) Thread Identifiers

	setbuf(stdout, NULL); // only for debugging
	printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long)pthread_self());

    int values[NTHREADS];
    int ret_values[NTHREADS];

	// new threads creation
	for (i = 0; i < NTHREADS; i++)
	{
        values[i] = i;
		if (pthread_create(&ids[i], NULL, rot, values+i) != 0)
			exit(-1); // here, we decided to end process
		else
			printf("\nNew thread %d ; TID: %lu.", i, (unsigned long)ids[i]);
	}
	// wait for finishing of created threads
	for (i = 0; i < NTHREADS; i++)
	{
		void* val;
		pthread_join(ids[i], &val); // Note: threads give no termination code
		ret_values[i] = *(int *)(val);
		free(val);
		printf("\nTermination of thread %d: %lu.", i, (unsigned long)ids[i]);
    }

    printf("\n-----\n");

    for (size_t i = 0; i < NTHREADS; i++)
    {
        printf("Value %d: %d", i, values[i]);
    }
    
	printf("\n-----\nWith ret values\n\n");

    for (size_t i = 0; i < NTHREADS; i++)
    {
        printf("Value %d: %d", i, ret_values[i]);
    }

	printf("\n");
	pthread_exit(NULL); // here, not really necessary...
	return 0;			// will not run this!
}
