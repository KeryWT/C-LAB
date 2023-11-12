#include "address.h"
#include "client.h"
#include "list_cl.h"

/* Modificare il programma affinché la lista dei clienti sia inizializzata leggendo 
 * un file dal seguente formato: Il file ha tante righe quanti sono i clienti. Ogni riga
 * ha i seguenti campi separati da virgole:
 *
 *     nome, cognome, via, civico, CAP, paese, codice fiscale
 *
 * Esempio:
 *     Donald, Duck, via dei Tigli, 20, 10149, US, DNDDCK60S08A784C
 *     Mickey, Mouse, ...
 *
 * Il file è passato al programma da linea di comando.
 * Si consiglia di usare le funzioni della libreria standard per accedere al file
 * in quanto fornisce di funzioni di input formattato (scanf)
 */

    
int main(int argc, char *argv[]){
   list_cl l = L_EMPTYLIST_CL;
   
   { // Aggiungo un cliente alla lista l
      client  cl;
      cl = cl_set_name(cl, "Donald", "Duck");
      address adr = new_address("via dei Tigli", 20, 10149, US);
      cl = cl_set_address(cl, adr);
      cl = cl_set_cf(cl, "DNDDCK60S08A784C");

      l = l_add_cl(l, cl);
   }
   
   {  // Rimuovo un cliente dalla lista l
      client cl;
      l=l_rem_cl(l, &cl);
      cl_print(cl);
   }
}
