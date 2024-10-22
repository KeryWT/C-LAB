#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;
typedef node *link;

link pick_odds(link head) {
  if (head == NULL) {
    return NULL;
  }

  link new_head = malloc(sizeof(node));
  if (head->next == NULL) {
    new_head->next = NULL;
    new_head->value = head->value;
    return new_head;
  }

  link curr = head;
  link temp = new_head;
  int position = 1;

  while (curr != NULL) {
    if (position % 2 != 0) {
      temp->value = curr->value;
      temp->next = malloc(sizeof(node));
      if (curr->next != NULL) { // se è vera solo la prima condizione, siamo in una lista pari e non dobbiamo far avanzare temp.
        if (curr->next->next != NULL) { // se è vera anche questa condizione allora siamo in una lista dispari e avanziamo.
          temp = temp->next;
        }
      }
    }

    position++;
    curr = curr->next;
  }
  free(temp->next);
  temp->next = NULL;

  return new_head;
}

int main(void) {
  // Create a linked list
  link head = malloc(sizeof(node));
  head->value = 1;

  link node2 = malloc(sizeof(node));
  node2->value = 2;
  head->next = node2;

  link node3 = malloc(sizeof(node));
  node3->value = 3;
  node2->next = node3;

  link node4 = malloc(sizeof(node));
  node4->value = 4;
  node3->next = node4;
  node4->next = NULL;

  // link node5 = malloc(sizeof(node));
  // node5->value = 5;
  // node4->next = node5;
  // node5->next = NULL;

  // Call the pick_odds function
  link new_head = pick_odds(head);

  // Print the resulting linked list
  link currr = head;
  while (currr != NULL) {
    printf("%d ", currr->value);
    currr = currr->next;
  }
  printf("\n");

  // Print the resulting linked list
  link curr = new_head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  printf("\n");

  // Free the memory
  curr = new_head;
  while (curr != NULL) {
    link temp = curr;
    curr = curr->next;
    free(temp);
  }

  return 0;
}