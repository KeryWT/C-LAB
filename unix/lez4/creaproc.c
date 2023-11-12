//
// Created by Luca Betti on 08/11/23.
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char** argv){

    pid_t proc_pid;
    int i, status, nof_procs;
    nof_procs = atoi(argv[1]);

    printf("[PARENT process with PID %d]: about to start creating child processes \n", getpid());
    for (int i = 0; i < nof_procs; ++i) {
        proc_pid = fork();

        if (proc_pid == -1){
            fprintf(stderr, "fork error... terminating \n");
            exit(EXIT_FAILURE);
        } else if(proc_pid == 0){ // ========= child code
            printf("[CHILD process with PID %d]: terminating in 2 seconds\n", getpid());
            sleep(2);
            exit(EXIT_SUCCESS);
        } else { // ======== parent code
            printf("[PARENT process with PID %d]: going through fork loop \n", getpid());
        }
    }

    // WAIT LOOP //
    for (i = 0; i < nof_procs; ++i) {
        printf("[PARENT process with PID %d]: child %d exited with status %d \n", getpid(), wait(&status), status);
    }
    exit(EXIT_SUCCESS);
}