#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

// you can do this with const reference
bool isInVector(vector<int>& v, int target){
    for(int i=0; i < v.size(); i++){
        if (v[i] == target){
            // w return true if we find the target
            return true;
        }
    }
    // we return false if we dont ever find the target
    return false;
}
// pass the v in with const ref b/c we aren't changing it
// signed int -2.1billion - 2.1billion
// unsigned int 0 to 4.2 billion
void makeUnique(vector<int>& v, vector<int>& noDups){
    for (int i=0; i < v.size(); i++){
        if (!isInVector(noDups,v[i])){
            // if v[i] is not present in noDuplicate
            noDups.push_back(v[i]);
        }
    }
}
/*
 void openFile(ifstream& inFile){
    string filename;
    cout << "enter in a filename";
    cin >> filename;
    inFile.open(filename);
    while (!inFile){
        cout << "incorrect file name";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
 }
 */
void fillVectFromFile (vector<int>& v){
    // declare variables
    string filename;
    ifstream inFile;
    int temp;

    // collect input
    cout << "Please enter a filename: ";
    cin >> filename;

    inFile.open(filename);

    while (!inFile){
        cout << "That is the incorrect filename, please try again. " << endl;
        cout << "Please enter a filename: ";
        cin >> filename;
        
        // clear the current 
        inFile.clear();
        
        // try to reopen the file
        inFile.open(filename);
    }
    // if we successfully make it into the file
    while (inFile >> temp){
        // push_back the results into the file
        v.push_back(temp);
    }
}
/*
   fillVectFromFile(vector<int>& v){
   ifstream inFile;
   openInputFile(inFile);
   int temp;
   while (infile>> temp);
        v.push_back(temp);
   }
 */
void getIntsFromFile () {
    // variable declaration
    ofstream outFile;
    vector<int> clean;
    vector<int> v;
    // pass to function
    fillVectFromFile(v);
    // clean the file
    makeUnique(v,clean);
    // start ofstream
    outFile.open("uniq_ints.txt");
    if (!outFile){
        cout << "Error opening file. " << endl;
    }
    for(int i=0; i<clean.size(); i++){
        // output the results to the file
        outFile << clean[i] << endl;
    }
    // message prompting where the file is going to be located. 
    cout << ">> Please check file named: 'uniq_ints.txt' in directory." << endl;
}

void printVec(const vector<int>& v){
    // this prints the vector in a readable format
    cout << "[";
    for (int i=0; i<v.size(); i++){
        if (i != v.size()-1)
            cout << v[i] << ",";
        else
            cout << v[i];
    }
    cout << "]" << endl;
}

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(8);
    v.push_back(7);
    v.push_back(2);
    v.push_back(9);
    v.push_back(1);
    cout << ">> original vector: ";
    printVec(v);
    cout << "Is 8 present?: " << isInVector(v,8) << endl;
    cout << "Is 0 present?: " << isInVector(v,0) << endl;
    cout << "Is 9 present?: " << isInVector(v,9) << endl;
    // test for make unique
    vector<int> v2;
    makeUnique(v,v2);
    cout << ">> original vector: ";
    printVec(v);
    cout << ">> cleaned vector: ";
    printVec(v2);
    // test for fill vector from file
    vector<int> v3;
    fillVectFromFile(v3);
    cout << ">> uncleaned vector from file: ";
    printVec(v3);
    // test for combination file
    getIntsFromFile();
}
