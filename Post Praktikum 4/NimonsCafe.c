// #ifndef NIMONSCAFE_H
// #define NIMONSCAFE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NimonsCafe.h"

/* Enum untuk tipe gula */
// typedef enum {
//     LESS_SUGAR,     // sedikit gula
//     NORMAL_SUGAR,   // gula normal
//     EXTRA_SUGAR     // ekstra gula
// } TipeGula;

// /* Enum untuk tipe es */
// typedef enum {
//     LESS_ICE,       // sedikit es
//     NORMAL_ICE,     // es normal
//     NO_ICE          // tanpa es
// } TipeEs;

// /* Tipe data pesanan minuman */
// typedef struct {
//     char namaMinuman[30]; // nama minuman (contoh: "Latte")
//     char ukuran;          // ukuran ('S', 'M', atau 'L')
//     TipeGula tipeGula;    // preferensi gula
//     TipeEs tipeEs;        // preferensi es
// } PesananMinuman;

/* Constructor */

/**
 * Membuat pesanan minuman berdasarkan:
 * - nama minuman
 * - ukuran ('S', 'M', 'L')
 * - tipe gula (LESS_SUGAR, NORMAL_SUGAR, EXTRA_SUGAR)
 * - tipe es (LESS_ICE, NORMAL_ICE, NO_ICE)
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(nimons.pekerjaan, pekerjaan);
 */
PesananMinuman BuatPesanan(char *nama, char ukuran, TipeGula tGula, TipeEs tEs){
    PesananMinuman p;
    strcpy(p.namaMinuman, nama);
    p.ukuran = ukuran;
    p.tipeGula = tGula;
    p.tipeEs = tEs;
    return p;
}

/* Getter & Setter */

/**
 * Return nama minuman
 */
char *getNamaMinuman(PesananMinuman *p){
    return p->namaMinuman;
}

/**
 * Mengubah nama minuman
 */
void setNamaMinuman(PesananMinuman *p, char *nama){
    strcpy(p->namaMinuman, nama);
}

/**
 * Return ukuran minuman
 */
char getUkuran(PesananMinuman p){
    return p.ukuran;
}

/**
 * Mengubah ukuran pesanan menjadi ukuran baru
 * Contoh: 
 * Mengubah ukuran minuman M menjadi S
 */
void setUkuran(PesananMinuman *p, char ukuran){
    p->ukuran = ukuran;
}

/**
 * Return Tipe Gula minuman
 */
TipeGula getTipeGula(PesananMinuman p){
    return p.tipeGula;
}

/**
 * Mengubah Tipe Gula minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeGula(PesananMinuman *p, TipeGula tGula){
    p->tipeGula = tGula;
}

/**
 * Return Tipe Es dari minuman
 */
TipeEs getTipeEs(PesananMinuman p){
    return p.tipeEs;
}

/**
 * Mengubah Tipe Es dari minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeEs(PesananMinuman *p, TipeEs tEs){
    p->tipeEs = tEs;
}

/* Display */

/**
 * Menampilkan pesanan dalam format:
 * <namaMinuman> - <ukuran> - <tipeGula>, <tipeEs>
 * Contoh Output:
 * "Cappuccino - M - normal sugar, less ice"
 * 
 * PASTIKAN ADA ENDLINE DI AKHIR OUTPUT!
 */
void TulisPesanan(PesananMinuman p){
    const char *gula;
    if(p.tipeGula == LESS_SUGAR){
        gula = "less sugar";
    } else if(p.tipeGula == NORMAL_SUGAR){
        gula = "normal sugar";
    } else{
        gula = "extra sugar";
    }
    const char *es;
    if(p.tipeEs == LESS_ICE){
        es = "less ice";
    } else if(p.tipeEs == NORMAL_ICE){
        es = "normal ice";
    } else{
        es = "no ice";
    }
    printf("%s - %c - %s, %s\n", p.namaMinuman, p.ukuran, gula, es);
}

/* Utility */

/**
 * Menghitung total kalori berdasarkan:
 * - Ukuran:
 *     S = 100 kalori
 *     M = 150 kalori
 *     L = 200 kalori
 * - Gula:
 *     LESS_SUGAR = +10 kalori
 *     NORMAL_SUGAR = +20 kalori
 *     EXTRA_SUGAR = +40 kalori
 * 
 * Return: nilai kalori dalam bilangan bulat
 */
int TotalKalori(PesananMinuman p){
    int kalori=0;
    if(p.ukuran == 'S') {
        kalori += 100;
    } else if(p.ukuran == 'M') {
        kalori += 150;
    } else if(p.ukuran == 'L'){
        kalori += 200;
    }

    if (p.tipeGula == LESS_SUGAR) {
        kalori += 10;
    } else if (p.tipeGula == NORMAL_SUGAR) {
        kalori += 20;
    } else if (p.tipeGula == EXTRA_SUGAR) {
        kalori += 40;
    }
    return kalori;
}

/**
 * Menghitung volume bersih (tanpa es) berdasarkan:
 * - Ukuran:
 *     S = 240 ml
 *     M = 360 ml
 *     L = 480 ml
 * - Es:
 *     volume es pada NORMAL_ICE = 25% dari volume ukuran
 *     volume es pada LESS_ICE = 10% dari volume ukuran
 *     volume es pada NO_ICE = 0% dari volume ukuran
 *
 * Return: volume bersih dalam bilangan bulat
 */
int VolumeBersih(PesananMinuman p){
    int vol = 0;
    if (p.ukuran ==  'S'){
        vol = 240;
    }else if (p.ukuran == 'M'){
        vol = 360; 
    }else if (p.ukuran == 'L'){
        vol = 480;
    }
    float persentase = 0.0;
    if (p.tipeEs == NORMAL_ICE){
        persentase = 0.25 ;
    } else if (p.tipeEs == LESS_ICE){
        persentase = 0.1 ;
    } else if (p.tipeEs == NO_ICE){
        persentase = 0.0 ;
    }
    int volBersih = vol - (int)(vol*persentase);
    return volBersih;
}
// #endif