// #ifndef STACK_H
// #define STACK_H
// #include "Boolean.h"
// #define boolean unsigned char
// #define TRUE 1
// #define FALSE 0
// #include <stdio.h>
#include "stack.h"

// #define IDX_UNDEF -1
// #define CAPACITY 100

// typedef int ElType;

// typedef struct
// {
//     ElType buffer[CAPACITY];
//     int idxTop;
// } Stack;

// #define IDX_TOP(s) (s).idxTop
// #define TOP(s) (s).buffer[(s).idxTop]

/*** Konstruktor/Kreator ***/
void CreateStack(Stack *s){
    IDX_TOP(*s) = IDX_UNDEF;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */

/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */
/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean isEmpty(Stack s){
    return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean isFull(Stack s){
    return IDX_TOP(s) == CAPACITY - 1;
}
/* Mengirim true jika Stack penuh */

int length(Stack s){
    if(isEmpty(s)){
        return 0;
    }
    return IDX_TOP(s) + 1;
}
/* Mengirim ukuran Stack s saat ini */

/*********** Menambahkan sebuah elemen ke Stack **********/
void push(Stack *s, ElType val){
    if(isEmpty(*s)){
        IDX_TOP(*s) = 0;
    } else{
        IDX_TOP(*s)++;
    }
    TOP(*s) = val;
}
/* Menambahkan val sebagai elemen Stack s.
I.S. s mungkin kosong, tidak penuh
F.S. val menjadi TOP yang baru, TOP bertambah 1 */

/*********** Menghapus sebuah elemen Stack **********/
void pop(Stack *s, ElType *val){
    *val = TOP(*s);
    if(IDX_TOP(*s) == 0){
        IDX_TOP(*s) = IDX_UNDEF;
    } else{
        IDX_TOP(*s)--;
    }
}
/* Menghapus X dari Stack S.
I.S. S tidak mungkin kosong
F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void SortirStack(Stack *S1, Stack *S2){
    ElType temp;
    while(!isEmpty(*S1)){
        pop(S1, &temp);
        ElType topS2;
        while(!isEmpty(*S2) && TOP(*S2) > temp){
            pop(S2, &topS2);
            push(S1, topS2);
        }
        push(S2, temp);

    }
}
/* Menyortir S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut (elemen terbesar berada di paling atas) */
/* Contoh: */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
/* CATATAN:
   Penyortiran HARUS dilakukan secara bertahap saat pemindahan elemen dari S1 ke S2.
   Tidak diperbolehkan memindahkan seluruh isi S1 ke S2 terlebih dahulu, lalu menyortir
   menggunakan algoritma seperti bubble sort, insertion sort, dan sejenisnya.
   Gunakan hanya operasi dasar stack (push, pop, isEmpty, TOP) dalam proses sortir ini.
*/
// #endif

// void printStack(Stack s)
// {
//     if (isEmpty(s))
//     {
//         printf("EMPTY\n");
//     }
//     else
//     {
//         for (int i = 0; i <= s.idxTop; i++)
//         {
//             printf("%d ", s.buffer[i]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     Stack s1, s2;
//     ElType val;

//     CreateStack(&s1);
//     CreateStack(&s2);

//     push(&s1, 23);
//     push(&s1, 92);
//     push(&s1, 98);
//     push(&s1, 31);
//     push(&s1, 3);
//     push(&s1, 34);
//     printf("Stack 1 :\n");
//     printStack(s1);
//     printf("Stack 2 :\n");
//     printStack(s2);

//     SortirStack(&s1, &s2);

//     printf("Stack 1 :\n");
//     printStack(s1);
//     printf("Stack 2 :\n");
//     printStack(s2);

//     return 0;
// }