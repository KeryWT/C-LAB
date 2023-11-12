//
// Created by Luca Betti on 26/10/23.
//

/*Esercizio A.2 Usando la funzione scanf() della libreria standard di I/O scrivere un
        programma che chieda all’utente di inserire su una linea e separandoli con degli
spazi bianchi dei valori numerici interi positivi non nulli. La lista deve essere
terminata con il valore 0 (end of list). Il programma deve calcolare la media
aritmetica dei valori inseriti e deve stampare il risultato sullo standard output.*/

#include "stdio.h"

int main(){
    int count = 0; // conto quanti numeri sono stati inseriti
    int sum = 0; // somma dei numeri inseriti
    int conversione;  // variabile di controllo per la scanf: 1 se corretto, EOF se non corretto
    int val; // valore inserito dall'utente

    printf("Inserisci dei numeri interi positivi non nulli e separati da uno spazio (termina con 0): \n");
    conversione = scanf("%u", &val); // se scansiona correttamente un numero intero positivo non nullo ritorna 1
        while(conversione != EOF){
            if(conversione == 1){ // == 1 perché scanf ritorna il numero di elementi correttamente scansionati e assegnati a val
                            //  noi stiamo guardando un elemento alla volta.
                if(val > 0){
                    count++;
                    sum += val;
                    conversione = scanf("%u", &val);
                } else if (val == 0){
                    printf("La media dei valori inseriti è uguale a %.2lf ", (double)sum/count );
                    conversione = EOF; // così esce dal ciclo
                } else {
                    printf("Hai inserito un numero non valido in posizione %d", count++);
                    conversione = EOF;
                }
            } else {
                printf("Hai inserito un numero non valido in posizione %d", count++);
                conversione = EOF;
            }
        }
}

