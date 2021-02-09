#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[], char *envp[])
{
    // printf("Number of args: %d\n", (int)argc);

    // for (size_t i = 0; i < (size_t)argc; i++)
    // {
    //     printf("Arg %d: %s\n", (int)i + 1, argv[i]);
    // }

    // for (size_t i = 0; envp[i]; i++)
    // {
    //     printf("Env Variable %d: %s\n", (int)i + 1, envp[i]);
    // }

    printf("\nChosen env vars:\n");

    for (size_t i = 0; envp[i]; i++)
    {
        for (size_t j = 0; j < (size_t)argc; j++)
        {
            if (strcmp(strtok(envp[i], "="), argv[j]) == 0)
                printf("Env Variable: %s\n", envp[i]);
        }
    }

    return 0;
}