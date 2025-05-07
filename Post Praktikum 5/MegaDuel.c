// NIM    : 18224075
// Nama   : Sherry Eunike
// Tanggal: 30 April 2025

// #ifndef MEGA_DUEL_H
// #define MEGA_DUEL_H

#include <stdio.h>
#include <string.h>
#include "MegaNimons.h"

// #define CAPACITY 100
// #define IDX_UNDEF -1

// typedef int IdxType;

// typedef struct {
//     int id;
//     char name[30];
//     float powerLevel;
//     char mutationType[20];
//     boolean isStable;
// } MegaNimons;

// typedef struct {
//     MegaNimons contents[CAPACITY];
//     int nEff;
// } LabTrack;

// void createLabTrack(LabTrack *L) {
//     L->nEff = 0;
// }

// int length(LabTrack L) {
//     return L.nEff;
// }

// int maxCapacity() {
//     return CAPACITY;
// }

// IdxType firstIdx(LabTrack L) {
//     return 0;
// }

// IdxType lastIdx(LabTrack L) {
//     return L.nEff - 1;
// }

// MegaNimons getElmt(LabTrack L, IdxType i) {
//     return L.contents[i];
// }

// void setElmt(LabTrack *L, IdxType i, MegaNimons val) {
//     (*L).contents[i] = val;
// }

// void setLength(LabTrack *L, int N) {
//     (*L).nEff = N;
// }

// boolean isIdxValid(IdxType i) {
//     return (i >= 0 && i < CAPACITY);
// }

// boolean isIdxEff(LabTrack L, IdxType i) {
//     return (i >= 0 && i < L.nEff);
// }

// boolean isEmpty(LabTrack L) {
//     return L.nEff == 0;
// }

// boolean isFull(LabTrack L) {
//     return L.nEff == CAPACITY;
// }

// void insertAt(LabTrack *L, MegaNimons m, IdxType idx) {
//     for (int i = (*L).nEff; i > idx; i--) {
//         (*L).contents[i] = (*L).contents[i - 1];
//     }
//     (*L).contents[idx] = m;
//     (*L).nEff++;
// }

// void insertFirst(LabTrack *L, MegaNimons m) {
//     insertAt(L, m, 0);
// }

// void insertLast(LabTrack *L, MegaNimons m) {
//     insertAt(L, m, (*L).nEff);
// }

// void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m) {
//     *m = (*L).contents[idx];
//     for (int i = idx; i < (*L).nEff - 1; i++) {
//         (*L).contents[i] = (*L).contents[i + 1];
//     }
//     (*L).nEff--;
// }

// void deleteFirst(LabTrack *L, MegaNimons *m) {
//     deleteAt(L, 0, m);
// }

// void deleteLast(LabTrack *L, MegaNimons *m) {
//     deleteAt(L, (*L).nEff - 1, m);
// }

// IdxType indexOf(LabTrack L, int id) {
//     for (int i = 0; i < L.nEff; i++) {
//         if (L.contents[i].id == id) {
//             return i;
//         }
//     }
//     return IDX_UNDEF;
// }

// void printLabTrack(LabTrack L) {
//     for (int i = 0; i < L.nEff; i++) {
//         printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n",
//                i,
//                L.contents[i].id,
//                L.contents[i].name,
//                L.contents[i].powerLevel,
//                L.contents[i].mutationType,
//                L.contents[i].isStable ? "Yes" : "No");
//     }
// }

// boolean isPowerEqual(MegaNimons m1, MegaNimons m2) {
//     return fabs(m1.powerLevel - m2.powerLevel) < 1e-6;
// }

// boolean isMoreStable(MegaNimons m1, MegaNimons m2) {
//     return (m1.isStable && !m2.isStable);
// }

// MegaNimons resolveDuel(MegaNimons m1, MegaNimons m2) {
//     MegaNimons winner;
//     if(m1.powerLevel > m2.powerLevel){
//         winner = m1;
//     } else if(m2.powerLevel > m1.powerLevel){
//         winner = m2;
//     } else{
//         if(isMoreStable(m1, m2)){
//             winner = m1;
//         } else if(!isMoreStable(m1, m2)){
//             winner = m2;
//         } else{
//             if(m1.id < m2.id){
//                 winner = m1;
//             } else{
//                 winner = m2;
//             }
//         }
//     }
//     return winner;
// }

// void duelOnce(MegaNimons m1, MegaNimons m2) {
//     printf("Duel: %s (%.1f) vs %s (%.1f)\n", m1.name, m1.powerLevel, m2.name, m2.powerLevel);
//     MegaNimons winner = resolveDuel(m1, m2);
//     printf("Winner: %s\n", winner.name);
// }

/**
 * Anda boleh menambahkan fungsi/prosedur tambahan jika diperlukan
 */

/**
 * Menjalankan turnamen pertarungan antar MegaNimons dalam LabTrack.
 * Pertarungan dilakukan secara berpasangan dari ujung list:
 *   - MegaNimons pertama vs terakhir
 *   - Pemenang tetap, yang kalah dieliminasi dari list
 *   - Proses berlanjut dengan MegaNimons berikutnya di sisi yang masih hidup
 *   - Berlangsung hingga hanya tersisa satu MegaNimons sebagai pemenang
 *
 * Aturan penentuan pemenang diatur oleh fungsi resolveDuel.
 *
 * I.S. LabTrack L berisi ≥ 1 MegaNimons
 * F.S. Semua MegaNimons tersingkir kecuali satu pemenang.
 *      Ditampilkan log setiap duel dan pemenang akhir.
 *
 * Contoh:
 *
 * Input List (nEff = 3):
 *   0: Kevzilla (800.0)
 *   1: Bobzilla (850.0)
 *   2: Melatron (780.0)
 *
 * Output:
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Melatron (780.0)
 *   Winner: Kevzilla
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Bobzilla (850.0)
 *   Winner: Bobzilla
 *   <endline>
 *   == The Champion: Bobzilla ==
 */
void runMegaDuel(LabTrack *L){
    while(L->nEff>1){
        printf("\n== DUEL ROUND ==\n");
        MegaNimons left = getElmt(*L, firstIdx(*L));
        MegaNimons right = getElmt(*L, lastIdx(*L));
        duelOnce(left, right);

        MegaNimons result = resolveDuel(left, right);
        if(result.id == left.id){
            deleteLast(L, &right);
        } else{
            deleteFirst(L, &left);
        }
    }
    MegaNimons champ = getElmt(*L, 0);
    printf("\n== The Champion: %s ==\n", champ.name);
}

// #endif