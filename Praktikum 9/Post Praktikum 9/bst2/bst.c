#include "bst.h"

Address newTreeNode(ElType X){
    Address p = (Address) malloc(sizeof(TreeNode));
    if(p != NIL){
        ROOT(p) = X;
        LEFT(p) = NIL;
        RIGHT(p) = NIL;
    }
    return p;
}

void deallocTreeNode(Address p){
    free(p);
}

boolean isTreeEmpty(BinTree p){
    return p == NIL;
}

boolean isOneElmt(BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p) == NIL && RIGHT(p) == NIL);
    }
    return false;
}

boolean isUnerLeft(BinTree p){
    if(!isTreeEmpty(p)){
        return (RIGHT(p) == NIL && LEFT(p) != NIL);
    }
    return false;
}

boolean isUnerRight(BinTree p){
    if(!isTreeEmpty(p)){
        return (RIGHT(p) != NIL && LEFT(p) == NIL);
    }
    return false;
}

boolean isBiner(BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p) != NIL && RIGHT(p) != NIL);
    }
    return false;
}

BinTree buildBalancedTree(int n){
    if(n >= 0){
        ElType x;
        x.key = n;
        x.count = 1;

        int nL = n/2;
        int nR = n - nL - 1;

        Address root = newTreeNode(x);
        if(root != NIL){
            LEFT(root) = buildBalancedTree(nL);
            RIGHT(root) = buildBalancedTree(nR);
        }
        return root;
    } else{
        return NIL;
    }
}

void insSearchTree(ElType x, BinTree *p){
    if(isTreeEmpty(*p)){
        *p = newTreeNode(x);
    } else if(x.key < ROOT(*p).key){
        insSearchTree(x, &LEFT(*p));
    } else if(x.key > ROOT(*p).key){
        insSearchTree(x, &RIGHT(*p));
    } else{
        ROOT(*p).count++;
    }
}

void delNode(BinTree *p){
    if(RIGHT(*p) != NIL){
        delNode(&RIGHT(*p));
    } else{
        Address temp = *p;
        *p = LEFT(*p);
        deallocTreeNode(temp);
    }
}

void delBTree(BinTree *p, ElType x){
    if(x.key < ROOT(*p).key){
        delBTree(&LEFT(*p), x);
    } else if(x.key > ROOT(*p).key){
        delBTree(&RIGHT(*p), x);
    } else{
        Address temp = *p;
        if(isOneElmt(*p)){
            *p = NIL;
            deallocTreeNode(temp);
        } else if(isBiner(*p)){
            Address max = LEFT(*p);
            while(RIGHT(max) != NIL){
                max = RIGHT(max);
            }
            (*p)->info = max->info;
            delNode(&LEFT(*p));
        } else if(isUnerRight(*p)){
            *p = RIGHT(*p);
            deallocTreeNode(temp);
        } else if(isUnerLeft(*p)){
            *p = LEFT(*p);
            deallocTreeNode(temp);
        }
    }
}

Address searchNode(BinTree p, int value) {
    if (isTreeEmpty(p)) {
        return NIL;
    }
    
    if (value < ROOT(p).key) {
        return searchNode(LEFT(p), value);
    } else if (value > ROOT(p).key) {
        return searchNode(RIGHT(p), value);
    } else {
        return p;
    }
}

Address findMinimum(BinTree p) {
    if (isTreeEmpty(p)) {
        return NIL;
    }
    
    while (!isTreeEmpty(LEFT(p))) {
        p = LEFT(p);
    }
    
    return p;
}

void preBeautifulView(BinTree p){
    if(isTreeEmpty(p)){
        printf("(x)");
    } else if(isOneElmt(p)){
        printf("(%d)", ROOT(p).key);
    } else if(!isTreeEmpty(p)){
        printf("(");
        printf("%d", ROOT(p).key);
        preBeautifulView(LEFT(p));
        preBeautifulView(RIGHT(p));
        printf(")");
    }
}

void inBeautifulView(BinTree p){
    if(isTreeEmpty(p)){
        printf("(x)");
    } else if(isOneElmt(p)){
        printf("(%d)", ROOT(p).key);
    } else if(!isTreeEmpty(p)){
        printf("(");
        inBeautifulView(LEFT(p));
        printf("%d", ROOT(p).key);
        inBeautifulView(RIGHT(p));
        printf(")");
    }
}

void postBeautifulView(BinTree p){
    if(isTreeEmpty(p)){
        printf("(x)");
    } else if(isOneElmt(p)){
        printf("(%d)", ROOT(p).key);
    } else if(!isTreeEmpty(p)){
        printf("(");
        postBeautifulView(LEFT(p));
        postBeautifulView(RIGHT(p));
        printf("%d", ROOT(p).key);
        printf(")");
    }
}

// int main() {
//     BinTree root = NIL;
//     ElType x;

//     // Insert nodes
//     x.key = 50;
//     x.count = 1;
//     insSearchTree(x, &root);
    
//     // Print the tree
//     printf("Preorder:\n");
//     preBeautifulView(root);
//     printf("\n");

//     printf("Inorder:\n");
//     inBeautifulView(root);
//     printf("\n");

//     printf("Postorder:\n");
//     postBeautifulView(root);
//     printf("\n");
    
//     x.key = 30;
//     x.count = 1;
//     insSearchTree(x, &root);
    
//     // Print the tree
//     printf("Preorder:\n");
//     preBeautifulView(root);
//     printf("\n");

//     printf("Inorder:\n");
//     inBeautifulView(root);
//     printf("\n");

//     printf("Postorder:\n");
//     postBeautifulView(root);
//     printf("\n");

//     x.key = 70;
//     x.count = 1;
//     insSearchTree(x, &root);

//     x.key = 20;
//     x.count = 1;
//     insSearchTree(x, &root);

//     x.key = 40;
//     x.count = 1;
//     insSearchTree(x, &root);

//     x.key = 60;
//     x.count = 1;
//     insSearchTree(x, &root);

//     x.key = 80;
//     x.count = 1;
//     insSearchTree(x, &root);

//     // Print the tree
//     printf("Preorder:\n");
//     preBeautifulView(root);
//     printf("\n");

//     printf("Inorder:\n");
//     inBeautifulView(root);
//     printf("\n");

//     printf("Postorder:\n");
//     postBeautifulView(root);
//     printf("\n");

//     return 0;
// }