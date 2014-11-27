#include <iostream>
#include <stdio.h>
#include <queue>

#define n 100

using namespace std;

enum color{
    WHITE, GRAY, BLACK
};

queue<int> q;
vector< vector< int> > graph;
color colors[n];
int pred[n];

void breadthFirstSearch(int start){
     q.push(start);
     for(int i = 0; i < n; i++){
        colors[i] = WHITE;
        pred[i] = -1;
     }
     colors[start] = GRAY;
     pred[start] = -1;
     while(!q.empty()){
          int current = q.front();
          q.pop();
          for(int i = 0; i < graph[current].size(); i++){
               if(  colors[ graph[current][i] ] == WHITE ){
                    colors[ graph[current][i] ] = GRAY;
                    q.push( graph[current][i] );
                    pred[   graph[current][i] ] = current;
               }
          }
          colors[current] = BLACK;
          //printf("%d ", current);
     }
}

int findPath(int j){
     int count = 1;
     if(pred[j] > -1){
          count += findPath(pred[j]);
     }
     return count;
}

int main(){
    int eLength;
    int vLength;

    printf("|V| = ");
    scanf("%d", &vLength);

    printf("|E| = ");
    scanf("%d", &eLength);

    graph.resize(vLength + 1);
    for(int i = 0; i < eLength; i++){
        int v1;
        int v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
     breadthFirstSearch(1);
     int fp = findPath(vLength);
     printf("%d\n", fp - 1);
    return 0;
}
