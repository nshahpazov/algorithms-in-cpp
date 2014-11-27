#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <stdio.h>

using namespace std;

const int MAXN = 1001;
const int INFINITY = 1000;
int n, m;

vector< pair<int, int> > mst;
vector< vector< pair < int, int> > > g;

bool visited[MAXN];
int pred[MAXN];
int e_length[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++) e_length[i] = INFINITY;
}

void print_mst()
{
    for (int i = 0; i < mst.size(); i++ ){
        printf("%d - %d\n", mst[i].first, mst[i].second );

    }
    printf("\n");
}

int get_mst(int s)  // Prim's Algorithm
{
    priority_queue< pair<int, int>,
        vector< pair<int, int> >, greater< pair<int, int> > > pq;

    pq.push( make_pair(0, s) );
    int length = 0;
    while( !pq.empty() ){
        pair<int, int> current = pq.top();
        pq.pop();
        if(visited[current.second]) continue;
        mst.push_back(make_pair(pred[current.second], current.second));
        length += current.first;

        visited[current.second] = true;

        for (int i = 0; i < g[current.second].size(); i++ ){
            pq.push(make_pair( g[current.second][i].second, g[current.second][i].first));
            if(e_length[g[current.second][i].first] > g[current.second][i].second ){
                pred[ g[current.second][i].first ] = current.second;
                e_length[ g[current.second][i].first ] = g[current.second][i].second;
            }
        }
    }
    return length;
}

int main()
{
    scanf("%d %d", &n, &m);
    g.resize(n);
    init();
    int v1, v2, edge;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &edge);
        g[v1].push_back(make_pair(v2, edge));
        g[v2].push_back(make_pair(v1, edge));
    }
    int length = get_mst(0);
    //print_mst();

    printf("%d\n", length);
    return 0;
}

/*
6 9
0 1 50
1 2 5
1 3 3
2 3 1
1 4 1
2 5 4
3 4 8
3 5 7
4 5 2
*/
