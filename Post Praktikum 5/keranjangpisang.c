#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "keranjangpisang.h"

/* MODUL KERANJANG PISANG - LIST STATIK TANPA SORTING/SEARCHING/ARITMATIKA */
/* Berisi definisi dan semua primitif pemrosesan list statik integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */

// #ifndef KERANJANGPISANG_H
// #define KERANJANGPISANG_H

// #include "Boolean.h"

// /*  Kamus Umum */
// #define CAPACITY 100
// #define IDX_MIN 0
// #define IDX_UNDEF -1
// #define MARK -9999

// /* Definisi elemen dan koleksi objek */
// typedef int ElType;
// typedef int IdxType;

// typedef struct
// {
//     ElType contents[CAPACITY];
// } KeranjangPisang;

// #define ELMT(l, i) (l).contents[(i)]

/* Indeks yang digunakan [0..CAPACITY-1] */

/* ********** KONSTRUKTOR ********** */
void CreateKeranjang(KeranjangPisang *k){
    for(int i=0; i<CAPACITY; i++){
        k->contents[i] = MARK;
    }
}
/* I.S. k sembarang */
/* F.S. Terbentuk keranjang kosong dengan semua elemen bernilai MARK */

/* ********** SELEKTOR TAMBAHAN ********** */
int lengthKeranjang(KeranjangPisang k){
    int i = 0, count = 0;
    while(i < CAPACITY && k.contents[i] != MARK){
        i++;
        count++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif keranjang */

IdxType getFirstIdx(KeranjangPisang k){
    return 0;
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(KeranjangPisang k){
    return (lengthKeranjang(k) - 1);
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(KeranjangPisang k, IdxType i){
    return (i>=0 && i<CAPACITY); //alt neff
}
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(KeranjangPisang k, IdxType i){
    return (i>=0 && i<lengthKeranjang(k)); //alt neff
}
/* Mengirimkan true jika i adalah indeks efektif dalam keranjang */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(KeranjangPisang k){
    return (lengthKeranjang(k) == 0);
}
/* Mengirimkan true jika keranjang kosong */

boolean isFull(KeranjangPisang k){
    return (lengthKeranjang(k) == CAPACITY);
}
/* Mengirimkan true jika keranjang penuh */

/* ********** BACA / TULIS ********** */
void readKeranjang(KeranjangPisang *k){
    int n;
    scanf("%d", &n);
    CreateKeranjang(k);
    for (int i = 0; i < n; i++){
        scanf("%d", &k->contents[i]);
        getchar();
    }
}
/* I.S. Sembarang */
/* F.S. Keranjang berisi n elemen hasil input (0 <= n <= CAPACITY) */
/* Format input: n diikuti n buah elemen */
/* Contoh: 3 10 20 30*/
/* n = 3 dengan elemen keranjang adalah 10,20,dan 30*/

void printKeranjang(KeranjangPisang k){
    printf("[");
    for (int i = 0; i < lengthKeranjang(k); i++){
        printf("%d", k.contents[i]);
        if(i < lengthKeranjang(k)-1){
            printf(",");
        }
    }
    printf("]\n");
}
/* Menampilkan isi keranjang dalam format [x1,x2,...,xn] */
/* Contoh : */
/* [10,20,30] */
/* Jika kosong : []*/

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */
void insertFirst(KeranjangPisang *k, ElType val){
    // if (isFull(*k)){
    //     return;
    // }
    // for (int i=lengthKeranjang(*k); i>0; i--){
    //     k->contents[i]=k->contents[i-1];
    // }
    // // lengthKeranjang(k)++;
    // k->contents[0] = val;
    insertAt(k, val, 0);
}
/* Menambahkan val sebagai elemen pertama */

void insertAt(KeranjangPisang *k, ElType val, IdxType idx){
    for (int i=lengthKeranjang(*k); i > idx; i--){
        k->contents[i]=k->contents[i-1];
    }
    k->contents[idx] = val;
}
/* Menambahkan val di indeks tertentu */

void insertLast(KeranjangPisang *k, ElType val){
    // if (isFull(*k)){
    //     return;
    // }
    // k->contents[lengthKeranjang(*k)] = val;
    insertAt(k, val, lengthKeranjang(*k));
}
/* Menambahkan val sebagai elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */
void deleteFirst(KeranjangPisang *k, ElType *val){
    // if(isEmpty(*k)){
    //     return;
    // }
    *val = k->contents[0];
    // for (int i=0; i<lengthKeranjang(*k)-1; i++){
    //     k->contents[i]=k->contents[i+1];
    // }
    // k->contents[lengthKeranjang(*k)-1] = MARK;
    // // lengthKeranjang(k)--;
    deleteAt(k, val, 0);
}
/* Menghapus elemen pertama */

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx){
    *val = k->contents[idx];
    for (int i=idx; i<lengthKeranjang(*k)-1; i++){
        k->contents[i]=k->contents[i+1];
    }
    k->contents[lengthKeranjang(*k)-1] = MARK;
    // lengthKeranjang(k)--;
}
/* Menghapus elemen di indeks tertentu */

void deleteLast(KeranjangPisang *k, ElType *val){
    // if(isEmpty(*k)){
    //     return;
    // }
    *val = k->contents[lengthKeranjang(*k)-1];
    k->contents[lengthKeranjang(*k)-1] = MARK;
}
/* Menghapus elemen terakhir */