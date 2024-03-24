#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <num_processes> <max_number>\n", argv[0]);
        exit(1);
    }

    int num_processes = atoi(argv[1]);
    int max_number = atoi(argv[2]);

    int pipes[num_processes][2];
    pid_t children[num_processes];

    // Create each pipe for each process
    for (int i = 0; i < num_processes; i++)
    {
        if (pipe(pipes[i]) == -1)
        {
            perror("pipe");
            exit(1);
        }
    }

    // Fork child processes
    for (int i = 0; i < num_processes; i++)
    {
        children[i] = fork();
        // Handle fork error
        if (children[i] == -1)
        {
            perror("fork");
            exit(1);
        }

        // Parent process
        srand(time(NULL));
        int initial_number = rand() % max_number + 1;                // Generate random number between 1 and max_number
        write(pipes[0][1], &initial_number, sizeof(initial_number)); // Write number to first process
        close(pipes[0][1]);                                          // Close write end of pipe

        // Child process
        if (children[i] == 0)
        {
            close(pipes[i][1]); // Close write end of pipe
            int number;
            read(pipes[i][0], &number, sizeof(number));           // Read number from pipe
            printf("Process %d received number %d\n", i, number); // Print received number

            if (number == 0)
            {
                write(pipes[(i + 1) % num_processes][1], &number, sizeof(number));
            }
            else
            {
                number--;
                write(pipes[(i + 1) % num_processes][1], &number, sizeof(number));
            }
            close(pipes[i][0]); // Close read end of pipe
            exit(0);
        }
    }

    // Wait for all children to terminate
    for (int i = 0; i < num_processes; i++)
    {
        waitpid(children[i], NULL, 0);
    }
    return 0;
}