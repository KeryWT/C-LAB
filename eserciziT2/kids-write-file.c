#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // included for portability

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Wrong number of arguments\n");
        exit(1);
    }

    FILE *file;
    char *filename = argv[1];
    int n_kids = atoi(argv[2]);
    int n_writes = atoi(argv[3]);

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < n_kids; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            for (int j = 0; j < n_writes; j++)
            {
                fprintf(file, "Child with PID: %d is writing. His father's PID is: %d\n", getpid(), getppid());
            }
            fclose(file);
            exit(0);
        }
        else if (pid == -1)
        {
            printf("Error creating child\n");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
