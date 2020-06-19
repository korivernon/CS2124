#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Measurement {
    private:
        int feet;
        int inches;
        int total;
        
        
    public:
        Measurement():feet(0),inches(0){}
        Measurement(int ni);
        int getTot() const {return total;}
        void reduce(const int& tot);
        friend ostream& operator<<(ostream& outs, const Measurement& m);

        //pre and post increment
        Measurement& operator++();
        Measurement operator++(int);

        //Measurement operator+(const Measurement& self);
        //Measurement operator-(const Measurement& self);
        
        
};
/*
Measurement operator+(const Measurement& self){
    Measurement temp;
    tem
}*/
Measurement operator-(const Measurement& self);

Measurement& Measurement::operator++(){
    reduce(getTot()+1);
    return *this;
}
Measurement Measurement::operator++(int){
    Measurement temp(inches);
    reduce(getTot()+1);
    return temp;
}
ostream& operator<<(ostream& outs, const Measurement& m){
    outs << m.feet << "'" << m.inches << '"' << endl;
    return outs;
}
bool operator==(const Measurement& m1, const Measurement& m2){
    return m2.getTot() == m1.getTot();
}
bool operator!=(const Measurement& m1, const Measurement& m2){
    return m2.getTot() != m1.getTot();
}
Measurement operator-(const Measurement& m1, const Measurement& m2){
    Measurement temp;
    temp.reduce(m1.getTot() - m2.getTot());
    return temp;
}
Measurement operator+(const Measurement& m1, const Measurement& m2){
    Measurement temp;
    temp.reduce(m1.getTot() + m2.getTot());
    return temp;
}
void Measurement::reduce(const int& tot){
    total = tot;
    feet = total / 12;
    inches = (total % 12);
    if (total < 0){
        feet -=1;
        if (inches!= 0) inches+=12;
        else feet+=1;
    }
}

Measurement::Measurement(int ni){
    reduce(ni);
}
int main(){
    Measurement m1;
    Measurement m2(24);
    Measurement m3(-12);
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1++: " << m1++;
    cout << "m1: " << m1;
    cout << "++m1: " << ++m1;
    cout << "m1: " << m1;
    
    
    cout << endl;
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1 + m2: " << (m1 + m2);
    cout << "m2 + m3: " << (m2 + m3);
    cout << "m2 - m1: " << (m2 - m1);
    cout << "m1 - m2: " << (m1 - m2);
    
    cout << endl;
    
    cout << "m1 == m2: " << boolalpha << (m1 == m2) << endl;
    cout << "m1 != m2: " << boolalpha << (m1 != m2)<< endl;
    
    cout << endl;
    
    cout << "m2 == m2: " << boolalpha << (m2 == m2) << endl;
    cout << "m2 != m2: " << boolalpha << (m2 != m2) << endl;
}
