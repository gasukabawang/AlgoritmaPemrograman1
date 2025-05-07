// NIM     : 18224075
// NAMA    : Sherry Eunike
// Tanggal : 2 Mei 2025

// #ifndef ALBUM_H
// #define ALBUM_H

#include <stdio.h>
#include <stdlib.h>  // untuk qsort
#include <string.h>  // untuk strcmp dan strcpy
// #include "boolean.h"
#include "album.h"

// #define Nil 0
// #define MaxElSong 300         // Maksimum jumlah lagu dalam satu album
// #define MaxStringLength 50    // Maksimum panjang judul lagu
// #define boolean unsigned char
// #define true 1
// #define false 0

// typedef struct
// {
//     char Songs[MaxElSong][MaxStringLength];   // Songs[i] menyimpan judul lagu
//     int Count;                                // Banyaknya lagu dalam album
// } Album;

/* Definisi Album A kosong : A.Count = Nil */
/* A.Count = jumlah element Album */
/* A.Songs = tempat penyimpanan element Album */

/* ********* Prototype ********* */

/* ********* Konstruktor/Kreator ********* */
void CreateEmptyAlbum(Album *A){
    A->Count = 0;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Album A kosong berkapasitas MaxElSong */
/* Ciri Album kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan Album ********* */
boolean IsEmptyAlbum(Album A){
    return A.Count == Nil;
}
/* Mengirim true jika Album A kosong*/
/* Ciri Album kosong : count bernilai Nil */

boolean IsFullAlbum(Album A){
    return A.Count >= MaxElSong;
}
/* Mengirim true jika Album A penuh */
/* Ciri Album penuh : count bernilai MaxElSong */

/* ********** Operator Dasar Album ********* */
boolean IsSongInAlbum(Album A, char SongTitle[]){
    for(int i=0; i<A.Count; i++){
        if(strcmp(A.Songs[i], SongTitle) == 0){
            return true;
        }
    }
    return false;
}
/* Mengembalikan true jika SongTitle sudah ada di dalam album A. Anda bisa memanfaatkan fungsi strcmp.
   strcmp bernilai 0 apabila dua string sama. */

/* ********* Comparator untuk qsort ********* */
int cmpstr(const void *a, const void *b){
    const char *sa = (const char *)a;
    const char *sb = (const char *)b;
    return strcmp(sa, sb);
}
/* Fungsi pembanding string untuk digunakan oleh qsort */
// const char *sa = (const char *)a;
// const char *sb = (const char *)b;
// return strcmp(sa, sb);

void SortAlbum(Album *A){
    qsort((*A).Songs, (*A).Count, sizeof(A->Songs[0]), cmpstr);
}
/* Mengurutkan Album secara leksikografis menggunakan qsort */
// qsort((*A).Songs, (*A).Count, sizeof((*A).Songs[0]), cmpstr);

void InsertSong(Album *A, char SongTitle[]){
    if(!IsFullAlbum(*A) && !IsSongInAlbum(*A, SongTitle)){
        strcpy(A->Songs[A->Count], SongTitle);
        A->Count++;
        SortAlbum(A);
    }
}
/* Menambahkan SongTitle sebagai elemen Album A. */
/* I.S. A mungkin kosong, A mungkin penuh
        A mungkin sudah beranggotakan SongTitle */
/* F.S. Jika A belum penuh, SongTitle menjadi anggota dari A. Bisa memanfaatkan fungsi strcpy.
        Jika SongTitle sudah merupakan anggota atau album sudah penuh, operasi tidak dilakukan
        Judul lagu dalam album akan tetap terurut secara alfabetik/leksikografis menggunakan SortAlbum() */

void DeleteSong(Album *A, char SongTitle[]){
    if(IsSongInAlbum(*A, SongTitle)){
        for(int i=0; i<A->Count; i++){
            if(strcmp(A->Songs[i], SongTitle) == 0){
                for(int j=i; j<A->Count; j++){
                    strcpy(A->Songs[j], A->Songs[j+1]);
                }
                A->Count--;
            }
            
        }
    }
}
/* Menghapus SongTitle dari Album A. */
/* I.S. A tidak kosong
        SongTitle mungkin anggota / bukan anggota dari A */
/* F.S. SongTitle bukan anggota dari A */
/* Bisa memanfaatkan strcmp dan strcpy */

/* ********* Operator Album Tambahan ********* */
Album UnionAlbum(Album A1, Album A2){
    Album new;
    CreateEmptyAlbum(&new);
    for(int i=0; i<A1.Count; i++){
        InsertSong(&new, A1.Songs[i]);
    }
    for(int i=0; i<A2.Count; i++){
        InsertSong(&new, A2.Songs[i]);
    }
    return new;
}
/* Menghasilkan Album baru yang berisi gabungan lagu dari A1 dan A2 tanpa duplikat lagu */
/* Contoh: 
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 U A2
   newAlbum.Songs = ["abc", "def", "ghi"] */

Album IntersectionAlbum(Album A1, Album A2){
    Album new;
    CreateEmptyAlbum(&new);
    for(int i=0; i<A1.Count; i++){
        if(IsSongInAlbum(A2, A1.Songs[i])){
            InsertSong(&new, A1.Songs[i]);
        }
    }
    return new;
}
/* Menghasilkan Album baru yang berisi lagu-lagu yang terdapat di A1 dan A2 secara bersamaan */
/* Contoh:
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 ∩ A2
   newAlbum.Songs = ["def"] */

Album DifferenceAlbum(Album A1, Album A2){
    Album new;
    CreateEmptyAlbum(&new);
    for(int i=0; i<A1.Count; i++){
        if(!IsSongInAlbum(A2, A1.Songs[i])){
            InsertSong(&new, A1.Songs[i]);
        }
    }
    return new;
}
/* Menghasilkan Album berisi lagu-lagu yang terdapat di A1 tetapi tidak di A2 */
/* Contoh:
   A1.Songs = ["abc", "def"]
   A2.Songs = ["def", "ghi"]
   newAlbum = A1 - A2
   newAlbum.Songs = ["abc"] */

/* ********* Utility Function ********* */
void PrintAlbum(Album A){
    printf("{");
    if(!IsEmptyAlbum(A)){
        for(int i=0; i<A.Count; i++){
            printf("%s", A.Songs[i]);
            if(i<A.Count-1){
                printf(", ");
            }
        }
    }
    printf("}\n");
}
/* Menampilkan semua lagu dalam Album dalam format {lagu1, lagu2, lagu3} */
/* Jika Album kosong, menampilkan {} */
/* Tampilkan juga dalam urutan judul lagu yang terurut */

// #endif