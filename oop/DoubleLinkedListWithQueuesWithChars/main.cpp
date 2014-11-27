#include <iostream>
#include <queue>
#include <cstdlib>
#include "dllist.cpp"
using namespace std;

double getPositiveSum(queue<double> q){
     double result = 0;
     while(!q.empty()){
          double element = q.front();
          if(element > 0){ result += element; }
          q.pop();
     }
     return result;
}

double getNegativeSum(queue<double> q){
     double result = 0;
     while(!q.empty()){
          double element = q.front();
          if(element < 0){ result += element; }
          q.pop();
     }
     return result;
}

bool isPartitionTo(DLList<queue<double> > dlist, int sentinel){
     dlist.IterStart();
     dlist.IterEnd();

     elem_link2<queue<double> >* forwardPointer = dlist.IterSucc();
     elem_link2<queue<double> >* backwardPointer = dlist.IterPred();
     double positiveSum = 0;
     double negativeSum = 0;
     for(int i = 1; i <= sentinel; i++){
          positiveSum += getPositiveSum(forwardPointer->inf);
          forwardPointer = dlist.IterSucc();
     }
     for(int i = dlist.length(); i > sentinel; i--){
          negativeSum += getNegativeSum(backwardPointer->inf);
          backwardPointer = dlist.IterPred();
     }
     return positiveSum == (negativeSum) * (-1);
}

void isPartition(DLList<queue<double> > dlist){
     for(int i = 1; i < dlist.length(); i++){
          if(isPartitionTo(dlist, i)){
               cout << "There is a partition with sentinel " << i << endl;
               resultFlag = true;
          }
     }
}

int main(){
     DLList< queue<double> > dlist;
     queue<double> q;
     queue<double> q2;

     q.push(3);
     dlist.ToEnd(q);
     dlist.ToEnd(q);
     dlist.ToEnd(q);

     q2.push(-3);
     dlist.ToEnd(q2);
     dlist.ToEnd(q2);
     dlist.ToEnd(q2);

     bool isPart = isPartitionTo(dlist, 3);
     if(isPart){
          cout << "There is a partition\n";
     }
     isPartition(dlist);
     return 0;
}
