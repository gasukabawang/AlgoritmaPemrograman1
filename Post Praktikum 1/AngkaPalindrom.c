#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    int temp=N;
    int reverse=0;
    while(temp>0){
        int remainder;
        remainder=temp%10;
        reverse=(reverse*10)+remainder;
        temp=temp/10;
    }
    if (reverse == N){
        printf("1\n");
    } else{
        printf("0\n");
    }
    return 0;
}