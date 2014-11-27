#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 10001;

int n, a[MAXN], q, a, b;
int table[MAXN];
void find_sums()
{
    table[0] = 0;
    for (int i = 1; i <= n; i++)
    {
       table[i] = table[i - 1] + a[i - 1];
    }

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &q);

    //dynamic algorithm
    find_sums();
    for (int i = 0; i < q; i++){
        scanf("%d %d", &a, &b);
        int r = table[n] - table[b];
        printf("%d\n", table[b] - table[a - 1]);
    }


    return 0;
}
