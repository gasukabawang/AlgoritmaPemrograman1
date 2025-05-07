// #ifndef MAP_H
// #define MAP_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

// Definisi struktur untuk setiap pasangan key-value dalam Map
// typedef struct {
//     int key;     // Key (integer)
//     char *value; // Nilai (string)
// } MapEntry;

// // Definisi struktur untuk ADT Map
// typedef struct {
//     MapEntry *entries; // Array dinamis dari MapEntry
//     int capacity;      // Kapasitas maksimum array
//     int size;          // Jumlah elemen yang saat ini ada di Map
// } Map;

/**
 * @brief Membuat dan menginisialisasi Map baru.
 *
 * @param capacity Kapasitas maksimum Map. Asumsikan bahwa nilai capacity selalu
 * > 0.
 * @return Pointer ke objek Map yang baru dibuat, atau NULL jika alokasi gagal
 * atau kapasitas tidak valid.
 */
Map *create_map(int capacity){
    if(capacity>0){
        Map *map = (Map *) malloc(sizeof(Map));
        if(!map){
            return NULL;
        }
        map->entries = (MapEntry *) malloc(capacity*sizeof(MapEntry));
        if(!map->entries){
            return NULL;
        }
        map->capacity = capacity;
        map->size = 0;
        return map;
    }
    return NULL;
}

/**
 * @brief Menyisipkan pasangan key-value baru ke dalam Map, atau memperbarui
 * value jika key sudah ada.
 * Keterangan:
 * 1. String yang dijadikan value harus dialokasikan ulang agar kepemilikan
 * string tersebut berpindah ke map.
 * 2. Key harus terurut di dalam map entries
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang akan disisipkan atau diperbarui.
 * @param value Nilai yang akan diasosiasikan dengan kunci.
 * @return true jika berhasil (penyisipan atau pembaruan), false jika Map penuh
 * atau input tidak valid.
 */
bool map_insert(Map *map, int key, const char *value){
    // if(map && value){
    //     for(int i=0; i<map->size; i++){
    //         if(map->entries[i].key == key){
    //             free(map->entries[i].value);
    //             map->entries[i].value = strdup(value);
    //             return true;
    //         }
    //     }
    // }
    // if(map->size<map->capacity){
    //     map->entries[map->size].key = key;
    //     map->entries[map->size].value = strdup(value);
    //     if(!map->entries[map->size].value){
    //         return false;
    //     }
    //     map->size++;
    //     return true;
    // }
    if(!map || !value){                             //validasi map dan value dulu
        return false;           
    }
    int l = 0;                                      //batas kiri binary search
    int r = map->size - 1;                          //batas kanan binary search
    while(l <= r){
        int m = (l+r) / 2;                          //mulai dari indeks tengah
        if(map->entries[m].key == key){             //diisi buat update value lama dgn value baru
            free(map->entries[m].value);
            map->entries[m].value = strdup(value);
            return map->entries[m].value != NULL;
        } else if(map->entries[m].key < key){
            l = m + 1;
        } else{
            r = m - 1;
        }                                           //kl blm nemu, l disini itu berakhir di posisi terurut
    }
    if(map->size >= map->capacity){
        return false;
    }
    for(int i = map->size; i>l; i--){
        map->entries[i] = map->entries[i-1];
    }
    map->entries[l].key = key;                      //disini tinggal insert langsung karena sudh diurutkan
    map->entries[l].value = strdup(value);          //diisi kl di list blm ada value tsb
    if(!map->entries[l].value){
        return false;
    }
    map->size++;
    return true;
}

/**
 * @brief Mengambil value yang terikat dengan key tertentu.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari key yang sesuai
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang nilainya akan diambil.
 * @return nilai jika kunci ditemukan, atau NULL jika kunci
 * tidak ditemukan atau input tidak valid.
 */
char *map_get(const Map *map, int key){
    // if(map){
    //     for(int i=0; i<map->size; i++){
    //         if(map->entries[i].key == key){
    //             return map->entries[i].value;
    //         }
    //     }
    // }
    // return NULL;
    if(map){
        int l=0, r=map->size-1;
        while(l <= r){
            int m = (l+r) / 2;
            if(map->entries[m].key == key){
                return map->entries[m].value;
            } else if(map->entries[m].key < key){
                l = m+1;
            } else{
                r = m-1;
            }
        }
    }
    return NULL;
}

/**
 * @brief Menghapus pasangan key-value dari Map berdasarkan key.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari entry yang akan dihapus
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci elemen yang akan dihapus.
 * @return true jika berhasil dihapus, false jika kunci tidak ditemukan atau
 * input tidak valid.
 */
bool map_delete(Map *map, int key){
    // for(int i=0; i<map->size; i++){
    //     if(map->entries[i].key == key){
    //         free(map->entries[i].value);
    //         for(int j=i; j<map->size; j++){
    //             map->entries[j] = map->entries[i+1];
    //         }
    //         map->size--;
    //         return true;
    //     }
    // }
    // return false;
    if(map){
        int l=0, r=map->size-1;
        while (l <= r){
            int m = (l+r) / 2;
            if(map->entries[m].key == key){
                free(map->entries[m].value);
                for(int i=m; i<map->size-1; i++){
                    map->entries[i] = map->entries[i+1];
                }
                map->size--;
                return true;
            } else if(map->entries[m].key < key){
                l = m+1;
            } else{
                r = m-1;
            }
        }
    }
    return false;
}

/**
 * @brief Mendapatkan jumlah elemen (pasangan key-value) dalam Map.
 *
 * @param map Pointer ke objek Map.
 * @return Jumlah elemen dalam Map .
 */
int map_size(const Map *map){
    if(map){
        return map->size;
    } else{
        return 0;
    }
}

/**
 * @brief Memeriksa apakah kunci tertentu ada di dalam Map.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari key yang sesuai
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang akan diperiksa keberadaannya.
 * @return true jika kunci ada, false jika kunci tidak ada.
 */
bool map_contains_key(const Map *map, int key){
    // for(int i=0; i<map->size; i++){
    //     if(map->entries[i].key == key){
    //         return true;
    //     }
    // }
    // return false;
    if(map){
        int l=0, r=map->size-1;
        while(l <= r){
            int m = (l+r) / 2;
            if(map->entries[m].key == key){
                return true;
            } else if(map->entries[m].key < key){
                l = m+1;
            } else{
                r = m-1;
            }
        }
    }
    return false;
}

// #endif // MAP_H

// int main() { 
//     Map *map = create_map(5);
//     char *nimons[] = {"Kebin", "Stuart", "Dave", "Pop", "Larry", "Mel"};
//     for (int i = 0; i <= 5; i++) {
//         if (!map_insert(map, i, nimons[i])) {
//             printf("Terjadi error ketika memasukkan %s ke bilik %d\n", nimons[i], i);
//         }
//     }
//     for (int i = 0; i <= 5; i++) {
//         const char *nimon = map_get(map, i);
//         if (nimon != NULL) {
//             printf("Bilik ke-%d diisi oleh %s\n", i, nimon);
//         } else {
//             printf("Terjadi error ketika melakukan pengecekan ke bilik %d\n", i);
//         }
//     }
//     if (map_delete(map, 1)) {
//         printf("Bilik ke-1 berhasil dikosongkan\n");
//     }
//     // Mencoba melakukan delete ke key yang sudah dihapus
//     if (!map_delete(map, 1)) {
//         printf("Terjadi error ketika ingin melakukan pengosongan bilik ke 1\n");
//     }
//     printf("Ukuran map saat ini %d\n", map_size(map));
//     return 0;
// }