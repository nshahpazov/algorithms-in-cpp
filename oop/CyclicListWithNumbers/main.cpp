#include <iostream>
#include <stack>
#include "cirlist.cpp"

using namespace std;

bool check(stack<int> s, CirList<int> list){
     elem_cir<int> p = *list.Iter();
     while(p.inf == s.top() && &p){
          //cout << p->inf << " ";
          s.pop();
     }
     return s.empty();
}

int main(){
     CirList<int> numberList;
     stack<int>  numberStack;

     for(int i = 1; i < 20; i++){ numberList.ToEnd(i); }
     int number = 23456;

     while(number != 0){
          numberStack.push(number % 10);
          number /= 10;
     }

     numberList.IterStart();
     elem_cir<int> *p = numberList.Iter();

     while(p){
          p = numberList.Iter();
     }
     return 0;
}
