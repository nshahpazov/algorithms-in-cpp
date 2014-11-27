#include <stdio.h>

int t, n;
const int MAXN = 10001;
int a[MAXN];

int ins_sort()
{
    int counter = 0;
    for (int i = 0; i < n; i++ ){
        int item = a[i], j;
        for(j = i; j > 0 && a[j - 1] > item; j--){
            a[j] = a[j - 1];
            counter++;
        }
        a[j] = item;
    }
    return counter;
}

int main()
{
    scanf("%d", &t);
    for (int i = 0; i <  t;i++ ){
        scanf("%d", &n);
        for (int j = 0; j < n; j++ ) scanf("%d", &a[j]);
        printf("%d\n", ins_sort());
    }
    return 0;
}
