#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

const int MAXN = 101;
const int INFINITY = INT_MAX / 2;

int n, m, q;

int g[MAXN][MAXN];

void init_graph()
{
    for (int i = 0; i < MAXN; i++ ){
        for (int j = 0; j < MAXN; j++) g[i][j] = INFINITY;
    }
}

void floyd_warshall()
{
    for (int k = 0; k < n; k++ ) {
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < n; j++)
                if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
        }
    }
}

int main() {

    init_graph();
    scanf("%d %d", &n, &m);

    int v1, v2, edge;
    for (int i = 0; i < m; i++ )
    {
        scanf("%d %d %d", &v1, &v2, &edge);
        g[v1][v2] = edge;
    }

    floyd_warshall();

    scanf("%d", &q);

    int a, b;
    for (int i = 0; i < q; i++ )
    {
        scanf("%d %d", &a, &b);
        if(a == b)printf("0\n");
        else if(g[a][b] == INFINITY) printf("unreachable\n");
        else printf("%d\n", g[a][b]);
    }
    return 0;
}
