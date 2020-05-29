#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

struct Meter{
    double month1kWh;
    int id;
    double util;
};
// ask user for filenames
void loadInFile(vector<Meter> meterVec){
    // declare variables
    ifstream month1;
    ifstream month2;
    string month1file;
    string month2file;
    double kWh;
    int id;
    // prompt user
    cout << "What is your month 1 file? ";
    cin >> month1file;
    cout << "What is your month 2 file? ";
    cin >> month2file;
    
    // attempt to open files
    month1.open(month1file);
    month2.open(month2file);

    while(!month1){
        cout << "Incorrect month 1 file. " << endl;
        cout << "What is your month 1 filename? ";
        cin >> month1file;
        month1.clear();

        month1.open(month1file);
    }

    while(!month2){
        cout << "Incorrect month 2 file. " << endl;
        cout << "What is your month 2 filename? ";
        cin >> month2file;
        month2.clear();

        month2.open(month2file);
    }

    while(month1 >> id >> kWh){
        Meter temp;
        temp.id = id;
        temp.month1kWh = kWh;
        temp.util = kWh;
        meterVec.push_back(temp);
    }
    while (month2 >> id >> kWh){

        for(int i = 0; i< meterVec.size(); i++){
            if (meterVec[i].id == id){
                meterVec[i].util = abs(meterVec[i].month1kWh - kWh);
            }
        }
    }
}
void printUsage(const vector<Meter>& meterVec){
    for(int i=0; i < meterVec.size(); i++){
        cout << meterVec[i].id << "\t" << meterVec[i].util << endl;
    }
}

int main(){
    vector<Meter> meterVec;
    loadInFile(meterVec);
    printUsage(meterVec);

}
