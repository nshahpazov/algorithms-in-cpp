#include <stdio.h>
#include <stdlib.h>
struct x{
     int cargo;
};

void quick(struct x *p, int left, int right){
     int i = left;
     int j = right;
     int sentinel = (i + j) / 2;
     struct x temp;
     do{
          while((p + i) -> cargo < (p + sentinel) -> cargo) i++;
          while((p + j) -> cargo > (p + sentinel) -> cargo) j--;

          if(i <= j){
               temp = *(p + i);
               *(p + i) = *(p + j);
               *(p + j) = temp;
               i++;
               j--;
          }

     }while(i <= j);

     if(i < right) quick(p, i, right);
     if(j > left) quick(p, left, j);
}

int main(){
     struct x array[15];
     for(int i = 0; i < 15; i++){
          (array + i) -> cargo = rand() % 15;
          printf("%d ", array[i].cargo);
     }
     quick(array, 0, 15);
     printf("\n");
     for(int i = 0; i < 15; i++){
          printf("%d ", array[i].cargo);
     }

     return 0;
}
