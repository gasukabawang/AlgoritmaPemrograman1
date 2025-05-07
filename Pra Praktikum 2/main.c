#include <stdio.h>
int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int sum = 10000*jumlah_anak+20000*jumlah_dewasa+15000*jumlah_lansia;
    return sum;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
}

void SelamatDatang(int input_1){
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    int anak = input_1 % 10; 
    input_1 /= 10;
    int dewasa = input_1 % 10; 
    input_1 /= 10;
    int lansia = input_1 % 10;
    printf("Jumlah anak: %d\n",anak);
    printf("Jumlah dewasa: %d\n",dewasa);
    printf("Jumlah lansia: %d\n",lansia);
    PrintTiket(anak,dewasa,lansia);
}

void HandleNimonsHunting(long long input_2){
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    long long pergerakan, lubang, hartaKarun;
    long long temp = input_2;
    pergerakan = temp % 10; 
    temp /= 10;
    lubang = temp % 10; 
    temp /= 10;
    hartaKarun = temp % 10; 
    temp /= 10;
    printf("Jumlah pergerakan Nimons di dalam kolam: %lld\n", pergerakan);
    printf("Jumlah lubang yang ada di kolam: %lld\n", lubang);
    printf("Jumlah harta karun yang ada di kolam: %lld\n", hartaKarun);

    long long langkah = 0, found = 0, cover = 0, cek;

    for(int i = 1; i <= pergerakan; i++) {
    	printf("Langkah ke-%d\n", i);
        cek = temp % 10;
      
        if(cek == 0) {
            printf("Nimons tidak bergerak\n");
            temp /= 10;
            if((temp % 10) == 1) {
                found++; 
                printf("Nimons menemukan harta karun!\n");
            } 
            temp /= 10;
            if((temp % 10) == 1) {
                cover++; 
                printf("Nimons menutup lubang!\n");
            }
            temp /= 10;
        } else {
            langkah += temp % 10; 
            printf("Nimons bergerak sejauh %lld langkah\n", cek);
            temp /= 10;
            if((temp % 10) == 1) {
                found++; 
                printf("Nimons menemukan harta karun!\n");
            } 
            temp /= 10;
            if((temp % 10) == 1) {
                cover++; 
                printf("Nimons menutup lubang!\n");
            }
            temp /= 10;
        }
    }
    printf("\n");
    printf("Total lubang yang ditutup: %lld dri %lld lubang\n", cover, lubang);
    printf("Total harta karun yang ditemukan: %lld\n", found);
    printf("Total harga harta karun yang ditemukan: %lld\n", temp*found*5);
    printf("Total langkah yang ditempuh: %lld\n", langkah);
    printf("Total biaya ganti rugi Pak Gro: %lld\n", temp*cover);
    printf("Total keuntungan Nimons dan Pak Gro: %lld\n", ((found*5)-cover)*temp);
}

#include <stdio.h>

int main() {
    int input_1;
    long long input_2;
    scanf("%d", &input_1);
    scanf("%lld", &input_2);
    SelamatDatang(input_1);
    HandleNimonsHunting(input_2);
    return 0;
}