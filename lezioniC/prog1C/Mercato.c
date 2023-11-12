//
// Created by Luca Betti on 20/10/23.
//
#include "stdio.h"

int main(){
    int norec = 0;
    double npom = 0.0;
    double priceo = 1.5;
    double pricep = 2.5;
    double tot = 0;

    printf("Quanti pacchi di orecchiette hai preso?: \n");
    scanf("%d", &norec);
    printf("Quanti Kg di pomodori hai preso?: \n");
    scanf("%lf", &npom);

    tot = (norec * priceo) + (npom * pricep);
    printf("In totale hai speso %.2lf euro", tot);
    return 0;
}