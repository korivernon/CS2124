#include<iostream>
#include<ctime>
using namespace std;

class Vehicle {
    int * vin;
    double * miles; // bad var name for mileage.. confused me a little
public:
    Vehicle(int * nvin = nullptr, double * nmiles = nullptr) : vin(nvin), miles(nmiles){}
    double calcGasUsed(double nmiles) const;
    double getMiles() const {return *miles;}
    double getVin() const {return *vin;}
    virtual void drive();
    void setMiles(double * nmiles) {miles = nmiles;}
    void setVin(int * nvin) {vin = nvin;} 
};
double Vehicle::calcGasUsed(double nmiles) const{
    return (*miles)/nmiles;
}
void Vehicle::drive() { 
    srand(time(NULL));
    double mmiles = rand() % 25 + 1;
    cout << "(V)Has Driven: " << calcGasUsed(mmiles) << " Miles: " << mmiles << " Per: " << *miles << endl;
    
}
class SUV : public Vehicle {
    bool * status; // fourWDStatus
    double * n4miles;
public:
    SUV(int * nvin = nullptr, double * nmiles = nullptr, bool * nstat = nullptr, double * nn4miles = nullptr) : Vehicle(nvin, nmiles), status(nstat), n4miles(nn4miles) {}
    bool fourWDStatus() const {return *status;}

    void setStatus(bool * stat){status = stat;}
    void set4x4Miles(double * nn4miles){n4miles = nn4miles;}

    bool get4x4Status() const { return *status; }
    double get4x4Miles() const {return *n4miles;}
    
    double calcGasUsed(double nmiles) const;
    void drive();
};
void SUV::drive() {
    srand(time(NULL));
    double mile = rand() % 25 + 1;
    cout << "(S)Has Driven: " << calcGasUsed(mile) << " Miles: " << mile << " Per: " << getMiles() << endl;
}
double SUV::calcGasUsed(double nmiles) const{
    srand(time(NULL));
    if (*status == false){   
        return getMiles()/nmiles;
    } else {
        return *n4miles/nmiles;
    } 
}



int main(){
    Vehicle * vehicleArr[3];
    double m = 40;
    double * miles = &m;
    int v = 123485;
    int * vin = &v;
    bool s = true;
    bool * status = &s;
    bool f = false;
    bool * tstatus = &f;
    double nn = 2;
    double * n4miles = &nn;

    Vehicle temp(vin, miles);
    SUV temp2(vin,miles,status,n4miles);
    SUV temp3(vin,miles,tstatus,n4miles);
    vehicleArr[0] = &temp;
    vehicleArr[1] = &temp2;
    vehicleArr[2] = &temp3;

    for (int i = 0; i < 3; i++){
        vehicleArr[i]->drive();
    }
}
