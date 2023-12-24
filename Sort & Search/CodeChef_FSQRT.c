#include <stdio.h>
#include <math.h>
int main() {

    int tc;
    scanf("%d", &tc);
    while (tc--){
        int number;
        scanf("%d", &number);
        number = sqrt(number);
        printf("%d\n", number);
    }

    return 0;
}