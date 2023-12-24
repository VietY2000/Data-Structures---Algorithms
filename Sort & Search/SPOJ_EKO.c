#include <stdio.h>
long long partition(long long arr[], long long left, long long right){
    long long pivot = arr[right];

    long long low = left - 1;
    for(long long p = left; p < right; ++p){
        if(arr[p] < pivot){
            low++;
            if(low < p){
            long long temp = arr[low];
            arr[low] = arr[p];
            arr[p] = temp;
        }
        }
    }
    arr[right] = arr[low+1];
    arr[low+1] = pivot;
    return low+1;
}

void sort(long long arr[], long long left, long long right){
    if(left < right){
        long long poi = partition(arr,left,right);
        sort(arr,left,poi-1);
        sort(arr,poi+1,right);
    }
}

long long search(long long arr[], long long n, long long value){

    long long result;
    long long left = 1;
    long long right = value;
    
    while (left <= right){
        long long sum = 0;
        long long mid = (left + right)/2;        
        result = arr[n-1] - mid;
        for(long long p = n - 1; p >= 0; --p) {
            if(arr[p] <=result){
                break;
            }
            sum = sum + (arr[p] - result);
        }
        
        if (left == right && sum < value){
            return result - 1;
        }
        
        if (sum == value){
            return result;
        }
        
        else if(sum < value){

            left = mid + 1;
        }
        else{

            right = mid - 1;
        }                
    }
    
    return result;
}

int main() {
    long long n, value;
    scanf("%lld %lld", &n, &value);
    long long arr[n];
    for(long long p = 0; p < n; ++p){
        scanf("%lld", &arr[p]);
    }
    sort(arr,0,n-1);
    long long result = search(arr,n,value);
    printf("%lld",result);
    return 0;
}