#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define NUM_KIDS 20

int main(int argc, char *argv[])
{
  int status = 0;
  int sum = 0;
  for (int i = 0; i < NUM_KIDS; i++)
  {
    switch (fork())
    {
    case -1:
      /* Handle error */
      fprintf(stderr, "%s, %d: Errore (%d) nella fork\n",
              __FILE__, __LINE__, errno);
      exit(EXIT_FAILURE);
      break;

    case 0:
      // CHILD CODE
      srand(getpid());
      int n = arc4random() % (6 + 1 - 1) + 1;
      printf(
          "I am the child #%d with pid %d and I generated this random number: %d\n",
          i, getpid(), n);
      exit(n);
    default:
      // PARENT CODE: nothing here
      break;
    }
  }

  while (wait(&status) != -1)
  {
    /*
     * Estrai l'exit status dei figli e somma in sum
     */
    sum += WEXITSTATUS(status);
  }

  printf("Number of childs: %d\n", NUM_KIDS);
  printf("Sum of the random numbers: %d\n", sum);
  exit(0);
}
