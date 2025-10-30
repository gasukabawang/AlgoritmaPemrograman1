// #include <stdio.h>

// int findWinningPosition(int n, int i, int k){
//     // i--;
//     // int nimons[n];
//     // for(int a=0; a<n; a++){
//     //     nimons[a]=a+1;
//     // }
//     // int sisaposisi=0;
//     // for(int j=1; j<=n; j++){
//     //     sisaposisi=(sisaposisi+k)%j;
//     // }
//     // int akhir=(sisaposisi+i)%n+1;
//     int winner=0;
//     for(int j=1; j<=n; j++){
//         winner=(winner+k)%j;
//     }
//     int eliminated_minion_position=(winner+i)%n;
//     if(eliminated_minion_position == 0){
//         eliminated_minion_position=n;
//     }
//     return eliminated_minion_position;
// }

// int main(){
//     int n, i, k;
//     scanf("%d %d %d", &n, &i, &k);
//     printf("%d\n", findWinningPosition(n, i, k));
//     return 0;
// }

#include <stdio.h>

#define MAX_N 1000

int findWinningPosition(int n, int i, int k) {
    int nimons[MAX_N];
    for(int j=0; j<n; j++){
        nimons[j] = j+1;
    }

    int sisa = n;
    int pos = i - 1;

    
    while(sisa>1){
        pos=(pos+k)%sisa;
        for(int j=pos; j<sisa-1; j++){
            nimons[j]=nimons[j+1];
        }
        sisa--;
    }

    int final_pos=nimons[0];
    return final_pos;
}

int main() {
    int n, i, k;
    scanf("%d %d %d", &n, &i, &k);
    
    int eliminated_minion_position = findWinningPosition(n, i, k);
    printf("%d\n", eliminated_minion_position);
    
    return 0;
}
