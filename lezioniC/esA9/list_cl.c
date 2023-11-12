#include <mm_malloc.h>
#include "list_cl.h"
#include "client.h"



// Aggiunge il cliente p alla lista l 
list_cl l_add_cl(list_cl l, client p){

   // allocazione dell'elemento da aggiungere in coda alla lista   
   l_node *elem = (l_node *)malloc(sizeof(l_node)); 
 
   if (elem!=NULL){
      //elem->id = ...
      elem->person = p;
      elem->next   = NULL;
  
       
      if (l.head==NULL) // lista vuota
         l.head = l.tail = elem;
      else{
         l.tail->next = elem;
         l.tail = elem;
      }
   }
      
   return l;
}


#define l_is_not_empty(l) ( (l).head!=NULL )

/*
client  l_rem_cl(list_cl l){
// se la lista è vuota restituisce un cliente 'vuoto'
   client c = CL_EMPTYCLIENT;
   
   if ( l_is_not_empty(l) ){
      l_node *t = l.head;
      c = l.head->person;
      l.head = l.head->next;
      free(t);
   }
   return c;
}
*/

list_cl  l_rem_cl(list_cl l, client *c){ 
// se la lista è vuota restituisce un cliente 'vuoto'
   
   if ( l_is_not_empty(l) ){
      l_node *t = l.head;
      *c = l.head->person;
      l.head = l.head->next;
      free(t);
   }
   return l;
}

int l_is_empty(list_cl l){
   return l.head==NULL;
}



 list_cl l_clear(list_cl l){
    l_node *e=l.head;
    l_node *t;
    
    while (e!=NULL){
      t = e;
      e = e->next;
      free(t);
    }
    
    l.head=NULL;
 
    return l;  
 }
 
 
 
 int l_length(list_cl l){
    int i;
    l_node *e=l.head;
    
    for ( i=0 ; e!=NULL ; i++, e=e->next)
      ;
 
    return i;
 }

