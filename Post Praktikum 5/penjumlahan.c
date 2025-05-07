#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1005

// typedef struct {
//     int *data;     // Array untuk menyimpan elemen list
//     int ukuran;    // Jumlah elemen saat ini dalam list
//     int kapasitas; // Kapasitas maksimum list
// } ListStatik;

// /**
//  * @brief Menginisialisasi list statik.
//  */
// void inisialisasiList(ListStatik *list, int capacity){
//     list->data = (int *) malloc(sizeof(int) * capacity);
//     list->ukuran = 0;
//     list->kapasitas = capacity;
// }

// /**
//  * @brief Menambahkan sebuah nilai ke akhir list statik.
//  */
// bool tambahElemen(ListStatik *list, int nilai){
//     if(list->ukuran >= list->kapasitas){
//         return false;
//     }
//     list->data[list->ukuran] = nilai;
//     list->ukuran++;
//     return true;
// }

// /**
//  * @brief Menghapus elemen terakhir dari list statik.
//  */
// bool hapusElemenAkhir(ListStatik *list){
//     if(list->ukuran > 0){
//         list->ukuran--;
//         return true;
//     }
//     return false;
// }

// /**
//  * @brief Menampilkan semua elemen yang ada di dalam list statik.
//  */
// void tampilkanList(ListStatik list){
//     if(list.ukuran > 0){
//         for(int i=0; i<list.ukuran; i++){
//             printf("%d", list.data[i]);
//         }
//         printf("\n");
//     } else{
//         printf("List kosong\n");
//     }
// }

// /**
//  * @brief Mencari apakah suatu nilai terdapat di dalam list statik.
//  */
// int cariElemen(ListStatik list, int nilai){
//     for(int i=0; i<list.ukuran; i++){
//         if(list.data[i] == nilai){
//             return i;
//         }
//     }
//     return -1;
// }

// /**
//  * @brief Mengubah nilai elemen pada indeks tertentu dalam list statik.
//  */
// bool ubahElemen(ListStatik *list, int indeks, int nilaiBaru){
//     if(indeks >= 0 && indeks < list->ukuran){
//         list->data[indeks] = nilaiBaru;
//         return true;
//     }
//     return false;
// }

void reverse(char *str){
    int length = strlen(str);
    for(int i=0; i<length/2; i++){
        int temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
}

int compare(char *a, char *b) {
    int la = strlen(a), lb = strlen(b);
    if (la != lb){
        return la > lb ? 1 : -1;
    }
    return strcmp(a, b);
}

void addition(char *num1, char *num2, char *result){
    char n1[MAX], n2[MAX];
    strcpy(n1, num1);
    strcpy(n2, num2);
    reverse(n1);
    reverse(n2);
    
    int length1 = strlen(n1);
    int length2 = strlen(n2);
    int maxlength = (length1>length2)? length1 : length2;

    int sum, sisa = 0;
    int i;
    for(i=0; i<maxlength; i++){
        int digit1 = (i<length1)? n1[i] - '0' : 0;      //ubah char dig jadi int dig (pake ascii)
        int digit2 = (i<length2)? n2[i] - '0' : 0;      //tinggal - '0'
        sum = digit1 + digit2 + sisa;
        result[i] = (sum%10) + '0';
        sisa = sum/10;
    }
    if(sisa){
        result[i++] = sisa + '0';
    }
    result[i] = '\0';
    reverse(result);
}

void subtract(char *a, char *b, char *res) {
    char x[MAX], y[MAX];
    strcpy(x, a);
    strcpy(y, b);
    reverse(x);
    reverse(y);
    int lx = strlen(x);
    int ly = strlen(y);
    int borrow = 0, k = 0;
    for (int i = 0; i < lx; i++) {
        int d1 = x[i] - '0';
        int d2 = (i < ly) ? y[i] - '0' : 0;
        int sub = d1 - d2 - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res[k++] = sub + '0';
    }
    while (k > 1 && res[k - 1] == '0') {
        k--;
    }
    res[k] = '\0';
    reverse(res);
}

int main(){
    char A[MAX], B[MAX], num1[MAX], num2[MAX], result[MAX];

    scanf("%s", A);
    scanf("%s", B);

    bool negA = (A[0] == '-');
    bool negB = (B[0] == '-');
    strcpy(num1, negA ? A+1 : A);
    strcpy(num2, negB ? B+1 : B);

    if (!negA && !negB) {
        // A + B
        addition(num1, num2, result);
        printf("%s\n", result);
    } else if (negA && negB) {
        // -A + -B = -(A + B)
        addition(num1, num2, result);
        printf("-%s\n", result);
    } else if (negA && !negB) {
        // -A + B = B - A
        int cmp = compare(num2, num1);
        if (cmp == 0) {
            printf("0\n");
        } else if (cmp > 0) {
            subtract(num2, num1, result); // B > A → positif
            printf("%s\n", result);
        } else {
            subtract(num1, num2, result); // A > B → negatif
            printf("-%s\n", result);
        }
    } else {
        // A + (-B) = A - B
        int cmp = compare(num1, num2);
        if (cmp == 0) {
            printf("0\n");
        } else if (cmp > 0) {
            subtract(num1, num2, result); // A > B → positif
            printf("%s\n", result);
        } else {
            subtract(num2, num1, result); // B > A → negatif
            printf("-%s\n", result);
        }
    }

    return 0;
}

// int main(){
//     // char m[MAX], n[MAX], result[MAX+1];
//     // scanf("%s %s", m, n);
//     // addition(m, n, result);
//     // printf("%s\n", result);
//     int m, n;
//     char A[MAX], B[MAX], num1[MAX], num2[MAX], result[MAX];

//     scanf("%d %d", &m, &n);
//     scanf("%s", A);
//     scanf("%s", B);

//     bool negA = (A[0] == '-');
//     bool negB = (B[0] == '-');
//     strcpy(num1, negA ? A+1 : A);
//     strcpy(num2, negB ? B+1 : B);

//     if (negA == negB) {
//         addition(num1, num2, result);
//         if (negA){
//             printf("-");
//         }
//         printf("%s\n", result);
//     } else {
//         int cmp = compare(num1, num2);
//         if (cmp == 0) {
//             printf("0\n");
//         } else if (cmp > 0) {
//             subtract(num1, num2, result);
//             if (negA){
//                 printf("-");
//             }
//             printf("%s\n", result);
//         } else {
//             subtract(num2, num1, result);
//             if (negB){
//                 printf("-");
//             }
//             printf("%s\n", result);
//         }
//     }
//     return 0;
// }