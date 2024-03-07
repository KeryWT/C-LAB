#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    // print every argument excpet for NULL
    printf("Ciao %s\n", argv[i]);
  }
  exit(EXIT_SUCCESS);
  return 0;
}
