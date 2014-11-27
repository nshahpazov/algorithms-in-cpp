#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int n, m;
int a, b, c, d;
const int MAXN = 1001;

char map[2][MAXN][MAXN];
char stairs[MAXN][MAXN];

int move[6][3] ={
                {0, 1, 0}, {0,-1, 0}, {1, 0, 0},
                {-1,0, 0}, {0, 0, 1}, {0, 0,-1} };

int visited[2][MAXN][MAXN];
int dist[2][MAXN][MAXN];

struct position{
    int x, y, z;
    position(int a = 0, int b = 0, int c = 0)
    { x = a; y = b; z = c; }
};

void bfs()
{
    queue< position > q;
    q.push(position(a - 1, b - 1, 1) );
    visited[1][a - 1][b - 1] = 1;
    while( !q.empty() )
    {
        position current = q.front();
        q.pop();
        //printf("x: %d y: %d z: %d dist: %d\n",
         //      current.x, current.y, current.z,
          //     dist[current.z][current.x][current.y]);
        for(int i = 0; i < 6; i++)
        {
            position new_pos;
            new_pos.x = current.x + move[i][0];
            new_pos.y = current.y + move[i][1];
            new_pos.z = current.z + move[i][2];

            if(new_pos.x >= n) continue;
            if(new_pos.y >= m) continue;
            if(new_pos.x < 0) continue;
            if(new_pos.y < 0) continue;
            if(new_pos.z > 1) continue;
            if(new_pos.z < 0) continue;

            if(move[i][2] > 0){
                if(stairs[new_pos.x][new_pos.y] != 'u'
                   && stairs[new_pos.x][new_pos.y] != 'b' )
                        continue;
            }
            if(move[i][2] < 0){
                if(stairs[new_pos.x][new_pos.y] != 'd'
                   && stairs[new_pos.x][new_pos.y] != 'b' )
                        continue;
            }

            if(map[new_pos.z][new_pos.x][new_pos.y] == '.'
               && !visited[new_pos.z][new_pos.x][new_pos.y])
            {
                    q.push(new_pos);

                    dist[new_pos.z][new_pos.x][new_pos.y] =
                        dist[current.z][current.x][current.y ] + 1;
                    visited[new_pos.z][new_pos.x][new_pos.y]= 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    scanf("%d %d %d %d", &b, &a, &c, &d);

    for (int i = 0; i < n; i++ )
        scanf("%s", map[1][i]);
    for (int i = 0; i < n; i++ )
        scanf("%s", map[0][i]);
    for (int i = 0; i < n; i++ )
        scanf("%s", stairs[i]);

    bfs();
    int result = dist[1][d - 1][c - 1];
    if(result == 0){printf("-1\n");}else{
        printf("%d\n", dist[1][d - 1][c - 1]);
    }
    return 0;
}
