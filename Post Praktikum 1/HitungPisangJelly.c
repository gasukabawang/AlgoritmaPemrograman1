#include <stdio.h>
int main(){
    int N, X;
    int pisang=0, jelly=0;
    int stop = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &X);
        if(X == 0){
            stop=1;
        }
        if(stop==1){
            continue;
        }
        if(X>0 && X%2 == 0){
            pisang+=X;
        } else if(X>0 && X%2 != 0){
            jelly+=X;
        }
    }
    printf("%d %d\n", pisang, jelly);
    return 0;
}