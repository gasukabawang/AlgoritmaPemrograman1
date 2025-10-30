// #ifndef STACK_H
// #define STACK_H
#include "Boolean.h"
#include "stack.h"
#include <stdio.h>
// #include <stdboolean.h>

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
    s->idxTop = IDX_UNDEF;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */

/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */
/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean isEmpty(Stack s){
    return s.idxTop == IDX_UNDEF;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean isFull(Stack s){
    return s.idxTop == CAPACITY - 1;
}
/* Mengirim true jika Stack penuh */

int length(Stack s){
    return s.idxTop + 1;
}
/* Mengirim ukuran Stack s saat ini */

/*********** Menambahkan sebuah elemen ke Stack **********/
void push(Stack *s, ElType val){
    if(!isFull(*s)){
        s->idxTop++;
        s->buffer[IDX_TOP(*s)] = val;
    }
}
/* Menambahkan val sebagai elemen Stack s.
I.S. s mungkin kosong, tidak penuh
F.S. val menjadi TOP yang baru, TOP bertambah 1 */

/*********** Menghapus sebuah elemen Stack **********/
void pop(Stack *s, ElType *val){
    if(!isEmpty(*s)){
        *val = s->buffer[IDX_TOP(*s)];
        s->idxTop--;
    }
}
/* Menghapus X dari Stack S.
I.S. S tidak mungkin kosong
F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
// #endif

// void printStack(Stack s)
// {
//     printf("Stack: ");
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
//     Stack s;
//     ElType val;

//     CreateStack(&s);
//     if (isEmpty(s))
//     {
//         printf("Stack is empty\n");
//     }

//     push(&s, 5);
//     push(&s, 3);
//     push(&s, 8);
//     push(&s, 3);
//     printStack(s);

//     printf("Top element: %d\n", TOP(s));

//     printf("Length: %d\n", length(s));

//     pop(&s, &val);
//     printf("Popped: %d\n", val);
//     printStack(s);

//     if (isFull(s))
//     {
//         printf("Stack is full\n");
//     }
//     else
//     {
//         printf("Stack is not full\n");
//     }

//     while (!isFull(s))
//     {
//         push(&s, 1);
//     }
//     printf("Filled the stack.\n");
//     printf("Length after filling: %d\n", length(s));
//     printf("Is full: %s\n", isFull(s) ? "true" : "false");

//     return 0;
// }