#include<vector>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;
// Read into students.txt file by asking for a prompt
void loadInFile(ifstream& inFile){
    string filename;

    cout << "What is the name of your file?: ";
    cin >> filename;

    inFile.open(filename);
    while (!inFile){
        cout << "That is the incorrect filename" << endl;
        cout << "Please try a different filename: ";
        cin >> filename;

        inFile.clear();
        inFile.open(filename);
    }
}

// Parse the data and put it into a Student Struct
// Data Represented: "Kori 99 100 Black"
struct Student
    string name;
    int grade1;
    int grade2;
    string race;
};

// Load the data into the student vector
void loadStudent();

void printStudentVec();


int main(){
    
    vector<Student> studentVec;

}
