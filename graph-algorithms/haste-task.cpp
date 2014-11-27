#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

vector< vector<pair<int, int> > > graph;

const int MAXN = 1001;
int n, m;

int dist[MAXN];
int times[MAXN];
bool visited[MAXN];
int pred[MAXN];

int bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while( !q.empty() ) {
        int current = q.front();
        q.pop();
        if(current == n) break;
        for (int i = 0; i < graph[current].size(); i++) {
            bool times_improvement = times[current] + graph[current][i].second < times[graph[current][i].first];
            bool no_street_improvement =  dist[graph[current][i].first] == dist[current] + 1;
            if(!visited[graph[current][i].first  ] || (times_improvement && no_street_improvement) ){
                q.push( graph[current][i].first );
                pred[ graph[current][i].first ] = current;
                times[ graph[current][i].first ] = times[current] + graph[current][i].second;
                dist[graph[current][i].first] = dist[current] + 1;
                visited[ graph[current][i].first  ] = true;
            }
        }
    }
}

void print_path()
{
    int current = n;
    stack<int> st;
    while(current != 0){
        st.push(current);
        current = pred[current];
    }
    printf("%d", st.top());
    st.pop();
    while(!st.empty()){
        printf(" %d", st.top());
        st.pop();
    }
    printf("\n");
}

int main()
{
    scanf("%d %d", &n, &m);
    graph.resize(n + 1);
    int v1, v2, street_time;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v1, &v2, &street_time);
        graph[v1].push_back(make_pair(v2, street_time) );
        graph[v2].push_back(make_pair(v1, street_time) );
    }
    bfs(1);
    int temp = dist[n];

    printf("%d\n",times[n]);
    print_path();

    return 0;
}
