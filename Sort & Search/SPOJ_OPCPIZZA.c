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

int search(int arr[], int left, int right, int value){
    int mid = (left + right)/2;
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

int main() {

    int tc;
    scanf("%d", &tc);
    while (tc--){

        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n];
        for(int p = 0; p < n; ++p){
            scanf("%d", &arr[p]);
        }
        sort(arr,0,n-1);
        int right = n;
        int result = 0;
        int k;
        for (int p = 0; p < n; ++p){
            k = search(arr, p+1, right - 1, m-arr[p]);
            if(k != -1){
                right = k;
                result++;
            }
            if(right - 1 <= p + 1){
                break;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}