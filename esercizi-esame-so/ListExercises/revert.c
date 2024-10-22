#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;
typedef node *link;

// input:  3 -> -1 -> 4 -> -2
// output: 3 <- -1 <- 4 <- -2
link revert(link head) {
  if (head == NULL) {
    return NULL;
  }

  link reversed_head = NULL;
  link curr = head;
  while (curr != NULL) {
    link new_node = (link)malloc(sizeof(node));
    if (new_node == NULL) {
      exit(1);
    }

    new_node->value = curr->value;
    new_node->next = reversed_head; // puntatore in direzione opposta

    reversed_head = new_node; // avanza nella nuova lista
    curr = curr->next;        // avanza nella lista originale
  }
  return reversed_head;
}

int main(void) {

  return 0;
}