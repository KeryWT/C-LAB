//
// Created by Luca Betti on 17/11/23.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execlp("./filter", "./filter", NULL);
        perror("execlp");
        return 1;
    } else {
        close(pipefd[1]);
        while (read(pipefd[0], &buf, 1) > 0) {
            putchar(buf);
        }
        wait(NULL);
    }

    return 0;
}
