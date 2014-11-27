#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 16384
#define INF 100000001


vector<vector<pair<int, int> > > graph;
int dist[MAXN];
int pred[MAXN];

class Compare{
    public : bool operator()(const int& l, const int& r){
                return dist[l] > dist[r];
             }
};

void getShortestPath()
{    
    priority_queue< pair<int, int>,vector< pair<int, int> >, greater< pair<int, int> > > pq;
    bool used[ graph.size() ];
    
    for(int i = 0; i < graph.size(); i++){
        used[i] = false;
        dist[i] = INF;
        pred[i] = -1;
    }
    
    dist[1] = 0;
    //pred[1] = 0;
    pq.push(make_pair(0, 1) );
    
    while( !pq.empty() )
    {
        pair<int, int> current = pq.top();
        pq.pop();
        if(used[ current.second ] ) continue;

        used[ current.second ] = true;
        
        for(int i = 0; i < graph[current.second].size(); i++) {
            int current_distance = dist[current.second] + graph[current.second][i].second;
            if( dist[ graph[current.second][i].first ] > current_distance){
                dist[ graph[current.second][i].first ] = current_distance;
                
                pred[graph[current.second][i].first  ] = current.second;
                pq.push(make_pair(current_distance, graph[current.second][i].first) );
            }
        }
    }
}

void showPath()
{    
    vector<int> path;
    int current = graph.size() - 1;
    while(current != 1){
        path.push_back(current);
        current = pred[current];
    }
    path.push_back(current);
    reverse(path.begin(), path.end() );
    cout << path.size() << endl;
    for(int i = 0; i < path.size() - 1; i++) cout << path[i] << " ";
    cout << path.back() << endl;
}

int main()
{
    int t, n, m;
    cin >> t;
    for (int k = 0; k < t; k++ )
    {
        cin >> n >> m;
        graph.resize(n + 1);
    
        for (int i = 0; i < m; i++ )
        {
            int v1, v2, edge_length;
            cin >> v1 >> v2 >> edge_length;
            
            graph[v1].push_back( pair<int, int>(v2, edge_length) );
        }
        getShortestPath();
        if (dist[graph.size() - 1] == INF) {
            cout<<-1<<endl;
            continue;
        }
       cout << dist[graph.size() - 1] << endl;
        showPath();
    }
    return 0;
}