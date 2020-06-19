#include "stringset.h"
#include<string>
#include<iostream>
#include<fstream>

int main(){
    std::string * set = new std::string[4];
    set[0] = "give";
    set[1] = "me";
    set[2] = "a";
    set[3] = "sixty-nine%";
    StringSet kori(set,4);
    std::cout << "StringSet 1: " << kori << std::endl;
    kori[3] = "100%";
    std::cout << "SIIIIIKE";
    kori.add("for");
    kori.add("this");
    kori.add("10/10");
    kori.add("pun");
    std::cout << kori << std::endl;
    kori.remove("give");
    std::cout << "'give' is gone: " << kori << std::endl;
    std::cout << kori.sizeset() << std::endl;
    std::cout << kori.pop() << std::endl;
    std::cout << "Pop from back: " << kori << std:: endl;
    std::cout << kori.sizeset() << std::endl;
    std::string * set2 = new std::string[5];
    set2[0] = "give";
    set2[1] = "I'll";
    set2[2] = "think";
    set2[3] = "about";
    set2[4] = "pun";
    StringSet xinyu(set2,5);
    StringSet qin = kori + xinyu;
    std::cout << "Adding Together: " << qin << std::endl;
    StringSet katz = kori + xinyu;
    std::cout << "Intersection: " << katz << std::endl;
    kori.clear();
    std::cout << "Cleared Function: " << kori << std::endl;
}
