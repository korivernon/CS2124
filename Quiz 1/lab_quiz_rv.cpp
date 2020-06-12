#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Meter {
    int id;
    double reading
};
void openInputFile(ifstream& inFile, string prompt){
    cout << prompt;
    string filename;
    cin >> filename;
    inFile.open(filename);
    while(!inFile){
        cout << prompt;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

void fillVecFromFile(vector<Meter>&, ifstream& inFile){
    Meter tempMeter;
    while (inFile >> tempMeter.id >> tempMeter.reading){
        Meter temp;
    }
}
int findMeter(vector<Meter>& meterVec, int id){
    for (int i=0; i < meterVec.size(); i++){
        if (meterVec[i].id == id)
            return i;
    }
    return -1;
}
void checkMissing(const vector<Meter>& a, const vector<Meter>& b){
    for (int i = 0; i < a.size(); i++){
        if (findMeter(b,a[i].id) < 0);// this is true if the meter's vector is not in b
            cout << a[i].id << " Only has meter reading for one month: " << a[i].reading << " kWh" << endl;
    }
}

void doCalc(const vector<Meter> first, const vector<Meter> second){
    for (Meter m: first){
        int index = findMeter(second, m.id);
        if (index >= 0){
            double diff = abs(m.reading - second[index].reading);
            cout << "Meter" << m.id << " used " << diff << "KWatt hours" << endl;
        }
        else
            cout << m.id << " Only has meter reading for one month: " << m.reading << "kWH" << endl;
    }
}
int main() {
    vector<Meter> firstVec;
    vector<Meter> secondVec;

    ifstream firstFile;
    ifstream secondFile;
    
    openInputFile(firstFile, "What's the name of the first file? ");
    openInputFile(secondFile, "What is the name of the second file? ");

    fillVecFromFile(firstVec, firstFile);
    fillVecFromFile(secondVec, secondFile);

    doCalc(firstFile, secondFile);
}
