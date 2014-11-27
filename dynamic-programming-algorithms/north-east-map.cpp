#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define n 10
using namespace std;

int map[n][n];
pair<int, int> pred[n][n];
int shortestPath(){
     int v[n][n];
     v[0][0] = -1;
     for(int i = 1; i < n; i++){
          v[0][i] += v[0][i - 1] + map[0][i];
     }
     for(int i = 1; i < n; i++){
          v[i][0] = v[i - 1][0] + map[i][0];
     }

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
               int east = v[i][j - 1] + map[i][j - 1];
               int north = v[i - 1][j] + map[i - 1][j];
               if(east <= north ){
                    v[i][j] = east;
                    pred[i][j].first = i;
                    pred[i][j].second = j - 1;

               }else{
                    v[i][j] = north;
                    pred[i][j].first = i - 1;
                    pred[i][j].second = j;
               }
          }
     }
}

void printPath(int x, int y){
     if(pred[x][y].first == -1){
        return;
     }
     printPath(pred[x][y].first, pred[x][y].second);
     printf("%d ", pred[x][y]);
}

int main(){
     for(int i = 0;i < n; i++){
          for(int j = 0; j < n; j++){
               map[i][j] = rand() % 40;
               printf("%2d ", map[i][j]);

               if((j + 1) % 10 ==0){
                    printf("\n");
               }
          }
     }
     int shortest = shortestPath();
     //printf("shortest path = %d", shortest);
     printPath(n - 1, n - 1);
    return 0;
}
