#include <iostream>
#include <stdio.h>

using namespace std;

const int MOD = 11;

long long fast_pow (long long a, int n)
{
    if(n == 0) return 1;
    if(n % 2 == 0) return fast_pow( (a * a) , n / 2 );
    return a * fast_pow((a * a) , n / 2) ;
}

long long pow(ínt a, int n ){
    long long res;
    while(n){
        if(n % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    resturn res;
}

int main()
{
    cout << fast_pow(5,5 );
    return 0;
}
