#include<iostream>
#include<string>

using namespace std;

class Angle{
    private:
        int degrees,minutes,seconds;
        int totalSeconds; //total seconds to keep track of everything
        void reduce(const int& total); // reduce to simplify
        int getTotal(const int& nd, const int& nm, const int& ns); //get total function to "fix" all values when necessart
        int getTot(const int& nd, const int& nm, const int& ns) const; //this is unecessary because we have totalseconds.. realized much later please disregard
    public:
        Angle(int nd = 0, int nm = 0, int ns = 0);
        Angle(const string& cont);
        void getDataKB();
        //getter functions
        int getDegrees() const{return degrees;}
        int getMinutes() const{return minutes;}
        int getSeconds() const{return seconds;}
        //setter functions
        void setDegrees(const int& nd);
        void setMinutes(const int& nm);
        void setSeconds(const int& ns);
        //overload
        friend Angle operator+(const Angle& self, const Angle& other);
        friend Angle operator-(const Angle& self, const Angle& other);
        
        //comparison
        bool operator==(const Angle& self);
        bool operator<(const Angle& self);
        bool operator>(const Angle& self);
        
        //pre and post increment
        Angle& operator++();
        Angle operator++(int);
        //output function
        friend ostream& operator<<(ostream& outs, const Angle& a);
        //input stream
        friend istream& operator>>(istream& ins, Angle& a);
};
void Angle::setMinutes(const int& nm){
    getTotal(degrees,nm,seconds);
    reduce(totalSeconds);
}
void Angle::setSeconds(const int& ns){
    getTotal(degrees,minutes,ns);
    reduce(totalSeconds);
}
void Angle::setDegrees(const int& nd){
    getTotal(nd, minutes, seconds);
    reduce(totalSeconds);
}
bool Angle::operator<(const Angle& self){
    return totalSeconds < self.totalSeconds;
}
bool Angle::operator>(const Angle& self){
    //cout << this->getTot(degrees, minutes, seconds) << endl;
    //cout << "hi"
    //cout << self.getTot(self.degrees,self.minutes,self.seconds) << endl;
    return self.totalSeconds < totalSeconds;
}
bool Angle::operator==(const Angle& self){
    return self.totalSeconds == totalSeconds;
}
istream& operator>>(istream& ins, Angle& a){
    int x, y, z;
    ins >> a.degrees >> a.minutes >> a.seconds;
    int hold = a.getTotal(a.degrees,a.minutes, a.seconds);
    a.reduce(hold);
    //dd mm yy
    //ins >> a.minutes;
    //ins >> a.seconds;
    return ins;
}
ostream& operator<<(ostream& outs, const Angle& a){
    outs << a.degrees << ":";
    if (a.minutes < 10) outs <<  "0" << a.minutes << ":";
    else outs << a.minutes << ":";
    if (a.seconds < 10) outs << "0" << a.seconds;
    else outs << a.seconds;
    return outs;
}
Angle& Angle::operator++(){
    reduce(getTotal(this->degrees+1,this->minutes,this->seconds));
    return *this;
}
Angle Angle::operator++(int){
    Angle temp(this->degrees,this->minutes,this->seconds);
    reduce(getTotal(this->degrees+1,this->minutes,this->seconds));
    return temp;
}
Angle operator-(const Angle& self, const Angle& other){
    Angle temp;
    // assuming the first is greater than the seconds
    temp.reduce(temp.getTotal(self.degrees-other.degrees,self.minutes-other.minutes,self.seconds-other.seconds));
    return temp;
}
Angle operator+(const Angle& self, const Angle& other){
    Angle temp;
    temp.reduce(temp.getTotal(other.degrees+self.degrees,other.minutes+self.minutes,other.seconds+self.seconds));
    return temp;
}

int Angle::getTot(const int& nd, const int& nm, const int& ns) const {
    //this is redundant and doesn't really make sense... plrease disregard lol
    return nd * 3600 + nm * 60 + ns;
}
int Angle::getTotal(const int& nd, const int& nm, const int& ns){
    //calculate totals and assign that to total seconds
    totalSeconds = nd * 3600 + nm * 60 + ns;
    return totalSeconds;
}
void Angle::reduce(const int& total){
    //take in totals and reduces it to degrees, minutes, and seconds.
    degrees = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = ((totalSeconds % 3600) % 60);
}
Angle::Angle(int nd, int nm, int ns){
    reduce(getTotal(nd,nm,ns));
}
Angle::Angle(const string& cont){
    if(cont[0]=='Y')
        getDataKB();
}
void Angle::getDataKB(){
    //pass in "Yes" to Angle angle("Yes") to get a keyboard input
    string nd,nm,ns;
    cout << "Enter in Degrees: ";
    cin >> nd;
    cout << "Enter in Minutes: ";
    cin >> nm;
    cout << "Enter in Seeconds: ";
    cin >> ns;

    int x = stoi(nd);
    int y = stoi(nm);
    int z = stoi(ns);
    
    minutes = x;
    minutes = y;
    minutes = z;
}

int main() {
    //Angle angle("Yes");
    Angle angle1;
    cin >> angle1;
    cout << "Angle 1: " << angle1 << endl;
    Angle angle2;
    cin >> angle2;
    cout << "Angle 2: " << angle2 << endl;
    
    cout << "Angle 1 + Angle 2: " << angle1 + angle2 << endl;
    cout << "Angle 1 - Angle 2: " << angle1 - angle2 << endl;
    
    cout << "Angle 1 < Angle 2: " << (angle1 < angle2) << endl;
    cout << "Angle 1 == Angle 2: " << (angle1 == angle2) << endl;
    cout << "Angle 1 > Angle 2: " << (angle1 > angle2) << endl;

    cout << "Angle 1++ : " << angle1++ << endl;
    cout << "++Angle 1: " << ++angle1 << endl;
}
