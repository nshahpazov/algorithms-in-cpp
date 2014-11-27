#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define NAMESIZE 24

using namespace std;
char buffer[NAMESIZE];

struct person{
     int key;
     char name[NAMESIZE];
};

void insertionSort(int a[], int n){
     for(int i = 0; i < n; i++){
          int x = a[i];
          int j = i;
          while(j > 0 && x < a[j - 1] ){
               a[j] = a[j - 1];
               j--;
          }
          a[j] = x;
     }
}

template <typename T>
void insertionSort(fstream& f, T dummy){
     T x, y, z;
     f.seekg(0, ios::end);
     int n = f.tellg() / sizeof(T);
     for(int i = 0; i < n; i++){
          int j = i;

          f.seekg(i * sizeof(T));       f.read((char*)&x, sizeof(T));
          f.seekg((j - 1)* sizeof(T));  f.read((char*)&y, sizeof(T));
          while(j > 0 && x > y){
               f.seekp(j * sizeof(T));  f.write((const char*)&y, sizeof(T));

               j--;
               f.seekg((j - 1)* sizeof(T));  f.read((char*)&y, sizeof(T));
          }
          f.seekp(j * sizeof(T)); f.write((const char *)&x, sizeof(T));
     }
}

template <typename T> void selectionSort(fstream& f, T dummy){
     f.seekg(0, ios::end);
     int n = f.tellg() / sizeof(T);
     f.seekg(0, ios::end);
     T min;
     T x, y;
     for(int i = 0; i < n - 1; i++){
          int k = i;
          f.seekg(i * sizeof(T));
          f.read((char*)&min, sizeof(T));
          for(int j = i + 1; j < n; j++){
               T current;
               f.seekg(j * sizeof(T));
               f.read((char*)&current, sizeof(T));
               if(current < min){
                    min = current;
                    k = j;
               }
          }
          f.seekg( i * sizeof(T) );  f.read( (char*)&x, sizeof(T));
          f.seekg( k * sizeof(T) );  f.read( (char*)&y, sizeof(T));

          f.seekp( i * sizeof(T) );  f.write( (const char*)&y, sizeof(T) );
          f.seekp( k * sizeof(T) );  f.write( (const char*)&x, sizeof(T) );
     }
}

template <typename T> void print(fstream& f, T dummy){
     T element;

//     long n = f.tellg() / sizeof(T);
     while(f.read( (char*)&element, sizeof(T) ) ){

          cout << element << " ";
     }
     cout << endl;
}

void seekCharsInFile(){
     ifstream file("text.txt", ios::in);
     if(!file){
          cerr <<"File open Error\n";
          exit(1);
     }
     int i = 0;
     while(!file.eof()){
          file.seekg(i);
          char c;
          file.get(c);
          cout << i << " = " << c << endl;
          i++;
     }
     file.close();
}

void createSimpleTextFile(){
     ofstream file("text.txt", ios::app);
     if(!file){
          cerr << "Error opening file\n";
          exit(1);
     }
     cout << "Enter a name: ";
     while(cin.getline(buffer, 32)){
         cout << "Enter a name: ";
         file << buffer << endl;
     }
     file.close();
}

void openSimpleTextFile(){
     ifstream file("text.txt", ios::in);
     if(!file){
          cerr << "Error opening file\n";
          exit(1);
     }

     while(file.getline(buffer, 32)){
          cout << buffer << endl;
     }
     file.close();
}

int main(){
     fstream f("pom.dat", ios::out|ios::binary);

     for(int i = 0; i < 30; i++){
          int number = 30 - i;
          f.seekp( i * sizeof(int) );
          f.write( (const char*)&number, sizeof(int) );
     }
     f.close();

     int dummy;
     f.open("pom.dat", ios::in|ios::out|ios::binary);
     insertionSort(f, dummy);
     //selectionSort(f, dummy);
     f.close();

     f.open("pom.dat", ios::in|ios::out|ios::binary);
     print(f, dummy);
     f.close();
     return 0;
}

