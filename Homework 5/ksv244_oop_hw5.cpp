#include<iostream>
using namespace std;

class Time{
    private:
        int days;
        int hours;
        int minutes;
        void reduce(const int& total); //reduce function to simplify everything

        int totalMinutes;
    public:
        Time() : days(0), hours(0), minutes(0), totalMinutes(0) {} //init to 0 by init list
        Time(int ndays, int nhours, int nmins) { //take in outside values
            totalMinutes = nmins + nhours*60 + ndays*1440;
            reduce(totalMinutes);
        }
        int getHours() const;
        int getMinutes() const;
        int getDays() const;

        void setHours(const int& nhours);
        void setMinutes(const int& nmins);
        void setDays(const int& ndays);

        int tmin() const {return totalMinutes;}
        //addition subtraction
        Time operator+(const Time& self);
        Time operator-(const Time& self);
        //ostream 
        friend ostream& operator<<(ostream& outs, const Time& t);
        //pre
        Time& operator++();
        Time& operator--();
        //post
        Time operator++(int);
        Time operator--(int);

};
ostream& operator<<(ostream& outs, const Time& t){
    if (t.getHours() == 24)
        outs << "0" << ":";
    else
        outs << t.getHours() << ":";
    if (t.getMinutes() == 60)
        outs << "00";
    else if (t.getMinutes() < 10)
        outs << "0" << t.getMinutes();
    else
        outs << t.getMinutes();
    outs << "(" << t.getDays() << ")";
    return outs;
}
//add
Time Time::operator-(const Time& self){
    Time t;
    t.reduce(this->totalMinutes - self.totalMinutes);
    return t;
}
//sub
Time Time::operator+(const Time& self){
    Time t;
    t.reduce(this->totalMinutes + self.totalMinutes);
    return t;
}
// post
Time Time::operator--(int){
    Time t(this->days,this->hours, this->minutes);
    this->reduce(this->totalMinutes-1); // dec by min
    // cout << *this << endl;
    return t;
} 
Time Time::operator++(int){
    Time t(this->days, this->hours, this->minutes); 
    this->reduce(this->totalMinutes+1); // inc by min
    return t; 
}
//pre
Time& Time::operator++(){
    reduce(totalMinutes+1);//inc by min
    return *this;
}
Time& Time::operator--(){
    reduce(totalMinutes-1); // dec by min
    return *this;
}

void Time::reduce(const int& total){ //reduce function simplifies everything
    totalMinutes = total;
    days = totalMinutes / 1440;
    hours = (totalMinutes % 1440) / 60;
    minutes = ((totalMinutes % 1440) % 60);
    if (totalMinutes < 0){
        days-=1;
        hours+=23;
        minutes+=60;
    }
}
int Time::getHours() const { 
    //reduce(totalMinutes);
    return hours;
}
int Time::getMinutes() const {
    //reduce(totalMinutes);
    return minutes;
}
int Time::getDays() const {
    //reduce(totalMinutes);
    return days;
}
void Time::setMinutes(const int& nmins){
    totalMinutes = days*1440 + nmins + 60*hours;
    reduce(totalMinutes);
}
// -1 0 17
// 0 23 37
void Time::setDays(const int& ndays){
    totalMinutes = ndays*1440 + minutes + 60*hours;
    reduce(totalMinutes);
}

void Time::setHours(const int& nhours){
    totalMinutes = days*1440 + minutes + 60*nhours;
    reduce(totalMinutes);
}

int main() {
    Time t2;
    /*cout << t2.getDays() << endl;
    cout << t2.getHours() << endl;
    cout << t2.getMinutes() << endl;*/
    cout << "t2: " << t2 << endl;
    cout << endl;
    
    Time t3(3,4,5);
    
    /*cout << t3.getDays() << endl;
    cout << t3.getHours() << endl;
    cout << t3.getMinutes() << endl;*/
    //cout << endl;
    cout << "t3: " << t3 << endl;
    cout << endl;

    Time t(-2,24,17); 
    /*cout << t.tmin() << endl;
    cout << t.getDays() << endl;
    cout << t.getHours() << endl;
    cout << t.getMinutes() << endl;*/
    
    cout << "t: " << t << endl;
    cout << endl;
    //cout << "Total Mins before: " << t.tmin() << endl;
    t.setDays(-2);
    //cout << "Total Mins: " << t.tmin() << endl;
    t.setHours(24);
    t.setMinutes(17);
    cout << t.tmin() << endl;
    cout << t.getDays() << endl;
    cout << t.getHours() << endl;
    cout << t.getMinutes() << endl;
    cout << "t: " << t << endl;
    cout << endl;
    Time t4 = t3 + t;
    cout << t3.tmin() << " + " << t.tmin() << endl;
    cout << "t4 = t3 + t: " << t4 << endl << endl;
    cout << "t2++: " << t2++ << endl;
    cout << "++t2: " << ++t2 << endl;
    cout << "--t2: " << --t2 << endl;
    cout << "t2--: " << t2-- << endl;
    //cout << t.tmin() << endl;
}