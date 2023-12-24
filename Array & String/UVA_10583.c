#include <stdio.h>

int parent[50000], rank[50000], ans;

void init(int n){
    ans = n;
    for(int p = 0; p < n; ++p){
        parent[p] = p;
        rank[p] = 1;
    }
}
int find(int p){
    while(p != parent[p]){
        p = parent[p];
    }
    return p;
}

void make_union(int p, int q){
    int e = find(p);
    int f = find(q);

    if(e == f){
        return;
    }

    if(rank[e] < rank[f]){
        parent[e] = f;
        rank[f] +=rank[e];
    }
    else{
        parent[f] = e;
        rank[e] += rank[f];
    }
    --ans;
}

int main(void){
    int n,m,x,y,tc = 1;
    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0){
            break;
        }
        init(n);

        for(int p = 0; p < m; ++p){
            scanf("%d %d", &x, &y);
            --x;
            --y;
            make_union(x,y);
        }

        printf("Case %d: %d\n", tc, ans);
        ++tc;
    }
    return 0;
}