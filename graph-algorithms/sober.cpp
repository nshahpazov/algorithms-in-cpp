#include <cstdio>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 50001;

int n, m, x, y, z;
int dist[MAXN];
int pred[MAXN];
bool visited[MAXN];

vector< vector<pair<int, int> > > graph;

void init_vertices(){
    for (int i = 0; i < MAXN; i++ )
    {
        //visited[i] = false;
        dist[i]  = 2147483647;
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
                pred[   graph[current.second][i].first  ] = current.second;

                if(!visited[  graph[current.second][i].first ]  )
                    pq.push( make_pair( current_dist, graph[current.second][i].first ));
            }
        }
    }
}

void print_path(int k)
{
    while(k != y){
        printf("%d ", k);
        k = pred[k];
    }
    printf("%d", y);
}

void print_path2(int k)
{
    stack<int> st;
   while(k != 0){
        st.push(k);
         k = pred[k];
    }
    st.pop();

    while(!st.empty() ){
        printf(" %d", st.top());
        st.pop();
    }
    printf("\n");
}

int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &z);
    int v1, v2, edge;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++ )
    {
        scanf("%d %d %d", &v1, &v2, &edge);
        graph[v1].push_back(make_pair(v2, edge) );
        graph[v2].push_back(make_pair(v1, edge) );
    }


    get_shortest_path(y);
    if(dist[z] == 0 && dist[x]){
        printf("-1\n");
    }else{
        printf("%d\n", dist[x] + dist[z]);
        pred[y] = 0;
        print_path(x);
        print_path2(z);
    }
    return 0;
}
