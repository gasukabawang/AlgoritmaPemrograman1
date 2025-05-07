#include <stdio.h>
#include <math.h>

int length(int angka) {
    if (angka == 0){
        return -1;
    }
    int count = 0;
    while (angka > 0) {
        angka = angka/10;
        count++;
    }
    return count;
}

int getDigit(int angka, int index) {
    int panjang = length(angka);
    if (index < 0 || index >= panjang){
        return -1;
    }
    int digit=(angka/(int) pow(10, index))%10;
    return digit;
}

int removeDigit(int angka, int index) {
    int panjang = length(angka);
    if (index < 0 || index >= panjang){
        return angka;
    }
    int left = angka / (int) pow(10, index+1);
    int right = angka % (int) pow(10, index);
    return left * (int) pow(10, index) + right;
}

void cariKombinasi(int angka, int current, int panjangAwal) {
    if (length(current) == panjangAwal) {
        printf("%d\n", current);
        return;
    }

    for (int i = 0; i < length(angka); i++) {
        int newangka=removeDigit(angka, i);
        int newcurrent=current*10 + getDigit(angka, i);
        cariKombinasi(newangka, newcurrent, panjangAwal);
    }
}

void NimonBruteforce(int angka) {
    cariKombinasi(angka, 0, length(angka));
}

// int main(){
//     int input;
//     scanf("%d", &input);
//     NimonBruteforce(input);
//     return 0;
// }