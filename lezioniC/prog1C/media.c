#include <stdio.h>
#include <math.h>

int main(void) {
	int x, y, z;

    printf("Introduci il primo numero (per es. 8):   ");
    scanf("%d", &x);
    printf("Introduci il secondo numero (per es. 2): ");
    scanf("%d", &y);
    printf("Introduci il terzo numero (per es. 3):   ");
    scanf("%d", &z);

    // divisione intera
    int media1 = (x + y + z) / 3;
    printf("int media1: (x+y+z)/3 = %d (divisione intera)\n", 
    	   media1);

    // divisione intera e cast a double
    double media2 = (x + y + z) / 3;
    printf(
        "double media2: (x+y+z)/3 = %lf (divisione intera e cast a double)\n",
    	media2
    );

    // divisione con virgola - risultato atteso!!
    double media3 = (x + y + z) / 3.0;
    printf("double media3: (x+y+z)/3.0 = %lf (divisione in virgola)\n", 
    	   media3);

    // ESERCIZIO: 
    // Consideriamo tre varianti per calcolare media3: 
    // double media3 = (x + y + z) / 3.0; // il cast è alla fine
    // double media3 = (double)(x + y + z) / 3; // il cast è sul risultato della somma nella parentesi
    // double media3 = (double)((x + y + z) / 3); // il cast è sul risultato della divisione
    // Cosa fanno rispettivamente? 
    // Quali sono i tipi delle operazioni intermedie?
    // Dove avviene il cast da int a double nelle tre varianti?
    
    
    puts("");
    // arrotondiamo il valore di media3 a intero
    printf("(int)media3 = %d\n", (int) media3);
    printf("(int)floor(media3) = %d\n", (int)floor(media3)); // per difetto
    printf("(int)round(media3) = %d\n", (int)round(media3)); // segue le regole
    printf("(int)ceil(media3)  = %d\n", (int)ceil(media3));  // per eccesso

    
    // ESERCIZIO: qual é la differenza tra i due modi di arrotondamento proposti?
    // Provare usando in input i valori 1,2,5
    
    
    printf("");
    // Problemi imprevisti dovuti a range di numeri finito,
    // che portano a rappresentazione binaria approssimata
    double f = 4.35;
    printf("4.35 * 100 = %d\n", round((int)(f * 100))); // provare round() prima del cast!
    
    
    // DOMANDA: spiegare per quale motivo il codice (int)(f * 100) non
    // produce il valore atteso (435).
}