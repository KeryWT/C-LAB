#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int val;
  struct _node *next;
} node;

node *creaNodo(int val) {
  node *new_node = (malloc(sizeof(node)));

  new_node->val = val;
  new_node->next = NULL;

  return new_node;
}

void printList(node *head) {
  for (node *i = head; i != NULL; i = i->next) {
    printf("%d ", i->val);
    if (i->next == NULL) {
      printf("\n");
      return;
    }
  }
}

void insertBeginning(node **head, int val) {
  node *new_node = malloc(sizeof(node));
  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

void insertEnd(node **head, int val) {
  node *new_node = malloc(sizeof(node));
  new_node->val = val;
  new_node->next = NULL;

  // node *curr = *head;
  for (node *curr = *head; curr->next != NULL; curr = curr->next) {
    if (curr->next->next == NULL) {
      curr->next->next = new_node;
      break;
    }
  }
  // curr->next = new_node;
}

void removenode(node **head, int val) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->val == val) { // If the element to remove is the head, I remove it and exit the function.
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }

  node *curr = *head;
  if (curr->next == NULL)
    return;

  while (curr->next->val != val) {
    curr = curr->next;
  }
  node *temp = curr->next;
  curr->next = temp->next;
  free(temp);
}

/* VERSIONE ALTERNATIVA ALL'ES 4 */
void removeAllnodes(node **head, int val) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->val == val) {
    node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }

  node *curr = *head;
  while (curr->next != NULL) {
    if (curr->next->val == val) {
      node *tmp = curr->next; // tmp = nodo da togliere
      curr->next = tmp->next;
      free(tmp);
    }

    if (curr->next->val != val) {
      curr = curr->next;
    }
  }
}

void lookupVal(node *head, int val) {
  if (head == NULL) {
    printf("Valore non trovato.\n");
    return;
  }

  node *curr = head;
  int position = 1;
  int found = 0;

  while (curr != NULL) {
    if (curr->val == val) {
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

int listSize(node *head) {
  if (head == NULL)
    return 0;

  int size = 0;
  node *curr = head;
  while (curr != NULL) {
    size++;
    curr = curr->next;
  }

  return size;
}

void invertList(node **head) {
  if (*head == NULL) // lista vuota
    return;

  if ((*head)->next == NULL) // lista da un solo elemento
    return;

  node *curr = *head;
  node *prev = NULL;
  node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev; // sposta la testa in fondo
}

node *list_erase_larger(node *head) {
  node *max = head;
  node *curr = head;

  if (curr->next == NULL) { // c'è un solo elemento
    return head;
  }

  while (curr != NULL) {
    if (curr->val > max->val) { // tengo max aggiornato. punta al nodo più grande incontrato finora
      max = curr;
    }

    if (curr->next == NULL) // fermati dopo aver controllato l'ultimo elemento
      break;

    if (curr->next->val > max->val) { // devo eliminare il nodo curr -> next
      node *tmp = curr->next;
      curr->next = curr->next->next;
      free(tmp);
    } else {
      curr = curr->next;
    }
  }

  return head;
}

node *list_erase_larger_prof(node *head) {
  node *p, *p_next, *aux;

  if (head != NULL) {
    p = head;
    for (p_next = p->next; p_next != NULL; p_next = p->next) {
      if (p_next->val > p->val) {
        /* Elimino elemento p_next */
        aux = p_next;
        p->next = p_next->next;
        free(aux);
      } else {
        p = p_next;
      }
    }
  }
  return head;
}

int main(void) {
  node *head = creaNodo(7);
  head->next = creaNodo(3);
  insertEnd(&head, 9);
  insertEnd(&head, 3);
  insertEnd(&head, 10);
  insertEnd(&head, 1);

  printf("List beofre changes\n");
  printList(head);

  list_erase_larger(head);

  printf("List after changes\n");
  printList(head);
}
