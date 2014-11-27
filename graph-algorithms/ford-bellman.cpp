#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stdio.h>

using namespace std;

const int MAXN  = 10001;
const int INFINITY = INT_MAX;
vector< vector< pair<int, int> > > g;
int pred[MAXN];
bool visited[MAXN];
int dist[MAXN];

int n, m;

void init_g(int s)
{
    for (int i = 0;i < MAXN; i++ ) {
        visited[i] = false;
        pred[i] = 0;
        dist[i] = INFINITY;
    }
    dist[s] = 0;
}

void relax(int u, int v, int weight)
{
    if(dist[u] + weight < dist[v]) dist[v] = dist[u] + weight;
}


void ford_bellman(int s)
{
    init_g(s);
    for (int i = 1; i < g.size(); i++ )
        for (int j = 0; j < g[i].size(); j++ ) relax(i, g[i][j].first, g[i][j].second);
}

void scan_edges()
{
    int v1, v2, edge_length;
    for (int i = 0; i < m; i++ ){
        scanf("%d %d %d", &v1, &v2, &edge_length);
        g[v1].push_back(make_pair(v2, edge_length) );
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    scan_edges();
    ford_bellman(1);
    printf("%d\n", dist[n]);
    return 0;
}
