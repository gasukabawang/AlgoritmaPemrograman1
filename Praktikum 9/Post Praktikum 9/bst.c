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

int nbLeaf(BinTree p){
    if(isTreeEmpty(p)){
        return 0;
    } else{
        nbLeaf1(p);
    }
}

int nbLeaf1(BinTree p){
    if(isOneElmt(p)){
        return 1;
    }else{
        if(isUnerLeft(p)){
            return nbLeaf1(LEFT(p));
        } else if(isUnerRight(p)){
            return nbLeaf1(RIGHT(p));
        } else{
            return nbLeaf1(LEFT(p)) + nbLeaf1(RIGHT(p));
        }
    }
}

int depth(BinTree p){
    if (isTreeEmpty(p)) return 0;
    int leftHeight = depth(LEFT(p));
    int rightHeight = depth(RIGHT(p));
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void addLeft(BinTree *p, ElType x){
    if(isTreeEmpty(*p)){
        *p = newTreeNode(x);
    } else{
        addLeft(&LEFT(*p), x);
    }
}

void delLeft(BinTree *p, ElType *x){
    if(isOneElmt(*p)){
        Address n = *p;
        *x = ROOT(*p);
        n = *p;
        *p = NIL;
        deallocTreeNode(n);
    } else{
        if(isUnerRight(*p)){
            delLeft(&RIGHT(*p), x);
        } else{
            delLeft(&LEFT(*p), x);
        }
    }
}

// int main()
// {
//     BinTree p = NIL;
//     ElType x;

//     x.key = 5;
//     x.count = 1;
//     insSearchTree(x, &p);

//     x.key = 3;
//     insSearchTree(x, &p);

//     x.key = 7;
//     insSearchTree(x, &p);

//     x.key = 2;
//     insSearchTree(x, &p);

//     printf("Leaf : %d\n", nbLeaf(p));
//     printf("Depth : %d\n", depth(p));

//     x.key = 6;
//     addLeft(&p, x);

//     delLeft(&p, &x);
//     printf("Delete : %d\n", x.key);

//     delLeft(&p, &x);
//     printf("Delete : %d\n", x.key);

//     delLeft(&p, &x);
//     printf("Delete : %d\n", x.key);

//     return 0;
// }