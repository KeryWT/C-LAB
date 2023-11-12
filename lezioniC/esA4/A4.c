/*
Esercizio A.4 Usando la funzione scanf() della libreria standard di I/O scrivere un
programma che chieda all’utente di inserire il numero n di voti dei quali fare la
media aritmetica. Successivamente il programma legge dallo standard input un voto
per linea e al termine ne calcola la media.
*/

#include "stdio.h"

int main(){
    printf("Inserisci il numero di voti: \n");
    int n = 0; // numero di voti da inserire
    scanf("%d", &n);
    double voto = 0;
    double sum = 0;

    for (int i = 1; i <= n; ++i) {
        printf("Inserisci il voto numero %d: \n", i);
        scanf("%lf", &voto);
        sum += voto;
    }
    printf("La media dei voti inseriti è %.2lf", (sum/n));
    return 0;
}
