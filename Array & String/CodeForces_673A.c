#include <stdio.h>

int main(void){

    int n;
    scanf("%d", &n);
    int arr[n];
    for(int p = 0; p < n; ++p){
        scanf("%d",&arr[p]);
    }
    for(int p = 0; p < n; ++p){

        if(p == 0 && 15 < arr[p]){
            printf("%d",15);
            break;
        }
        else if(p == n - 1){
            if(arr[p] + 15 >= 90){
                printf("90");
                break;
            }
            else{
                printf("%d",arr[p] + 15);
                break;
            } 
        }

        if(arr[p] + 15 < arr[p+1]){
            printf("%d\n", arr[p] + 15);
            break;
        }
    }
    return 0;
}