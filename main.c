#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Arv.h"

main(){
    Node* root = NULL;

    root = treeInsert(root,10);
    root = treeInsert(root,20);
    root = treeInsert(root,30);
    root = treeInsert(root,40);
    root = treeInsert(root,25);
    root = treeInsert(root,50);
    root = treeInsert(root,25);
    root = treeInsert(root,7);

    treePrint(root);

    return 0;
}


