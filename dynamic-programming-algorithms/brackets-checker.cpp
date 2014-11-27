#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 6;
char s[] = "????(?";

int main() {
    int F[N + 1][N + 2];

    // initialization
    for(int c = 0; c <= N + 1; c++) F[0][c] = 0;
    for(int k = 0; k <= N; k++) F[k][N + 1] = 0;
    F[0][0] = 1;

    for(int k = 1; k <= N; k++){
        int c = 0;
        if(s[k] == '(') F[k][c] = 0;
        else if(s[k] == ')') F[k][c] = F[k - 1][c + 1];
        else F[k][c] = F[k - 1][c + 1];
        for(c = 1; c <= N; c++){
            if( s[k] == '(' ) F[k][c] = F[k - 1][c - 1];
            else if( s[k] == ')' ) F[k][c] = F[k - 1][c + 1];
            else F[k][c] = F[k - 1][c - 1] + F[k - 1][c + 1];
        }

    }


    cout << F[N][0];
    return 0;
}
