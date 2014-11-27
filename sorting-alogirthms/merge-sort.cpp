#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 2000001;

int a[MAXN];
int result[MAXN];
int n;

int* copy(int* start, int* end, int* result)
{
    while(start < end)  *(result++) = *(start++);
    return result;
}

int* merge(int* a, int* a_end, int* b, int* b_end, int* result)
{
    int a_length = a_end - a;   //the end - the beginning pointer

    while(true) {
        if(a == a_end){
            return copy(b, b_end, result);  //if you get the end of a, fills result with the rest of b
        }
        if(b == b_end){
            return copy(a, a_end, result);  //if you get the end of b, fills result with the rest of a
        }
        //fills result with the lesser one
        if(*a <= *b){
            *(result++) = *a++;
        }else{
            *(result++) = *b++;
        }
    }
}

void merge_sort(int* a, int* a_end, int* buf)
{
    int length = (a_end - a);   //the length is the end - the beginning
    if(length <= 1) return;     //recursion's end
    int* middle = a + length / 2;
    merge_sort(a, middle, buf); //merge_sort on the first half until it gets to length <= 1
    merge_sort(middle, a_end, buf); //merge_sort on the second half until it gets to length <= 1
    int* buf_end = merge(a, middle, middle, a_end, buf);    // merges the two parts
    copy(buf, buf_end, a);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, a + n, result);
    for(int i = 0; i < n; i++) cout << result[i] << ", ";
    return 0;
}
