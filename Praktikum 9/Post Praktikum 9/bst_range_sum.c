#include "bst_range_sum.h"
#include <stdio.h>
#include <stdlib.h>

void printPreOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printf("%d ", ROOT(p).key);
        printPreOrder(LEFT(p));
        printPreOrder(RIGHT(p));
    }
}

void printInOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printInOrder(LEFT(p));
        printf("%d ", ROOT(p).key);
        printInOrder(RIGHT(p));
    }
}

void printPostOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printPostOrder(LEFT(p));
        printPostOrder(RIGHT(p));
        printf("%d ", ROOT(p).key);
    }
}

NodeList* newNodeListElement(ElType val) {
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    if (newNode != NULL) {
        Info(newNode) = val;
        Next(newNode) = NULL;
    }
    return newNode;
}

NodeList* concat(NodeList* l1, NodeList* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    NodeList* temp = l1;
    while (Next(temp) != NULL) {
        temp = Next(temp);
    }
    Next(temp) = l2;
    return l1;
}

NodeList* makeListPreOrder(BinTree p) {
    if (isTreeEmpty(p)) return NULL;
    
    NodeList* currentNode = newNodeListElement(ROOT(p));
    if (currentNode == NULL) return NULL;
    
    NodeList* leftList = makeListPreOrder(LEFT(p));
    NodeList* rightList = makeListPreOrder(RIGHT(p));
    
    NodeList* result = concat(currentNode, leftList);
    result = concat(result, rightList);
    
    return result;
}

NodeList* makeListInOrder(BinTree p) {
    if (isTreeEmpty(p)) return NULL;
    
    NodeList* leftList = makeListInOrder(LEFT(p));
    NodeList* currentNode = newNodeListElement(ROOT(p));
    if (currentNode == NULL) {
        if (leftList != NULL) free(leftList);
        return NULL;
    }
    
    NodeList* rightList = makeListInOrder(RIGHT(p));
    
    NodeList* result = concat(leftList, currentNode);
    result = concat(result, rightList);
    
    return result;
}

NodeList* makeListPostOrder(BinTree p) {
    if (isTreeEmpty(p)) return NULL;
    
    NodeList* leftList = makeListPostOrder(LEFT(p));
    NodeList* rightList = makeListPostOrder(RIGHT(p));
    NodeList* currentNode = newNodeListElement(ROOT(p));
    if (currentNode == NULL) {
        if (leftList != NULL) free(leftList);
        if (rightList != NULL) free(rightList);
        return NULL;
    }
    
    NodeList* result = concat(leftList, rightList);
    result = concat(result, currentNode);
    
    return result;
}

void printNodeList(NodeList* l) {
    NodeList* current = l;
    while (current != NULL) {
        printf("[%d]", Info(current).key);
        current = Next(current);
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> FINISH\n");
}

int rangeSumBST(BinTree p, int L, int R){
    int sum = 0;
    if(isTreeEmpty(p)){
        return 0;
    }
    if(p->info.key < L){
        sum += rangeSumBST(RIGHT(p), L, R);
    } else if(p->info.key > R){
        sum += rangeSumBST(LEFT(p), L, R);
    } else{
        sum = p->info.key + rangeSumBST(RIGHT(p), L, R) + rangeSumBST(LEFT(p), L, R);
    }
    return sum;
}

// int main() {
//     // Bentuk pohon BST nya begini:
//     //         8
//     //       /   \
//     //      3     10
//     //     / \      \
//     //    2   6      14
//     //   /   / \     /
//     //  1   4   7   13
    
//     BinTree T = NIL;
//     ElType x;

//     // Pengujian rangeSumBST (pohon kosong)
//     int L = 5, R = 10;
//     int result = rangeSumBST(T, L, R);
//     printf("Hasil penjumlahan key node dalam rentang [%d, %d] adalah %d\n", L, R, result);

//     // Bangun BST menggunakan insSearchTree
//     int keys[] = {8, 3, 10, 2, 6, 14, 1, 7, 4, 13};
//     int n = sizeof(keys) / sizeof(keys[0]);

//     for (int i = 0; i < n; i++) {
//         x.key = keys[i];
//         x.count = 1;
//         insSearchTree(x, &T);
//     }

//     // Pengujian rangeSumBST (bukan kosong)
//     L = 4; R = 13;
//     result = rangeSumBST(T, L, R); // 4 + 6 + 7 + 8 + 10 + 13 = 48

//     printf("Hasil penjumlahan key node dalam rentang [%d, %d] adalah %d\n", L, R, result);

//     return 0;
// }