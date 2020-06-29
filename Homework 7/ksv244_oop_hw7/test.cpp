#include<ctime>
#include<iostream>
using namespace std;



void randomize() {
    srand(time(NULL));
    for (int i = 0; i < 20; i++){
        
        
        int location = rand() % 399 + 0; // random number between 399 and 0
        
        cout << location << endl;
    }
}

int main(){
    randomize();
}