// #include<string>
// #include<iostream>
#include "person.h"

using namespace std;
//std --> where there exists any ambiguity, use standard
void Person::setName(string newname){
    name = newname;
}
bool Person::marry(Person& other){
    if (spouse== nullptr){
        spouse = &other;
        return true;
    }
    return false;
}
