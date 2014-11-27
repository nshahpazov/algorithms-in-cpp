#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 400;
int n;
int table[MAXN*MAXN + 1];
int a[MAXN + 1][MAXN + 1];

void fill_table()
{   int counter = 1;
    for (int i = 0; i < n; i++ ) {
        for (int j = 0;j < n; j++ ){
            table[counter] = table[counter - 1] + a[i][j];
            if(table[counter] < 0){ table[counter] = 0;
                counter++;
                break;
            }
            counter++;
        }
    }
}

int get_max(){
    int max = 0;
    for (int i = 0; i < n * n; i++ ){
        if(table[i] >= max) max = table[i];
       // cout <<"MAX: " << max << endl;
    }
    return max;
}

void scan_input(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++ )
        for (int j = 0; j < n; j++ ) scanf("%d", &a[i][j]);
}

int main()
{
    scan_input();
    fill_table();
    int result = get_max();
    printf("%d\n", result);
    return 0;
}
