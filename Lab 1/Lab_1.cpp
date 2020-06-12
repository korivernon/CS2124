#include<iostream>
#include<string>
#include<algorithm>
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
    srand ((unsigned)time (NULL));
    vector<string> fileVec;
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
        string tmp;
        tmp = temp;
        fileVec.push_back(tmp);
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
    string add = to_string(randNum);    
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

    double getPay() const{
        return hours * payRate;
         
    }
    int getID(){
       return id; 
    } 
    void addHours(int hoursm){
        hours = hours + hoursm;
    }
    string display() const {
        string idStr = to_string(id);
        string totalPayStr = to_string(hours*payRate);
        string retString;
        retString = name + " " + idStr + " " + totalPayStr;
        return retString;
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
        cout << "id = " << name << endl;
        temp.payRate = payRate;
        temp.name = name;
        employeeVec.push_back(temp);
    }
    while(hourly >> id >> hours){
        cout << "hours" << hours << endl;
        for (int i=0; i < employeeVec.size(); i++){
            cout << "id" << employeeVec[i].id << "idnum" << id << endl;
            if (employeeVec[i].id == id){
                cout << "id = " << id << "hours" << hours;
                employeeVec[i].addHours(hours);
            }
        }
    }
}
bool comp(const Employee& a, const Employee& b){
    return a.getPay() > b.getPay();
}
void displayVector(const vector<Employee>& employeeVec){
    for(int i = 0; i < employeeVec.size(); i++){
        cout << employeeVec[i].display() << endl;
    }
}
void sortVec(vector<Employee>& employeeVec){ 
    sort(employeeVec.begin(), employeeVec.end(), comp);
}
void task2(){

    // test code for Task 2
    mathCPP(); 
}
void task3(){

    // test code for Task 3
    cout << "randomPassword(0) = ";
    randomPassword(0);
   
    cout << "randomPassword(1) = ";
    randomPassword(1);
    
    cout << "randomPassword(-4) = ";
    randomPassword(-4);
}

void output(vector<Employee>& employeeVec){
    ofstream out;
    out.open("payroll.txt");
    if (!open){
        cout << "Error " << endl;
    }
    for (int i=0; i < employeeVec.size(); i++){
        out << employeeVec[i].id << "\t" << employeeVec[i].name << employeeVec[i].getPay() << endl;
    }
}
int main(){
    // testcode for Task 4
    vector<Employee> employeeVec;
    readInDataFile(employeeVec);
    cout << "BEFORE: " << endl;
    displayVector(employeeVec);
    cout << "AFTER: " << endl;
    sortVec(employeeVec);
    displayVector(employeeVec);
    cout << employeeVec.size() << endl;
    cout << "Done" << endl;
    output(employeeVec);
}
