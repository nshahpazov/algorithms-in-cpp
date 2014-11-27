#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 512;

vector< vector<pair<int, int> > > graph;
int n, m, q;

int dist[MAXN];
bool visited[MAXN];

void init_vertices(){
    for (int i = 0; i < n; i++)
    {
        dist[i] = 2147483647;
        visited[i] = false;
    }
}

class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {
            return a.first > b.first;
        }
};

void get_shortest_path(int s)
{
    init_vertices();
    priority_queue< pair<int,int>, vector<pair<int, int> >, Compare > pq;
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

int main()
{
    scanf("%d %d", &n, &m);
    graph.resize(n);
    int v1, v2, edge;
    for (int i = 0; i < m; i++ )
    {
        scanf("%d %d %d", &v1, &v2, &edge);
        graph[v1].push_back( make_pair(v2, edge) );
    }

    scanf("%d", &q);
    int a1, a2;
    int temp;
    if(q != 0){

        scanf("%d %d", &a1, &a2);
        temp = a1;

        get_shortest_path(a1);
        if(a1 == a2) printf("0\n");
        else if(!visited[a2]) printf("unreachable\n");
        else printf("%d\n", dist[a2]);
    }
    for (int i = 1; i < q; i++)
    {
        scanf("%d %d", &a1, &a2);
        if(temp != a1) get_shortest_path(a1);
        temp = a1;
        if(a1 == a2) printf("0\n");
        else if(!visited[a2]) printf("unreachable\n");
        else printf("%d\n", dist[a2]);
    }
    return 0;
}
