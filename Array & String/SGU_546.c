#include <stdio.h>

int main(void){

    int n, zero, one;
    scanf("%d %d %d", &n, &zero, &one);
    char pass[n];
    scanf("%s", pass);
    if(zero + one > n){
        printf("-1");
    }
    else{
        int two = n - zero - one;    
        int change = 0;
        int p_one = 0, p_zero = 0, p_two = 0;

        for(int p = 0; p < n; ++p){
            if(pass[p] == '0'){
                p_zero++;
            }
            else if(pass[p] == '1'){
                p_one++;
            }
            else{
                p_two++;
            }
        }

        for(int p = 0; p < n; ++p){
            if(pass[p] == '2'){
                if(p_two <= two){
                    continue;
                }
                else{
                    if(p_one < one){
                        p_one++;
                        p_two--;
                        pass[p] = '1';
                        change++;
                    }
                    else{
                        p_zero++;
                        p_two--;
                        pass[p] ='0';
                        change++;
                    }
                }
            }
            else if(pass[p] == '1'){
                if(p_one <= one){
                    continue;
                }
                else{
                    if(p_two < two){
                        p_two++;
                        p_one--;
                        pass[p] = '2';
                        change++;
                    }
                    else{
                        p_zero++;
                        p_one--;
                        pass[p] ='0';
                        change++;
                    }
                }
            }
            else{
                if(p_zero <= zero){
                    continue;
                }
                else{
                    if(p_one < one){
                        p_one++;
                        p_zero --;
                        pass[p] = '1';
                        change++;
                    }
                    else{
                        p_two++;
                        p_zero--;
                        pass[p] ='2';
                        change++;
                    }
                }
            }
        }

        printf("%d\n", change);
        for(int p = 0; p < n; ++p){
            printf("%c",pass[p]);
        }

    }
    } 