//
// Created by Luca on 12/11/2023.
//
//
// Created by Luca Betti on 11/11/23.
//

/*
Esercizio A.5
Scrivere un programma che legge dallo standard input un testo e conta in esso
la frequenza di ogni carattere dell’alfabeto (senza distinzione tra stile minuscolo e maiuscolo)
e la frequenza degli spazi bianchi. Facoltativo: usando il carattere * come mattone elementare,
dare una rappresentazione a istogramma orizzontale delle frequenze delle lettere dell’alfabeto,
esempio:
a: ***********************************
b: ************
c: ***********************
d: ****
....
*/
#include "defs_macros.h"
#include "stdio.h"

#define MAX_LENGTH 200
#define ALPHABET_SIZE 26

char tolowercase(char c) {
    if (c <= 'Z' && c >= 'A') {
        c = c - 'A' + 'a';
    }
    return c;
}


int main() {
    char c;
    int digitFreq[ALPHABET_SIZE] = {0}; // array dove ogni indice corrisponde a una lettera
    counter ws = 0;
//    char text[MAX_LENGTH];

    printf("Inserisci un testo:\n");

//    scanf("%[^\n]s", text); altro metodo possibile
//    if (fgets(text, MAX_LENGTH, stdin) == NULL) { fprintf(stderr, "Error \n"); }

    while ((c = getchar()) != '\n') {
        // Contiamo frequenza spazi bianchi
        if (is_whitespace(c)) {
            ws++;
        } else if (is_letter(c)) { // contiamo lettere
            int index = tolowercase(c) - 'a';
            digitFreq[index]++;
        }
    }
/*    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (is_whitespace(text[i])){
            ws++;
        } else if(is_letter(text[i])){
            int index = tolowercase(text[i]) - 'a';
            digitFreq[index]++;
        }
    }*/

    printf("\nFrequenza delle lettere dell'alfabeto:\n");
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (digitFreq[i] != 0) {
            printf("%c: %d occorrenze\n", (i + 'a'), digitFreq[i]);
        }
    }
    printf("\nFrequenza degli spazi bianchi: %lu\n", ws);


    return 0;
}


