#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
class Person {
    private:
        string name;
        double GPA;
    public:
        Person(string newname = "" , double gpa = 0) : name(newname), GPA(gpa) {}
        string getName() const {return name;}
        double getGPA() const {return GPA;}
        
        void setName(const string & newname) {name = newname; }
        void setGPA(const double & newGPA) {GPA = newGPA;}
};

void openFile(ifstream& inFile){
    
    cout << "What is the name of the file: ";
    string filename;
    cin >> filename;

    inFile.open(filename);

    while (!inFile){
        cout << "Incorrect filename. What is the name of the file: ";
        cin >> filename;

        inFile.clear();
        inFile.open(filename);
    }
}

void loadFile( vector<Person>& v, ifstream& inFile){
    Person temp;
    double gpa;
    string name;
    while (inFile >> gpa){
        temp.setGPA(gpa);
        getline(inFile, name);
        temp.setName(name);
        v.push_back(temp);
    }
}

void firstInClass(){
    vector<Person> v;
    ifstream file;
    openFile(file);
    loadFile(v, file);
    Person first;
    for (int i = 0; i < v.size(); i++){
        if(v[i].getGPA() > first.getGPA()){
            first = v[i];
        }
    }
    cout << "The valedictorian is: " << first.getName() << endl;
}

int main() {
    firstInClass();
}
