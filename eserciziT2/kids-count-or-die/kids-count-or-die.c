#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER 50

struct child
{
    pid_t pid;
    long iter;
    int rerun;
};

long strtol_err(char *string);
void run_child(long timeout, long n_iter);
int lookup_arr(struct child *, int size, pid_t pid);

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s <timeout> <number of Iterations> <number of kids>\n",
               argv[0]);
        exit(1);
    }

    long timeout, n_iter, n_kids;
    int i, status;
    struct child *children;
    pid_t pid;

    timeout = strtol_err(argv[1]);
    n_iter = strtol_err(argv[2]);
    n_kids = strtol_err(argv[3]);

    children = malloc(sizeof(*children) * n_kids);

    for (i = 0; i < n_kids; i++)
    {
        children[i].iter = n_iter;
        children[i].pid = fork();
        children[i].rerun = 0;

        if (children[i].pid == -1) // error handling
        {
            printf("Error in fork\n");
            exit(1);
        }
        else if (children[i].pid == 0) // CHILD CODE
        {
            run_child(timeout, n_iter);
        }
    }

    while ((pid = wait(&status)) != -1)
    {
        if (WIFSIGNALED(status))
        {
            printf("Child %d was killed by signal, ", pid);
            int i = lookup_arr(children, n_kids, pid);

            children[i].iter >>= 1;
            children[i].pid = fork();
            children[i].rerun++;

            if (children[i].pid == 0)
            {
                run_child(timeout, children[i].iter);
            }
            printf("now it's %d and will run for %ld iterations\n", children[i].pid, children[i].iter);
        }
    }

    for (int i = 0; i < n_kids; i++)
    {
        printf("Child %d, iterations: %ld iterations, rerun %d times\n", children[i].pid, children[i].iter, children[i].rerun);
    }

    free(children);
}

void run_child(long timeout, long n_iter)
{
    char timeout_str[BUFFER];
    char n_iter_str[BUFFER];
    char *args[4];
    args[0] = "";
    args[1] = timeout_str;
    args[2] = n_iter_str;
    args[3] = NULL;

    snprintf(timeout_str, BUFFER - 1, "%ld", timeout);
    snprintf(n_iter_str, BUFFER - 1, "%ld", n_iter);

    execve("count-loop", args, NULL);

    perror("");

    exit(-2);
}

int lookup_arr(struct child *children, int size, pid_t pid)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (children[i].pid == pid)
            return i;
    }
    return -1;
}

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
