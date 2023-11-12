//
// Created by Luca Betti on 27/10/23.
//
#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    printf( "argc = %d\n", argc);
    for(i=0; i<argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);
    return 0;
}