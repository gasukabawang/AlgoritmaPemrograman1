#include "hashmap.h"
#include <stdio.h>
// #include <stdio.h>
// #define Nil 0
// #define MaxEl 16
// #define Undefined -9999

// // typedef int bool;
// typedef int keytype;   // Tipe data untuk key
// typedef int valuetype; // Tipe data untuk value
// typedef int address;   // Tipe data untuk alamat penyimpanan

// typedef struct{
//     keytype Key;
//     valuetype Value;
// } infotype;

// typedef struct{
//     infotype Elements[MaxEl];
//     int Count;
// } HashMap;

void CreateEmpty(HashMap *M){
    M->Count = 0;
    for(int i=0; i<MaxEl; i++){
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

address Hash(keytype K){
    return (K%MaxEl);
}

valuetype Value(HashMap M, keytype k){
    for(int i=0; i<MaxEl; i++){
        int currIdx = (Hash(k)+i) % MaxEl;
        if(M.Elements[currIdx].Key == k){
            return M.Elements[currIdx].Value;
        } else if(M.Elements[currIdx].Key == Undefined){
            return Undefined;
        }
    }
    return Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v){
    if(M->Count < MaxEl && Value(*M, k) == Undefined){              //biar ga ada key yang double
        for(int i=0; i<MaxEl; i++){                                 //kl key udh ada di map, maka update
            int currIdx = (Hash(k)+i) % MaxEl;                      //kl key ga ada, baru tambah baru
            if(M->Elements[currIdx].Key == k){
                M->Elements[currIdx].Value = v;
                return;
            } else if(M->Elements[currIdx].Key == Undefined){
                M->Elements[currIdx].Value = v;
                M->Elements[currIdx].Key = k;
                M->Count++;
                return;
            }
        }
    }
}

void printHashMap(HashMap M){
    for(int i=0; i<MaxEl; i++){
        printf("%d:\n", i);
        printf("  Key: %d\n", M.Elements[i].Key);
        printf("  Value: %d\n", M.Elements[i].Value);
    }
}

void Delete(HashMap *M, keytype k){
    for(int i=0; i<MaxEl; i++){
        int currIdx = (Hash(k)+i) % MaxEl;
        if(M->Elements[currIdx].Key == k){
            M->Elements[currIdx].Key = Undefined;
            M->Elements[currIdx].Value = Undefined;
            M->Count--;
            return;
        } else if(M->Elements[currIdx].Key == Undefined){
            return;
        }
    }
}
/* Menghapus elemen dengan key k dari HashMap M */
/* I.S. M tidak kosong */
/* F.S. Elemen dengan key k dihapus dari M */
/* Jika k tidak ada, tidak ada perubahan pada M */

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
//     Delete(&M, 123); // delete element with key 123
//     printf("%d\n", Value(M, 123));
//     printHashMap(M); 
//     Delete(&M, 10); // delete element with key 10 (not exist)
//     printf("%d\n", Value(M, 10));
//     printHashMap(M); 
//     Insert(&M, 10, 20); // insert element with key 10
//     printf("%d\n", Value(M, 10));
//     Insert(&M, 10, 30);
//     printf("%d\n", Value(M, 10));
//     printHashMap(M);
//     Insert(&M, 26, 40); // insert element with key 26 (conflict)
//     printf("%d\n", Value(M, 10));
//     printf("%d\n", Value(M, 11));
//     printf("%d\n", Value(M, 26));
//     printHashMap(M);
//     Delete(&M, 11); // delete element with key 11
//     printf("%d\n", Value(M, 26));
//     printHashMap(M);
//     Delete(&M, 26); // delete element with key 26
//     printf("%d\n", Value(M, 26));
//     printHashMap(M);

//     return 0;
// }