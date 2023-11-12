//
// Created by Luca Betti on 27/10/23.
//
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int i;
    for(i=1; i <= 10; i++)
        printf((i&1) ? "%d odd\n" : "%d even\n",i);
    exit(EXIT_SUCCESS);
}