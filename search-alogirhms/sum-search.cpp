#include <stdio.h>

const int MAXN = 1000001;
int a[MAXN];

int n, m;

bool bin_search(int x){
    int l = 0;
    int r = n;
    int mid;
    while(l < r - 1){
        mid = (l + r) / 2;
        if(x == a[mid]) return true;
        else if(x < a[mid]) r = mid;
        else l = mid;
    }
    return false;
}

bool is_sum(int s){
    for(int i = 0; i < n; i++){
        if(bin_search(s - a[i])) return true;
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int target;
    for(int i = 0; i < m; i++){
        scanf("%d", &target);
        if( is_sum(target) ) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
