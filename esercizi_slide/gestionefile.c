#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  // apri un file di testo in scrittura
  FILE *f = fopen("test.txt", "w");
  pid_t pid = fork();
  if (pid == -1) {
    printf("Errore nella creazione del processo figlio\n");
    exit(-1);
  } else if (pid == 0) {
    // siamo nel figlio
    // scrivi nel file
    fprintf(f, "Testo a caso scritto dal figlio.\n");
    fclose(f); // chiudi il file
    exit(0);
  } else {
    // siamo nel padre
    wait(NULL);
    // aspetta l'esecuzione del figlio, poi apri il file e stampane il contenuto
    f = fopen("test.txt", "r");
    // stampa il contenuto del file
    char c;
    while ((c = fgetc(f)) != EOF) {
      printf("%c", c);
    }
    fclose(f); // chiudi il file
  }
}
