#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Person {
    string name;
    Person* spouse; //Person pointer
public:
    Person(string newname) : name(newname) {spouse = nullptr;} // nullptr is a location 
    void changeName(string newname){name = newname; }
    bool Marry(Person& p2);
    string getName() const {return name;}
    string getSpouseName()const {return (*spouse).name;}// (*ptr).member == ptr->member
};

bool Person::Marry( Person& p2){
    if (spouse== nullptr & p2.spouse == nullptr){
        spouse = &p2;
        p2.spouse = this;
        return true;
    }
    else
        return false;

}

int main() {

    int x = 20;
    int *ptr = &x;
    cout << x << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    //int ptr is 4 bytes
    int **pptr = &ptr;// this is a pointer TO a pointer
    cout << pptr << endl; //addr of ptr
    cout << **pptr << endl;
    Person a("Daniel");
    Person b("Gloria");
    if (a.Marry(b))
        cout << "WEDDING BELLSSSS" << endl;
    else
        cout << "Um, problem..." << endl;
    a.changeName("John Doe");

    cout << a.getName() << "'s spouse is " << a.getSpouseName() << endl;
    cout << b.getName() << "'s spouse is " << b.getSpouseName() << endl;
}
