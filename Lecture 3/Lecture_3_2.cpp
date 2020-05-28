#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Enumerated Datatype is where we list all of the possible values. 
//Think of it as a dropdown datatype that you can choose on a form. 
enum EYE_COLOR {RED, GREY, BLACK, HAZEL, GREEN, BLUE, BROWN, VIOLET};

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        // you can choose to include the constructor or not. here we are
        // Date() { day = 1; month = 1; year = 1970; } // Default Constructor
        Date(int newday = 1, int newmonth = 1 , int newyear = 1970 ){
            day = newday; 
            month = newmonth; 
            month = newmonth; 
        }
        Date(int newyear){ //if you are just given the year
            day = 1;
            month = 1;
            year = newyear;
        }
        void setYear(int newyear) {year=newyear; }
        void setMonth(int newmonth);
        void setDay(int newday);
        // if you want to make a call to a private variable, 
        // you must use the "const" keyword after the function. 
        int getYear() const {return year;}
        int getMonth() const {return month;}
        int getDay() const {return day;}
};

void Date::setMonth(int newmonth){
    // the scope resolution operator <Class>::<Function>
    if (newmonth < 0 && newmonth <= 12 ){
        month = newmonth;
    } 
}
void Date::setDay(int newday){
    // the scope resolution operator <Class>::<Function>
    if (newday < 0 && newday <= 31 ){
        day = newday;
    } 
}

void printDate(const Date& d){
    cout << d.getYear() << endl;
}
class Person {
    string name;
    double height;
    int ficoScore;
    Date bday;
public:
    Person(string newname ) {name =newname;}
};

string strEyeColor(EYE_COLOR e){
    switch(e){
        //switch is a series of choices .. only used on a char, int, enum, bool 
        case GREY: return "Grey";
            break;
        case BLACK: return "Black";
            break;
        case HAZEL: return "Hazel";
            break;
        case RED: return "Red";
            break;
        case BROWN: return "Brown";
            break;
        case BLUE: return "Blue";
            break;
        case VIOLET: return "Violet";
            break;
        default: return "Huhhh??? "; // this should not be possible
    }
}
int main() {
    Person one("Kori");
    // This cannot be accessed because by default a class is private.
    // one.name("Kori");
    EYE_COLOR c = HAZEL;
    cout << strEyeColor(c) << endl;
};
