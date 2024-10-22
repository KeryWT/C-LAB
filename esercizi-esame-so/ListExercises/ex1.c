#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *creaNodo(int val) {
  Node *new_node = (malloc(sizeof(Node)));

  new_node->data = val;
  new_node->next = NULL;

  return new_node;
}

void printList(Node *head) {
  for (Node *i = head; i != NULL; i = i->next) {
    printf("%d ", i->data);
    if (i->next == NULL) {
      printf("\n");
      return;
    }
  }
}

void insertBeginning(Node **head, int val) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = val;
  new_node->next = *head;
  *head = new_node;
}

void insertEnd(Node **head, int val) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = val;
  new_node->next = NULL;

  // Node *curr = *head;
  for (Node *curr = *head; curr->next != NULL; curr = curr->next) {
    if (curr->next->next == NULL) {
      curr->next->next = new_node;
      break;
    }
  }
  // curr->next = new_node;
}

void removeNode(Node **head, int val) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->data == val) { // If the element to remove is the head, I remove it and exit the function.
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }

  Node *curr = *head;
  if (curr->next == NULL)
    return;

  while (curr->next->data != val) {
    curr = curr->next;
  }
  Node *temp = curr->next;
  curr->next = temp->next;
  free(temp);
}

/* VERSIONE ALTERNATIVA ALL'ES 4 */
void removeAllNodes(Node **head, int val) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->data == val) {
    Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }

  Node *curr = *head;
  while (curr->next != NULL) {
    if (curr->next->data == val) {
      Node *tmp = curr->next; //tmp = nodo da togliere
      curr->next = tmp->next;
      free(tmp);
    }

    if (curr->next->data != val) {
      curr = curr->next;
    }
  }
}

void lookupVal(Node *head, int val) {
  if (head == NULL) {
    printf("Valore non trovato.\n");
    return;
  }

  Node *curr = head;
  int position = 1;
  int found = 0;

  while (curr != NULL) {
    if (curr->data == val) {
      printf("Valore trovato al nodo %d.\n", position);
      found = 1;
    }
    position++;
    curr = curr->next;
  }
  if (!found) {
    printf("Valore non trovato.\n");
  }
}

int listSize(Node *head) {
  if (head == NULL)
    return 0;

  int size = 0;
  Node *curr = head;
  while (curr != NULL) {
    size++;
    curr = curr->next;
  }

  return size;
}

void invertList(Node **head) {
  if (*head == NULL) // lista vuota
    return;

  if ((*head)->next == NULL) // lista da un solo elemento
    return;

  Node *curr = *head;
  Node *prev = NULL;
  Node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev; // sposta la testa in fondo
}


int main(void) {

  Node *head = creaNodo(4);
  head->next = creaNodo(6);
  insertBeginning(&head, 5);
  insertEnd(&head, 4);
  insertEnd(&head, 4);
  insertEnd(&head, 9);
//  removeNode(&head, 4);
//  removeAllNodes(&head, 4);

  printf("Numero di nodi nella lista: %d\n", listSize(head));

  printf("Lista iniziale\n");
  printList(head);

  invertList(&head);
  printf("Lista invertita\n");
  printList(head);
  // lookupVal(head, 5);
  return 0;
}
