#include <stdio.h>

int main() {
    long N;
    scanf("%ld", &N); 
    long count = 0;
    long factor = 5;
    while (N / factor > 0) {
        count += N / factor; 
        factor *= 5; 
    }
    printf("%ld\n", count); 
    return 0;
}