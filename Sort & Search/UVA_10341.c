#include <stdio.h>
#include <math.h>
int search(float arr[], int n, int p, int q, int r, int s, int t, int u) {

    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right) {  
        mid = (left + right)/2;
        double sum = p*exp(-arr[mid]) + q*sin(arr[mid]) + r*cos(arr[mid]) + s*tan(arr[mid]) + t*pow(arr[mid],2) + u;
        if(sum > 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return mid;
}

double negative(double x){

    return -x;
}

int main(){

    float arr[10001];
    float value = 0;
    for(int e = 0; e < 10001; ++e){
        arr[e] = value;
        value = value + 0.0001;
    }    

    int p,q,r,s,t,u;
    scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u);
    while(p != EOF || q != EOF || r != EOF || s != EOF || t != EOF|| u != EOF){
        int position = search(arr,10001,p,q,r,s,t,u);
        double sum = p*exp(-arr[position]) + q*sin(arr[position]) + r*cos(arr[position]) + s*tan(arr[position]) + t*pow(arr[position],2) + u;
        if (sum < 0){
            sum = negative(sum);
        }
        if( sum <= 1e-3){
            printf("%.4f\n",arr[position]);
        }
        else{
            printf("No solution\n");

        }
        scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u);
    }

    return 0;
}