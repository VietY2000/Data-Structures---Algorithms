#include <stdio.h>
int main(void){
    int arr1_n, arr2_n;
    int number1, number2;
    scanf("%d %d", &arr1_n, &arr2_n);
    scanf("%d %d", &number1, &number2);

    int arr1[arr1_n], arr2[arr2_n];

    for(int p = 0; p < arr1_n; p++){
        scanf("%d", &arr1[p]);
    }

    for(int p = 0; p < arr2_n; p++){
        scanf("%d", &arr2[p]);
    }
    int flag = 1;
    for(int p = 0; p < arr2_n; p++){
        if((arr2[p] > arr1[number1 - 1]) && (arr2_n - p) >= number2){
            printf("YES\n");
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("NO\n");
    }
    return 0;
}