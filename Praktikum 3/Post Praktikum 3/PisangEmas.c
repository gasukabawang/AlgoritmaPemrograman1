#include <stdio.h>

void reverse(int arr[], int start, int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void pisangemas(int berat[], int target, int n){
    int posisi;
    for(int i=0; i<n; i++){
        if(berat[i]==target){
            posisi=i;
            break;
        }
    }
    if(posisi==0){
        berat[posisi]=berat[posisi+1];
    } else if(posisi==n-1){
        berat[posisi]=berat[posisi-1];
    } else{
        berat[posisi]=berat[posisi+1]+berat[posisi-1];
    }
    reverse(berat, posisi+1, n-1);
}

int main(){
    int n, target;
    scanf("%d %d", &n, &target);
    int berat[n];
    for(int i=0; i<n; i++){
        scanf("%d", &berat[i]);
    }
    reverse(berat, 0, n-1);
    pisangemas(berat, target, n);
    for(int i=0; i<n; i++){
        printf("%d", berat[i]);
        if(i<n-1){
            printf(" ");
        }
    } printf("\n");
    return 0;
}