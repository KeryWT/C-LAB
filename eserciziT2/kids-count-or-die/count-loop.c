#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

long strtol_err(char *string)
{
    long ret_var = strtol(string, NULL, 10);
    if (ret_var == 0 && errno != 0)
    {
        fprintf(stderr, "Error in converting %s into a number", string);
        exit(-1);
    }
    return ret_var;
}

int main(int argc, char **argv)
{ // dobbiamo ricevere due argomenti. Primo:una durata TIMEOUT, Secondo:numero n_iter  di iterazioni
    if (argc != 3)
    {
        printf("Usage: %s <timeout> <number of Iterations>\n", argv[0]);
        exit(1);
    }
    long timeout = strtol_err(argv[1]);
    long n_iter = strtol_err(argv[2]);
    alarm(timeout);

    for (long i = 0; i < n_iter; i++)
        ;
    return 0;
}
