#include <stdio.h>

int search(int arr[], int n, int value) {

    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right) {
        mid = (left + right)/2;
        if(arr[mid] == value) {
            return mid;
        }
        else if(arr[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return mid;
}

int main(void){

    int n;
    scanf("%d", &n);
    int arr[n];
    for(int p = 0; p < n; ++p){
        scanf("%d", &arr[p]);
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int queue;
        scanf("%d", &queue);
        int mid = search(arr,n,queue);
        if(arr[mid] == queue){
            int left = 1;
            int right = 1;
            while(arr[mid - left] == queue){
                left++;
            }
            while(arr[mid + right] == queue){
                right++;
            }

            if(mid - left < 0){

                printf("X ");
            }
            else{

                printf("%d ", arr[mid - left]);
            }
            
            if(mid + right > n-1){
                printf("X\n");
            }
            else{
                printf("%d\n",arr[mid + right]);
            }
        }
        else if(arr[mid] > queue){
            if(mid - 1 < 0){
                printf("X ");
            } 
            else{
                printf("%d ",arr[mid-1]);
            }

            printf("%d\n",arr[mid]);
        }
        else{
            printf("%d ",arr[mid]);
            if(mid + 1 > n - 1){
                printf("X\n");
            }
            else{
                printf("%d\n",arr[mid + 1]);
            }
        }
    }
    return 0;      
}