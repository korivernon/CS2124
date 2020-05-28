//lecture 2
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<sstream>
#include<vector>
using namespace std;

void demo(){
    // you must include fstream if you want to manipulate files. 
// you can also use a file constructor "ofstream outFile("output.txt");" and this does the same thing 

//you must use "ofstream" in order to write to a file correctly. 
	ofstream outFile;
	ofstream runFile;

	runFile.open("total runs.txt", ios::app);
	runFile << "Program started at: " << time(NULL) << endl;

	ifstream inFile;
	inFile.open("input.txt");
	string filename;
	cout << "Could you give us a filename? ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile) {
		cout << "Bad Filename." << endl;
		cout << "What filename? :";
		cin >> filename;
		inFile.clear(); // clear the fail state so we can see if the next open is successful
		inFile.open(filename);
	}
	
	char c;
	while(inFile >> noskipws >> c)
		cout << c << endl;
/*
	if (!inFile) { // this tests to see if the file is created
		cout << "input.txt does not exist, sorry, please create it" << endl;
		return 1; // end of a program so you return with an error
	}
*/
/*
	// file contents: 1 Kori \n 2 Vernon \n
	int sid;
	string name;
	while (inFile >> sid) {
		// inFile >> name;
		getline(inFile, name); // gets whatever remains on the line after the student ID   
		cout << "Student Name: " << name << " (id: " << sid << ")" << endl;
	}
*/	
/*
	int temp;
	int sum =0;
	int count =0;
	while(inFile >> temp) {
		sum += temp;
		count++;
	}
	
	cout << "The average is " << ((double)sum)/count << endl;
	// this is how you can get a timestamp of the time
*/
/*
	outFile.open("output.csv");
	outFile << "Hello World" << endl;
	for (int i=0; i < 10; i++){
		outFile << "HW " << (i+1);
	}
	outFile << endl;
*/
	runFile << "Program ended at: "<< time(NULL) << endl;
}
void demoDoFunction(){
	string cont;
	do {
		int age;
		cout<< "How old are you?: " << endl;
		cin >> age;
		if (age >= 21){ 
			int contrib;
			cout << "How much can you contribute?: " << endl;
			cin >> contrib;
			if (contrib >= 100)
				cout << "Welcome to the party!" << endl;
			else
				cout << "Get outta here chepaskate" << endl;
        }
		else { 
			cout << "sorry man you're too young" << endl;
	    	cout << "Do you want to continue?: ";
	    	cin >> cont;
    	}
    }while (cont[0] == 'y' || cont[0]=='Y');
}

void demoinFile_forChar(){
    cout << "I work but dont " << endl;
    ofstream runFile;
    ofstream outFile;

    ifstream inFile;
    runFile.open("total runs.txt");
    inFile.open("input2.txt");
    if (!inFile){
        cout << "There is an error with your filename" << endl;
       // return 1;
    }
    char c;
    while (inFile >> c) //while you are still reading into the file
        cout << c << endl;
    runFile << "Program ended at: " << time(NULL) << endl;
}
void demoWhileinFile() {
    ofstream runFile;
    string filename;
    runFile.open("total runs.txt");
    runFile << "Program started at: " << time(NULL) << endl;

    ifstream inFile;
    // prompt for user input
    cout << "What is your filename?: "; 
    cin >> filename; 
    inFile.open(filename);
    
    while (!inFile){
        cout << "filename does not exist";
        cout << "Can you try a different file name?: ";
        cin >> filename;

        inFile.clear();
        inFile.open(filename);
    }
}
void demoVectors(){
    vector<int> v;
    vector<string> vs;
// ranged for loop: "for (int i: v)"
    for (int i=0; i < 10; i++)
        v.push_back(i);
    cout << "First item's value is: " << v[0] << endl;
    cout << "Sixth item's value is: " << v[5] << endl;

    for (int i=0; i < v.size() ; i++)
        cout << "v[" << i << "]= " << v[i] << endl;
    v.resize(5);
    for (int i=0; i < v.size() ; i++)
        cout << "v[" << i << "]" << v[i] << endl; 
    vector<vector<int> > v2;
    v2.resize(10);
    for (int i= 0; i < 10; i++)
        v2[i].resize(10);
/*
    string one = "Daniel";
    string two = "Katz";
    string three = one + two;
*/
}

int func() {
	return 5;
}
string func2() {
	return "Daniel Katz";
}

void func3(int id, string name){
	if (id == 0)
		return; // you can write the key word return but it won't return anything
}
// func4() ????

void func5( int x) {
// pass by value
	x = 100;
}

void func6(int& val) {
// pass by reference
	val = 100; 
}

void func7(vector<int>& v) {
// we are modifing the vector directly
	v.push_back(100);
}
void func8(const vector<int>& v){
	for (int i = 0; i < v.size(); i++)
		cout << "v[" << i << "]=" << v[i] << endl;
}
int main(){
	int id;
	id = func();
    
    demoWhileinFile();
    ofstream runFile;
	string name = func2();
	cout << func() << "\t" << func2() << endl;    
	int x = 10;
	cout << "X before the function call: " << x << endl;
	func6(x);
	cout << "X after the function call: " << x << endl;
	vector<int> v;
	cout << "Size of vector before: " << v.size() << endl;
	func7(v);
	cout << "Size of vector after: " << v.size() << endl;
	func8(v);	
}
