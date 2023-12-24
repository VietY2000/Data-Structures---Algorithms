#include <stdio.h>
#include <string.h>

int main(void){

    char str1[101],str2[101];
    scanf("%s %s",str1, str2);

    if(strcmp(str1,str2) >= 0){
        printf("No such string\n");
    }
    else{
        for (int p = strlen(str1)-1; p >=0; --p ){
            if(str1[p] == 'z'){
                str1[p] = 'a';
            }
            else{
                str1[p] = str1[p] + 1;
                break;
            }
        }

        if(strcmp(str1,str2) < 0){
            printf("%s",str1);
        }
        else{
            printf("No such string");
        }
    }  
    return 0;
} 