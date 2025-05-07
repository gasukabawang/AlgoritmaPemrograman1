#include <stdio.h>
int TotalVirus(int N, int T, int X){
    // int virus[N];
    // int total;
    // virus[0]=N;
    // virus[1]=N+(N*X);
    // if(N<1 || N>1000 || X<1 || X>10){
    //     total=0;
    //     X=0;
    // } else{
    //     for(int i=2; i<T+1; i++){
    //         virus[i]=virus[i-1]+((virus[i-1]-virus[i-2])*X);
    //     }
    //     total=virus[T];
    // }
    int total = N;
    for(int i=1; i<= T; i++){
        total = (total*X)+N;
    }
    return total;
}

int main(){
    int N, T, X, totalvirus;
    scanf("%d\n", &N);
    scanf("%d\n", &T);
    scanf("%d", &X);
    if (N==0 ){
        printf("Terdapat %d Virus Nimons Gila pada jam ke-%d", 0, T);
    }
    else if(T==0){
        printf("Terdapat %d Virus Nimons Gila pada jam ke-%d", totalvirus = N, T);
        
    }
    else if (!((N<1 || N>1000) &&( X<1 || X>10))){

        totalvirus=TotalVirus(N, T, X);
        printf("Terdapat %d Virus Nimons Gila pada jam ke-%d", totalvirus, T);
    }
    printf("\n");
    return 0;
}