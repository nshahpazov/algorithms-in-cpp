#include <iostream>
#include <stdio.h>
using namespace std;

int pipes[12000];
int n;

int separate(int length){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += pipes[i] / length;
    }
    return result;
}

int binarySearch(int value, int low, int high){
    while(low = high){

        int counter = separate(high);

        if(counter < value){
            return binarySearch(value, middle + 1, high);
        }else {
            return binarySearch(value, low, middle - 1);
        }
    }
}

int main()
{
    int result;
    int high = 0;
    int t;
    int k;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        for(int j = 0; j < n; j++){
            scanf("%d", &pipes[j]);
            high += pipes[j];
        }
        high /= k;
        result = binarySearch(k, 0, high);
        printf("%d\n", result);
    }
    return 0;
}
