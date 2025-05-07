#include <stdio.h>
int main(){
    int A, B, i;
    int maks=1;
    scanf("%d", &A);
    scanf("%d", &B);
    for(int i=1; i<=A && i<=B; i++){
        if(A%i == 0 && B%i == 0){
            maks = i;
        }
    }
    printf("%d\n", maks);
    return 0;
}