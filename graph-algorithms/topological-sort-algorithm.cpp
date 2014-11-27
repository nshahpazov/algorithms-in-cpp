#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
const int MAXN = 1024;

vector< vector<pair<int, int> > > graph;

int  income[MAXN];
int pred[MAXN];
int best_way[MAXN];

void push_independent_vertices(queue<int>& q)
{
    for(int i = 1; i < graph.size() ; i++)
        if(income[i] == 0) q.push(i);
}

void top_sort()
{
    queue<int> q;
    push_independent_vertices(q);

    while(!q.empty()){
        int current = q.front();
         path.push_back(current);
        if(current == 1) best_way[1] = 0;
        q.pop();
        for(int i = 0; i < graph[current].size(); i++){
            income[graph[current][i].first ]--;
            if(income[graph[current][i].first ] == 0){
                pred[graph[current][i].first ] = current;

                q.push(graph[current][i].first);
            }
        }
    }
}

void get_best_way(){
    for(int i = 1; i < path.size(); i++){
        if(){}
    }
}


int get_max_path()
{
    int max = 0;
    for(int i = 1; i <= n; i++)
        if(best_way[i] > max) max = best_way[i];
    return max;
}

int main()
{
    scanf("%d %d", &n, &m);
    graph.resize(n + 1);

    int v1, v2, edge;
    for (int i = 0; i < m; i++ )
    {
    	scanf( "%d %d %d", &v1, &v2, &edge );
    	graph[v1].push_back(make_pair(v2, edge));
    	income[v2]++;
    }

    top_sort();
    printf("%d\n", get_max_path() );

    return 0;
}
