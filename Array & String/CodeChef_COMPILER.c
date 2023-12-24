#include <stdio.h>
#include <string.h>


int main(void){
    int t;
    scanf("%d", &t);
    while (t--){
        
        char str[1000000];
        scanf("%s", str);

        int symbol = 0;
        int result = 0;

        for(int p = 0; p < strlen(str); p++){
            if(str[p] == '>'){
                symbol--;
            }
            else{
                symbol++;
            }
            if(symbol == 0){
                result = p + 1;
            }
            else if(symbol < 0){
                break;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}