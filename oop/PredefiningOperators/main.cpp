#include <iostream>
#include <iomanip>
#include <assert.h>
#include <string.h>

using namespace std;

class String{
     friend ostream &operator<<(ostream &, const String &);
     friend istream &operator>>(istream &, String &);
public :
     String(const char * = "");
     String(const String &);
     ~String();
     const String &operator=(const String &);
     const String &operator+=(const String &);
     int operator!() const;
     int operator==(const String &) const;
     int operator!=(const String &) const;
     int operator<(const String &) const;
     int operator>(const String &) const;
     int operator<=(const String &) const;
     int operator>=(const String &) const;
     char &operator[](int);
     String operator()(int, int);
     int getLength() const;
private:
     char *pointer;
     int length;
};

String::String(const char *s){
     length = strlen(s + 1);
     pointer = new char[length];
     strcpy(pointer, s);
}

String::String(const String &other){
     length = other.length;
     pointer = new char[length + 1];
     strcpy(pointer, other.pointer);
}

String::~String(){
     delete[] pointer;
}

 String& operator=(const String &other){
     if(this != &other){
          delete[] pointer;
          length = other.length;
          pointer = new char[length + 1];
          strcpy(pointer, other.pointer);
          return *this;
     }
}

int String::operator!() const{
     return length == 0;
}

int String::operator==(const String &other) const{
     return strcmp(pointer, other.pointer) == 0;
}

int String::operator!=(const String &other) const{
     return strcmp(pointer, other.pointer) != 0;
}

int String::operator<(const String &other) const{
     return strcmp(pointer, other.pointer) < 0;
}

int String::operator<(const String &other) const{
     return strcmp(pointer, other.pointer) > 0;
}

int String::operator<=(const String &other) const{
     return strcmp(pointer, other.pointer) <= 0;
}

int String::operator>=(const String &other) const{
     return strcmp(pointer, other.pointer) >= 0;
}

char &String::operator[](int index){
     return pointer[index];
}

String String::operator(int index, int sublen){
     String sub;
     if(sublen == 0 || (index + sublen > 0) ){
          sub.length = length - index;
     }else{
          sub.length = sublen;
     }

     delete[] sub.pointer;

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
