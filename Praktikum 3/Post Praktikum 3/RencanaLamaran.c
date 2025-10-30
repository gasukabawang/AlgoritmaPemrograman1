#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WAKTU 20000

int timeToInt(const char *times){
    int hour=(times[0]-'0')*10 + (times[1]-'0');
    int minute=(times[3]-'0')*10 + (times[4]-'0');
    return hour*60+minute;
}

int palindrom(int n){
    int reversed=0;
    int original=n;

    while(n>0){
        reversed=reversed*10+(n%10);
        n/=10;
    }
    return original == reversed;
}

void bubbleSort(char times[][6], int N){
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(times[j], times[j + 1]) > 0) {
                char temp[6];
                strcpy(temp, times[j]);
                strcpy(times[j], times[j+1]);
                strcpy(times[j + 1], temp);
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);

    char times[MAX_WAKTU][6];
    for(int i=0; i<N; i++){
        scanf("%s", times[i]);
    }
    bubbleSort(times, N);
    int found=0;
    printf("[");
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if (strcmp(times[i], times[j]) != 0) { // Pastikan waktu tidak sama
                int start = timeToInt(times[i]);
                int end = timeToInt(times[j]);
                if (start < end) {
                    int duration = end - start;
                    if (palindrom(duration)) {
                        if (found > 0) {
                            printf(", ");
                        }
                        printf("[(%s - %s), %d menit]", times[i], times[j], duration);
                        found++;
                    }
                }
            }
        }
    }
    printf("]\n");

    if (found == 0) {
        printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.\n");
    }
            // for(int a=0; a<i; a++){
            //     for(int b=a+1; b<N; b++){
            //         int x=timeMinute[a];
            //         int y=timeMinute[b];
            //         int s=a<b? a : b;
            //         int e=a>b? a : b;
            //         if(s == start && e == end){
            //             found=1;
            //             break;
            //         }
            //     }
            //     if(found){
            //         break;
            //     }
            // }
            // printf("[");
            // if(!found && palindrom(duration)){
    //         if(duration>=0 && palindrom(duration)){
    //             if(muncul){
    //                 printf(", ");
    //             }
    //             printf("[(%0.2d:%0.2d - %0.2d:%0.2d), %d menit]", start/60, start%60, end/60, end%60, duration);
    //             muncul =1;
    //         }
    //     }
    // }
    // if(!muncul){
    //     printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.]\n");
    // } else{
    //     printf("]\n");
    // }
    return 0;
}