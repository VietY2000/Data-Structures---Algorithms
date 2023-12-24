#include <stdio.h>
#include <string.h>


int main(void){
    int n,k;
    scanf("%d %d",&n, &k);
    char str[n][101];

    for(int p = 0; p < n; ++p){
        scanf("%s", str[p]);
    }

    char pass[101];
    scanf("%s",pass);

    int more = 0, not_more = 0;

    for(int p = 0; p < n; ++p){
        if(strlen(str[p]) < strlen(pass)){
            ++not_more;
        }
        else if(strlen(str[p]) > strlen(pass)){
            ++more;
        }
    }

    int best = (not_more*1) + (not_more/k)*5 + 1;
    int worst = (n - more - 1) + (n - more - 1)/k*5 +1;

    printf("%d %d", best, worst);
    return 0;
}