#include <iostream>
#include <fstream>
#define NAMESIZE 200
#define DESCRSIZE 200
using namespace std;



struct product{
     char name[NAMESIZE];
     int code;
     double price;
};

void createFile(){
     fstream pf("products.dat", ios::in|ios::binary);
     ifstream cf("codes.txt", ios::in);
     ofstream rf("codeReport.txt", ios::out);
     product p;
     int code;
     double average = 0;
     int count = 1;
     char description[DESCRSIZE];
     while(cf >> code >> description){
          pf.seekg(0);
          rf << code << " ";
          while( pf.read((char*)&p, sizeof(product)) ){
               if(p.code == code){
                    rf << p.name << " ";
                    count++;
                    average += p.price;
               }
          }
          average /= count;
          rf << average << " " << description << endl;
     }

     pf.close();
     cf.close();
     rf.close();
}

createPro

int main(){
     pr
     cout << "Hello world!" << endl;
     return 0;
}
