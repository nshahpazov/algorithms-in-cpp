#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAXN = 1001;

char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dist[MAXN][MAXN];

int n, m;

int move[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };  // possible moves on the map

void init(){    // init the arrays after bfs
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool is_outside(int x, int y)       //checks whether is out of the map
{
    if(x >= n) return true;
    if(y >= m) return true;
    if(x < 0) return true;
    if(y < 0) return true;
    else return false;
}

pair<int, int> bfs(int x, int y)
{
    queue<pair<int, int> > q;
    int max = 0;
    pair<int, int> best_index = make_pair(0,0);
    q.push( make_pair(x, y) );
    visited[x][y] = 1;

    while(!q.empty()){
        pair<int, int> current = q.front();
        visited[x][y] = 1;
        q.pop();

        for (int i = 0;i < 4; i++ )
        {
            pair<int, int> new_pos;
            new_pos.first = current.first + move[i][0];
            new_pos.second = current.second + move[i][1];
            if( is_outside(new_pos.first, new_pos.second) ) continue;
            if( map[new_pos.first][new_pos.second] == '.' &&
               !visited[new_pos.first][new_pos.second] )
            {
                q.push(new_pos);
                visited[new_pos.first][new_pos.second] = 1;
                dist[new_pos.first][new_pos.second] =
                    dist[current.first][current.second] + 1;

                if( dist[new_pos.first][new_pos.second] > max )
                {
                    max = dist[new_pos.first][new_pos.second];
                    best_index.first = new_pos.first;
                    best_index.second = new_pos.second;
                }
            }
        }
    }
    return best_index;
}
/*
 pair<int, int> get_start(){
    for(int i = 1; i < m; i++)
        if(map[1][i] == '*') return i;
}*/

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) scanf( "%s", map[i] );
//    int start = get_start();
    pair<int, int> f = bfs(1, 1);
    init();
    pair<int, int> s = bfs(f.first, f.second);

    printf("%d\n", dist[s.first][s.second]);
    return 0;
}
