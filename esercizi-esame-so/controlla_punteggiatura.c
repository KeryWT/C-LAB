#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int count_occurrences(char *str, char c){
  if (str == NULL){
    exit(1);
  }

  int occurrences = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == c){
      occurrences++;
    }
  }
  
  return occurrences;
}

int controlla_punteggiatura(char *string){
  if (string == NULL){
    exit(1);
  }
  
  int excl_num = count_occurrences(string, '!');
  int interr_num = count_occurrences(string, '?');

  return (excl_num == interr_num) ? TRUE : FALSE;
}

int main(void){
  int result = controlla_punteggiatura("Stringa !?!! di prova ??");

  printf("Risultato (1 TRUE, 0 FALSE):   %d\n", result);
  return 0;
}