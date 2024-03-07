    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>


int main(int argc, char *argv[]){

    FILE *f = fopen("write.txt", "w");
    fprintf(f, "Hello World\nCiao\n");
    fflush(f);
    // printf("Hello World\n");
    // write(STDOUT_FILENO, "Ciao\n", 5);

    if(fork() == -1){
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}