#include <stdio.h>

int kategori(int hari, int *mentah, int *matang, int *terlalu){
    if(hari >= 0 && hari <=2){
        printf("Kategori: Mentah\n");
        (*mentah)++;
    } else if(hari >= 3 && hari <= 5){
        printf("Kategori: Matang\n");
        (*matang)++;
    } else if(hari > 5){
        printf("Kategori: Terlalu matang\n");
        (*terlalu)++;
    }
}

int main(){
    int N, pilihan, hari;
    int mentah=0, matang=0, terlalu=0;
    scanf("%d", &N);
    while(mentah+matang+terlalu < N){
        scanf("%d", &pilihan);
        if(pilihan == 1){
            scanf("%d", &hari);
            kategori(hari, &mentah, &matang, &terlalu);
        } else if(pilihan == 2){
            printf("Laporan Kematangan Pisang\n");
            printf("Mentah: %d\n", mentah);
            printf("Matang: %d\n", matang);
            printf("Terlalu matang: %d\n", terlalu);
        } else{
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }
    printf("Program selesai\n");
    return 0;
}