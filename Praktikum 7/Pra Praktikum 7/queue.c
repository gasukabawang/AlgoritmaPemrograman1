// #ifndef QUEUE_H
// #define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// #define MAX_SIZE 10
// #define SENTINEL -1

// struct Queue {
//     int items[MAX_SIZE]; // Array untuk menyimpan elemen integer
//     int count;           // Jumlah elemen yang ada di array saat ini
// };

/*
 * Fungsi untuk menginisialisasi queue.
 * Mengatur count ke 0.
 * Parameter:
 * - q: Pointer ke struct Queue yang akan diinisialisasi.
 */
void initQueue(struct Queue *q){
    q->count = 0;
}

/*
 * Fungsi untuk mengecek apakah queue kosong.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - true jika queue kosong (count == 0), false jika tidak.
 */
bool isEmpty(struct Queue *q){
    return q->count == 0;
}

/*
 * Fungsi untuk mengecek apakah queue penuh.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - true jika queue penuh (count == MAX_SIZE - 1), false jika tidak.
 */
bool isFull(struct Queue *q){
    return q->count == MAX_SIZE;
}

/*
 * Fungsi untuk menambahkan elemen ke belakang (enqueue) queue.
 * Prekondisi: Queue belum penuh. Periksa isFull()
 * sebelum memanggil fungsi ini untuk menghindari overflow. Parameter:
 * - q: Pointer ke struct Queue.
 * - value: Nilai integer yang akan ditambahkan.
 * Postkondisi: Elemen ditambahkan ke queue jika tidak penuh.
 * Catatan: Jika queue kosong sebelum penambahan keluarkan pesan "Queue penuh!".
 */
void enqueue(struct Queue *q, int value){
    if(isFull(q)){
        printf("Queue penuh!\n");
        return;
    }
    q->items[q->count] = value;
    q->count++;
}

/*
 * Fungsi untuk mengambil elemen dari depan (dequeue) queue.
 * Jika queue kosong, fungsi ini akan mencetak pesan error
 * dan mengembalikan nilai SENTINEL. Karena bukan circular queue, maka array
 * perlu di geser ke depan untuk mengisi ruang yang kosong setelah dequeue
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Nilai elemen integer yang diambil dari depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue kosong!\n");
        return SENTINEL;
    }
    int front = q->items[0];
    for(int i=1; i<q->count; i++){
        q->items[i-1] = q->items[i];
    }
    q->count--;
    return front;
}

/*
 * Fungsi untuk melihat elemen di depan queue tanpa menghapusnya (peek).
 * Prekondisi: Queue tidak kosong. Periksa isEmpty()
 * sebelum memanggil fungsi ini.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Nilai elemen integer yang berada di depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int front(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue kosong!\n");
        return SENTINEL;
    }
    return q->items[0];
}

/*
 * Fungsi untuk mendapatkan jumlah elemen saat ini dalam queue.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Jumlah elemen integer dalam queue saat ini (nilai count).
 */
int size(struct Queue *q){
    return q->count;
}

// #endif // QUEUE_H

// int main() {
//     struct Queue myQueue;

//     printf("--- Memulai Pengujian Queue ---\n");

//     printf("\n1. Inisialisasi queue...\n");
//     initQueue(&myQueue);
//     printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
//     printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
//     printf("Ukuran queue: %d\n", size(&myQueue));

//     printf("\n2. Menambahkan elemen (enqueue)...\n");
//     enqueue(&myQueue, 10);
//     printf("Enqueue 10. Ukuran: %d\n", size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     enqueue(&myQueue, 20);
//     printf("Enqueue 20. Ukuran: %d\n", size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     enqueue(&myQueue, 30);
//     printf("Enqueue 30. Ukuran: %d\n", size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
//     printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");

//     printf("\n3. Mengambil elemen (dequeue)...\n");
//     int item = dequeue(&myQueue);
//     printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     item = dequeue(&myQueue);
//     printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     item = dequeue(&myQueue);
//     printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));

//     printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
//     printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
//     printf("Ukuran queue: %d\n", size(&myQueue));

//     printf("\n4. Mencoba dequeue dari queue kosong...\n");
//     item = dequeue(&myQueue);
//     printf("Hasil dequeue: %d\n", item);

//     printf("\n5. Menambahkan elemen hingga penuh (MAX_SIZE = %d)...\n",
//            MAX_SIZE);
//     for (int i = 0; i < MAX_SIZE; i++) {
//         if (!isFull(&myQueue)) {
//             enqueue(&myQueue, (i + 1) * 100);
//             printf("Enqueue %d. Ukuran: %d\n", (i + 1) * 100, size(&myQueue));
//         } else {
//             printf("Gagal enqueue %d, queue penuh.\n", (i + 1) * 100);
//         }
//     }

//     printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
//     printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
//     printf("Ukuran queue: %d\n", size(&myQueue));
//     printf("Elemen depan: %d\n", front(&myQueue));

//     printf("\n6. Mencoba enqueue ke queue penuh...\n");
//     enqueue(&myQueue, 999);
//     printf("Ukuran queue setelah mencoba enqueue ke penuh: %d\n",
//            size(&myQueue));

//     printf("\n7. Mengosongkan queue...\n");
//     while (!isEmpty(&myQueue)) {
//         item = dequeue(&myQueue);
//         printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
//     }

//     printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
//     printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
//     printf("Ukuran queue: %d\n", size(&myQueue));

//     printf("\n8. Mencoba front dari queue kosong\n");
//     item = front(&myQueue);
//     printf("Hasil front: %d\n", item);

//     printf("\n--- Pengujian Queue Selesai ---\n");

//     return 0;
// }