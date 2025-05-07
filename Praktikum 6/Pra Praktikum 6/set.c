// #ifndef set_H
// #define set_H
#include <stdio.h>
#include "set.h"
// #include <stdbool.h>
// #include "boolean.h"

// #define Nil 0
// #define MaxEl 100

// typedef struct
// {
//     int Elements[MaxEl];
//     int Count;
// } Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    S->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
boolean IsMember(Set S, int Elmt){
    for(int i=0; i<S.Count; i++){
        if(S.Elements[i] == Elmt){
            return true;
        }
    }
    return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */

void Insert(Set *S, int Elmt){
    if(IsFull(*S)){
        return;
    }
    if(IsMember(*S, Elmt)){
        return;
    }
    int i;
    for(i=S->Count-1; i>=0 && S->Elements[i]>Elmt; i--){
        S->Elements[i+1] = S->Elements[i];
    }
    S->Elements[i+1] = Elmt;
    S->Count++;
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S, Elmt terurut dari kecil ke besar.
Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, int Elmt){
    if(!IsMember(*S, Elmt)){
        return;
    }
    int idx = -1;
    for(int i=0; i<S->Count; i++){
        if(S->Elements[i] == Elmt){
            idx = i;
            break;
        }
    }
    if(idx>-1){
        for(int j=idx; j<S->Count-1; j++){
            S->Elements[j] = S->Elements[j+1];
        }
        S->Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

// #endif

// int main(){
//     Set s;
//     CreateEmpty(&s);
//     if (IsEmpty(s))
//     {
//         printf("Set is empty\n");
//     }
//     Insert(&s, 5);
//     Insert(&s, 3);
//     Insert(&s, 8);
//     Insert(&s, 3);

//     printf("Set elements: ");
//     for (int i = 0; i < s.Count; i++)
//     {
//         printf("%d ", s.Elements[i]);
//     }
//     printf("\n");

//     printf("Is 3 a member? %s\n", IsMember(s, 3) ? "Yes" : "No");
//     printf("Is 7 a member? %s\n", IsMember(s, 7) ? "Yes" : "No");

//     Delete(&s, 3);
//     printf("Set elements after deleting 3: ");
//     for (int i = 0; i < s.Count; i++)
//     {
//         printf("%d ", s.Elements[i]);
//     }
//     printf("\n");

//     if (IsFull(s))
//     {
//         printf("Set is full\n");
//     }
//     else
//     {
//         printf("Set is not full\n");
//     }
//     return 0;
// }