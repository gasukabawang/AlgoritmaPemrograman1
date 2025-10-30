// #ifndef CIRCULAR_LINKED_LIST_H
// #define CIRCULAR_LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

// typedef struct Node {
//     int data;
//     struct Node *next;
// } Node;

/**
 * @brief Membuat node baru.
 *
 * @param data Nilai integer yang akan disimpan dalam node baru.
 * @return Node* Pointer ke node yang baru dibuat.
 * NULL jika alokasi memori gagal.
 */
Node *createNode(int data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = newNode;
    }
    return newNode;
}

/**
 * @brief Mengecek apakah circular linked list kosong.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @return int 1 jika list kosong, 0 jika tidak.
 */
int isEmpty(Node *last){
    return last == NULL;
}

/**
 * @brief Menambahkan node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika list awalnya kosong atau saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtBeginning(Node **last, int data){
    if(*last == NULL){
        *last = createNode(data);
        return (*last != NULL);
    } else{
        Node *newNode = createNode(data);
        if(newNode == NULL){
            return false;
        }
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        return true;
    }
}

/**
 * @brief Menambahkan node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtEnd(Node **last, int data){
    if(*last == NULL){
        *last = createNode(data);
        return (*last != NULL);
    } else{
        Node *newNode = createNode(data);
        if(newNode == NULL){
            return false;
        }
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
        return true;
    }
}

/**
 * @brief Menambahkan node setelah node dengan nilai tertentu.
 * Jika ada beberapa node dengan nilai 'searchValue', node baru akan
 * dimasukkan setelah kemunculan pertama.
 * Jika 'searchValue' tidak ditemukan, node tidak ditambahkan.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai data dari node yang dicari untuk penyisipan
 * setelahnya.
 * @param data Nilai integer yang akan ditambahkan pada node baru.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAfter(Node **last, int searchValue, int data){
    if(*last == NULL){
        return false;
    }
    Node *current = (*last)->next;
    do{
        if(current->data == searchValue){
            Node *newNode = createNode(data);
            if(newNode == NULL){
                return false;
            }
            newNode->next = current->next;
            current->next = newNode;
            if(current == *last){
                *last = newNode;
            }
            return true;
        }
        current = current->next;
    } while(current != (*last)->next);
    return false;
}

/**
 * @brief Menghapus node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi.
 */
void deleteFromBeginning(Node **last){
    if(*last == NULL){
        return;
    }
    if((*last)->next == *last){
        free(*last);
        *last = NULL;
    } else{
        Node *temp = (*last)->next;
        (*last)->next = temp->next;
        free(temp);
    }
}

/**
 * @brief Menghapus node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list
 *
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list kosong setelah penghapusan.
 *
 * Keterangan:
 */
void deleteFromEnd(Node **last){
    if(*last == NULL){
        return;
    }
    if((*last)->next == *last){
        free(*last);
        *last = NULL;
    } else{
        Node *current = (*last)->next;
        while(current->next != *last){
            current = current->next;
        }
        current->next = (*last)->next;
        free(*last);
        *last = current;
    }
}

/**
 * @brief Menghapus node dengan nilai tertentu dari circular linked list.
 * Jika ada beberapa node dengan nilai 'dataToDelete', hanya kemunculan
 * pertama yang akan dihapus.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika node yang dihapus adalah node terakhir atau
 * satu-satunya node.
 * @param dataToDelete Nilai integer dari node yang akan dihapus.
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list menjadi kosong atau jika dataToDelete tidak ditemukan.
 */
void deleteNodeWithValue(Node **last, int dataToDelete){
    if(*last == NULL){
        return;
    }
    if((*last)->next == *last && (*last)->data == dataToDelete){
        free(*last);
        *last = NULL;
        return;
    }
    Node *current = (*last)->next;
    Node *prev = *last;
    do{
        if(current->data == dataToDelete){
            prev->next = current->next;
            if(current == *last){
                *last = prev;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while(current != (*last)->next);
}

/**
 * @brief Mencari sebuah nilai dalam circular linked list.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai integer yang akan dicari.
 * @return Node* Pointer ke node yang mengandung searchValue jika ditemukan.
 * NULL jika searchValue tidak ditemukan dalam list atau list kosong.
 */
Node *searchNode(Node *last, int searchValue){
    if(last == NULL){
        return NULL;
    }
    Node *current = last->next;
    do{
        if(current->data == searchValue){
            return current;
        }
        current = current->next;
    } while(current != last->next);
    return NULL;
}

/**
 * @brief Menampilkan semua elemen dalam circular linked list.
 * Dimulai dari node setelah node 'last' (yang secara efektif adalah awal list).
 *
 * @param last Pointer ke node terakhir dalam list.
 *
 * Keterangan:
 * 1. Jika list kosong maka keluarkan "KOSONG"
 * 2. Contoh keluaran: 1 -> 2 -> 3
 * 3. Akhiri keluaran dengan newline
 */
void displayList(Node *last){
    if(last == NULL){
        printf("KOSONG\n");
        return;
    }
    Node *current = last->next;
    do{
        printf("%d", current->data);
        current = current->next;
        if(current != last->next){
            printf(" -> ");
        }
    } while(current != last->next);
    printf("\n");
}

/**
 * @brief Menghapus semua node dalam circular linked list dan membebaskan
 * memorinya.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan diatur menjadi NULL setelah semua node dihapus.
 */
void deleteAllNodes(Node **last){
    if(*last == NULL){
        return;
    }
    Node *current = (*last)->next;
    Node *nextNode;
    do{
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while(current != (*last)->next);
    *last = NULL;
}

// #endif