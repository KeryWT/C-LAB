#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  int value;
  struct node *next;
} node;
typedef node *link;

int add_after(link head, int to_add, int after) {
  if (head == NULL) {
    return FALSE;
  }

  int curr_pos = 1;
  link curr = head;

  while (curr != NULL) {
    if (curr_pos == after) {
      link temp = curr->next;
      link new_node = malloc(sizeof(node));
      new_node->value = to_add;
      new_node->next = temp;
      curr->next = new_node;

      return TRUE;
    }
    curr = curr->next;
  }
  return FALSE;
}
