#include <stdio.h>

void rotate(int arr[], int n, int k){
    for(int j=0; j<k; j++){
        int temp=arr[n - 1];                //elemen terakhir ditaro di temp
        for(int a=(n - 2); a>=0; a--){      //mulai dari elemen kedua akhir
            arr[a+1]=arr[a];                //current element dipindah ke kanan 1
        }
        arr[0]=temp;
    }
}

int main(){
    int n, jumlahrot;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &jumlahrot);
    int K[jumlahrot];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<jumlahrot; i++){
        scanf("%d", &K[i]);
    }

    int original[n];
    for(int i=0; i<n; i++){
        original[i]=arr[i];
    }

    for(int i=0; i<jumlahrot; i++){
        rotate(arr, n, K[i]);
        printf("[");
        for(int j=0; j<n; j++){
            printf("%d", arr[j]);
            if(j<n-1){
                printf(", ");
            }
        }
        printf("]\n");

        for(int j=0; j<n; j++){
            arr[j]=original[j];
        }
    }
    return 0;
}