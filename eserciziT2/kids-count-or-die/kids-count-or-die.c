#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <timeout> <number of Iterations> <number of kids>\n",
           argv[0]);
    exit(1);
  }
  char *arguments[] = {"./count-loop.out", argv[1], argv[2], NULL};
  int n_kids = atoi(argv[3]);

  for (int i = 0; i < n_kids; i++)
  {
    pid_t pid = fork();
    if (pid == 0)
    {
      if (execve("./count-loop.out", arguments, NULL) == -1)
      {
        printf("Error in execve\n");
        exit(1);
      }
    }
    else if (pid != -1)
    {
      int status;
      wait(&status);
      if (WIFSIGNALED(status))
      {
        long n_iter = atoi(argv[2]) / 2;
        char *arguments[] = {"./count-loop.out", argv[1], (char *)n_iter, NULL};
        printf("A child count-loop has been interrupted due to the alarm.\n");
      }
    }
    else
    {
      printf("Error in fork\n");
      exit(1);
    }
  }
}
