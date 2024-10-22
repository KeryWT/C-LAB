#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  int value;
  struct node *next;
} node;
typedef node *link;

int delete_all(link head, int to_delete){
  if (head == NULL)
    return FALSE;

  int deleted = 0;

  link curr = head;
  while (curr != NULL) {
    if (curr->next == NULL)
      break;

    if(curr->next->value == to_delete){
      link temp = curr->next;
      curr->next = curr->next->next;
      free(temp);
      deleted = 1;
    } else {
      curr = curr->next;
    }    
  }

  return deleted ? TRUE : FALSE;
}

int main(void){

  return 0;
}