//
// Created by Luca Betti on 11/10/23.
//

#ifndef LAB_CL_LIST_H
#define LAB_CL_LIST_H

#endif //LAB_CL_LIST_H

#include "client.h"

// Definizione del tipo 'l_node' usato per rappresentare i nodi della lista
typedef struct _node{
    unsigned int id;
    client person;
    struct _node *next;
} l_node;

// Definizione del tipo list_cl (lista di client)
typedef struct {
    l_node *head;
    l_node *tail
} list_cl;

#define L_EMPTYLIST_CL {NULL, NULL}; // Inizializzare lista vuota

// Definizione di una lista di studenti inizialmente vuota
//list_cl class = L_EMPTYLIST_CL;