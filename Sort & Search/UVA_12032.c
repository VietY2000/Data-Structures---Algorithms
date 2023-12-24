#include <stdio.h>
int main(){
    int tc;
    
    scanf("%d", &tc);
    for(int e = 1; e <= tc; ++e){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int p = 0; p < n; ++p){
            scanf("%d", &arr[p]);
        }
        int k = arr[0] - 0;
        int count = k - 1;
        int flag = 0;
        for(int p = 1; p < n; ++p){
            if(arr[p] - arr[p-1] > k){
                k = arr[p] - arr[p-1];
                count = k - 1;
                flag = 0;
            }
            else{
                if(arr[p] - arr[p-1] > count){
                    flag = 1;
                    continue;
                }
                if(arr[p] - arr[p-1] == count){
                    count--;
                }
                
            }
        }
        if(count < 0 || flag){
            printf("Case %d: %d\n", e, k+1);
        }
        else{
            printf("Case %d: %d\n", e, k);
        }
    }
    return 0;
}