#include <iostream>
#define MAXN 21
using namespace std;

// Number of sequences of length n from the set {0, 1}
int getNumberOfSequences(int n){
    // T(n) = 2 * T(n-1)
    int b[n + 1];
    b[1] = 2;
    for(int i = 2; i <= n; i++) b[i] = b[i - 1] * 2;
    // Can be done without array
    return b[n];
}

// sequences from {0, 1} with no two 1s neighbours

long long getNumberOfSequences2(int n){
    long long b1 = 2;
    long long b2 = 3;
    long long b;
    for(int i = 3; i <= n; i++){
        b = b1 + b2;
        b1 = b2;
        b2 = b;
    }
    // Can be done with array
    return b;
}

//Recursive Realization using memoization technique
//There must be initialization of the v[MAXN] array !!!
int v[MAXN];
long long getNumberOfSequences2_2(int n){
    if(v[n] == 0){
        v[n] =  getNumberOfSequences2_2(n - 1) +
                getNumberOfSequences2_2(n - 2);
    }
    return v[n];

}


int main() {
    cout << "Hello world!" << endl;
    return 0;
}
