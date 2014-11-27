#include <iostream>
#include <stdio.h>
#define MINUS_INFINITY -1000000

using namespace std;

const int MAX = 4001;

void get(int F[], int N, int x){
    for(int i = 0; i < N + 1; i++){
    	if(i - x < 0) F[i] = F[i - 1];
    	else F[i] = 1 + F[i - x];
	}
}

int max_sum[MAX];

void try_x (int i, int a)
{
	if(i - a >= 0)
	{
    	int max_sum_a = 1 + max_sum[i - a];
    	if (max_sum[i] < max_sum_a)
        	max_sum[i] = max_sum_a;
	}
}

int main() {
	int n, a, b, c ;
	cin >> n >> a >> b >> c;

	max_sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
    	max_sum[i] = MINUS_INFINITY;
	}

	for(int i = 1; i <= n; i++)
	{
    	try_x(i, a);
    	try_x(i, b);
    	try_x(i, c);
	}
	cout << max_sum[n] << endl;
	return 0;
}

