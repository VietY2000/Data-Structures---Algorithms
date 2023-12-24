#include <stdio.h>

int main(){

    unsigned n, volume, p;
    scanf("%d %d", &n, &volume);

    long long start[n];
    long long time[n];

    for(p = 0; p < n; ++p){
        scanf("%lld %lld", &start[p], &time[p]);
    }

    long long tg = start[0] + time[0];

    long long result[n];
    result[0] = tg;

    unsigned ct = 0;
    unsigned count = 0;

    for(p = 1; p < n; ++p){

        if(start[p] < result[ct]){
            if(count < volume){
                count++;
                tg = tg + time[p];
                result[p] = tg;
            }
            else{
                result[p] = -1;
            }
        }
        else if(start[p] == result[ct]){
            ct++;
            tg = tg + time[p];
            result[p] = tg;
        }
        else{
            if(start[p] >= tg){
                count = 0;
                ct = p;
                tg = start[p] + time[p];
                result[p] = tg;
            }
            else{
                while(start[p] >= result[ct]){
                    ct++;

                    count--;
                }
                count++;

                tg = tg + time[p];
                result[p] = tg;
            }
        }
    }

    for(p = 0; p < n; ++p){
        printf("%lld ", result[p]);
    }
    return 0;
}