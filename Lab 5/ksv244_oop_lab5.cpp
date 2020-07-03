/*
 * Kori Vernon
 * Lab 5
 * ksv244
*/
#include<iostream>
using namespace std;

class myLocation {
    protected:
        int x,y;
    public:
        myLocation() : x(0),y(0) {cout << "In the no-argument-constructor of myLocation." << endl;}
        myLocation(int newx, int newy) : x(newx), y(newy) {cout << "In the two-argument-constructor of myLocation" << endl;}
        virtual void display() const {cout << "In the display of myLocation. " << endl << "x: " << x << " y: " << y << endl;}
};

class myPoint : public myLocation {
    protected:
        char color;
    public:
        // used a "-" to signify no color
        myPoint(): myLocation() , color('-') {cout << "In the single argument constructor of myPoint" << endl;}
        myPoint(int newx, int newy, char newc) : myLocation(newx,newy),color(newc) {cout << "In the two argument constructor of myPoint" << endl;}
        void display() const {cout << "In the display function of myPoint" << endl << "x: " << x << " y: " << y << " color: " << color << endl;}
        
};

class myCircle : public myPoint {
    private:
        int diameter;
    public:
        myCircle(int x, int y, char c, int d) : myPoint(x,y,c), diameter(d) {cout << "Inside myCircle four-argument-constructor" << endl;}
        myCircle() : myPoint() , diameter(0) {cout << "Inside myCircle no-argument constructor" << endl;}
        void display() const {cout << "x: " << x << " y: " << y << " color: " << color << " diameter: " << diameter << endl;}
};
void menu() {
    char cont;
    int op;

    do{
        cout << "Select your menu option." << endl << endl;
        cout << "1) Display myLocation menu option. " << endl;
        cout << "2) Display myPoint menu option. " << endl;
        cout << "3) Display myLocation pointer to myPoint. " << endl;
        cout << "4) Array of myLocation objects" << endl;
        cout << "5) Array of myLocation objects without pointers" << endl;

        cout << "Option: ";
        cin >> op;

        if (op == 1){
            myLocation temp;
            temp.display();

            myLocation temp2(4,5);
            temp2.display();
        }

        else if (op == 2){
            myPoint temp;
            temp.display();

            myPoint temp2(4,5,'r');
            temp2.display();
        }

        else if (op == 3){
            myLocation * loc;
            myPoint temp;
            loc = &temp;
            loc->display();
            
            myLocation * loc2;
            myPoint temp2(4,5,'r');
            loc2 = &temp2;
            loc2->display();
        }

        else if (op == 4){
            myLocation * theArray[6];
            myLocation temp;
            myLocation temp1(4,5);
            myPoint temp2;
            myPoint temp3(6,9,'p');
            myCircle temp4;
            myCircle temp5(7,23,'y',20);
            theArray[0] = &temp;
            theArray[1] = &temp1;
            theArray[2] = &temp2;
            theArray[3] = &temp3;
            theArray[4] = &temp4;
            theArray[5] = &temp5;
            for (int i = 0; i < 6; i++){
                theArray[i]->display();
            }
            
        }

        else if (op == 5){
            myLocation theArray[6];
            myLocation temp;
            myLocation temp1(4,5);
            myPoint temp2;
            myPoint temp3(6,9,'p');
            myCircle temp4;
            myCircle temp5(7,23,'y',20);
            theArray[0] = temp;
            theArray[1] = temp1;
            theArray[2] = temp2;
            theArray[3] = temp3;
            theArray[4] = temp4;
            theArray[5] = temp5;
            for (int i = 0; i < 6; i++){
                theArray[i].display();
            }
        /* What happened in this code was that only
         * myLocation objects were constructed.
         * Instead of assigning ambiguous 
         * myLocation's which could be filled with
         * derived myLocation objects, strict
         * myLocation containers are allocated, 
         * which can take in derived classes, but
         * "distribute" strictly on the basis on
         * what they're able to take in. 
         */
        }
        cout << "Do you want to continue? (y/n) ";
        cin >> cont;
    } while (cont=='Y' || cont=='y');
}

int main(){
    menu();
}
