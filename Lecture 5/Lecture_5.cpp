//lecture 5
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Registration {
    string name;
    double credits;
    double score;
public:
    Registration(string newname, double newcredits, double newscore = 0) : name(newname), credits(newcredits), score(newscore) {}
    Registration(string newname, double newcredits, string grade) : name (newname), credits(newcredits) {setScore(grade);}
    string getName() const {return name; }
    void setScore(string newscore);
    double getCredits() const {return credits;}
    double getScore() const {return score; }
    double getQP() const { return credits * score; }
};
void Registration::setScore(string newscore){
    if (newscore == "A")
        score = 4.000;
    else if (newscore == "A-")
        score = 3.667;
    else if (newscore == "B+")
        score = 3.333;
    else if (newscore == "B")
        score = 3.000;
    else if (newscore == "B-")
        score = 2.667;
    else if (newscore == "C+")
        score = 2.333;
    else if (newscore == "C")
        score = 2.000;
    else if (newscore == "C-")
        score = 1.667;
    else if (newscore == "D+")
        score = 1.333;
    else if (newscore == "D")
        score = 1.000; 
}
class Student {
    string name;
    vector<Registration> reg;
public:
    Student (string newname) : name(newname) {}
    friend ostream& operator<<(ostream& outs, const Student& s);
    string getName() const {return name;}
    void addReg(Registration r) {reg.push_back(r);}
    double calcGpa() const;
};
ostream& operator<<(ostream& outs, const Student& s){
    outs << "Name: " << s.name << endl;
    for (Registration r: s.reg){
        outs << "Course: " << r.getName() << "\tScore: " << r.getScore() << endl;
    }
    outs << "Cumulative GPA: " << s.calcGpa();
    return outs;
}
double Student::calcGpa() const {
    double credits= 0;
    double qpTotal= 0;
    for (Registration r: reg){
        credits += r.getCredits();
        qpTotal += r.getQP();
    }
    if (credits > 0)
            return qpTotal/credits;
    else
        return 0;
}

int main(){
    Student s("John Doe");
    s.addReg(Registration("OOP",4,"A"));
    s.addReg(Registration("Xbox",4,"B"));
    s.addReg(Registration("EG1003",3, "A-"));
    cout << s << endl;
}
