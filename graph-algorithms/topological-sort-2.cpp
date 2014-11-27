#include <iostream>
#include <stdio.h>
#include <queue>
#include <list>
#define n 100
using namespace std;

enum color{
    WHITE, GRAY, BLACK
};

queue<int> q;
int time = 0;
vector< vector< int> > graph;
vector< vector< int> > transposedGraph;
int d[n];
color colors[n];
int pred[n];
int f[n];
int sortedFS[n];
list<int> l;

void sortFS(){
     for(int i = 0; i < n; i++){
          int max = 0;
          for(int j = i + 1; j < n - 1; j++){
               if(f[max] > f[j]){
                    max = j;
               }
          }
          sortedFS[i] = max;
     }
}


void dfsVisit(int u){
     colors[u] = GRAY;
     d[u] = ++time;
     for(int i = 0; i < graph[u].size(); i++){
          if(colors[graph[u][i]] == WHITE){
               pred[graph[u][i]] = u;
               dfsVisit(graph[u][i]);
          }
     }
     colors[u] = BLACK;
     l.push_front(u);
     printf("%d ", u);
     f[u] = ++time;
}

void depthFirstSearch(){
     for(int i = 1; i < n; i++){
          colors[i] = WHITE;
          pred[i] = -1;
     }
     time = 0;
     for(int i = 1; i < graph.size(); i++){
          if(colors[i] == WHITE){
               dfsVisit(i);
          }
     }
}


void depthFirstSearchOnTransposed(){
     for(int i = 1; i < n; i++){
          colors[i] = WHITE;
          pred[i] = -1;
     }
     time = 0;
     for(int i = 1; i < graph.size(); i++){
          if(colors[i] == WHITE){
               dfsVisit(i);
          }
     }
}

void getSCC(){
     depthFirstSearch();
     depthFirstSearchOnTransposed();

}

int main(){
     int eLength;
     int vLength;

     printf("|V| = ");
     scanf("%d", &vLength);

     printf("|E| = ");
     scanf("%d", &eLength);

     transposedGraph.resize(vLength + 1);
     graph.resize(vLength + 1);
     for(int i = 0; i < eLength; i++){
          int v1;
          int v2;
          scanf("%d %d", &v1, &v2);
          graph[v1].push_back(v2);
          transposedGraph[v2].push_back(v1);
     }
     depthFirstSearch();
     printf("\nTopologicaly Sorted: \n");
     while(!l.empty()){
          printf("%d ", l.front());
          l.pop_front();
     }
     sortFS();
     printf("Reversed finishing time:\n");
     for(int i = 0; i < n; i++){
          printf("%d ", f[i]);
     }
     return 0;
}
