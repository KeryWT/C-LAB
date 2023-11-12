//
// Created by Luca Betti on 27/10/23.
//
#include <string.h>
#define ARLEN 3
void ordina(char* alfabeto[], int length);
int main() {
    char* array_char_p[] = {
            "defghi",
            "jklmnopqrst",
            "abc"
    };
    ordina(array_char_p, ARLEN);
}
void ordina(char* array_char_p[], int length) {
    int i, j; char* tmp;
    for( i=0; i< length; i++ ) {
        for(j=i+1; j< length; j++) {
            if( strcmp(array_char_p[i], array_char_p[j]) > 0 ) {
                tmp = array_char_p[i];
                array_char_p[i] = array_char_p[j];
                array_char_p[j] = tmp;
            }
        }
    }
}