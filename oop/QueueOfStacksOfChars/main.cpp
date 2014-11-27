#include <stack>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;

typedef stack<char> word;
typedef queue<word> sentance;

void pull(word w){
     if(!w.empty()){
          char c = w.top();
          w.pop();
          pull(w);
          printf("%c", c);
     }
}

void print(sentance s){
     while(!s.empty()){
          word w = s.front();

          pull(w);
          printf(" ");
          s.pop();
     }
}

int main(){
     sentance sent;
     char s[] = "This is a sample string.";
     char* pch = strtok(s, " .");
     while(pch != NULL){
          word wordElement;
          for(int i = 0; i < strlen(pch); i++){
               wordElement.push(pch[i]);
          }
          sent.push(wordElement);
          pch = strtok(NULL, " .");
     }
     print(sent);
     return 0;
}
