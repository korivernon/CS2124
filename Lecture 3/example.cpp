#include<iostream>
#include<string>
#include<fstream>
const int YEAR = 2020;

using namespace std;
class JoeyAKAJoseph{
    private:
        int yob;
        int dob;
        int mob;
    public:


        JoeyAKAJoseph(int dayb = 5, int monthb = 5, int yearb = 1970){
            yob = yearb;
            dob = dayb;
            mob = monthb; 
            
            // yob is private, but we can access it inside of the function
        }// default constructor

        // JoeyAKAJoseph() {
        //     yob = 1970;
        //     dob = 1;
        //     mob = 1;
        // }

        // JoeyAKAJoseph(int yearb, int monthb, int dayb){
        //     yob = yearb;
        //     dob = dayb;
        //     mob = monthb;
        // }

        int getAge() {
            return YEAR-yob; 
        }

};

int main(){
    JoeyAKAJoseph joe(5,2000);

    cout << joe.getAge() << endl;
    return 0;
}
