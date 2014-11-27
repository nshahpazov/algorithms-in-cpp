#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

const int MAXN = 200001;
const int MAX_HEIGHT = 220;
const int MIN_HEIGHT = 120;
int n;

int males[MAX_HEIGHT + 1], females[MAX_HEIGHT + 1];
int heights[221];

int main()
{
    scanf("%d", &n);
    int height;
    char gender;
    for(int i = 0; i < n; i++){
        scanf("%d %c", &height, &gender );
        if(gender == 'M') males[height]++;
        else females[height]++;
    }
    int couples_count = 0;
    for (int i = MIN_HEIGHT; i <= MAX_HEIGHT ;i++) {
        if(males[i] > 0 && females[i] > 0) {
            heights[i] = min(males[i], females[i]);
            couples_count += heights[i];
        }
    }
    printf("%d\n", couples_count);
    for (int i = MAX_HEIGHT; i >=  MIN_HEIGHT; i--)
        if(heights[i] > 0) printf("%d %d\n", i, heights[i]);
    return 0;
}
