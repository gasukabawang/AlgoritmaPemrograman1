// /* MODUL LIST NIMONS STATIK */
// /* Berisi definisi dan semua primitif pemrosesan list statik untuk menyimpan data Nimons */
// /* Penempatan elemen selalu rapat kiri */
// /* Banyaknya elemen didefinisikan secara implisit, memori list statik */

// // #ifndef LISTNIMONS_H
// // #define LISTNIMONS_H

// #include "listnimons.h"
// #include <string.h>
// #include <stdio.h>

// // /*  Kamus Umum */
// // #define NIMONS_CAPACITY 100
// // #define IDX_MIN 0
// // #define IDX_UNDEF -1

// /* Definisi elemen dan koleksi objek */
// // typedef struct
// // {
// //     char name[21]; // nama Nimons, maksimal 20 karakter
// //     int age;       // umur Nimons
// //     int height;    // tinggi badan dalam cm
// // } Nimons;

// // typedef struct
// // {
// //     Nimons contents[NIMONS_CAPACITY];
// // } ListNimons;

// // /* Definisi Nimons kosong: name adalah string kosong ("") atau age = -1 */

// // /* ********** SELEKTOR ********** */
// // #define ELMT_NIMONS(l, i) (l).contents[(i)]

// /* ********** KONSTRUKTOR ********** */
// void CreateListNimons(ListNimons *l){
//     for(int i=0; i<NIMONS_CAPACITY; i++){
//         ELMT_NIMONS(*l, i).name[0] = '\0';
//         ELMT_NIMONS(*l, i).age = -1;
//         ELMT_NIMONS(*l, i).height = 0;
//     }
// }
// /* I.S. l sembarang */
// /* F.S. Terbentuk ListNimons l kosong dengan semua elemen memiliki name kosong dan age = -1 */

// /* ********** SELEKTOR TAMBAHAN ********** */
// int listNimonsLength(ListNimons l){
//     int nEff = 0;
//     while(nEff<NIMONS_CAPACITY && ELMT_NIMONS(l, nEff).age != -1){
//         nEff++;
//     }
//     return nEff;
// }
// /* Mengirimkan banyaknya elemen efektif ListNimons */
// /* Mengirimkan nol jika List kosong */

// boolean isIdxValidNimons(ListNimons l, int i){
//     return (i>=IDX_MIN && i<NIMONS_CAPACITY);
// }
// /* Mengirimkan true jika i adalah indeks yang valid untuk kapasitas list */

// boolean isIdxEffNimons(ListNimons l, int i){
//     return (i>=IDX_MIN && i<listNimonsLength(l));
// }
// /* Mengirimkan true jika i adalah indeks yang terdefinisi dalam list (0..length-1) */

// boolean isNimonsEmpty(ListNimons l){
//     return (listNimonsLength(l) == 0);
// }
// /* Mengirimkan true jika ListNimons kosong */

// boolean isNimonsFull(ListNimons l){
//     return (listNimonsLength(l) == NIMONS_CAPACITY);
// }
// /* Mengirimkan true jika ListNimons penuh */

// /* ********** BACA dan TULIS ********** */
// void readNimonsList(ListNimons *l){
//     int n;
//     // printf("Masukkan banyak Nimons: ");
//     scanf("%d", &n);
//     if(n>NIMONS_CAPACITY){
//         n=NIMONS_CAPACITY;
//     }
//     for(int i=0; i<n; i++){
//         Nimons m;
//         // printf("Nimons %d (nama, umur, tinggi): ", i);
//         scanf("%s %d %d", m.name, &m.age, &m.height);
//         ELMT_NIMONS(*l, i) = m;
//     }
// }
// /* I.S. l sembarang */
// /* F.S. ListNimons l berisi n data Nimons hasil pembacaan dari user */
// /* Format: nama umur tinggi, misalnya: Bob 8 100 */

// void printNimonsList(ListNimons l){
//     printf("[");
//     for(int i=0; i<listNimonsLength(l); i++){
//         printf("%s-%d-%d", ELMT_NIMONS(l, i).name, ELMT_NIMONS(l, i).age, ELMT_NIMONS(l, i).height);
//         if(i<listNimonsLength(l)-1){
//             printf(", ");
//         }
//     }
//     printf("]\n");
// }
// /* Proses : Menuliskan isi ListNimons dalam format:
//    [name1-age1-height1, name2-age2-height2, ..., nameN-ageN-heightN] */

// /* ********** MENAMBAH dan MENGHAPUS ********** */
// void insertNimonsLast(ListNimons *l, Nimons m){
//     if(listNimonsLength(*l)<NIMONS_CAPACITY){
//         ELMT_NIMONS(*l, listNimonsLength(*l)) = m;
//     }
// }
// /* Menambahkan Nimons m sebagai elemen terakhir */

// void deleteNimonsLast(ListNimons *l, Nimons *m){
//     int length = listNimonsLength(*l);
//     if(length > 0){
//         *m = ELMT_NIMONS(*l, length-1);
//         ELMT_NIMONS(*l, length-1).name[0] = '\0';
//         ELMT_NIMONS(*l, length-1).age = -1;
//         ELMT_NIMONS(*l, length-1).height = 0;
//     }
// }
// /* Menghapus elemen terakhir list dan menyimpan ke *m */

// /* ********** SEARCHING ********** */
// int indexOfNimons(ListNimons l, char *name){
//     for(int i=0; i<listNimonsLength(l); i++){
//         if(strcmp(ELMT_NIMONS(l, i).name, name) == 0){
//             return i;
//         }
//     }
//     return IDX_UNDEF;
// }
// /* Mencari nama Nimons dalam list.
//    Mengembalikan indeks pertama yang cocok, atau IDX_UNDEF jika tidak ditemukan */

// /* ********** NILAI EKSTREM ********** */
// void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest){
//     if(listNimonsLength(l) == 0){
//         return;
//     }
//     *tallest = *shortest = ELMT_NIMONS(l, 0);
//     for(int i=1; i<listNimonsLength(l); i++){
//         if(ELMT_NIMONS(l, i).height > tallest->height){
//             *tallest = ELMT_NIMONS(l, i);
//         }
//         if(ELMT_NIMONS(l, i).height < shortest->height){
//             *shortest = ELMT_NIMONS(l, i);
//         }
//     }
// }
// /* Menentukan Nimons dengan tinggi tertinggi dan terendah dari list */

// // #endif

#include <stdio.h>
#include <string.h>
#include "listnimons.h"

void CreateListNimons(ListNimons *l) {
    int i;
    for (i = 0; i < NIMONS_CAPACITY; i++) {
        l->contents[i].name[0] = '\0'; 
        l->contents[i].age = -1;       
        l->contents[i].height = 0;
    }
}

int listNimonsLength(ListNimons l) {
    int count = 0;
    while (count < NIMONS_CAPACITY && l.contents[count].age != -1) {
        count++;
    }
    return count;
}

boolean isIdxValidNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < NIMONS_CAPACITY);
}

boolean isIdxEffNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < listNimonsLength(l));
}

boolean isNimonsEmpty(ListNimons l) {
    return listNimonsLength(l) == 0;
}

boolean isNimonsFull(ListNimons l) {
    return listNimonsLength(l) == NIMONS_CAPACITY;
}

void readNimonsList(ListNimons *l) {
    int n;
    scanf("%d", &n);
    getchar(); 
    CreateListNimons(l);
    for (int i = 0; i < n; i++) {
        Nimons m;
        scanf("%s %d %d", m.name, &m.age, &m.height);
        ELMT_NIMONS(*l, i) = m;
    }
}

void printNimonsList(ListNimons l) {
    int len = listNimonsLength(l);
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%s-%d-%d", l.contents[i].name, l.contents[i].age, l.contents[i].height);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
}

void insertNimonsLast(ListNimons *l, Nimons m) {
    int len = listNimonsLength(*l);
    if (len < NIMONS_CAPACITY) {
        ELMT_NIMONS(*l, len) = m;
    }
}

void deleteNimonsLast(ListNimons *l, Nimons *m) {
    int len = listNimonsLength(*l);
    if (len > 0) {
        *m = ELMT_NIMONS(*l, len - 1);
        l->contents[len - 1].name[0] = '\0';
        l->contents[len - 1].age = -1;
        l->contents[len - 1].height = 0;
    }
}

int indexOfNimons(ListNimons l, char *name) {
    for (int i = 0; i < listNimonsLength(l); i++) {
        if (strcmp(l.contents[i].name, name) == 0) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest) {
    int len = listNimonsLength(l);
    if (len == 0) return;
    
    *tallest = l.contents[0];
    *shortest = l.contents[0];
    
    for (int i = 1; i < len; i++) {
        if (l.contents[i].height > tallest->height) {
            *tallest = l.contents[i];
        }
        if (l.contents[i].height < shortest->height) {
            *shortest = l.contents[i];
        }
    }
}