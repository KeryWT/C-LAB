#include <stdio.h>
#include <stdlib.h>

int * alloca_array(int *a, int n){ // a = puntatore a array di interi, n = numero elementi nell'array

	if (a == NULL || n < 1){ // parametri di input non validi
		return NULL;
	}

	int max = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > max){
			max = a[i];
		}
	}

	// Make sure that we can proceed
	if (max < 1 || max > n) {
		return NULL;
	}

	int *new_arr = malloc(max * sizeof(int));

	for (int i = 0; i < max; i++){
		new_arr[i] = a[i];
	}

	return new_arr;
}
