#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<vector>
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
void randomPassword(int choice){
    // variable declaration
    ifstream inFile;
    string random;
    int oneToThree;
    int generateRandom;
    srand (time (NULL));
    vector<int> fileVec;
    string temp;
    int prep;
    int randNum;
   
    // read into file
    inFile.open("2124 Lab1 - 57pwordlist.txt");

    // read into file
    if (!inFile){
        cout << "This is the incorrect filename. " << endl;
    }
    // generate random number 1-3
    oneToThree = rand() % 3 + 1;
    generateRandom = rand() % 57 +1;
    // add passwords 5-7 characters to fileVec
    while(inFile >> temp ){
        fileVec.push_back(temp);
    }
    // choose the generateRandom'th index
    random = fileVec[generateRandom];
    // determine path
    if (choice == 0 ){
        int appOrPrep = rand() % 2 + 1;
        if (appOrPrep == 1){
            choice = -1;
        }
        else {
            choice = 1;
        }
    }
    // get random number
    if (oneToThree == 1 ){
        randNum = rand() % 9;
    }
    else if (oneToThree == 2 ){
        randNum = rand() % 99 + 10;
    }
    else {
        randNum = rand() % 999 + 100;
    }
    // append random number 
    auto add = to_string(randNum);    
    // append to the back
    if (choice > 0){
        // append
        random = random + add;
    }
    else {
        // prepend
        random = add + random;
    }
    cout << "Your randomly generated password is: " << random << endl;
}

// Task 4
struct Employee{
    int id;
    double payRate;
    string name;
    int hours;
    double totalPay;

    double getPay(){
        totalPay = hours * payRate;
        return totalPay;
    }
    int getID(){
       return id; 
    }
};
void readInDataFile(vector<Employee>& employeeVec){
    ifstream data;
    ifstream hourly;
    
    data.open("data.txt");
    hourly.open("hourly.txt");
    int hours;
    int id;
    double payRate;
    string name;
    if(!data){
        cout << "Incorrect data file." << endl;
    }
    if(!hourly){
        cout << "Incorrect hourly file." << endl;
    }

    while(data >> id >> payRate >> name){
        Employee temp;
        temp.id = id;
        temp.payRate = payRate;
        temp.name = name;
        employeeVec.push_back(temp);
    }
    while(hourly >> id >> hours){
        for (int i=0; i < employeeVec.size(); i++){
            if (employeeVec[i].id == id){
                employeeVec[i].hours += hours;
            }
        }
    }
}

void sortAndReturn(vector<Employee>& employeeVec){
    sort(employeeVec.)
}

int main(){
    // test code for Task 2
    mathCPP();
    // test code for Task 3
    cout << "randomPassword(0) = ";
    randomPassword(0);
    cout << endl; 
    cout << "randomPassword(1) = ";
    randomPassword(1);
    cout << endl;
    cout << "randomPassword(-1) = ";
    randomPassword(-1);
    cout << endl;
    readInDataFile();
}
