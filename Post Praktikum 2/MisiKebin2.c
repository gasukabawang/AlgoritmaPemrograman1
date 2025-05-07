#include <stdio.h>

int isPrime(int num){
    if(num<=1){
        return 0;
    }
    if(num == 2 || num == 3){
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= num; i += 6){
        if (num % i == 0 || num % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

int countDigit(int num){
    int total = 0;
    while (num > 0) {
        total += num % 10; 
        num = num/10;
    }
    return total;
}

int toBingro(int num){
    if (num == 0){
        return 0;
    }
    int hasil = 0;
    while (num > 0) {
        hasil = hasil * 10 + (num % 2); 
        num = num/2;
    }
    return hasil;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    
    if (1 <= A && A <= B && B <= 10000){
        int hitung = 0;
        for (int angka = A; angka <= B; angka++){
            if (isPrime(angka)) {
                int digit = countDigit(angka);
                if (isPrime(digit)) {
                    hitung++;
                }
            }
        }
        int hasil_bingro = toBingro(hitung);
        printf("%d\n", hasil_bingro);
    } else {
        printf("Input tidak valid\n");
    }
    return 0;
}