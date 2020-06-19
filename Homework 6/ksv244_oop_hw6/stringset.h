#include<iostream>
#include<fstream>
#include<string>

#ifndef STRINGSET_H
#define STRINGSET_H

class StringSet {
    private:
        std::string *set;
        size_t size,cap;
        void resize(const size_t& newsize); // helper function to resize the array
        bool inset(const std::string& str); // helper function to tell us if an element is inide
    public:
        StringSet(std::string * arr, size_t newsize);
        StringSet():set(new std::string[5]),size(0),cap(5){} //default constructor
        //copy control
        ~StringSet(){delete [] set;}
        StringSet& operator=(const StringSet& self);
        StringSet(const StringSet* self):set(nullptr){*this = self;}
        //pop, and remove, and add functions
        void remove(const std::string& rm); //removing a specific string
        std::string pop() {return set[--size];} // popping from the back
        void add(const std::string& add);
        //overloaded functions
        StringSet operator+(const StringSet& self);
        StringSet operator*(const StringSet& self);
        std::string& operator[](const int i) {return set[i];} //return by value
        std::string operator[](const int i) const {return set[i];} //return by reference
        //clear function
        void clear();
        //return the size of the string set
        int sizeset()const {return (int)size;}
        friend std::ostream& operator<<(std::ostream& outs, const StringSet& ss);
};
#endif
