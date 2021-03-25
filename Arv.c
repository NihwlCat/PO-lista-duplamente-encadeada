#include "Arv.h"

// Não tem como sobrecarregar método em C :/

Node* nodeInit(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->item = value;
    node->esq = NULL;
    node->dir = NULL;

    return node;
}

Node* treeMinimum(Node* root){
    if(root != NULL){
        Node* aux = root;
        while(aux->esq != NULL)
            aux = aux->esq;

        return aux;
    }
    return NULL;
}

Node* rot_esq(Node* desbal){
    Node* filho = desbal->dir;
    Node* neto = filho->esq;

    filho->esq = desbal;
    desbal->dir = neto;
    return filho;
}

Node* rot_dir(Node* desbal){
    Node* filho = desbal->esq;
    Node* neto = filho->dir;

    filho->dir = desbal;
    desbal->esq = neto;
    return filho;
}

Node* treeDelete(Node* root, int value){
    // O objetivo aqui é rodar a recursividade da função até achar um valor correspondente a 'value'
    if(root != NULL){
        if(root->item == value){
            if(root->esq == NULL && root->dir == NULL){
                // Caso a recursividade encontre uma folha
                free(root);
                return NULL;
            } else if (root->esq == NULL && root->dir != NULL){
                // Caso a recursividade encontre um nó com um filho
                Node* aux = root->dir;
                free(root);
                return aux; // Retorna o valor de aux para root a direita.
            } else if (root->esq != NULL && root->dir == NULL){
                Node* aux = root->esq;
                free(root);
                return aux; // Retorna o valor de aux para root a esquerda.
            } else {
                Node* aux = treeMinimum(root->esq);
                int item = aux->item;
                root = treeDelete(root,item);
                root->item = item;
            }

        } else if (value > root->item)
            root->dir = treeDelete(root->dir, value);
        else
            root->esq = treeDelete(root->esq, value);

        return root;
    }
}

Node* treeInsert(Node* root, int value){
    if (root == NULL){
        Node* node = nodeInit(value);
        return node;
    } else {
        if(value > root->item)
            root->dir = treeInsert(root->dir, value);
        else if (value < root->item)
            root->esq = treeInsert(root->esq, value);
    }

    return root;
    // As funções recursivas que estão dentro dos if's nunca acessarão este return.
    // Sendo assim, sempre que a root da chamada principal for diferente de nula, o método principal estará retornando root.
}

Node* searchInTree(Node* root, int value){
    if(root != NULL){
        if(root->item == value)
            return root;
        else {
            if(value > root->item) return searchInTree(root->dir, value);
            else return searchInTree(root->esq, value);
        }
    }
    return NULL;
}

void treePrint(Node* root){
    if(root != NULL){
        printf("[%d] ", root->item);
        treePrint(root->esq);
        treePrint(root->dir);
    }
}

void treeFree(Node* root){
    if(root != NULL){
        treeFree(root->esq);
        treeFree(root->dir);
        free(root);
    }
}


