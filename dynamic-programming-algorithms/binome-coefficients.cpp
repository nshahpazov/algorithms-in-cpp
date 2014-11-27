#include <iostream>
#include <stdio.h>

using namespace std;

int recursiveC(int n, int k){
    if(k == 0 || n == k) return 1;
    else return recursiveC(n - 1, k - 1) + recursiveC(n - 1, k);
}


int main() {
    //cout << recursiveC(4, 2);
    int n, k;
    scanf("%d %d", &n, &k);
    int t[n + 1][n + 1];

    for(int i = 0; i <= n; i++){
        t[i][0] = 1;
        t[i][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
    }
    printf("%d\n", t[n][k]);
    return 0;

}
