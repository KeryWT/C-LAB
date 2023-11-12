#include <stdio.h>
#include "client.h"

client cl_set_name(client cl, const char *first_name, const char *last_name){
   cl.first_name = first_name;
   cl.last_name  = last_name;

   return cl;
}

client cl_set_address(client cl, address addr){
   cl.addr = addr;
   return cl;
}

client cl_set_cf(client cl, char cf[]){
   int i;
   for (i=0 ; i<CL_CFLENGTH ; i++)
	   cl.cf[i] = cf[i];
   return cl;
}

void cl_print(client cl){
   printf("Nome: %s\tCognome: %s\n", cl.first_name, cl.last_name);
   //printf("CF: %s\n",cl.cf); ERRORE
   addr_print(cl.addr);
}
