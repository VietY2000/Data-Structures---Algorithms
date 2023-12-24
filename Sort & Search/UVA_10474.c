#include <stdio.h>
int partition(int arr[], int left, int right){
    int pivot = arr[right];

    int low = left - 1;
    for(int p = left; p < right; ++p){
        if(arr[p] < pivot){
            low++;
            if(low < p){
            int temp = arr[low];
            arr[low] = arr[p];
            arr[p] = temp;
        }
        }
    }
    arr[right] = arr[low+1];
    arr[low+1] = pivot;
    return low+1;
}

void sort(int arr[], int left, int right){
    if(left < right){
        int poi = partition(arr,left,right);
        sort(arr,left,poi-1);
        sort(arr,poi+1,right);
    }
}
int search(int arr[], int n, int value) {

    int left = 0;
    int right = n-1;

    while(left <= right) {
        int mid = (left + right)/2;
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
    return -1;
}

int main(){

    int n, q;
    int tc = 0;
    int arr[10005];

    while(++tc && tc <= 64){
        scanf("%d %d", &n, &q);
        if(n == 0 && q == 0){
            break;
        }

        for (int p = 0; p < n; ++p){
            scanf("%d", &arr[p]);
        }
        
        int value[q];
        for(int p = 0; p < q; ++p){
            scanf("%d", &value[p]);
        }
        sort(arr,0,n-1);
        printf("CASE# %d:\n",tc);
        for(int p = 0; p < q; ++p){
            int result = search(arr,n,value[p]);
            if(result != -1){
                while(arr[result - 1] == value[p]){
                    result--;
                }
                printf("%d found at %d\n",value[p], result + 1);
            }
            else{
                printf("%d not found\n", value[p]);
            }
        }
    }
    return 0;
}