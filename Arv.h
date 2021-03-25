#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node* esq;
    struct node* dir;
};

typedef struct node Node;

void treePrint(Node* root);

void treeFree(Node* root);

Node* treeInsert(Node* root, int value);

Node* nodeInit(int value);

Node* searchInTree(Node* root, int value);

Node* treeDelete(Node* root, int value);

Node* treeMinimum(Node* root);

Node* rot_dir(Node* desbal);

Node* rot_esq(Node* desbal);

#endif
