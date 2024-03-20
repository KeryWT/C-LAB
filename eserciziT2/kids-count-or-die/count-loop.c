#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){ // dobbiamo ricevere due argomenti. Primo:una durata TIMEOUT, Secondo:numero n_iter  di iterazioni
    if(argc != 3){
        printf("Usage: %s <timeout> <number of Iterations>\n", argv[0]);
        exit(1);
    }
    int timeout = atoi(argv[1]);
    int n_iter = atoi(argv[2]);
    alarm(timeout);

    for(int i=0; i<n_iter; i++);
    printf("Child with PID: %d has finished executing the count-loop file\n", getpid());
    return 0;
}
