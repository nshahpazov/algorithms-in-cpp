#include <iostream>
#include <stdio.h>
#define MAXN 200
using namespace std;

int n = 14;
int v = 5;

char A[MAXN][MAXN] = {
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }
};

char used[MAXN];

void bfs(int x){
     int currentVertex = 0;
     int levelVertex = 1;
     int endVertex = 1;
     int queue[MAXN];
     for(int i = 0; i < n; i++) queue[i] = 0;
     for(int i = 0; i < n; i++) used[i] = 0;
     queue[0] = x;
     used[x] = 1;
     while(currentVertex < endVertex){
          for(int k = currentVertex; k < levelVertex; k++){
               currentVertex++;
               for(int j = 0; j < n; j++){
                    if(A[k][j] && !used[j]){
                         queue[endVertex++] = j;
                         used[j] = 1;
                    }
               }
               //printf("%d ", queue[k] + 1);

          }
      printf("\n");
      levelVertex = endVertex;
     }
     printf("%d", levelVertex - 1);
}

int main(){
     for(int i = 0; i < MAXN; i++){
          for(int k = 0; k < MAXN; k++){
               A[i][k] = 0;
          }
     }
     int n, m;
     scanf("%d %d", &n, &m);
     for(int i = 0; i < m; i++){
          int x,y;
          scanf("%d %d", &x, &y);
          A[x][y] = 1;
          A[y][x] = 1;

     }
     bfs(1);
     return 0;
}
