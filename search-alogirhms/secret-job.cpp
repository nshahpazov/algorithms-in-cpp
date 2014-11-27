#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int MAXN = 750001;
int n,k;
int a[MAXN];

int compare(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int bin_search(int x){
    int l = -1;
    int r = n;
    int mid;
    while(l < r - 1){
        mid = (l + r) / 2;
        if(x == a[mid]){
            return mid + 1;
        }
        else if(x < a[mid])
        {
            r = mid;
        }
        else{ l = mid ;}
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++ )
    {
    	scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare );
    int key;
    for(int i = 0; i < n / 2 + 1; i++){
        scanf("%d", &key);
        if(key == 0){break;}
        else{
            int r = bin_search(key);
            printf("%d\n", r);
        }
    }
    return 0;
}
