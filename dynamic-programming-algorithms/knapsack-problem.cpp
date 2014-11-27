#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAXN = 10001;

int n, w;

struct item{
    int c;
    int w;
};

item items[MAXN];

int t[MAXN];

int get_max(){ return *max_element(t, t + w + 1); }

void fill_table() {
    for (int i = 0;i < n; i++ )
        for (int j = w; j >= 0; j--)
            if(items[i].w <= j) t[j] = t[j - items[i].w ] + items[i].c;
}

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) scanf("%d %d",&items[i].w, &items[i].c);
    fill_table();
    int result = get_max();
    printf("%d\n", result);
    return 0;
}
