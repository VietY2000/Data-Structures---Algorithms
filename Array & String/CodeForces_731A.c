#include <stdio.h>
#include <string.h>
int abs(int x){
    if(x > 0){
        return x;
    }
    return x*(-1);
}

int main(void){
    
    char str[101];
    scanf("%s", str);
    int sum = 0;
    if(str[0] - 'a' <= 13){
        sum = sum + str[0] - 'a';
    }
    else{
        sum = sum + (26 - abs(str[0] - 'a'));
    }
    for(int p = 1; p < strlen(str); ++p){
        if(abs(str[p] - str[p-1]) <= 13){
            sum = sum + abs(str[p] - str[p-1]);
        }
        else{
            sum = sum + (26 - abs(str[p] - str[p-1]));
        }
    }
    printf("%d",sum);
    return 0;
}