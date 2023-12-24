#include <stdio.h>

int partition(int level[], int misson[], int left, int right) {

    int pivot_level = level[right];
    int pivot_misson = misson[right];
    int position = left - 1;
    for(int p = left; p < right; ++p) {
        if(level[p] < pivot_level) {
            position++;
            if(p > position) {
                int temp_level = level[p];
                int temp_misson = misson[p];
                
                level[p] = level[position];
                level[position] = temp_level;

                misson[p] = misson[position];
                misson[position] = temp_misson;                
            }
        }
    }

    level[right] = level[position + 1];
    level[position + 1] = pivot_level;

    misson[right] = misson[position + 1];
    misson[position + 1] = pivot_misson;

    return position + 1;
}

void sort(int level[], int misson[], int left, int right){
    if(left < right){
        int position = partition(level, misson, left, right);
        sort(level, misson, left, position - 1);
        sort(level, misson, position + 1, right);
    }
}

void print_array(int arr[], int n){
    for(int p = 0 ; p < n; ++p){
        printf("%d ",arr[p]);
    }
    printf("\n");
}

int main(){

    int n;
    scanf("%d", &n);
    int level[n];
    int misson[n];
    for (int p = 0; p < n; ++p) {
        scanf("%d",&level[p]);
        misson[p] = p + 1;
    }

    sort(level, misson, 0, n - 1);

    int swap = 0;
    for(int p = 1; p < n; ++p) {
        if(level[p] == level[p-1]){
            swap++;
            if(swap == 2){
                break;
            }
        }
    }

    if(swap < 2) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        print_array(misson,n);
        swap = 0;
        for(int p = 1; p < n; ++p){
            if(level[p] == level[p-1]){
                swap++;
                int temp = misson[p];
                misson[p] = misson[p-1];
                misson[p-1] = temp;
                print_array(misson,n);
                if(swap == 2){
                    break;
                }
            }
        }
    }
    
    return 0;
}