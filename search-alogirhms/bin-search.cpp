#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 100001;
int n;
int a[MAXN];


int lower_bound(int x)
{
    int l = -1;
    int r = n - 1;
    int mid;
    while(l < r - 1){
        mid = (l + r) / 2;
        if(x <= a[mid]) r = mid;
        else l = mid;
    }
    if(a[r] < x ) return r + 1;
    return r;
}

int upper_bound(int x){
    int l = 0;
    int r = n;
    int mid;
    while(l < r - 1){
        mid = (l + r) / 2;
        if(x >= a[mid]) l = mid;
        else r = mid;
    }
    if(a[l] > x) return l - 1;
    return l;
}

int main()
{
    int m;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    int a, b;
    for (int i = 0;i < m;i++ ){
        cin >> a >> b;
        int l = lower_bound(a);
        int r = upper_bound(b);
        cout << r - l + 1 << endl;
    }
    return 0;
}
