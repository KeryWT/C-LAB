#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
  switch (fork())
  {
  case -1:
    perror("fork");
    return -1;
  case 0:
    // fai execlp usando saluta_persone.c come programma
    // e passa "Giovanni", "Maria", "Luca" come argomenti
    execlp("./saluta_persone.out", "saluta_persone", "Giovanni", "Maria",
           "Luca", NULL);
    perror("execlp");
    return -1;
  default:
    wait(NULL);
    exit(EXIT_SUCCESS);
  }
}
