#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int offset = 97;
int occurances[26];

void scan_word()
{
    char c = getchar();
    while(c != '\n'){
        occurances[(int)c - 97] ++;
        c = getchar();
    }
}

int get_middle_count() // -1 no middle, and -2 Impossible
{
    int mid_count = 0;
    for(int i = 0; i < 26; i++)
    {
        if(occurances[i] % 2 != 0){
            mid_count++;
        }
    }
    return mid_count;
}

int get_middle_index() // -1 no middle, and -2 Impossible
{
    int mid_index = -1;
    for(int i = 0; i < 26; i++)
    {
        if(occurances[i] % 2 != 0){
            occurances[i]--;
            mid_index = i;
        }
    }
    return mid_index;
}




void print_right(stack<char> &st){
    for(int i = 0; i  < 26; i++) {
            if(occurances[i] > 0 ){
                for(int j = 0; j < occurances[i] / 2; j++ ){
                    printf("%c", (char)(i + 97)  );
                    st.push( (char)(i + 97) );
                }
            }
    }
}

void print_middle(int i)
{
    if(i != -1)  printf("%c", (char)(i + offset) );
}


void print_left(stack<char> &st)
{
    while(!st.empty()){
        printf("%c", st.top());
        st.pop();
    }
}

int main()
{
    scan_word();

    stack<char> st;

    int mid_count = get_middle_count();
    int mid_index = get_middle_index();
    if(mid_count > 1){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    print_right(st);
    print_middle(mid_index);
    print_left(st);

    printf("\n");
    return 0;
}
