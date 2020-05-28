#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Enumerated Datatype is where we list all of the possible values. 
//Think of it as a dropdown datatype that you can choose on a form. 
enum EYE_COLOR {RED, GREY, BLACK, HAZEL, GREEN, BLUE, BROWN, VIOLET};

class Person {
    string name;
    double height;
    int ficoScore;
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
    Person one;
    EYE_COLOR c = HAZEL;
    cout << strEyeColor(c) << endl;
};
