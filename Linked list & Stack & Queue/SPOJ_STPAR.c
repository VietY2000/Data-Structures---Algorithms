    #include <stdio.h>
    #define capacity 1005
    int main(){

        int arr[capacity];
        int stack[capacity];
        int e;
        int b;
        int number;
        while(1){
            scanf("%d", &number);
            if(number == 0){
                break;
            }
            for(int p = 0; p < number; ++p){
                scanf("%d",&arr[p]);
            }
            e = 0;
            b = 1;
            int start = 1;
            for(int p = 0; p < number; ++p){
                while(e > 0 && stack[e-1] == start){

                    e--;
                    start++;
                }
                if(arr[p] == start){
                    start++;
                }
                else if(e > 0 && stack[e - 1] < arr[p]){
                    b = 0;
                    break;
                }
                else{
                    stack[e] = arr[p];
                    e++;
                }
            }
            if(b){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        return 0;
    }