//lecture 4
#include<iostream>
#include<fstream>
#include <vector>
#include <vector>
using namespace std;

class A {
    private:
        int x;
    public:
        A(int newx) {x = newx; } // non-default constructor
};

class B {
    private:
        A a;
        double d;
        char c;
    public:
        B(int x = 100) :a(x), d(5.5) /* member initialization list*/ {c = 'A'; cout << d << endl;}
        // first initialized then assigned a value
};

class C {
    public:
        C() { cout << "We're in C's constructor!" << endl; }
};

class D {
    C c;
    public:
        D(){cout << "We're in D's constructor!" << endl;}
};

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        void setYear(int newyear) {year = newyear; }
        void setDay(int newday){ if (newday >0 && newday < 31) day = newday; }
        void setMonth(int newmonth){if (newmonth > 0 && newmonth < 12) month = newmonth;}
        int getDay() const {return day;}
        int getMonth() const {return month;}
        int getYear() const {return year;}
};

class Person {
    string name;
    int age;
    public:
        class SerialNumber{
            private: // xxx-xx-xxxx
                string pt1;
                string pt2;
                string pt3;
        };
        //  Person(string name): name(name){ age=0; }
        Person(string newname) : name(newname) {age =0; }
        string getName() const {return name;}
        int getAge() const {return age;}
        void happyBirthday() {age++;}
        // to get over the private limitation, use friend
        friend ostream& operator<<(ostream& outs, const Person& p);
};

ostream& operator<<(ostream& outs, const Person& p){
    outs << "name: " << p.getName() << "\tAge:" << p.getAge();
    return outs;
}
int main(){
    A a(100);
    D d;
    cout << "=====" << endl;
    B b; // system provided default constructor
    Person p("Daniel Katz");
    cout << p << endl;
}

