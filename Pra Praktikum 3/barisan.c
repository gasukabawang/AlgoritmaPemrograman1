#include <stdio.h>
int FPB(int a, int b){
    while(b!=0){                //jadi intinya bandingin antara dua bilangan dulu
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int KPK(int a, int b){
    return (a/FPB(a, b))*b;
}

void cari(int A[], int N, int *hasilFPB, int *hasilKPK){
    *hasilFPB = A[0];
    *hasilKPK = A[0];
    for(int i=1; i<N; i++){                 //lanjut bandingin per 2 bilangan
        *hasilFPB=FPB(*hasilFPB, A[i]);
        *hasilKPK=KPK(*hasilKPK, A[i]);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    if(N==0){
        printf("0\n");
        return 0;
    }
    int A[N];
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    int M=0;
    int hasilFPB, hasilKPK;
    cari(A, N, &hasilFPB, &hasilKPK);           //oke ini paham intiny kan FPB*KPK
    M=hasilFPB*hasilKPK;

    for(int i=0; i<N; i++){
        int tempFPB = 0;                        //GOBLINNN INI APA MAKSUD UDH KAGA NGERTI SETERUSNYA
        int tempKPK = 1;                        //tp tetep aja ga ngerti logikanya :)
        for(int j=0; j<N; j++){
            if(j!=i){
                if (tempFPB == 0) {
                    tempFPB = A[j];
                } else {
                    tempFPB = FPB(tempFPB, A[j]);
                }
                tempKPK = KPK(tempKPK, A[j]);
            }
        }
        int tempM = tempFPB*tempKPK;               //bagian ini paham udh
        if(tempM > M){
            M = tempM;
        }
    }
    printf("%d\n", M);
    return 0;
}