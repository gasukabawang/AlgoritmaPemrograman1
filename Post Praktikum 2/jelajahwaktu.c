#include <stdio.h>
#include <string.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;

/**
 * @brief Fungsi untuk mengecek apakah tahun adalah tahun kabisat.
 *
 * Tahun kabisat adalah tahun yang:
 * Jika tahun habis dibagi 100, maka tahun tersebut harus juga habis dibagi 400,
 * Jika tahun tidak habis dibagi 100, maka tahun harus habis habis dibagi 4
 *
 * @param year Tahun yang akan dicek.
 * @return int Mengembalikan 1 jika tahun adalah tahun kabisat, 0 jika bukan.
 */
int isLeapYear(int year) {
    if((year%100 == 0 && year%400 == 0) || (year%100 != 0 && year%4 == 0)){
        return 1;
    }
    return 0;
}

/**
 * @brief Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu.
 *
 * @param month Bulan yang akan dicek.
 * @param year Tahun yang akan dicek.
 * @return int Jumlah hari dalam bulan tersebut.
 */
int getDaysInMonth(int month, int year) {
    int daysInMonth[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(year) && month == 2){
        return 29;
    }
    return daysInMonth[month - 1];
}

/**
 * @brief Fungsi untuk menghitung jumlah hari sejak 1 Januari tahun 1.
 *
 * @param date Tanggal yang akan dihitung.
 * @return int Jumlah hari sejak 1 Januari tahun 1.
 */
int daysSinceBeginning(Date date) {
    int totalDays = 0;
    for(int year=1; year<date.year; year++){
        totalDays+=365;
        if(isLeapYear(year)){
            totalDays+=1;
        }
    }
    for(int month=1; month<date.month; month++){
        totalDays+=getDaysInMonth(month, date.year);
    }
    totalDays+=date.day;
    return totalDays;
}

/**
 * @brief Fungsi untuk menambahkan n hari ke tanggal.
 *
 * @param date Tanggal awal.
 * @param n Jumlah hari yang akan ditambahkan.
 * @return Date Tanggal baru setelah menambahkan n hari.
 */
Date addDays(Date date, int n) {
    while(n>0){
        int daysCurrentMonth = getDaysInMonth(date.month, date.year);
        if(date.day+n > daysCurrentMonth){
            n -= (daysCurrentMonth - date.day + 1);
            date.day = 1;
            date.month++;
            if(date.month>12){
                date.month = 1;
                date.year++;
            }
        } else{
            date.day += n;
            break;
        }
    }
    return date;
}

/**
 * @brief Fungsi untuk mendapatkan indeks hari dalam seminggu.
 *
 * @param date Tanggal yang akan dicek.
 * @return int Indeks hari dalam seminggu (0 = Minggu, 1 = Senin, ..., 6 =
 * Sabtu).
 * Keterangan: 1 Januari tahun 1 adalah Senin (index 1)
 */
int getDayOfWeekAsIndex(Date date) {
    int totalDays=daysSinceBeginning(date);
    int Indeks=(totalDays)%7;
    return Indeks;
}

/* FUNGSI - FUNGSI DI BAWAH INI TIDAK PERLU DIUBAH*/

static const char *months[] = {"Januari",   "Februari", "Maret",    "April",
                               "Mei",       "Juni",     "Juli",     "Agustus",
                               "September", "Oktober",  "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis",  "Jumat", "Sabtu"};

/**
 * @brief Fungsi untuk mendapatkan nama hari dari tanggal tertentu.
 *
 * @param date Tanggal yang akan dicek.
 * @return const char* Nama hari dalam bahasa Indonesia.
 */
const char *getDayOfWeek(Date date) {
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}

/**
 * @brief Fungsi untuk mencetak tanggal dalam format yang diinginkan.
 *
 * @param date Struktur Date yang akan dicetak.
 */
void printDate(Date date) {
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}

/**
 * @brief Fungsi untuk mengonversi string bulan ke angka.
 *
 * @param monthStr String nama bulan yang akan dikonversi.
 * @return int Angka bulan yang sesuai, atau -1 jika bulan tidak valid.
 */
int getMonthNumber(const char *monthStr) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Bulan tidak valid
}

/**
 * @brief Fungsi untuk mengonversi string tanggal ke struct Date.
 *
 * @param dateStr String tanggal yang akan dikonversi.
 * @return Date Struktur Date yang sesuai dengan string tanggal.
 */
Date parseDate(const char *dateStr) {
    Date date;
    char monthStr[10];
    sscanf(dateStr, "%d %s %d", &date.day, monthStr, &date.year);
    date.month = getMonthNumber(monthStr);

    if (date.month == -1) {
        printf("Bulan tidak valid!\n");
    }
    return date;
}

/**
 * @brief Fungsi utama untuk menjalankan program.
 *
 * Program ini membaca tanggal dan jumlah hari dari input, menambahkan jumlah
 * hari ke tanggal, dan mencetak tanggal baru.
 *
 * @return int Status keluar dari program.
 */
int main() {
    char inputDate[30];
    int n;

    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;
    scanf("%d", &n);

    Date date;
    date = parseDate(inputDate);

    date = addDays(date, n);
    printDate(date);

    return 0;
}