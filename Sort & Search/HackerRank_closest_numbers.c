#include <stdio.h>

int partition(int arr[], int left, int right){

    int pivot = arr[right];
    int position = left - 1;
    for(int p = left; p < right; ++p){
        if(arr[p] < pivot){
            position++;
            if(p > position){
                int temp = arr[p];
                arr[p] = arr[position];
                arr[position] = temp;
            }
        }
    }
    arr[right] = arr[position + 1];
    arr[position + 1] = pivot;
    return position + 1;
}

void sort(int arr[], int left, int right){

    if(left < right){
        int position = partition(arr, left, right);
        sort(arr, left, position - 1);
        sort(arr, position + 1, right);
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    int arr[n];
    for(int p = 0; p < n; ++p){
        scanf("%d", &arr[p]);
    }
    sort(arr, 0, n - 1);
    int min_number = arr[1] - arr[0];
    for(int p = 2; p < n; ++p){
        if(arr[p] - arr[p-1] < min_number){
            min_number = arr[p] - arr[p-1];
        }
    }
    for(int p = 1; p < n; ++p){
        if(arr[p] - arr[p-1] == min_number){
            printf("%d %d ",arr[p-1], arr[p]);
        }
    }
    return 0;
}