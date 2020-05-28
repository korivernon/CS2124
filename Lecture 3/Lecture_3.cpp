//lecture 3
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Student{
    string name;
    vector<int> testScores;
};

void openInputFile(ifstream& inFile){
    cout << "What is the student file name? ";
    string filename;
    cin >> filename;
    inFile.open(filename);

    while (!inFile){
        cout << "Error, bad file name. Try again ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
    
}

void loadStudents(vector<Student>& s){
    ifstream inFile;
    openInputFile(inFile);
    
    string name;
    int grade1;
    int grade2;
    

    while (inFile >> name >> grade1 >> grade2){
        Student stemp;
        stemp.name = name;
        stemp.testScores.push_back(grade1);
        stemp.testScores.push_back(grade2);
        s.push_back(stemp);
    }
}

void printStudent(const Student& s){
    cout << s.name << ": ";
    for (int score : s.testScores){
        cout << score << "\t";
    }
    cout << endl;
}

void printStudentVec(const vector<Student>& s){

    // we are opening a vector of students 
    for (Student s: s){
        printStudent(s);
    }
}
struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    // think of it as a python class if it had nothing in it
    string name;
    double height;
    Date bday;
    Date anniversary;
};

void printDateGood(Date d){
    cout << d.year << "-" << d.month << "-" << d.day;
}

void printPerson(Person p){
    cout << p.name << ": height=" << p.height << ", BDay=";
    printDateGood(p.bday);
    cout << ", Anniversary=";
    printDateGood(p.anniversary);
    cout << endl;
}
void pop_front(vector<int>& v){
    for(int i=0; v.size() -1; i++ ){
        v[i] = v[i+1]; //set the element to equal the element in the front
    }
    v.pop_back(); //remove the last element
}
void demoChangeCapacity(){
    // initialize vector 
    vector<int> v;
    // fill vector by multiplying i*10 --> no particular reason
    for (int i=0;i < 100; i++){
        v.push_back(i*10);
        cout << "v.size()= " << v.size() << "\t" << "v.capacity()= " << v.capacity() << endl;
    }
    v.resize(0); // the size changes to 0 but the capacity DOES NOT change
    cout << "RESIZE OPERATION: v.size()= " << v.size() << "\t" << "v.capacity()= " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "SHRINK TO FIT: v.size()= " << v.size() << "\t" << "v.capacity()=" << v.capacity() << endl;
    while(!v.empty()){
        pop_front(v);
    }
     cout << "POPFRONT: v.size()= " << v.size() << "\t" << "v.capacity()=" << v.capacity() << endl;
}
int main() {
    demoChangeCapacity();

    // Person Testcode
    cout << "Person Testcode: " << endl;
    Person p1;
    p1.name = "Kori Vernon";
    p1.height = 165;
    p1.bday.day = 23;
    p1.bday.month = 7;
    p1.bday.year = 2000;

    p1.anniversary.day = 3;
    p1.anniversary.month = 7;
    p1.anniversary.year = 2025;
    printPerson(p1);
    // Student Testcode
    cout << "Student Testcode: "<< endl;
    vector<Student> studentsInClass;
    loadStudents(studentsInClass);
    printStudentVec(studentsInClass);

}
