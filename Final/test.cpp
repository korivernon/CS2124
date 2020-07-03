
#include<iostream>
#include<vector>
using namespace std;
// i present to you... finesse
class Car {
protected:
    int trainWeight; //stores the weight of the train car
    double cargoWeight;
public:
    Car(int tWeight = 267436, double cWeight = 0) : trainWeight(tWeight), cargoWeight(cWeight) {} // average weight of a locomotive is 121,000 kg
    //Car& operator=(Car const& self){trainWeight = self.trainWeight; cargoWeight = self.cargoWeight; return *this;}
    int getWeight() const {return trainWeight+cargoWeight;}
    int getTrainWeight() const {return trainWeight;}
    double getCargoWeight() const{return cargoWeight;}
    void setTrainWeight(int tw) {trainWeight = tw; }
    void setCargoWeight(double cw) {cargoWeight = cw;}
    virtual void display() const {cout<< "Total Weight: " << getWeight();}
};

class CargoCar: public Car {
private:
    vector<double> packages;
    void adjust();
public: 
    CargoCar(int tWeight = 66000) : Car(tWeight, 0) {} //average weight of a cargo car is 33,000 kg
    void addPackage(double packW){packages.push_back(packW); adjust();}
    void display() const{ cout << "Total Weight: " << getWeight() << " Cargo Weight: " << getCargoWeight();}
    friend ostream& operator<<(ostream& outs, const CargoCar& c);
};
void CargoCar::adjust() {
    double temp = 0;
    for (size_t i = 0; i < packages.size(); i++){
        temp+=packages[i];
    }
    Car::setCargoWeight(temp);
}
ostream& operator<<(ostream& outs, const CargoCar& c){
    outs << "Total Weight: " << c.getWeight() << " Cargo Weight: " << c.getCargoWeight();
    return outs;
}
class PassengerCar: public Car {
private:
    int passenger;
    void adjust();//rawr xD -- this is to adjust my tren
public: 
    PassengerCar(int tWeight = 129727, int passengers = 0) : Car(tWeight, passengers*220), passenger(passengers) {} //average weight of a passenger car is 129,727 kg

    PassengerCar& operator++();
    PassengerCar operator++(int);
    PassengerCar& operator--();
    PassengerCar operator--(int);
    
    // getters and setters
    int getPassengers() const {return passenger;}
    void setPassengers(int pass){passenger = pass;}
    friend ostream& operator<<(ostream& outs, const PassengerCar& c);
    void display() const{  cout << "Total Weight: " << getWeight() << " Passenger Number: " << getPassengers() << " Passenger Weight: " << getWeight();}

};

ostream& operator<<(ostream& outs, const PassengerCar& c){
    outs << "Total Weight: " << c.getWeight() << " Passenger  Number: " << c.getPassengers() << " Passenger Weight: " << c.getWeight();
    return outs;
}
void PassengerCar::adjust() { //this function just helps to adjust the weights of the car
    cargoWeight = passenger*220;
}

PassengerCar& PassengerCar::operator++(){
    passenger += 1;
    adjust();
    return *this;
}
PassengerCar PassengerCar::operator++(int){
    PassengerCar temp(this->trainWeight,this->cargoWeight);
    passenger +=1;
    adjust();
    return temp;
}

PassengerCar& PassengerCar::operator--(){
    if (passenger == 0) return *this; // this is to prevent negative passengers
    passenger -= 1;
    adjust(); // it's honestly beautiful. 10/10
    return *this;
}
PassengerCar PassengerCar::operator--(int){
    PassengerCar temp(this->trainWeight,this->cargoWeight);
    if (passenger == 0) return temp; //this is to prevent negative passengers
    passenger-=1;
    adjust(); // full points ? is that what i hear?
    return temp;
}

template< class T> // using a template to store my trens.. ignore dis.. hehe  rawr xD 
class Train {
private:
    vector<T> train;//definitely not a template
public:
    Train() {vector<T> cars; train = cars;} //is it a Car*... technically it is
    void addCar(T ncar) {train.push_back(ncar);}
    int getTotalWeight() const;
    void display() const;
};
template < class T> 
int Train<T>::getTotalWeight() const{
    int total = 0;
    for (size_t i = 0; i < train.size(); i++){
        total += train[i]->getWeight();
    }
    return total;
}
template <class T>
void Train<T>::display() const {
    for (size_t i = 0; i < train.size(); i++){
        train[i]->display();
        cout << endl;
    }
    cout << "Total Train Weight: " << getTotalWeight() << " Total Cars: " << train.size() << endl; 
}
int main() {
    PassengerCar pcar1;
    PassengerCar pcar2;
    CargoCar ccar1;

    Train<Car*> train; //....... heheh.. if the shoe fits .. we could have a train of people too :) ..how to we know it's a train train.. we should account for that eh?

    train.addCar(&pcar1); train.addCar(&pcar2); train.addCar(&ccar1);

    cout << "Post-Incrementing Pcar1: " << pcar1 << endl;
    cout << "Pre-Incrementing Pcar2: " << ++pcar2 << endl;
    ccar1.addPackage(1500);
    cout << ccar1 << endl;
    cout << endl;

    cout << "First: ";
    train.display();
    pcar1++;
    cout << endl;

    cout << "Second: ";
    train.display();
    
    cout << endl;
    cout << "Third: ";
    pcar1++;
    train.display();
    // but does it work? yes.
    cout << "\nTESTING TOTAL TRAIN WEIGHT -->";
    cout << "Total Train Weight: " << train.getTotalWeight() << endl;
}
