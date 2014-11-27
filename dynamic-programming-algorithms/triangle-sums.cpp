#include <iostream>

using namespace std;

const int N = 5;
int tri[N][N + 1] =
{
    {0,7,0,0,0,0},
    {0,3,8,0,0,0},
    {0,8,1,0,0,0},
    {0,2,7,4,4,0},
    {0,4,5,2,6,5},
};

int maxSums[N][N + 1];    // Maximum sum for (i,j)
int path[N][N + 1];    // help array to show the path

int main()
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            maxSums[i][j] = 0;
            path[i][j] = 0;
        }
    }
    maxSums[0][1] = tri[0][1];
    for (int i = 1; i < N; i++ )
    {
        for(int j = 1; j <= i + 1; j++)
        {
            if (tri[i][j] + maxSums[i - 1][j - 1] > tri[i][j] + maxSums[i - 1][j] )
            {
                maxSums[i][j] = tri[i][j] + maxSums[i - 1][j - 1];
                path[i][j] = j - 1;
            }else{
                maxSums[i][j] = tri[i][j] + maxSums[i - 1][j];
                path[i][j] = j;
            }
        }
    }


    int maxResult = maxSums[N - 1][1];     // The maximum required result
    for (int i = 2; i <= N; i++ )
    {
        if(maxResult < maxSums[N - 1][i])
            maxResult = maxSums[N - 1][i];
    }
    cout << maxResult << endl;
    return 0;
}
