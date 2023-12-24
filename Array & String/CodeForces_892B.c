#include <stdio.h>

int main(void){

    int n;
    scanf("%d", &n);
    int arr[n];
    int rank[n];
    for(int p = 0; p < n; ++p){
        scanf("%d", &arr[p]);
        rank[p] = 1;
    }
    int max_claw = n;
    for(int p = n - 1, e = n - 2; p > 0; p -=2, e -= 2){
        int claw_p = p - arr[p];
        int claw_e = e - arr[e];

        if(claw_p >= max_claw && claw_e >= max_claw){
            continue;
        }
        if(claw_p < max_claw){
            int position = max_claw;
            max_claw = claw_p;
            if(p < position){
                for(int m = p-1; m >= max_claw && m >= 0; --m){
                    rank[m] = 0;
                }
            }
            else{
                for(int m = position - 1; m >= max_claw && m >= 0; --m){
                    rank[m] = 0;
                }
            }
        }
        if(claw_e < max_claw){
            int position = max_claw;
            max_claw = claw_e;
            if(e < position){
                for(int m = e-1; m >= max_claw && m >= 0; --m){
                    rank[m] = 0;
                }
            }
            else{
                for(int m = position - 1; m >= max_claw && m >= 0; --m){
                    rank[m] = 0;
                }
            }
        }

        if(max_claw <=0){
            break;
        }
        
        // for(int m = p - 1, n = e - 1; ((n >= claw_e || m >= claw_p) && (m >= 0 && n >= 0)); --m, --n){
        //     if(m >= claw_p){
        //         rank[m] = 0;
        //     }
        //     if(n >= claw_e){
        //         rank[n] = 0;
        //     }
        // }
    }

    int result = 0; 
    for(int p = 0; p < n; ++p){
        if(rank[p]){
            ++result;
        }
    }
    printf("%d", result);
}