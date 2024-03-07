// Scrivere un programma che prende in input un numero varaibile di interi i1, i2, ... , in.
// Il programma genera n figli: ohni figlio si mette in attesa ( con il comando sleep) il primo per i1 secondi, il secondo per 12 secondi, il terzo per i3 secondi, e cosi via, poi termina.
// Il genitore aspetta la termiunaione di tutti i figli e poi termina a sua volta.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s i1 i2 ... in\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = argc - 1;
    pid_t pid;
    for(int i = 0; i < n; i++){
        pid = fork();
        if(pid == -1){ // error
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pid == 0){// child process
            printf("Child %d: %d, going to sleep for %d seconds\n", i, getpid(), atoi(argv[i+1]));
            sleep(atoi(argv[i+1]));
            exit(EXIT_SUCCESS);
        }
    }

    /**
     * This code snippet waits for all child processes to terminate.
     * It uses the wait() function to wait for each child process to terminate.
     * The loop continues until wait() returns -1, indicating that there are no more child processes.
     * If an error occurs during the wait() call, the errno variable is checked and an error message is printed.
     * If the error is not due to there being no child processes (ECHILD), the program exits with failure.
     */

    int childPid;  // PID of a terminated child process
    while ((childPid = wait(NULL)) != -1)
    {
        continue;
    }
    if (errno != ECHILD)
    {
        perror("wait");
        exit(EXIT_FAILURE);
    }
    printf("Parent: all children have terminated, I'm terminating too.\n");
    exit(EXIT_SUCCESS);
}