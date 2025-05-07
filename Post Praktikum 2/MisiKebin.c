#include <stdio.h>
void countPrime(int A, int B, int *total){
    int prime;
    *total = 0;
    for(int i=A; i<=B; i++){
        prime = 1;
        if(i<2){
            prime=0;
        } else{
            for(int j=2; j*j <= i; j++){
                if(i%j == 0){
                    prime = 0;
                    break;
                }
            }
        }
        if(prime){
            (*total)++;
        }
    }
}

int main(){
    int A, B, total;
    scanf("%d %d", &A, &B);

    countPrime(A, B, &total);

    printf("%d\n", total);
    return 0;
}