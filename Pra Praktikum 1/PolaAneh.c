#include <stdio.h>
int main(){
    int N, i, j;
    int condition;
    scanf("%d", &N);
    int mid =N/2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            condition=(i-mid)+(j-mid);
            if(condition<0){
                condition*=-1;
            }
            if(condition == mid ){
                printf("*");
            } else if(i>=mid && j==i-mid || i<mid && j==i+mid){
                printf("*");
            } else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}