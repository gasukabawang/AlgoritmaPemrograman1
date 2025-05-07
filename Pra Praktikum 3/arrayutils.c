#include <stdio.h>

void sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int find(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

double calculateAverage(int arr[], int n){
    double sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum/n;
}

int findMedian(int arr[], int n){
    sort(arr, n);
    if(n%2 == 0){
        int median=arr[(n/2)-1]+arr[n/2];
        return median/2;
    } else{
        return arr[n/2];
    }
}

int findMode(int arr[], int n){
    int max=0;
    int mode=arr[0];
    for(int i=0; i<n; i++){
        int count=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>max){
            max=count;
            mode=arr[i];
        }
    }
    return mode;
}

int findMax(int arr[], int n){
    int max=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n){
    int min=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

void reverseArray(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
}