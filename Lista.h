#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct No {
    int item;
    struct No* prox;
    struct No* ant;
};

typedef struct No no;

struct Lista {
    no* inicio;
    no* fim;
    int length;
};

typedef struct Lista lista;

lista* create_list();

void printList(lista *l);

void insertAt(lista *l, int value, int a);

bool listIsEmpyt(lista *l);

no* createNodo(int value);

int removeAt(lista *l, int a);

lista* breakList(lista *l, int where);







#endif
