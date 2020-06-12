//lecture 7
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

class Thing {
    private:
        int x;
    public:
        Thing(int newx) {x = newx;}
        int getx() const {
            return x;
        }
        void setx( int newx) {
            x = newx;
        }
        int& getRefx() {return x;}
};
ostream& operator <<(ostream& outs, const Thing& t){
    outs << t.getx();
    return outs;
}
void func1(Thing obj){
    obj.setx(obj.getx()*2);
}
void func2(Thing& obj){
    obj.setx(obj.getx()*2);
}
void func3(Thing* obj){
    obj = new Thing(obj->getx()*2);
}
/*
void func4(const Thing& obj){
    obj.getx() * 2;
}*/
int& func5(Thing& obj){
    return obj.getRefx();
}
void func6(Thing*& obj){
    // if we want to change the pointer we have to pass it in by ref
    obj = new Thing(obj->getx()*2);
}
void func8(int& x){
    x*=2;
}
void func9(const Thing* obj){
    obj = new Thing(100);
}
void func10(Thing* const obj){
    obj->setx(obj->getx()*2); // fix
}
void arrfunc1(int arr[], size_t size){

}
void resizeArr(int*& arr, int& oldSz, int newSz){
    //arr must be on the heap
    //size is diff from capacity
    int* temp = new int[newSz];
    if (newSz < oldSz){
        for (int i = 0; i < newSz; i++){
            temp[i] = arr[i];
        }
    }else {
        for (int i=0; i < oldSz; i++){
            temp[i] = arr[i];
        }
    }
    delete [] arr; // deletes all of the elements
    arr = temp; // mandates that it must be passed in by reference
    oldSz = newSz;
}

int main(){
    Thing one(10);
    cout << "Thing before func1: " << one << endl; //10
    func1(one);
    cout << "Thing after func1: " << one << endl;

    cout << "Thing before func2: " << one << endl;
    func2(one);
    cout << "Thing after func2: " << one << endl;

    Thing* tptr = &one;
    cout << "Thing before func3: " << *tptr << endl;
    func3(tptr);
    cout << "Thing after func3: " << *tptr << endl;

    cout << "Thing before func6: " << *tptr << endl;
    func6(tptr);
    cout << "Thing after func6: " << *tptr << endl;

    cout << "Thing before func5: " << one << endl;
    // int x = func5(one); --> this will be making a copy instead of referencing the value
    int& x = func5(one);
    int* xptr = &func5(one);
    x*= 2;
    cout << "Thing after func5: " << one << endl;
    cout << "X after func5: " << x << endl;
    cout << "xptr after func5: " << *xptr << endl;
    delete tptr;

    int arr[100]; // stack-dynamic array, fixed size
    arrfunc1(arr, 100);

    int arr2[5];
    arrfunc1(arr2, 5);

    int var = 10;
    int* arr3 = new int[var]; // heap array, variable sized, set at construction.
    // fill arr3
    for (size_t i = 0; i < var; i++){
        arr3[i] = i*10;
    }
    arrfunc1(arr3, 10);

    int ** pptr = new int*(new int(10));
    delete *pptr;
    delete pptr;
    pptr = nullptr;

    /*Also the same as...
    int * ptr = new int(10);
    int ** pptr = new int*(ptr);
    delete * pptr; //-> same as delete ptr;
    ptr = nullptr;
    delete pptr; //-> allowed but causes memory leak
    pptr = nullptr;
     */

}
