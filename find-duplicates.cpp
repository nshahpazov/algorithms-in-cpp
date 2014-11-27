#include <iostream>
#include <set>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int occ[256];

char* findDuplicates(char* origin, char* mask)
{
    vector<char> vec;
    for(int i = 0; i < strlen(mask); i++) occ[(int)mask[i] ] = 1;
    for (int i = 0; i < strlen(origin) ; i++ )
        if(occ[ (int)origin[i] ]){ vec.push_back( origin[i] ) ;}
    char* result = new char[vec.size()];
    for( int i = 0; i < vec.size() ; i++ ) result[i] = vec[i] ;
    return result;
}

int main(){
    findDuplicates("Nikola", "Svilen");
//    cout << result << endl;
}
