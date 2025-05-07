// // #ifndef _NIMONS_BALAP_H_
// // #define _NIMONS_BALAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NimonsBalap.h"

// typedef struct Dimensi {
//     int panjang;
//     int lebar;
//     int tinggi;
// } dimensi;

// typedef struct Kendaraan {
//     char kode[4];
//     int jumlahKursi;
//     int jumlahRoda;
//     int kecepatan;
//     dimensi dim;
//     int berat;
//     int hargaJual;
// } kendaraan;

/* Getter & Setter */
char *getKode(kendaraan k){
    return k.kode;
}
void setKode(kendaraan *k, char *kode){
    strcpy(k->kode, kode);
}

int getJumlahKursi(kendaraan k){
    return k.jumlahKursi;
}
void setJumlahKursi(kendaraan *k, int jumlahKursi){
    k->jumlahKursi = jumlahKursi;
}

int getJumlahRoda(kendaraan k){
    return k.jumlahRoda;
}
void setJumlahRoda(kendaraan *k, int jumlahRoda){
    k->jumlahRoda = jumlahRoda;
}

int getKecepatan(kendaraan k){
    return k.kecepatan;
}
void setKecepatan(kendaraan *k, int kecepatan){
    k->kecepatan = kecepatan;
}

int getPanjang(kendaraan k){
    return k.dim.panjang;
}
void setPanjang(kendaraan *k, int panjang){
    k->dim.panjang = panjang;
}

int getLebar(kendaraan k){
    return k.dim.lebar;
}
void setLebar(kendaraan *k, int lebar){
    k->dim.lebar = lebar;
}

int getTinggi(kendaraan k){
    return k.dim.tinggi;
}
void setTinggi(kendaraan *k, int tinggi){
    k->dim.tinggi = tinggi;
}

int getBerat(kendaraan k){
    return k.berat;
}
void setBerat(kendaraan *k, int berat){
    k->berat = berat;
}

int getHargaJual(kendaraan k){
    return k.hargaJual;
}
void setHargaJual(kendaraan *k, int hargaJual){
    k->hargaJual = hargaJual;
}

/* Constructor */

/**
 * Buat kendaraan dengan parameter:
 * - kode
 * - jumlahKursi
 * - jumlahRoda
 * - kecepatan
 * - dimensi (panjang, lebar, tinggi)
 * - berat
 * - harga
 */
kendaraan buatKendaraan(char *kode, int jumlahKursi, int jumlahRoda, int kecepatan, dimensi d, int berat, int hargaJual){
    kendaraan k;
    strcpy(k.kode, kode);
    k.jumlahKursi = jumlahKursi;
    k.jumlahRoda = jumlahRoda;
    k.kecepatan = kecepatan;
    k.dim = d;
    k.berat = berat;
    k.hargaJual = hargaJual;
    return k;
}

/**
 * Kendaraan default
 * - kode = "XXX"
 * - jumlahKursi = 4
 * - jumlahRoda = 4
 * - kecepatan = 10
 * - dim = 10x10x10
 * - berat = 100
 * - hargaJual = 100000
 *
 * Notes: Anda harus menggunakan fungsi buatKendaraan untuk membuat kendaraan
 */
void buatKendaraanDefault(kendaraan *k){
    dimensi d = {10, 10, 10};
    *k = buatKendaraan("XXX", 4, 4, 10, d, 100, 100000);
}

/**
 * Lakukan input detail kendaraan dari user dengan format:
 * <kode> <jumlahKursi> <jumlahRoda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <hargaJual>
 * Contoh: "XXX 4 4 10 10 10 10 1000 100000"
 *
 * Notes: Anda harus menggunakan fungsi buatKendaraan untuk membuat kendaraan
 */
void buatKendaraanInput(kendaraan *k){
    char kode[4];
    int kursi, roda, kecepatan, panjang, lebar, tinggi, berat, harga;
    scanf("%s %d %d %d %d %d %d %d %d", kode, &kursi, &roda, &kecepatan, &panjang, &lebar, &tinggi, &berat, &harga);
    dimensi d = {panjang, lebar, tinggi};
    *k = buatKendaraan(kode, kursi, roda, kecepatan, d, berat, harga);
}

/* Methods */

/**
 * Print detail kendaraan dengan format:
 * <kode> <jumlahKursi> <jumlahRoda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <hargaJual>
 * Contoh: "XXX 4 4 10 10 10 10 1000 100000"
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printDetailKendaraan(kendaraan k){
    printf("%s %d %d %d %d %d %d %d %d\n", k.kode, k.jumlahKursi, k.jumlahRoda, k.kecepatan, k.dim.panjang, k.dim.lebar, k.dim.tinggi, k.berat, k.hargaJual);
}

/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * jumlah roda <= 2 -> NimoRide
 * jumlah roda > 2 && jumlah roda <= 4 -> NimoCar
 * jumlah roda > 4 && jumlah roda <= 6 -> NimoTruck
 * jumlah roda > 6 -> NimoTanker
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanRoda(kendaraan k){
    int roda = getJumlahRoda(k);
    if(roda<=2){
        printf("NimoRide\n");
    } else if(roda<=4){
        printf("NimoCar\n");
    } else if(roda<=6){
        printf("NimoTruck\n");
    } else{
        printf("NimoTanker\n");
    }
}
/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * kecepatan <= 10 -> NimoSlow
 * kecepatan > 10 && kecepatan <= 20 -> NimoFast
 * kecepatan > 20 && kecepatan <= 30 -> NimoSuperFast
 * kecepatan > 30 -> NimoSpeedy
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanKecepatan(kendaraan k){
    int kecepatan = getKecepatan(k);
    if(kecepatan<=10){
        printf("NimoSlow\n");
    } else if(kecepatan<=20){
        printf("NimoFast\n");
    } else if(kecepatan<=30){
        printf("NimoSuperFast\n");
    } else{
        printf("NimoSpeedy\n");
    }
}
/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * berat <= 100 -> NimoLight
 * berat > 100 && berat <= 200 -> NimoMedium
 * berat > 200 && berat <= 300 -> NimoHeavy
 * berat > 300 -> NimoSuperHeavy
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanBerat(kendaraan k){
    int berat = getBerat(k);
    if (berat<=100) {
        printf("NimoLight\n");
    } else if (berat<=200) {
        printf("NimoMedium\n");
    } else if (berat<=300) {
        printf("NimoHeavy\n");
    } else {
        printf("NimoSuperHeavy\n");
    }
}

/**
 * Hitung harga kendaraan berdasarkan kriteria berikut:
 * harga 1 buah roda = 1000
 * harga 1 buah kursi = 10000
 * harga 1 cm panjang = 100
 * harga 1 cm lebar = 100
 * harga 1 cm tinggi = 100
 * harga 1 kg berat = 100
 *
 * apabila harga kendaraan yang dihitung lebih dari harga jual kendaraan,
 * maka tampilkan pesan "Nimons Rugi! Harga rakit mobil <kode> lebih mahal dari harga jual"
 *
 * apabila harga kendaraan yang dihitung kurang dari harga jual kendaraan,
 * maka tampilkan pesan "Nimons Kaya hehe! Harga rakit mobil <kode> lebih murah dari harga jual"
 *
 * apabila harga kendaraan yang dihitung sama dengan harga jual kendaraan,
 * maka tampilkan pesan "Nimons Pas! Harga rakit mobil <kode> sama dengan harga jual"
 */
void jualKendaraan(kendaraan *k){
    int biayaDim = (k->dim.panjang + k->dim.lebar + k->dim.tinggi) * 100;
    int biaya = (k->jumlahRoda*1000) + (k->jumlahKursi*10000) + biayaDim + (k->berat*100);
    if(biaya>k->hargaJual){
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", k->kode);
    } else if(biaya<k->hargaJual){
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", k->kode);
    } else{
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", k->kode);
    }
}

/**
 * Faktor penentu kemenangan dalam balap ini adalah:
 * - Kecepatan memiliki bobot 10
 * - Berat memiliki bobot -2
 * - Lebar memiliki bobot -1
 *
 * Tampilkan pesan "Nimons Balap! Kendaraan <kode> menang! dengan skor <skor>"
 *
 * Apabila kedua kendaraan memiliki skor yang sama,
 * tampilkan pesan "Nimons Balap! Kedua kendaraan <kode1> dan <kode2> seri! dengan skor <skor>"
 *
 * Notes: Skor dihitung dengan menjumlahkan faktor penentu kemenangan * bobot nya
 * contoh:
 * - Kecepatan = 20, bobot = 10 -> 20 * 10 = 200
 * - Berat = 1000, bobot = -2 -> 100 * -2 = -200
 * - Lebar = 10, bobot = -1 -> 10 * -1 = -10
 *
 * Skor = 200 - 200 - 10 = -10
 */
void pBalap(kendaraan *k1, kendaraan *k2){
    int skor1 = k1->kecepatan*10 - k1->berat*2 - k1->dim.lebar*1;
    int skor2 = k2->kecepatan*10 - k2->berat*2 - k2->dim.lebar*1;
    if(skor1 == skor2){
        printf("Nimons Balap! Kedua kendaraan %s dan %s seri! dengan skor %d\n", k1->kode, k2->kode, skor1);
    } else if(skor1>skor2){
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", k1->kode, skor1);
    } else if(skor2>skor1){
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", k2->kode, skor2);
    }
}

// // #endif

