#include <stdio.h>
#include <stdlib.h>
#include "NimonsBaris.h"

// #ifndef ARRAY_H
// #define ARRAY_H

// /* Kamus Umum */

// #define IdxMax 100
// #define IdxMin 1
// #define IdxUndef -999 /* indeks tak terdefinisi*/

// /* Definisi elemen dan koleksi objek */
// typedef int IdxType; // Index Type
// typedef int ElType;  // Element Type

// typedef struct
// {
//     ElType baris[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
//     int Neff;                          /* banyaknya elemen efektif (banyak nimons di barisan) */
// } BarisanNimons;

/**
 * Indeks yang digunakan [IdxMin..IdxMax]
 * Jika T adalah BarisanNimons, cara deklarasi dan akses:
 * Deklarasi -> T : BarisanNimons
 *
 * Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.baris untuk mengakses seluruh nilai elemen tabel
 * T.baris[i] untuk mengakses elemen ke-i
 *
 * Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.baris[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.baris[i] dengan i=T.Neff
 */

/* ********** KONSTRUKTOR ********** */
/**
 * Konstruktor : create tabel kosong
 * I.S. sembarang
 * F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1
 */
void MakeEmpty(BarisanNimons *T){
    T->Neff = 0;
    //(*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/** --- Banyaknya elemen ---
 * Mengirimkan banyaknya elemen efektif tabel
 * Mengirimkan nol jika tabel kosong
 */
int NbElmt(BarisanNimons T){
    return T.Neff;
}

/** --- Daya tampung container ---
 * Mengirimkan maksimum elemen yang dapat ditampung oleh tabel
 */
int MaxNbEl(BarisanNimons T){
    return IdxMax - IdxMin + 1;
}

/* --- Selektor INDEKS --- */
/**
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen pertama
 */
IdxType GetFirstIdx(BarisanNimons T){
    return IdxMin;
}
/**
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen terakhir
 */
IdxType GetLastIdx(BarisanNimons T){
    return T.Neff;
}

/* --- Menghasilkan sebuah elemen --- */
/**
 * Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T)
 * Mengirimkan elemen tabel yang ke-i
 */
ElType GetElmt(BarisanNimons T, IdxType i){
    return T.baris[i];
}

/* --- Selektor SET : Mengubah nilai TABEL dan elemen tabel --- */
/**
 * Untuk type private/limited private pada bahasa tertentu
 * I.S. Tin terdefinisi, sembarang
 * F.S. Tout berisi salinan Tin
 * Assignment THsl -> Tin
 */
void SetTab(BarisanNimons Tin, BarisanNimons *Tout){
    for(int i=IdxMin; i<=Tin.Neff; i++){
        Tout->baris[i] = Tin.baris[i];
    }
    Tout->Neff = Tin.Neff;
}

/**
 * I.S. T terdefinisi, sembarang
 * F.S.Elemen T yang ke - i bernilai v
 * Mengeset nilai elemen tabel yang ke - i sehingga bernilai v
 */
void SetEl(BarisanNimons *T, IdxType i, ElType v){
    if(IsIdxValid(*T, i)){
        T->baris[i] = v;
        if(i>T->Neff){
            T->Neff =i;
        }
    }
    // T->baris[i]=v;
    // if(i>T->Neff){
    //     T->Neff =i;
    // }
}

/**
 * I.S. T terdefinisi, sembarang
 * F.S. Nilai indeks efektif T bernilai N
 * Mengeset nilai indeks elemen efektif sehingga bernilai N
 */
void SetNeff(BarisanNimons *T, IdxType N){
    if(N>=0 && N<=MaxNbEl(*T)){
        T->Neff = N;
    }
}

/* ********** Test Indeks yang valid ********** */
/**
 * Prekondisi : i sembarang
 * Mengirimkan TRUE jika i adalah indeks yang valid utk ukuran tabel
 * yaitu antara indeks yang terdefinisi utk container
 */
boolean IsIdxValid(BarisanNimons T, IdxType i){
    // boolean valid = FALSE;           biasa pak Riza begini
    // if(i>=i && i<=IdxMax){
    //     valid = TRUE;
    // }
    // return valid;
    return (i>=IdxMin && i<=IdxMax);
}
/**
 * Prekondisi : i sembarang
 * Mengirimkan TRUE jika i adalah indeks yang terdefinisi utk tabel
 * yaitu antara FirstIdx(T)..LastIdx(T)
 */
boolean IsIdxEff(BarisanNimons T, IdxType i){
    return (i>=IdxMin && i<=T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */

/* --- Test tabel kosong --- */
/* Mengirimkan TRUE jika tabel T kosong, mengirimkan FALSE jika tidak */
boolean IsEmpty(BarisanNimons T){
    return (T.Neff == 0);
}
/* --- Test tabel penuh --- */
/* Mengirimkan TRUE jika tabel T penuh, mengirimkan FALSE jika tidak */
boolean IsFull(BarisanNimons T){
    return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/**
 * Proses : Menuliskan isi tabel dengan traversal
 * I.S. T boleh kosong
 * F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah
 * Jika isi tabel [1,2,3] maka akan diprint
1:1
2:2
3:3
 * Jika T kosong : Hanya menulis "Tabel kosong"
 */
void TulisIsi(BarisanNimons T){
    if(IsEmpty(T)){
        printf("Tabel kosong\n");
    } else{
        for(int i=IdxMin; i<=T.Neff; i++){
            printf("%d:%d\n", i-IdxMin, T.baris[i]);
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* --- Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... --- */
/** Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
 * Mengirimkan T1 + T2
 */
BarisanNimons PlusTab(BarisanNimons T1, BarisanNimons T2){
    BarisanNimons TNew;
    MakeEmpty(&TNew);
    if(T1.Neff == T2.Neff){
        for(int i=IdxMin; i<=T1.Neff; i++){
            TNew.baris[i] = T1.baris[i] + T2.baris[i];
        }
        SetNeff(&TNew, T1.Neff);
    }
    return TNew;
}
/** Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
 * Mengirimkan T1 - T2
 */
BarisanNimons MinusTab(BarisanNimons T1, BarisanNimons T2){
    BarisanNimons TNew;
    MakeEmpty(&TNew);
    if(T1.Neff == T2.Neff && !IsEmpty(T1) && !IsEmpty(T2)){
        for(int i=IdxMin; i<=T1.Neff; i++){
            TNew.baris[i] = T1.baris[i] - T2.baris[i];
        }
    }
    SetNeff(&TNew, T1.Neff);
    return TNew;
}

/* ********** NILAI EKSTREM ********** */
/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan nilai maksimum tabel
 */
ElType ValMax(BarisanNimons T){
    ElType maks = T.baris[IdxMin];
    for(int i=IdxMin+1; i<=T.Neff; i++){
        if(maks < T.baris[i]){
            maks = T.baris[i];
        }
    }
    return maks;
}

/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan nilai minimum tabel
 */
ElType ValMin(BarisanNimons T){
    ElType min = T.baris[IdxMin];
    for(int i=IdxMin+1; i<=T.Neff; i++){
        if(min > T.baris[i]){
            min = T.baris[i];
        }
    }
    return min;
}

/* --- Mengirimkan indeks elemen bernilai ekstrem --- */
/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel
 */
IdxType IdxMaxTab(BarisanNimons T){
    ElType maks = T.baris[IdxMin];
    int indeksmaks = IdxMin;
    for(int i=IdxMin+1; i<=T.Neff; i++){
        if(maks < T.baris[i]){
            maks = T.baris[i];
            indeksmaks = i;
        }
    }
    // boolean found = FALSE;
    // IdxType i = IdxMin;
    // while(!found && i<T.Neff){
    //     if(T.baris[i] == maks){
    //         found = TRUE;
    //     } else{
    //         i++;
    //     }
    // }
    // return i;
    return indeksmaks;
}

/** Prekondisi : Tabel tidak kosong
 * Mengirimkan indeks i
 * dengan elemen ke-i nilai minimum pada tabel
 */
IdxType IdxMinTab(BarisanNimons T){
    ElType min = T.baris[IdxMin];
    int indeksmin = IdxMin;
    for(int i=IdxMin+1; i<=T.Neff; i++){
        if(min > T.baris[i]){
            min = T.baris[i];
            indeksmin = i;
        }
    }
    return indeksmin;
}

// #endif

// int main(){
//     BarisanNimons A;
//     MakeEmpty(&A);
//     SetEl(&A, 1, 10);
//     SetEl(&A, 2, 20);
//     SetEl(&A, 3, 5);
//     SetNeff(&A, 3);

//     TulisIsi(A);
//     printf("Max: %d di index %d\n", ValMax(A), IdxMaxTab(A));
//     printf("Min: %d di index %d\n", ValMin(A), IdxMinTab(A));

//     return 0;
// }