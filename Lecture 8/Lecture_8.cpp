//lecture 8
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

class Fraction {
    int num;
    int denom;

    int gcd(int a, int b) const;
    void reduce();
public:
    Fraction(int newnum=0, int newde=1) : num(newnum), denom(newde) {
        reduce();
    }
    explicit Fraction(double val);
    double getDouble() const {return (double(num)/double(denom));}
    int getNum() const {return num;}
    int getDenom() const {return denom;}
    
    friend istream& operator>>(istream& ins, Fraction& frac);
    friend ostream& operator<<(ostream& outs, const Fraction& f);
    
    Fraction& operator-=(const Fraction& self);
    Fraction& operator+=(const Fraction& self);

    Fraction operator-(const Fraction& self);
    Fraction operator+(const Fraction& self);
    Fraction operator*(const Fraction& self);
    Fraction operator/(const Fraction& self);
/*
    bool operator<(const Fraction& self, const Fraction& other);
    bool operator>(const Fraction& self, const Fraction& other);
    bool operator<=(const Fraction& self, const Fraction& other);
    bool operator>=(const Fraction& self, const Fraction& other);
    bool operator==(const Fraction& self, const Fraction& other);
    bool operator!=(const Fraction& self, const Fraction& other);
*/    
    int& operator*() {return num;}
    int operator*() const {return num;}
    int operator[](const int& val) {return num+val;}
    int operator[](const int& val) const {return num + val;}

    Fraction& operator++(){
        //pre increment returns a pointer
        num += denom;
        return *this;
    }
    Fraction operator++(int){

        Fraction frac(this->num, this->denom);
        num +=denom;
        return frac;
    }
    /*
    Fraction operator-(const Fraction& lhs, const Fraction& rhs){
        Fraction temp(lhs);
        temp -= rhs; //we can reuse code
        return temp;
    }
    */
    
};

bool operator<(const Fraction& self, const Fraction& other){
    return self.getDouble() < other.getDouble();
}
bool operator>(const Fraction& self, const Fraction& other){
    return other < self;
}
bool operator<=(const Fraction& self, const Fraction& other){
    return !(other < self);
}
bool operator>=(const Fraction& self, const Fraction& other){
    return !(self < other);
}
bool operator==(const Fraction& self, const Fraction& other){
    return !(other < self || self < other);
}
bool operator!=(const Fraction& self, const Fraction& other){
    return other < self || self < other;
}
int Fraction::gcd(int a, int b) const {
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void Fraction::reduce() {
    int div = gcd(num, denom);
    num/=div;
    denom /= div;
}
Fraction Fraction::operator/(const Fraction& self){
        Fraction frac;
        frac.denom = this->denom*self.num;
        frac.num = this->num*self.denom;
        frac.reduce();
        return frac;
}
Fraction Fraction::operator*(const Fraction& self){
        Fraction frac;
        frac.num = this->num*self.num;
        frac.denom = this->denom*self.denom;
        frac.reduce();
        return frac;
}
Fraction Fraction::operator+(const Fraction& self){
        Fraction frac;
        if (this->denom != self.denom){
            frac.num = this->denom*self.num + this->num*self.denom;
            frac.denom = this->denom * self.denom;
            return frac;
        }
        frac.num = self.num + this->num;
        frac.denom = self.denom;
        frac.reduce();
        return frac;
}
Fraction Fraction::operator-(const Fraction& self){
        Fraction frac;
        if(this->denom != self.denom){
            frac.num = this->denom*self.num - this->num*self.denom;
            frac.denom = this->denom*self.denom;
            frac.reduce();
            return frac;
        }
        frac.num = this->num - self.num;
        frac.denom = this->denom;
        frac.reduce();
        return frac;
}
Fraction& Fraction::operator-=(const Fraction& self){
        num = num * self.denom - self.num * denom;
        denom *= self.denom;
        reduce();
        return *this;
        //return the object
}
Fraction& Fraction::operator+=(const Fraction& self){
        num = num * self.denom + self.num * denom;
        denom = denom * self.denom;
        reduce();
        return *this;
}
istream& operator>>(istream& ins, Fraction& frac){
    cout << "Numerator: ";
    ins >> frac.num;
    cout << "Denominator: ";
    ins >> frac.denom;
    frac.reduce();
    return ins;
}
ostream& operator<<(ostream& outs, const Fraction& f){
    outs << f.getNum() << "/" << f.getDenom();
    return outs;
}
Fraction::Fraction(double val){
        denom = 1;
        while(val!=floor(val)){
            val*=10;
            denom*=10;
        }
        num = val;
}
// operator overloading
int main(){
    int x = 5;
    int y = 6;
    y = ++x;
    cout << x << endl;
    cout << y << endl; //new value of x;

    x = 5;
    y = x++;
    cout << x << endl;
    cout << y << endl; //original value of x
    cout <<( (x < y) ? y : x ) << endl;
    Fraction f1(5,2);
    Fraction f2(3,4);
   
    Fraction f3 =f1 + f2;
    
    Fraction f5(7,1);
    Fraction f7(2,1);

    cout << "f3 = f1 + f2: " << f3 << endl;
    cout << "++f3: " << f3 << ":" << ++f3 << endl;
    cout << "f3++: " << f3++ << ":" << f3 << endl;
    cout << "f3: " << f3 << endl;
    
    Fraction f4 =f1 - f2;    
    cout << "f4 = f1 - f2: " << f4 << endl;
    
    Fraction f6 = f5 / f7;
    cout << "f6 = f5 / f7: " << f6 << endl;
    
    //  cout << f3.getDouble() << endl;
    
    Fraction f8(5.5);    
    cout << "f8(5.5): " << f8 << endl;
    
    // is x less than y. if it is, then print y, otherwise, print x.
}
