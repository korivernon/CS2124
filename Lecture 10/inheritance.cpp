#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class C {
    public:
        C() { cout << "C's Constructor " << endl; }
};
class A {
    private:
        C cInA;
    public:
        A(int val = 0){cout << "A's constructor" << endl;}
};
class B:public A {
    private:
        C c;
    public:
        B():A(100) {cout << "B's constructor" << endl;}
};
class Pet {
    private:
        string name;
        int age;
    public:
        Pet(const string newname = "") : name(newname) , age(0) {}
        void setName(const string newname) {name = newname;}
        string getName()const {return name;}
        void setAge(const int& newage) {age = newage;}
        int getAge() const {return age;}
        Pet& operator++() {age++; return *this;}
        Pet operator++(int);
};

class Dog: public Pet {
//constructors are not inherited --> private restrictions are still in place
    private:
        int barkVolume;
    public:
        Dog(const string newname = "" ) : Pet(newname),barkVolume(3) {}
        void setBarkVolume(int val) {barkVolume = val;}
        void speak() const;
        void setName(string newname);
        Dog& operator++();
        Dog operator++(int);
};
Dog& Dog::operator++(){
    barkVolume++;
    Pet::operator++();
    return *this;
}
Dog Dog::operator++(int){
    Dog temp = *this;
    barkVolume++;
    Pet::operator++(0);
    return temp;
}
void Dog::setName(string newname){
    barkVolume = 3;
    Pet::setName(newname);
}
/*
void Dog::setBarkVolume(int val){
    barkVolume = val;
    if (barkVolume >= 5){
        string newname = getName();
        char* temp = new char[newname.length()+1];
        strcpy(temp, newname.c_str());
        newname = strupr(temp);
        delete [] temp;
    } else {
        string newname = getName();
        char* temp = new char[newname.length()+1];
        strcpy(temp, newname.c_str());
        newname = strlwr(temp);
        delete [] temp;
    }
}
*/
void Dog::speak() const {
    string phrase;
    if (barkVolume <= 3)
        phrase = "Woof";
    else if (barkVolume <= 5)
        phrase = "WOOF";
    else
        phrase = "HOOOOOOWLLLLL";
    cout << phrase << endl;
}

ostream& operator<<(ostream& outs, const Dog& d){
    outs << "Dog Name: " << d.getName() << "\tAge: " << d.getAge() <<  endl;
    return outs;
}
ostream& operator<<(ostream& outs, const Pet& p){
    outs << "Pet Name: " << p.getName() << "\tAge: " << p.getAge();
    return outs;
}
Pet Pet::operator++(int){
    Pet temp = *this;
    age++;
    return temp;
}

int main() {
    Dog spike("Spike");
    spike.setBarkVolume(6);
    cout << spike;
    Pet fido("fido");
    fido++;
}
