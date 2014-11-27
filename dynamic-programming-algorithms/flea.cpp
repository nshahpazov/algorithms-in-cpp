#include <iostream>
#include <stdio.h>


using namespace std;

const int MAXN = 1501;
int n;
int map[MAXN][MAXN];
int path[MAXN][MAXN];

void f(){
    path[0][0] = 1;
    int p1, p2;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            p1 = p2 = 1000000;
            if(i > 0){
                bool is_white = (map[i][j] && path[i - 1][j] % 2) ||
                (!(path[i - 1][j] % 2) && !map[i][j]);
                if(is_white) p1 = path[i - 1][j] + 1;
                else p1 = path[i - 1][j] + 2;
            }
            if(j > 0){
                 bool is_white = (map[i][j] && (path[i][j - 1] % 2)) ||
                (!(path[i][j - 1] % 2) && !map[i][j]);
                if(is_white) p2 = path[i][j - 1] + 1;
                else p2 = path[i][j - 1] + 2;
            }
            path[i][j] = min(p1, p2);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    f();
    printf("%d\n", path[n - 1][n - 1]);

    return 0;
}
