#include "Arv.h"

// Não tem como sobrecarregar método em C :/

Node* nodeInit(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->item = value;
    node->esq = NULL;
    node->dir = NULL;

    node->altura = 1;

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

    desbal->altura = maxValue(altura(desbal->esq),altura(desbal->dir)) + 1;
    filho->altura = maxValue(altura(filho->esq),altura(filho->dir)) + 1;
    return filho;
}

Node* rot_dir(Node* desbal){
    Node* filho = desbal->esq;
    Node* neto = filho->dir;

    filho->dir = desbal;
    desbal->esq = neto;

    desbal->altura = maxValue(altura(desbal->esq),altura(desbal->dir)) + 1;
    filho->altura = maxValue(altura(filho->esq),altura(filho->dir)) + 1;
    return filho;
}

Node* rot_dir_esq(Node* desbal){
    desbal->esq = rot_dir(desbal->esq);
    return rot_esq(desbal);
}

Node* rot_esq_dir(Node* desbal){
    desbal->dir = rot_esq(desbal->dir);
    return rot_dir(desbal);
}

int maxValue(int a, int b){
    return (a > b) ? a : b;
}

int altura(Node *n){
    if (n == NULL)
        return 0;
    return n->altura;
}

int balancear(Node *n){
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
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
    }
        if(value > root->item)
            root->dir = treeInsert(root->dir, value);
        else if (value < root->item)
            root->esq = treeInsert(root->esq, value);
        else
            return root;


    //Balanceando

    root->altura = 1 + maxValue(altura(root->esq),altura(root->dir));

    int balance = balancear(root);

    // LL
    if (balance > 1 && value < root->esq->item)
        return rot_dir(root);

    // RR
    if (balance < -1 && value > root->dir->item)
        return rot_esq(root);

    // LR
    if (balance > 1 && value > root->esq->item){
        root->esq =  rot_esq(root->esq);
        return rot_dir(root);
    }

    // RL
    if (balance < -1 && value < root->dir->item){
        root->dir =  rot_dir(root->dir);
        return rot_esq(root);
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


