#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Arv.h"

main(){
    Node* root = NULL;
    root = treeInsert(root,7);
    root = treeInsert(root,22);
    root = treeInsert(root,66);
    root = treeInsert(root,4);
    root = treeInsert(root,3);
    root = treeInsert(root,1);



    treePrint(root);

    root = treeDelete(root,7);

    treePrint(root);

    return 0;
}


