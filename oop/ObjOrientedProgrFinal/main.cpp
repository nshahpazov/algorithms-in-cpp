#include <iostream>

using namespace std;

char* copyStr(char *b){
     char *r = new char[strlen(b) + 1];
     strcpy(r,b);
     return r;
}

class Function{

public:
     Function(char * = "f(x)");
     ~Function();
     Function(const Function &);
     Function& operator=(const Function &);
     void setVariableName(char *);
     char *getVariableName() const;
     virtual double evaluate(double) const = 0;

private:
char *variableName;

};

Function::Function(char *name) : name(copyStr(name)) {}

Function::~Function(){
     delete[] variableName;
}

Function::Function(const Function &f) : name(f.name) {}

Function& Function::operator=(const Function &f){
     if(this != &f){
          setVariableName()(f.name);
     }
     return *this; // do not forget!!!
}

void Function::setVariableName(char *n){
     delete[] name; // !!!
     name = copyStr(n);
}

char *Function::getVariableName() const{
     return variableName;
}

class Monomial : public Function{

private:

double k;
unsigned short p;

public:

Monomial(char *, double = 0,unsigned short = 0);
void setK(double);
void setP(unsigned short);
double getK() const;
unsigned short getP() const;
double evaluate() const;


};

Monomial::Monomial(char *name, double koef, unsigned short power) : Function(name), k(koef), p(power) {

}

void Monomial::setK(double kf){
     k = kf;
}

void Monomial::setP(unsigned short pow){
     p = pow;
}

double Monomial::getK() const{
     return k;
}

unsigned short Monomial::getP() const{
     return p;
}

double Monomial::evaluate(double a) const{
     return k * pow(a, p);
}

Monomial* copy(Monomial *m, int length){ // !! Remember it !!
     Monomial *r = NULL;
     if(m != NULL){
          r = new Monomial[length];
          for(int i = 0; i < length; i++){
               r[i] = m[i];
          }
     }
     return r;
}

class Polynomial : public Function{
private:
     int count;
     Monomial *monomials;
     void resize(int);
public:
     Polynomial(char * = "x");
     Polynomial(int c, Monomial *, char * = "x");
     Polynomial(const Polynomial &);
     Polynomial(const Monomial*, char * = "f");
     ~Polynomial();
     Polynomial& operator=(const Polynomial &);

     int getCount() const;
     Monomial operator[](int) const;
     double evaluate(double) const;

     void add(const Monomial &);
     Polynomial operator+(const Polynomial &);
     Polynomial operator-(const Polynomial &);

     void print(ostream&) const;
};

void Polynomial::resize(int size){ // !!NB
     Monomial *m = monomials; // temp pointer, be sure to delete temp after use
     monomials = new Monomial[size];
     if(m != NULL){
          for(int i = 0; i < size; i++){
               monomials[i] = m[i];
          }
          delete[] m; // be sure to delete temp
     }
     count = size;
}

Polynomial::Polynomial(char *name) : Function(name), monomials(NULL), count(0) {}










int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
