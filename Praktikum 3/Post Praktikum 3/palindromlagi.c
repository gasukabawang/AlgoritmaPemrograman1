#include <stdio.h>
#include <string.h>

int palindrom(char s[]){
    // int left=0;
    // int right=strlen(s)-1;
    // while(left<right){
    //     if(s[left]!=s[right]){
    //         return 0;
    //     }
    //     for(int start=0; start<=1001; start++){
    //         for(int end=1001; end>=0; end--){
    //             if(s[start]==s[end]){
    //                 return 1;
    //             }
    //         }
    //     }
    //     left++;
    //     right--;
    // }
    // return 1;
    int freq[256] = {0};
    int oddCount = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

int main(){
    char s[1001];
    scanf("%s", s);         //pake scanf aja kl ga ada spasi di input
    if(palindrom(s)){
        printf("YES\n");
    } else{
        printf("NO\n");
    }
    return 0;
}