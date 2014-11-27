#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000;

vector<vector<pair<int, int> > > graph;

enum color{
    WHITE, GRAY, BLACK
};

void insert_vertex(int v1, int v2, int length)
{
    graph[v1].push_back(pair<int, int>(v2, length) );
    graph[v2].push_back(pair<int, int>(v1, length) );
}

bool used[MAXN];

int max_sum = 0;

void init_visit(){
    for (int i = 0; i < graph.size(); i++ )
        used[i] = false;
}

int dfs_visit(int current, int current_sum){
    used[current] = true;
    if(current_sum > max_sum) max_sum = current_sum;

    for (int i = 0; i < graph[current].size(); i++ ){
        if(used[graph[current][i].first] == false )
            dfs_visit(graph[current][i].first, current_sum + graph[current][i].second );
    }
    used[current] = false;
    return current_sum;
}

int main()
{
    int vCount, eCount;
    cin >> vCount >> eCount;
    while(vCount != 0 && eCount != 0){
        graph.clear();
        init_visit();
        graph.resize(vCount + 1);
        max_sum = 0;
        for (int i = 0; i < eCount; i++ )
        {
            int v1, v2, length;
            cin >> v1 >> v2 >> length;
            insert_vertex(v1, v2, length);
        }
        dfs_visit(1, 0);
        cout << max_sum << endl;
        cin >> vCount >> eCount;
    }
    return 0;
}
