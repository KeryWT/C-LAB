//
// Created by Luca Betti on 20/10/23.
//

#include "stdio.h"


int main(){
    int a = 0, b = 0;
    printf("Inserisci due numeri interi: \n"); // Prendo i due numeri in input
    scanf("%d", &a);
    scanf("%d", &b);

    int sum = a + b; // Eseguo le operazioni
    int prod = a * b;
    int divint = a / b;
    float divreal = (float) a / (float) b;
    int mod = a%b;

    printf("La somma dei due numeri è uguale a: %d \n", sum);
    printf("Il prodotto dei due numeri è uguale a: %d \n", prod);
    printf("La divisione intera dei due numeri è uguale a: %d \n", divint);
    printf("La divisione reale (arrotondata a 2 cifre decimali) dei due numeri è uguale a: %.2f \n", divreal);
    printf("Il resto della divisione intera dei due numeri è uguale a: %d \n", mod);
    return 0;
}