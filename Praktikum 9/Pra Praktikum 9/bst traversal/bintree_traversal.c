#include "bintree_traversal.h"

void printPreOrder(BinTree p){
    if(!isTreeEmpty(p)){
        printf("%d ", ROOT(p).key);     //cetak root
        printPreOrder(LEFT(p));         //baru cetak semua di kiri
        printPreOrder(RIGHT(p));        //cetak semua di kanan
    }
}
void printInOrder(BinTree p){
    if(!isTreeEmpty(p)){
        printInOrder(LEFT(p));
        printf("%d ", ROOT(p).key);
        printInOrder(RIGHT(p));
    }
}

void printPostOrder(BinTree p){
    if(!isTreeEmpty(p)){
        printPostOrder(LEFT(p));
        printPostOrder(RIGHT(p));
        printf("%d ", ROOT(p).key);
    }
}

NodeList* newNodeListElement(ElType val){
    NodeList* node = (NodeList*) malloc(sizeof(NodeList));
    if(node != NULL){
        Info(node) = val;       //set ke val
        Next(node) = NULL;      //berikutnya kosong
    }
    return node;
}

NodeList* concat(NodeList* l1, NodeList* l2){
    if(l1 == NULL){
        return l2;                  //kl l1 kosong, artinya sisa l2
    }
    NodeList* temp = l1;            //mulai dari l1
    while(Next(temp) != NULL){
        temp = Next(temp);          //nyambungin
    }
    Next(temp) = l2;                //pas akhir l1 lanjut ke l2
    return l1;
}

NodeList* makeListPreOrder(BinTree p){
    if(!isTreeEmpty(p)){
        NodeList* head = newNodeListElement(ROOT(p));               //mulai dari root
        if(head != NULL){
            NodeList* left = makeListPreOrder(LEFT(p));
            NodeList* right = makeListPreOrder(RIGHT(p));
            NodeList* final = concat(head, concat(left, right));    //gabungin root + keft + right
            return final;
        }
        return NULL;
    }
    return NULL;
}

NodeList* makeListInOrder(BinTree p){
    if(!isTreeEmpty(p)){
        NodeList* head = newNodeListElement(ROOT(p));
        NodeList* left = makeListInOrder(LEFT(p));
        if(head != NULL){
            NodeList* right = makeListInOrder(RIGHT(p));
            NodeList* final = concat(concat(left, head), right);
            return final;
        }
        return NULL;
    }
    return NULL;
}

NodeList* makeListPostOrder(BinTree p){
        if(!isTreeEmpty(p)){
        NodeList* head = newNodeListElement(ROOT(p));
        NodeList* left = makeListPostOrder(LEFT(p));
        NodeList* right = makeListPostOrder(RIGHT(p));
        if(head != NULL){
            NodeList* final = concat(concat(left, right), head);
            return final;
        }
        return NULL;
    }
    return NULL;
}

void printNodeList(NodeList* l){
    while(l != NULL){
        printf("[%d] -> ", Info(l).key);
        l = Next(l);
    }
    printf("FINISH\n");
}