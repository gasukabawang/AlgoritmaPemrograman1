#include "bst.h"

Address newTreeNode(ElType X){
    Address p = (Address) malloc(sizeof(TreeNode));
    if(p != NIL){
        ROOT(p) = X;        //set root dengan X
        LEFT(p) = NIL;      //left and right masih kosong
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

boolean isOneElmt(BinTree p){               //cuma ada root
    if(!isTreeEmpty(p)){
        return (LEFT(p) == NIL && RIGHT(p) == NIL);
    }
    return false;
}

boolean isUnerLeft(BinTree p){              //anak kiri semua
    if(!isTreeEmpty(p)){
        return (RIGHT(p) == NIL && LEFT(p) != NIL);
    }
    return false;
}

boolean isUnerRight(BinTree p){             //anak kanan semua
    if(!isTreeEmpty(p)){
        return (RIGHT(p) != NIL && LEFT(p) == NIL);
    }
    return false;
}

boolean isBiner(BinTree p){                 //ada kiri kanan
    if(!isTreeEmpty(p)){
        return (LEFT(p) != NIL && RIGHT(p) != NIL);
    }
    return false;
}

BinTree buildBalancedTree(int n){
    if(n >= 0){
        ElType x;
        x.key = n;                      //isi x dengan n
        x.count = 1;                    //karna udh diisi, count muali dr 1

        int nL = n/2;
        int nR = n - nL - 1;

        Address root = newTreeNode(x);              //buat node root
        if(root != NIL){
            LEFT(root) = buildBalancedTree(nL);     //buat bagian kiri
            RIGHT(root) = buildBalancedTree(nR);    //buat bagian kanan
        }
        return root;
    } else{
        return NIL;
    }
}

void insSearchTree(ElType x, BinTree *p){
    if(isTreeEmpty(*p)){
        *p = newTreeNode(x);                //buat simpul baru kl pohon kosong
    } else if(x.key < ROOT(*p).key){        //kl x lebih kecil, ke kiri
        insSearchTree(x, &LEFT(*p));
    } else if(x.key > ROOT(*p).key){        //kl x lebih besar, ke kanan
        insSearchTree(x, &RIGHT(*p));
    } else{
        ROOT(*p).count++;                   //kl x sama, tambah count
    }
}

void delNode(BinTree *p){
    if(RIGHT(*p) != NIL){               //cari node paling kanan
        delNode(&RIGHT(*p));
    } else{
        Address temp = *p;              //simpan nodedel
        *p = LEFT(*p);                  //anak kiri naik jadi root pengganti nodedel
        deallocTreeNode(temp);          //apus nodedel
    }
}

void delBTree(BinTree *p, ElType x){
    if(x.key < ROOT(*p).key){               //kl x lebih kecil, ke kiri
        delBTree(&LEFT(*p), x);
    } else if(x.key > ROOT(*p).key){        //kl x lebih besar, ke kanan
        delBTree(&RIGHT(*p), x);
    } else{                                 //kl x ketemu
        Address temp = *p;
        if(isOneElmt(*p)){                  //kl x daun, apus langsung
            *p = NIL;
            deallocTreeNode(temp);
        } else if(isBiner(*p)){             //kl x ada 2 anak
            Address max = LEFT(*p);         //cari node maks
            while(RIGHT(max) != NIL){
                max = RIGHT(max);
            }
            (*p)->info = max->info;         //ganti node x dengan maks
            delNode(&LEFT(*p));             //hapus node x
        } else if(isUnerRight(*p)){         //kl x anak kanan semua
            *p = RIGHT(*p);
            deallocTreeNode(temp);
        } else if(isUnerLeft(*p)){          //kl x anak kiri semua
            *p = LEFT(*p);
            deallocTreeNode(temp);
        }
    }
}

Address searchNode(BinTree p, int value){
    if(!isTreeEmpty(p)){
        if(value < ROOT(p).key){
            return searchNode(LEFT(p), value);
        } else if(value > ROOT(p).key){
            return searchNode(RIGHT(p), value);
        } else{
            return p;
        }
    }
    return NIL;
}

Address findMinimum(BinTree p){
    if(!isTreeEmpty(p)){
        Address current = p;
        while(LEFT(current) != NIL){        //cari terus di kiri
            current = LEFT(current);
        }
        return current;
    }
    return NIL;
}