#include <stdio.h>
int main(){
    long kode, digit, temp;
    scanf("%ld", &kode);
    long sum=0;
    do{
        temp=kode;
        sum=0;
        while(temp>0){
            digit=temp%10;
            sum+=digit;
            temp=temp/10;
        }
        kode=sum;
    } while(sum>=10);
    printf("%ld\n", sum);
    return 0;
}