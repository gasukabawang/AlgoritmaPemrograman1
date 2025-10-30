// NIM     : 18224075
// NAMA    : Sherry Eunike
// Tanggal : 7 Mei 2025

/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

// #ifndef __circular_queue_h__
// #define __circular_queue_h__

#include <stdio.h>
#include <string.h>
// #include <stdbool.h>
#include "circular_queue.h"
// #include "boolean.h"

// #define IDX_UNDEF -1
// #define IDX_MAX 99

// typedef struct {
//         char namaTim[50];  /* Nama Tim Pemadam Kebakaran */
// } Tim;

// /* Definisi tipe elemen dan indeks pada Queue */
// typedef Tim ElType;
// typedef int IdxType;

// typedef struct {
//         ElType Tab[IDX_MAX+1];  /* tabel penyimpan elemen */
//         IdxType idxHead;  /* indeks elemen paling awal (terdepan) */
//         IdxType idxTail;  /* indeks tempat menambah elemen baru */
// } Queue;

// /* ********* AKSES (Selektor) ********* */
// /* Jika q adalah Queue, maka akses elemen : */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).Tab[(q).idxHead]
// #define     TAIL(q) (q).Tab[(q).idxTail]

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF;
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q){
    return (IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX) || (IDX_HEAD(Q) == IDX_TAIL(Q)+1);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int Length (Queue Q){
    if(IsEmpty(Q)){
        return 0;
    } else if(IDX_TAIL(Q) >= IDX_HEAD(Q)){
        return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    } else{
        return (IDX_MAX - IDX_HEAD(Q) + 1) + (IDX_TAIL(Q) + 1);
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue *Q){
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType X){
    if(!IsFull(*Q)){
        if(IsEmpty(*Q)){
            IDX_HEAD(*Q) = 0;
            IDX_TAIL(*Q) = 0;
        } else{
            IDX_TAIL(*Q) = (IDX_TAIL(*Q)+1) % (IDX_MAX+1);  //semisal 100 itu nanti tailnya balik ke awal 0
        }
        TAIL(*Q) = X;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */

ElType dequeue (Queue *Q){
    ElType first = HEAD(*Q);
    if(IDX_HEAD(*Q) == IDX_TAIL(*Q)){
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    } else{
        IDX_HEAD(*Q) = (IDX_HEAD(*Q)+1) % (IDX_MAX+1);
    }
    return first;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Operasi Tambahan *** */
ElType peek (Queue Q){
    return HEAD(Q);
}
/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */

/* *** Display Queue *** */
void displayQueue(Queue q){
    printf("[");
    if(!IsEmpty(q)){
        int i = IDX_HEAD(q);
        while(true){
            printf("%s", q.Tab[i].namaTim);
            if(i == IDX_TAIL(q)){
                break;
            }
            printf(", ");
            i = (i+1) % (IDX_MAX+1);           //kl udh 100 dia balik ke 0
        }
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1, e2, ..., en] */
/* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */

// #endif

// int main() {
//     Queue Q;
//     CreateQueue(&Q);

//     // Cek apakah queue kosong
//     if (IsEmpty(Q)) {
//         printf("Queue kosong\n");
//     }

//     // Enqueue beberapa tim
//     Tim t1 = {"Tim Api Membara"};
//     Tim t2 = {"Tim Hihang Hoheng"};
//     Tim t3 = {"Tim Air Beku"};
//     Tim t4 = {"Tim Pisang Panggang"};
//     Tim t5 = {"Tim Es Batu"};

//     printf("\nMelakukan enqueue...\n");
//     enqueue(&Q, t1);
//     enqueue(&Q, t2);
//     enqueue(&Q, t3);
//     enqueue(&Q, t4);
//     enqueue(&Q, t5);

//     printf("Isi queue setelah enqueue:\n");
//     displayQueue(Q);

//     // Cek apakah queue penuh
//     if (IsFull(Q)) {
//         printf("Queue penuh\n");
//     }
//     else {
//         printf("Queue belum penuh\n");
//     }

//     // Cek panjang queue
//     printf("Panjang antrean tim: %d antrean\n", Length(Q));

//     // Peek elemen terdepan
//     Tim depan = peek(Q);
//     printf("Tim terdepan (peek): %s\n", depan.namaTim);

//     // Dequeue dua kali
//     printf("\nMelakukan dequeue...\n");
//     Tim keluar1 = dequeue(&Q);
//     printf("Tim yang dikeluarkan: %s\n", keluar1.namaTim);
//     Tim keluar2 = dequeue(&Q);
//     printf("Tim yang dikeluarkan: %s\n", keluar2.namaTim);

//     printf("\nIsi queue setelah dequeue:\n");
//     displayQueue(Q);

//     // Menambahkan tim untuk menguji circularity
//     Tim t6 = {"Tim Salju"};
//     Tim t7 = {"Tim Lava"};
//     enqueue(&Q, t6);
//     enqueue(&Q, t7);

//     printf("\nIsi queue setelah menambahkan 2 tim baru:\n");
//     displayQueue(Q);

//     // Habisin queue
//     printf("\nMengosongkan queue...\n");
//     while (!IsEmpty(Q)) {
//         Tim keluar = dequeue(&Q);
//         printf("Mengeluarkan: %s\n", keluar.namaTim);
//     }

//     // Final check
//     printf("\nQueue setelah dikosongkan:\n");
//     displayQueue(Q);

//     if (IsEmpty(Q)) {
//         printf("Queue sekarang kosong.\n");
//     }

//     return 0;
// }