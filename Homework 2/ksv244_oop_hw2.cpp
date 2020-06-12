#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Measurement {
    private:
        int inches;
        int feet;
    public:
        Measurement( int inch = 0 ){
            if ( inch >= 0 ){
                feet = (inch/12);
                inches = (inch%12);
            } else{
                feet = -1+(inch/12);// we need to figure this out...
                if (inch%12!=0)
                    inches = 12-(-inch%12);
                else
                    inches = 0;
                
            }
            }
        int getInches() const{
            return inches;
        }
        int getFeet() const{
            return feet;
        }
        friend ostream& operator<<(ofstream& outs, const Measurement& m);

};

ostream& operator<<(ostream& outs, const Measurement& m){
    if (m.getFeet() != 0){
        outs << m.getFeet() << " feet, " << m.getInches() << " inches";
    }
    else {
        outs << m.getInches() << " inches";
    }
    return outs;
}
int main(){
    Measurement  m(10);
    cout << "m(10) = "<< m << endl;
    Measurement m2(5);
    cout << "m2(5) = " << m2 << endl;
    Measurement m3(-12);
    cout << "m3(-12) = " << m3 << endl;
    Measurement m4(-5);
    cout << "m4(-5) = " << m4 << endl;
    Measurement m5(15);
    cout << "m5(15) = " << m5 << endl;
    Measurement m6;
    cout << "default constructor = " << m6 << endl;
}
