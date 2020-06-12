#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;

class Car{
    private:
        string make;
        string model;
        string lp;
        double gas; // this is the amount of gallons left in the tank
        int odometer;
        int eff;
    public:
        Car(string newmake = "(unspecified)", string newmodel = "(unspecified)", string newlp = "N/A", int neweff = 25){
            make = newmake;
            model = newmodel;
            lp = newlp;
            eff = neweff;
            gas = 15.0;
        }
        // freind functions o that we can output the data
        friend ostream& operator<<(ostream& outs, const Car& c);
        void drive() {
            srand(time(NULL));
            int randnum = rand() % 25 + 1;
            odometer += randnum;
            
            if (gas >= 0 ){
                gas-=((double)randnum/(double)eff);
                cout << "drove " << randnum << " miles." << endl;
                cout << gas << " gallons left." << endl;
                cout << endl;
            }
            else {
                cout << "Tank is empty. " << endl;
            }
        }

        void changeLP(string licenseplate){
            lp = licenseplate;
        }
        // getter functions 
        double getGas() const {return gas;}
        int getOd() const {return odometer;}
        string getMake() const {return make;}
        string getModel() const {return model;}
        string getLP() const {return lp;}
        int getEff() const {return eff;}
};

ostream& operator<<(ostream& outs, const Car& c){
    // make an ostream to output...
    outs << "Make: " << c.getMake() << endl;
    outs << "Model: " << c.getModel() << endl;
    outs << "License: " << c.getLP() << endl;
    outs << "Efficiency Rating: " << c.getEff() << endl;
    outs << endl;
    return outs;
}

int main(){
    Car c1;
    cout << c1;
    Car kori("AUDI", "Q7", "IZATRINI", 25);
    cout << kori;

    kori.drive();

}
