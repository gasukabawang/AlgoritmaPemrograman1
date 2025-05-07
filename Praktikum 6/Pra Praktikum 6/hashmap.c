// #ifndef hashHashMap_H
// #define hashHashMap_H
// #include "Boolean.h"
#include <stdio.h>
#include "hashmap.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
 */

// #define false 0
// #define true 1
// #define Nil 0
// #define MaxEl 16
// #define Undefined -9999

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
    M->Count = 0;
    for(int i=0; i<MaxEl; i++){
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}
// TODO: 1. CreateEmpty

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    return (K%MaxEl);
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */

valuetype Value(HashMap M, keytype K) {
    address idx = Hash(K);
    int i = 0;
    // while (i < MaxEl) {
    //     address currentIdx = (idx + i) % MaxEl;
    //     if (M.Elements[currentIdx].Key == K) {
    //         return M.Elements[currentIdx].Value;
    //     }
    //     if (M.Elements[currentIdx].Key == Undefined) {
    //         break;
    //     }
    //     i++;
    // }
    for(int i=0; i<MaxEl; i++){
        int currentIdx = (idx+i) % MaxEl;       //mencari secara melingkar
        if (M.Elements[currentIdx].Key == K) {
            return M.Elements[currentIdx].Value;
        } else if (M.Elements[currentIdx].Key == Undefined) {
            return Undefined;
        }
    }
    return Undefined;
}
// TODO: 2. Value

void Insert(HashMap *M, keytype K, valuetype V){
    if(M->Count >= MaxEl){
        return;
    }
    address idx = Hash(K);
    // while(M->Elements[idx].Value != Undefined){
    //     if(M->Elements[idx].Key == K){
    //         M->Elements[idx].Value = V;
    //         return;
    //     }
    //     idx = (idx+1) % MaxEl;
    // }
    // M->Elements[idx].Key = K;
    // M->Elements[idx].Value = V;
    // M->Count++;
    for(int i=0; i<MaxEl; i++){
        int currentIdx = (idx+i) % MaxEl;
        if(M->Elements[currentIdx].Key == K){
            M->Elements[currentIdx].Value = V;
            return;
        }

        if(M->Elements[currentIdx].Key == Undefined){
            M->Elements[currentIdx].Key = K;
            M->Elements[currentIdx].Value = V;
            M->Count++;
            return;
        }
    }
}
// TODO: 3. Insert

void printHashMap(HashMap M){
    for(int i=0; i<MaxEl; i++){
        printf("%d:\n", i);
        printf("  Key: %d\n", M.Elements[i].Key);
        printf("  Value: %d\n", M.Elements[i].Value);
    }
}
// TODO: 4. printHashMap

// #endif

// int main() {
//     HashMap M;
//     CreateEmpty(&M); // init with undefined values
//     Insert(&M, 1, 2); // map, key, value
//     Insert(&M, 2, 3);
//     Insert(&M, 3, 4);
//     Insert(&M, 123, 123);
//     printf("%d\n", Value(M, 1)); // get value with key 1
//     printf("%d\n", Value(M, 2));
//     printHashMap(M); // print all elements in the map

//     return 0;
// }