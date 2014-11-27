#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAXN = 1000001;
int n, a[MAXN], table[MAXN];

void fill_table(){
    for (int i = 1; i <= n; i++){
        table[i] = table[i - 1] + a[i];
        if(table[i] <= 0) table[i] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    fill_table();
    int r = *max_element(table, table + n + 1);
    printf("%d\n", r);
    return 0;
}

/*
12
-10 1 2 5 -7 3 4 8 -50 5 5 5
*/
