#include <iostream>

using namespace std;

void printStarLine(int n, int m)
{
    cout << "*";
    for(int i = 0; i < m * (n - 1); i++) cout << " *";
    cout << endl;
}

void printMiddleLine(int n, int m)
{
    cout << "*";
    for(int i = 1; i < m * (n - 1); i++ ){
        if(i % (n - 1) == 0) cout << " *";
        else cout << "  ";
    }
    cout << " *";
    cout << endl;
}

int main()
{
    int t, m, n;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        cin >> n >> m;
        printStarLine(m, n);
        for(int i = 0; i < m - 2; i++) printMiddleLine(m, n);
        printStarLine(m, n);
    if(k < t - 1) cout << endl;
    }

    return 0;
}
