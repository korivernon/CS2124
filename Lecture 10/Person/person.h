//lecture 10
#include<iostream>
#include<string>
// using namespace std;
// a header file does not get compiled directly
#ifndef PERSON_H
#define PERSON_H
class Person {
    private:
        std::string name;
        int age;
        Person* spouse;
    public:
            Person(std::string newname = "") : spouse(nullptr) {name = newname;}
            void setName(std::string newname);
            std::string getName() const {return name;}
            bool isMarried() const {return spouse != nullptr;}
            void printMarriageCert()const;
            bool marry(Person& other);
            void divorce();
};
/*
int main(){
    Person p1("Daniel");
    Person p2("Gloria");
    p1.marry(p2);
}
*/
#endif
