#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Arv.h"

main(){
    Node* root = NULL;
    root = treeInsertABB(root,10);
    root = treeInsertABB(root,20);
    root = treeInsertABB(root,30);
    root = treeInsertABB(root,40);
    root = treeInsertABB(root,25);
    root = treeInsertABB(root,50);
    root = treeInsertABB(root,25);
    root = treeInsertABB(root,22);
    root = treeInsertABB(root,33);

    Node* rootAVL = NULL;

    printf("ARVORE ABB\n");

    treePrint(root);

    printf("\nARVORE AVL\n");

    rootAVL = balancearTree(rootAVL,root);

    treePrint(rootAVL);

    return 0;
}


