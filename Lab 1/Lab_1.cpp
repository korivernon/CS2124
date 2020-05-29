#include<iostream>
#include<string>

using namespace std;

// task 1
void mathCPP(){
    // declare variables
    int opr1;
    int opr2;
    char op;
    string output;
    int calc;
    // prompt user
    cout << "Enter a mathematical expression: ";
    cin >> opr1 >> op >> opr2;
    // cout << "opr1" << opr1 << "op" << op << "opr2" << opr2;
    // perform operations for ,-,*,1)

    if (op == '/'){
       cout << opr1 << " " << op << " " << opr2 << " = " << (opr1/opr2) << endl;
    }
    else if (op == '+'){
       cout << opr1 << " " << op << " " << opr2 << " = " << (opr1+opr2) << endl;
    } 
    else if (op == '-'){
       cout << opr1 << " " << op << " " << opr2 << " = " << (opr1-opr2) << endl;
    }
    else if (op == '*'){
        cout << opr1 << " " << op << " " << opr2 << " = " << (opr1*opr2) << endl;
    }
}

// task 3

int main(){
    // test code for Task 2
    mathCPP();
}
