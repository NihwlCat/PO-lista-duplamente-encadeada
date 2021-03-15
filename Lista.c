#include "Lista.h"

lista* createList(){
    lista *l = (lista*) malloc(sizeof(lista));
    l->fim = NULL;
    l->inicio = NULL;
    l->length = 0;

    return l;
}

no* createNodo(int value){
    no *nodo = (no*) malloc(sizeof(no));
    nodo->item = value;
    nodo->prox = NULL;
    nodo->ant = NULL;

    return nodo;
}

bool listIsEmpyt(lista *l){
    if(l->inicio == NULL)
        return true;
    else
        return false;
}

void insertAt(lista *l, int value, int a){
    no* nodo = createNodo(value);

    if(listIsEmpyt(l)){
        l->inicio = nodo;
        l->fim = nodo;
    } else {
        if (a == 0) { // Inserir no início
            l->inicio->ant = nodo;
            nodo->prox = l->inicio;
            l->inicio = nodo;
        } else if (a == 1) { // Inserir no final
            l->fim->prox = nodo;
            nodo->ant = l->fim;
            l->fim = nodo;
        }
    }
    l->length++;
}

void printList(lista *l){
    no* aux = l->inicio;

    printf("[ ");
    while(aux != NULL){
        printf("%d ",aux->item);
        aux = aux->prox;
    }
    printf("]");
}

int removeAt(lista *l, int a){
    int num;
    no* aux = l->inicio;

    if(listIsEmpyt(l)){
        num = l->inicio->item;
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        if (a == 0){ // Remover do início
            num = l->inicio->item;
            l->inicio = l->inicio->prox;
            l->inicio->ant = NULL;
            aux->prox = NULL;
        } else if (a == 1){ // Remover do fim
            num = l->fim->item;
            l->fim = l->fim->ant;
            l->fim->prox = NULL;
            aux->ant = NULL;
        }
    }
    l->length--;
    aux = NULL;
    free(aux);

    return num;
}

// Quebrar lista em duas
lista* breakList(lista *l, int where){
    l->length = where;
    lista* la = createList();
    no* aux = l->inicio;

    if(listIsEmpyt(l))
        return NULL;
    else {
        la->length = 1;
        while(where != 0){
            if(aux == NULL)
                return l;

            aux = aux->prox;
            la->length++;
            where--;
        }

        la->inicio = aux;
        la->fim = l->fim;
        l->fim = aux->ant;
        l->fim->prox = NULL;
        la->inicio->ant = NULL;

        return la;
    }
}











