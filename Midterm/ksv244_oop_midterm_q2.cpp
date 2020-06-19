#include<iostream> // cout, endl, etc..
#include<vector> // vector needed to iterate through our vector of students
#include<fstream> // fstream needed for ifstream
#include<string> // string needed for name

using namespace std;

class Person {
    private:
        string name;
        double GPA;
    public:
        Person(const string& newname = "" , double gpa = 0) : name(newname), GPA(gpa) {}
        // using initialization list and default constructor 
        // we set gpa to 0.0, assuming that there will always be a greater gpa --> helps later in the function 
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
        temp.setGPA(gpa); // reading into the file, then setting the temp gpa to the gpa we are reading in
        getline(inFile, name); // getting the rest of the line so we can read in "2.981 U A B Kori's Awesome"
        temp.setName(name); // we set the name to the name we get from the remainder of the line
        v.push_back(temp); // push back temp and we start over again
    }
}

void firstInClass(){
    vector<Person> v;
    ifstream file; //creating ifstream file
    openFile(file); //passing file to grab our filename and
    loadFile(v, file); // passing file to open and grab information from it
    Person first; // creating person who's gpa will be 0.0 -> we assume that there will always be a higher gpa
    for (int i = 0; i < v.size(); i++){
        // here we are iterating through the GPAs to see who has the highest. if we find a gpa
        // that is higher, we have that person become our first Person.
        if(v[i].getGPA() > first.getGPA()){
            first = v[i];
        }
    }
    cout << "The valedictorian is: " << first.getName() << endl;
    // return the name of the first person
}

int main() {
    firstInClass();
}
