// #include <stdio.h>

// int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
//     int total;
//     total=(jumlah_anak*10000)+(jumlah_dewasa*20000)+(jumlah_lansia*15000);
//     return total;
// }

// void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
//     int total=HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
//     printf("Tiket berhasil dibeli!\n");
//     printf("Rincian:\n");
//     printf("- Jumlah anak-anak: %d\n", jumlah_anak);
//     printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
//     printf("- Jumlah lansia: %d\n", jumlah_lansia);
//     printf("- Total biaya: %d\n", total);
// }

// void SelamatDatang(int input_1){
//     int jumlah_anak, jumlah_dewasa, jumlah_lansia;
//     jumlah_anak=input_1%10;
//     jumlah_dewasa=(input_1/10)%10;
//     jumlah_lansia=input_1/100;
//     printf("----------------------------------------\n");
//     printf("Selamat datang di Wahana Mandi Bola!\n");
//     printf("\nSilakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n");
//     printf("\nHarga tiket:\n");
//     printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
//     printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
//     printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n");
//     printf("\nJumlah anak: %d\n", jumlah_anak);
//     printf("Jumlah dewasa: %d\n", jumlah_dewasa);
//     printf("Jumlah lansia: %d\n", jumlah_lansia);
//     PrintTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
// }

// void HandleNimonsHunting(long input_2){
//     long harga, jumlah_harta_karun, jumlah_lubang, jumlah_pergerakan;
//     long jumlah_lubang_ditutup, total_harta_karun, total_langkah, total_harga_harta_karun, total_biaya_ganti_rugi, total_keuntungan;

//     jumlah_pergerakan=input_2 % 10;
//     jumlah_lubang= (input_2/10)%10;
//     jumlah_harta_karun=(input_2/100)%10;

//     printf("----------------------------------------\n");
//     printf("Selamat datang di Treasure Hunting Nimons!\n");
//     printf("\nJumlah pergerakan Nimons di dalam kolam: %ld\n", jumlah_pergerakan);
//     printf("Jumlah lubang yang ada di kolam: %ld\n", jumlah_lubang);
//     printf("Jumlah harta karun yang ada di kolam: %ld\n", jumlah_harta_karun);
    
//     total_langkah=0;
//     total_harta_karun=0;
//     jumlah_lubang_ditutup=0;
//     for(int i=1; i<=jumlah_pergerakan; i++){
//         printf("Langkah ke-%d\n", i);
//         // langkah=(input/(long)(pow(10, (3*i))))%10;
//         // act1=(input/(long)(pow(10, (2+(3*i)))))%10;
//         // act2=(input/(long)(pow(10, (3+(3*i)))))%10;
//         long long langkah=input_2/1000;
//         input_2=langkah;
//         if(langkah%10 > 0){
//             printf("Nimons bergerak sejauh %ld langkah\n", langkah%10);
//             total_langkah+=langkah;
//         } else if(langkah%10 == 0){
//             printf("Nimons tidak bergerak\n");
//         }
//         if((langkah/10)%10 == 1){
//             printf("Nimons menemukan harta karun!\n");
//             total_harta_karun++;
//         } if((langkah/100)%10 == 1){
//             printf("Nimons menutup lubang!\n");
//             jumlah_lubang_ditutup++;
//         }
//     }

//     harga=input_2/1000;
//     printf("\nTotal lubang yang ditutup: %ld dari %d lubang\n", jumlah_lubang_ditutup, jumlah_lubang);
//     printf("Total harta karun yang ditemukan: %ld\n", total_harta_karun);
    
//     total_harga_harta_karun=total_harta_karun*harga*5;
//     printf("Total harga harta karun yang ditemukan: %ld\n",total_harga_harta_karun);
//     printf("Total langkah yang ditempuh: %ld\n", total_langkah);
    
//     total_biaya_ganti_rugi=harga*jumlah_lubang_ditutup;
//     printf("Total biaya ganti rugi Pak Gro: %ld\n", total_biaya_ganti_rugi);
    
//     total_keuntungan=total_harga_harta_karun-total_biaya_ganti_rugi;
//     printf("Total keuntungan Nimons dan Pak Gro: %ld\n", total_keuntungan);

// }


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

void HandleNimonsHunting(long input_2){
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    long pergerakan, lubang, hartaKarun;
    long temp = input_2;
    pergerakan = temp % 10; 
    temp /= 10;
    lubang = temp % 10; 
    temp /= 10;
    hartaKarun = temp % 10; 
    temp /= 10;
    printf("Jumlah pergerakan Nimons di dalam kolam: %ld\n", pergerakan);
    printf("Jumlah lubang yang ada di kolam: %ld\n", lubang);
    printf("Jumlah harta karun yang ada di kolam: %ld\n", hartaKarun);

    long langkah = 0, found = 0, cover = 0, cek;

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
            printf("Nimons bergerak sejauh %ld langkah\n", cek);
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
    printf("Total lubang yang ditutup: %ld dari %ld lubang\n", cover, lubang);
    printf("Total harta karun yang ditemukan: %ld\n", found);
    printf("Total harga harta karun yang ditemukan: %ld\n", temp*found*5);
    printf("Total langkah yang ditempuh: %ld\n", langkah);
    printf("Total biaya ganti rugi Pak Gro: %ld\n", temp*cover);
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n", ((found*5)-cover)*temp);
}