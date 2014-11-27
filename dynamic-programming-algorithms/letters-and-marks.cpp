#include <iostream>
#include <stdio.h>
#define N 5

using namespace std;

int marks[] = {0, 1, 2, 3, 4, 5};

int F(int k, int S){
    if(S < 0) return 0;
    if(S == 0) return 1;
    if(k == 1){
        if(marks[1] == S) return 1;
        else return 0;
    }
    return F(k - 1, S - marks[k]) + F(k - 1, S);
}

int main() {
    int sum;
    scanf("%d", &sum);
    int table[N + 1][sum + 1];

    for(int i = 1; i <= N; i++) table[i][0] = 1;
    for(int i = 0; i <= sum; i++) table[0][i] = 0;
    for(int k = 1; k <= N; k++)  table[k][1] = 1;

    for(int k = 1; k <= N; k++){
        int w = 0;
        for(int j = 2; j <= sum; j++){
            if(j - marks[k] < 0) w = 0;
            else w = table[k - 1][j - marks[k] ];
            table[k][j] = w + table[k - 1][j];
        }
    }
    printf("%d\n",table[N][sum]);

    return 0;
}
