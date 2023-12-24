#include <stdio.h>

int main(void){
    int n, t;
    scanf("%d %d", &n, &t);
    int arr[n];
    for(int p = 0; p < n; ++p){
        scanf("%d", &arr[p]);
    }
   
    int max = 0;
    int sum = 0;
    int left = 0;

    for(int right = 0; right < n; ++right){
        sum = sum + arr[right];
        if(sum <= t){
            ++max;
        }
        else{
            sum = sum - arr[left];
            ++left;
        }
    }
    printf("%d",max);
    return 0;
}