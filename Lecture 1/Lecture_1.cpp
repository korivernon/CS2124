//lecture 1
#include<iostream>
#include<string>
using namespace std;

const double PI = 3.1415927; //creation and assignment of values on the global scope
int main(){
    int count = 0;
    while (count < 100 ){
        cout << count << ": Hello world" << endl;
        count++; //often forgotten
    }
    
    for (int count =1; count <=100; count++)
        cout << count << ": Hellow world" << endl;

    string cont = "yes";
    while (cont[0]=='Y' || cont[0]=='y'){
        cout << "What is your age? ";

        int age;
        cin >> age;

        cout << "What do you want to contribute? ";
        double contrib;
        cin >> contrib;

        if(age >= 21 && contrib>=100) {
            cout << "Welcome to the club!" << endl;
        } else if (!(age >= 21)) {
            cout << "You aren't old enough jit" << endl;
        } else {
            cout << "Cheapieee!" << endl;
        }

        cout << "Continue? ";
        cin >> cont;

    }
    
    // cout << "Hello" << " " << "World" << endl;
    // cout << "Second Line!" << endl;
    // int age = INT_MAX;
    // age++; // if there is a possibility that your number exceeds intmax, it will loop around
    // cout << "Age at its highest number: " << age <<endl;
    // double pi = 3.1415927; //creation and assignment of a variable
    // char c = 'D'; // single quote for a character and single quotes for strings

    // cout << "this is a character: " << c << endl;
    // bool torF = true;

    // cout << "this is a boolean: " << torF << endl;
    // string name = "Kori Vernon";
    // cout << "this is a string: " << name << endl;
    // cout << "The area of a circle with radius 2: " << (2 * 2 * PI) << endl;

    // cout << "What is your age? ";
    // cin >> age; //asking for an integer
    // cout << "Your age is: " << age << endl;

    // double amount;
    // amount = age;

    // amount += 0.99999;

    // age = amount;
    
    // cout << "age: " << age << ", amount: " << amount << endl;
    // // amount will "round down" double will "round up"
}

