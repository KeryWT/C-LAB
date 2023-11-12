#include "stdio.h"

int main(){

    printf("Inserisci un carattere alfanumerico: \n");
    char c = ' ';
    scanf("%c" , &c);
    if (c >= '0' && c <= '9'){
        printf("Il carattere \"%c\" inserito è un numero.", c);
    } else if ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z')){
        printf("Il carattere \"%c\" inserito è una lettera.", c);
    } else {
        printf("Il carattere \"%c\" che hai inserito non è alfanumerico.", c);
    }
    return 0;
}