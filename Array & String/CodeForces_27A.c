#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int arr[3009];
    for(int p = 0; p < n; ++p){
        int value;
        scanf("%d",&value);
        arr[value] = 1;
    }
    for(int p = 1; p < 3009; ++p){
        if(arr[p] != 1){
            printf("%d",p);
            break;
        }
    }
}