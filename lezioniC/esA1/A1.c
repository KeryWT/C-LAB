//
// Created by Luca Betti on 26/10/23.
//
#include <stdio.h>

int main(){
    char *s = "Hello WoRLd! Today's temperature is 34C.";
    char c;
    for(int i = 0; s[i] != '\0'; i++){
        if(!(s[i] >= 'A' && s[i] <= 'Z')) {
            putchar(s[i]);
        } else {
            c = s[i];
            putchar(s[i] - ( 'A' - 'a'));
        }
    }
    return 0;
}