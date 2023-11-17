//
// Created by Luca Betti on 17/11/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if(c == EOF){
            printf("Output erro");
            exit(EXIT_FAILURE);
        }
        putchar(toupper(c));
    }
    return 0;
}

