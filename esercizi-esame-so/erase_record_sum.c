#include <stdio.h>
#include <stdlib.h>

struct record {
  int *data;
  int length;
};

int erase_record_sum(struct record *recordings[], int n, int sum) {
  if (recordings == NULL || n < 1 || sum < 1) {
    exit(1);
  }

  int arr_sum = 0;
  int deleted_counter = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < recordings[i]->length; j++) {
      arr_sum += recordings[i]->data[j];
    }
    if (arr_sum > sum) {
      free(recordings[i]->data);
      recordings[i]->data = NULL; // I don't know if 'free' sets the pointer = NULL
      recordings[i]->length = 0;
      deleted_counter++;
    }
    arr_sum = 0;
  }

  return deleted_counter;
}

int main(void) {
  int length = 3;
  int length1 = 4;
  int length2 = 4;

  // Allocazione e inizializzazione degli array con numeri diversi
  int *data = malloc(length * sizeof(int));   // Array da 3 elementi
  int *data1 = malloc(length1 * sizeof(int)); // Array da 4 elementi
  int *data2 = malloc(length2 * sizeof(int)); // Altro array da 4 elementi

  // Inizializza data con valori specifici
  data[0] = 1;
  data[1] = 2;
  data[2] = 3;

  // Inizializza data1 con valori specifici
  data1[0] = 4;
  data1[1] = 5;
  data1[2] = 6;
  data1[3] = 7;

  // Inizializza data2 con valori specifici
  data2[0] = 2;
  data2[1] = 3;
  data2[2] = 4;
  data2[3] = 6;

  struct record **recordings = malloc(3 * sizeof(struct record *));
  for (int i = 0; i < 3; i++) {
    recordings[i] = malloc(sizeof(struct record));
    if (i == 0) {
      recordings[i]->data = data;
      recordings[i]->length = length;
    } else if (i == 1) {
      recordings[i]->data = data1;
      recordings[i]->length = length1;
    } else {
      recordings[i]->data = data2;
      recordings[i]->length = length2;
    }
  }

  // Esempio: cerca  di eliminare i record con una somma totale di 6
  int target_sum = 6;
  int result = erase_record_sum(recordings, 3, target_sum);

  printf("Il numero di nodi eliminati è: %d\n", result);

  // Libera la memoria per i record rimanenti
  for (int i = 0; i < 3; i++) {
    if (recordings[i] != NULL) {
      free(recordings[i]->data);
      free(recordings[i]);
    }
  }
  free(recordings);
}
