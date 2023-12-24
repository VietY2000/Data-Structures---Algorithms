#include <stdio.h>
#include <string.h>
void funtion(char str1[], char str2[]){

    int l1 = strlen(str1);
    int l2 = strlen(str2);

    if(l1 >= l2){
        int count = 0;
        for(int p = 0; p < l1; ++p){
            if(str1[p] == str2[count]){
                count ++;
                if(count == l2){
                    printf("automaton");
                    return;
                }
            }
        }

        int arr[l2+1];
        count = 0;
        for(int p = 0; p < l1; ++p){
            for(int e = 0; e < l2; ++e){
                if(str1[p] == str2[e] && arr[e] != 1){
                    count ++;
                    arr[e] = 1;
                    if(count == l2){
                        if(l1 > l2){
                            printf("both");
                            return;
                        }
                        else{
                            printf("array");
                            return;
                        }                        
                    }
                    break;
                }
            }
        }

        printf("need tree");
        return;        
    }
    else{
        printf("need tree");
        return;
    }
    
}

int main(void){

    char str1[106];
    char str2[106];
    scanf("%s", str1);
    scanf("%s",str2);
    funtion(str1,str2);
    return 0;
}