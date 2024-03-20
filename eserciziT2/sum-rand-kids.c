#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_KIDS 20

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 0; i < NUM_KIDS; i++) {
    int pid = fork();
    if (pid == 0) {
        srand(getpid());
      int n = rand() % (6 + 1 - 1) + 1;
      printf(
          "I am the child #%d with pid %d and I generated this random number: %d\n",
          i, getpid(), n);
      exit(n);
    } else if (pid != 0) {
      int status;
      wait(&status);
      sum += WEXITSTATUS(status);
    } else {
      printf("Error creating child %d\n", i);
    }
  }
  printf("I am the Father and the sum of the random numbers is: %d\n", sum);
}
