#include <stdio.h>

const int MAXN = 100001;

int dists[MAXN];
int litres[MAXN];

int n;

int cmp(int guess)
{
    int sum = 0;
    for(int i = n - 1; i > 0; i--){
        sum -= dists[i] - dists[i - 1];
    }
    for(int i = 0; i < n; i++){
        sum += litres[i];
        sum -= guess;
    }
    return sum >= 0;
}

int bin_search()
{
    int l = 1;
    int r = MAXN - 1;
    int mid;
    while(l < r - 1){
        mid = (l + r) / 2;
        if(cmp(mid) )l = mid;
        else r = mid;
    }
    return r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++ ) scanf("%d %d", &dists[i], &litres[i]);
    int result = bin_search();
    printf("%d\n", result);
    return 0;
}
