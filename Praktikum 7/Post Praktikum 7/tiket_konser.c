// NIM     : 18224075
// NAMA    : Sherry Eunike
// Tanggal : 14 Mei 2025

/* MODUL PRIORITY QUEUE BERBASIS LINEAR BUFFER */
/* Digunakan untuk mengatur antrean penonton Festival Musik Gro */
/* Penonton akan diatur berdasarkan prioritas queueNumber (QN), dan dicegah agar tidak duplikat berdasarkan seatNumber (SN) */

// #ifndef __tiket_konser_h__
// #define __tiket_konser_h__

// #include <stdio.h>
#include "tiket_konser.h"
// #include "boolean.h"
// #define boolean unsigned char
// #define true 1
// #define false 0

// #define IDX_UNDEF -1
// #define IDX_MAX 99

// /* ********* Tipe Data Penonton (Elemen Queue) ********* */
// typedef struct {
//         char nama[50];     /* Nama penonton (Nimons) */
//         int seatNumber;    /* SN: nomor unik tempat duduk */
//         int queueNumber;   /* QN: semakin kecil → semakin depan antrean */
// } Penonton;

// /* Definisi tipe elemen dan indeks pada Queue */
// typedef Penonton ElType;
// typedef int IdxType;


// /* ********* Definisi Queue Linear Buffer dengan representasi array secara eksplisit dan alokasi statik (Alternatif I) ********* */
// typedef struct {
//         ElType Tab[IDX_MAX+1];  /* tabel penyimpan elemen */
//         IdxType idxHead;  /* indeks elemen paling awal (terdepan) */
//         IdxType idxTail;  /* indeks tempat menambah elemen baru */
// } Queue;

// /* ********* AKSES (Selektor) ********* */
// /* Jika q adalah Queue dan p adalah elemen Queue, maka akses elemen: */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).Tab[(q).idxHead]
// #define     TAIL(q) (q).Tab[(q).idxTail]
// #define     NAMA(p) (p).nama
// #define       SN(p) (p).seatNumber
// #define       QN(p) (p).queueNumber

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q){
    return (IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX */
int Length (Queue Q){
    if(IsEmpty(Q)){
        return 0;
    } else;
        return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
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

boolean isDuplicateSN(Queue Q, int sn){
    for(int i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++){
        if(Q.Tab[i].seatNumber == sn){
            return true;
        }
    }
    return false;
}
/* Mengirim true jika terdapat Penonton dalam antrean dengan SN yang sama */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType P){
    if(IsEmpty(*Q)){
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
        HEAD(*Q) = P;
    } else{
        if(!isDuplicateSN(*Q, P.seatNumber)){
            int i = IDX_TAIL(*Q);
            while(i >= IDX_HEAD(*Q) && Q->Tab[i].queueNumber > P.queueNumber){
                Q->Tab[i+1] = Q->Tab[i];
                i--;
            }
            Q->Tab[i+1] = P;
            IDX_TAIL(*Q)++;
        }
        return;
    }
}
/* Proses: Menambahkan P ke dalam antrean jika dan hanya jika: */
/* - SN dari P belum pernah ada di antrean (tidak duplikat) */
/* - QN dari P menentukan posisi berdasarkan prioritas */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Apabila P memenuhi semua syarat, P masuk ke posisi yang sesuai berdasarkan queueNumber
        Semakin kecil, semakin berada di depan antrean
        IDX_TAIL akan "mundur" ke belakang */
ElType dequeue (Queue *Q){
    ElType temp = HEAD(*Q);
    for(int i = IDX_HEAD(*Q); i < IDX_TAIL(*Q); i++){
        Q->Tab[i] = Q->Tab[i+1];
    }
    IDX_TAIL(*Q)--;
    if(IDX_TAIL(*Q) < IDX_HEAD(*Q)){
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    }
    return temp;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        jika Q belum kosong idxHead "tetap" di indeks 0 dan elemen akan digeser satu per satu
        Q mungkin kosong dan idxHead akan menjadi IDX_UNDEF */

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
        for(int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
            printf("(%s-%d-%d)", q.Tab[i].nama, q.Tab[i].seatNumber, q.Tab[i].queueNumber);
            if(i < IDX_TAIL(q)){
                printf(", ");
            }
        }
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [p1, p2, ..., pn] */
/* Contoh : jika ada tiga elemen bernilai "Kebin" dgn SN: 3 QN: 1, "Pop" dgn SN: 1 QN: 2, dan "Toto" dgn SN: 2 QN: 3 akan dicetak: [(Kebin-3-1), (Pop-1-2), (Toto-2-3)] */
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

//     Penonton p1 = {"Kebin", 3, 2};
//     Penonton p2 = {"Pop", 1, 5};
//     Penonton p3 = {"Toto", 2, 4};
//     Penonton p4 = {"CloneKebin", 3, 0}; // SN duplikat
//     Penonton p5 = {"Jeffrey", 4, 1};

//     printf(">> Mendaftarkan: %s\n", NAMA(p1));
//     enqueue(&Q, p1);
//     displayQueue(Q);

//     printf(">> Mendaftarkan: %s\n", NAMA(p2));
//     enqueue(&Q, p2);
//     displayQueue(Q);

//     printf(">> Mendaftarkan: %s\n", NAMA(p3));
//     enqueue(&Q, p3);
//     displayQueue(Q);

//     printf(">> Mendaftarkan: %s\n", NAMA(p4));
//     enqueue(&Q, p4); // Seharusnya ditolak karena SN duplikat
//     displayQueue(Q);

//     printf(">> Mendaftarkan: %s\n", NAMA(p5));
//     enqueue(&Q, p5);
//     displayQueue(Q);

//     // Cek panjang queue
//     printf("Panjang antrean penonton: %d antrean\n", Length(Q));

//     printf("\n>> Dequeue satu penonton\n");
//     Penonton keluar = dequeue(&Q);
//     printf("Penonton masuk venue: (%s-%d-%d)\n", NAMA(keluar), SN(keluar), QN(keluar));
//     displayQueue(Q);

//     printf("\n>> Antrean penonton paling depan sekarang: (%s-%d-%d)\n", NAMA(peek(Q)), SN(peek(Q)), QN(peek(Q)));

//     return 0;
// }