#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

vector<vector<pair<int, int> > > graph;
const int MAXN = 10001;
const int INFINITY = INT_MAX;
int n, m, h;
int dist[MAXN];
int hospitals[MAXN];
bool visited[MAXN];

void init_vertices(){
    for (int i = 0; i < MAXN; i++)
    {
        dist[i] = 2147483647;
        visited[i] = false;
    }
}

void nullify_hospitals()
{
    for (int i = 0;i < MAXN; i++ )
        if(hospitals[i] != 0) dist[ hospitals[i] ] = 0;
}

int get_sum()
{
    int sum = 0;
    for(int i = 1; i < graph.size(); i++){ sum += dist[i];  }
    return sum;
}

void get_shortest_path(int s)
{
    init_vertices();
    priority_queue< pair<int,int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        if(visited[current.second] ) continue;
        visited[current.second] = true;
        for(int i = 0; i < graph[current.second].size(); i++){
            int current_dist = current.first + graph[current.second][i].second;
            if( dist[ graph[current.second][i].first ] > current_dist ){
                dist[ graph[current.second][i].first ] = current_dist;
                if(!visited[  graph[current.second][i].first ]  )
                    pq.push( make_pair( current_dist, graph[current.second][i].first ));
            }
        }
    }
}

int get_min_sum()
{
    int min = INFINITY;
    for (int i = 0; i < h; i++) {
        get_shortest_path(hospitals[i]);
        nullify_hospitals();
        int cur_sum = get_sum();
        if(min > cur_sum) min = cur_sum;
    }
    return min;
}

void scan_edges()
{
    int v1, v2, edge;
    for (int i = 0; i < m; i++ ){
    	scanf("%d %d %d", &v1, &v2, &edge);
        graph[v1].push_back( make_pair(v2, edge) );
        graph[v2].push_back( make_pair(v1, edge) );
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &h);
    graph.resize(n + 1);
    for (int i = 0; i  < h; i++ ) scanf("%d", &hospitals[i]);

    scan_edges();

    int min = get_min_sum();
    printf("%d\n", min);
    return 0;
}
