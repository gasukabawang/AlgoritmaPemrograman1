#include <stdio.h>
int main(){
    int f2=0;
    int f1=1;
    int fn=0;
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        printf("%d", fn);
        if(i<N){
            printf(" ");
        }
        f2=f1;
        f1=fn;
        fn=f1+f2;
    }
    printf("\n");
    return 0;
}

// int N;
// scanf("%d", &N);
// int F[N];
// F[0]=0;
// if(N>1){
//     F[1]= 1;
// }
// for(int i=2; i<N; i++){
//     F[i]=F[i-2] + F[i-1];
// }
// for(int i=0; i<N; i++){
//     printf("%d", F[i], "\n");
// }

// int N, i, next;
// int fib1=0;
// int fib2=1;
// scanf("%d", &N);
// for (int i=0; i<N; i++){
//     if(i==0){
//         next=fib1;
//     } else if(i==1){
//         next=fib2;
//     } else{
//         next=fib1+fib2;
//         fib1=fib2;
//         fib2=next;
//     }
//     printf("%d\n", next);
// }