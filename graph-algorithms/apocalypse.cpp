#include <stdio.h>
#include <iostream>

#include <set>
using namespace std;

const int MAXN = 150001;

int n, m;
set< pair<int, int> > cities_set;
bool used[MAXN];
int cities[MAXN];

void f_operation(){
    if(cities_set.empty() ) printf("-1\n");
    else{
        int current_height = cities_set.begin()->first;
        int current_index = cities_set.begin()->second;
        printf("%d %d\n", current_index, current_height);
        cities_set.erase(cities_set.begin() );
        used[current_index] = true;
    }
}

void s_operation()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if( !used[a] ){
        cities_set.erase(cities_set.find(make_pair(cities[a], a) ) );
        cities[a] -= b;
        cities_set.insert(make_pair(cities[a], a) );
    }
}

void scan_cities()
{
    int height;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &height);
        cities_set.insert( make_pair(height, i) );
        cities[i] = height;
    }
}

int main(){
    scanf("%d", &n);
    scan_cities();
    scanf("%d", &m);
    char c[4];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", &c);
        if(c[0] == 'F') f_operation();
        else s_operation();

    }
    return 0;
}
