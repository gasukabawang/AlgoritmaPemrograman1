#include <stdio.h>
int main(){
    int a, b, luas;
    scanf("%d %d", &a, &b);
    for(int i=1; i<=b; i++){
        luas=a+(9*i);
        printf("tahun ke-%d = %d\n", i, luas);
    }
    return 0;
}