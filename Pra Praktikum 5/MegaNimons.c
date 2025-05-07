// NIM    : 18224075
// Nama   : Sherry Eunike
// Tanggal: 23 April 2025

// #ifndef MEGA_NIMONS_H
// #define MEGA_NIMONS_H

#include "MegaNimons.h"
#include <stdio.h>
#include <string.h>

/* *** Konstanta *** */
// #define CAPACITY 100
// #define IDX_UNDEF -1

// /* *** Type Data *** */
// typedef int IdxType;

// /* Struktur MegaNimons */
// typedef struct {
//     int id;                         // ID eksperimen unik
//     char name[30];                  // Nama MegaNimons
//     float powerLevel;              // Power level maksimum MegaNimons
//     char mutationType[20];         // Tipe mutasi (contoh: "fly", "laser", dsb.)
//     boolean isStable;              // TRUE kalau stable, FALSE kalau unstable
// } MegaNimons;

// /* Struktur LabTrack */
// typedef struct {
//     MegaNimons contents[CAPACITY]; // Tempat penyimpanan data MegaNimons
//     int nEff;                      // Jumlah elemen efektif dalam list
// } LabTrack;

/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah LabTrack:
 *   - L.contents[i] mengakses MegaNimons ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createLabTrack(LabTrack *L){
    L->nEff = 0;
}

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(LabTrack L){
    return L.nEff;
}

/**
 * Mengembalikan kapasitas maksimum list
 */
int maxCapacity(){
    return CAPACITY;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType firstIdx(LabTrack L){
    return 0;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType lastIdx(LabTrack L){
    return L.nEff-1;
}

/**
 * Mengembalikan MegaNimons pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
MegaNimons getElmt(LabTrack L, IdxType i){
    return L.contents[i];
}

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(LabTrack *L, IdxType i, MegaNimons val){
    L->contents[i] = val;
}

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(LabTrack *L, int N){
    if(N>=0 && N<=CAPACITY){
        L->nEff = N;
    }
}

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i){
    // if(i>=0 && i<CAPACITY){
    //     return TRUE;
    // } else{
    //     return FALSE;
    // }
    return (i>=0 && i<CAPACITY);
}

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(LabTrack L, IdxType i){
    return(i>=0 && i<L.nEff);
}

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(LabTrack L){
    return (L.nEff == 0);
}

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(LabTrack L){
    return (L.nEff == CAPACITY);
}

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan MegaNimons pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(LabTrack *L, MegaNimons m, IdxType idx){
    if(!isFull(*L) && isIdxValid(idx) && idx <= L->nEff){
        for(int i=L->nEff; i>idx; i--){
            L->contents[i] = L->contents[i-1];
        }
        L->contents[idx] = m;
        L->nEff++;
    }
}

/**
 * Menambahkan MegaNimons ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(LabTrack *L, MegaNimons m){
    insertAt(L, m, 0);
}

/**
 * Menambahkan MegaNimons ke posisi terakhir dalam list
 */
void insertLast(LabTrack *L, MegaNimons m){
    // if(!isFull(*L)){
    //     L->contents[L->nEff] = m;
    //     L->nEff++;
    // }
    insertAt(L, m, L->nEff);
}

/**
 * Menghapus MegaNimons pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m){
    if(isIdxEff(*L, idx)){
        *m = L->contents[idx];
        for(int i=idx; i<L->nEff-1; i++){
            L->contents[i] = L->contents[i+1];
        }
        L->nEff--;
    }
}

/**
 * Menghapus MegaNimons pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteFirst(LabTrack *L, MegaNimons *m){
    deleteAt(L, 0 , m);
}

/**
 * Menghapus MegaNimons pada indeks terakhir
 * Elemen terakhir disimpan pada *m
 */
void deleteLast(LabTrack *L, MegaNimons *m){
    // if(!isEmpty(*L)){
    //     L->nEff--;
    //     *m = L->contents[L->nEff];
    // }
    deleteAt(L, L->nEff-1, m);
}

/**
 * Mengembalikan indeks MegaNimons berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(LabTrack L, int id){
    for(int i=0; i<L.nEff; i++){
        if(L.contents[i].id == id){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list MegaNimons
 * Format: [index]: ID=xxx NAME=xxx POWER=xxx.x MUT=xxx STABLE=Yes/No
 */
void printLabTrack(LabTrack L){
    for(int i=0; i<L.nEff; i++){
        printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i, L.contents[i].id, L.contents[i].name, L.contents[i].powerLevel, L.contents[i].mutationType, L.contents[i].isStable? "Yes" : "No");
    }
}

/**
 * Menghapus seluruh MegaNimons yang tidak stabil (isStable == false)
 * Setiap MegaNimons yang dihapus akan dicetak namanya ke layar
 * Format output: "EJECTED: <nama_minion>"
 * I.S. L terdefinisi
 * F.S. Semua MegaNimons tidak stabil dihapus dari list dan ditampilkan namanya
 */
void ejectUnstable(LabTrack *L){
    int i=0;
    MegaNimons temp;
    while(i<L->nEff){
        if(!L->contents[i].isStable){
            printf("EJECTED: %s\n", L->contents[i].name);
            deleteAt(L, i, &temp);
        } else{
            i++;
        }
    }
}

/**
 * Menampilkan hanya MegaNimons dengan powerLevel >= minPower
 */
void filterByPower(LabTrack L, float minPower){
    for(int i=0; i<L.nEff; i++){
        if(L.contents[i].powerLevel >= minPower){
            printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i, L.contents[i].id, L.contents[i].name, L.contents[i].powerLevel, L.contents[i].mutationType, L.contents[i].isStable? "Yes" : "No");
        }
    }
}

// #endif

// int main(){
//     LabTrack lab;
//     createLabTrack(&lab);

//     MegaNimons m1 = {101, "Zaptor", 75.5, "laser", true};
//     MegaNimons m2 = {102, "Flygon", 63.2, "fly", false};
//     MegaNimons m3 = {103, "Pyrosaur", 88.9, "fire", true};
//     MegaNimons m4 = {104, "Hydron", 42.7, "water", false};

//     insertLast(&lab, m1);
//     insertLast(&lab, m2);
//     insertLast(&lab, m3);
//     insertLast(&lab, m4);

//     printf("== LAB SAAT INI ==\n");
//     printLabTrack(lab);

//     printf("\n== FILTER POWER >= 65 ==\n");
//     filterByPower(lab, 65);

//     printf("\n== EJECT YANG UNSTABLE ==\n");
//     ejectUnstable(&lab);

//     printf("\n== LAB SETELAH EJECT ==\n");
//     printLabTrack(lab);

//     printf("\n== DELETE FIRST DAN LAST ==\n");
//     MegaNimons removed;
//     deleteFirst(&lab, &removed);
//     printf("Removed first: %s\n", removed.name);
//     deleteLast(&lab, &removed);
//     printf("Removed last: %s\n", removed.name);

//     printf("\n== LAB FINAL ==\n");
//     printLabTrack(lab);

//     return 0;
// }