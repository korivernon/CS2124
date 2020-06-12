//lecture 6
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;
/*
 * Using pointers makes everything more difficult,
 * but there are some things that we cannot do 
 * without pointers.
 */

class Thing {
    public:
        int* ptr;
        double d;
};
class DrSeuss {
    public:
        Thing* thingPtr;
};

void func() {
    int x; //x exists ONLY inside func
}

int* createObject() {
    return new int;
}
void destroyObject(int* obj) {
    delete obj;
}
int main(){
    int x = 10;
    int* ptr = &x;
    // When x is an r-value, we access the value
    // when x is a l-value, we access the memory location
    cout << "*ptr: " << *ptr << endl;
    int **pptr = &ptr;

    Thing one;
    Thing two;

    Thing* thingPtr;
    thingPtr = &one;

    (*thingPtr).d = 5.5;
    thingPtr->d = 5.5;

    one.ptr = ptr;
    cout << "=========Dereferencing" << endl;
    cout << "thingPtr->d: " << thingPtr->d << endl;
    cout << "*one.ptr: " << *one.ptr << endl;
    cout << "*thingPtr->ptr: " << *thingPtr->ptr << endl;

    DrSeuss ds;
    ds.thingPtr = &one;
    DrSeuss* dsptr = &ds;
    /*
     * The arrow de-references the 'thing'
     * on the left.
     */
    cout << "=========Confusing Dereferencing" << endl;
    cout << "dsptr->thingPtr->d: " << dsptr->thingPtr->d << endl; //5.5
    cout << "dsptr->thingPtr->ptr: " << dsptr->thingPtr->ptr <<  endl; //&x
    cout << "*dsptr->thingPtr->ptr: " << *dsptr->thingPtr->ptr << endl; //11

    const int var = 100;
    const int * vptr = &var; // pointer can change, int canot

    int * const constptr = &x; //pointer cannot change, int can change
    *constptr+=1; // we can do this

    const int * const reallyconstptr = &var; // nothing can change;

    cout << "=========Array's" << endl;
    int arr[10]; // an array of ten integers, aka stack dynamic array

    for (int i=0; i < 10; i++){
        arr[i] = i * 10;
    }
    int * arrptr = arr;
    cout << "arrptr[0]=" << arrptr[0] << endl;
    // let's get fancy
    arrptr+=1; //this adds one unit to arrptr
    cout << "arrptr[0]=" << arrptr[0] << endl;
    cout << "arr[100]=" << arr[100] << endl;
    
    cout << "=========Incrementing" << endl;
    arrptr++; //advances to arr[2]
    ++arrptr; //advances the pointer to arr[3]
    cout << "*(arrptr++): " << *(arrptr++) << endl; //increments after
    cout << "*(arrptr): " << *(arrptr) << endl;
    cout << "*(++arrptr): " << *(++arrptr) << endl; // increments before
    cout << "*(arrptr++): " << *(arrptr++) << endl; //increments after
    

    cout << "=========Heap Stuff" << endl;  
    int studentCount;
    cout << "How many students are in this course? ";
    cin >> studentCount;

    // you cannot create an array on the stack with a variable
    // Heap -> separate section of program energy that can grow unlike a stack
    // and doesn't have any limitation except for the program memory
    

   
    // we need pointers to access anything on the heap
    int * heapPtr = new int; // the 'new operator' returns a pointer to be allocated
    /* 
     * When something is created on the heap, you get a pointer to that location
     */
    int * otherptr = heapPtr;
    delete heapPtr;
    // delete otherptr; // you cannot do this
    int *testarr = new int(studentCount);

    cout << "*testarr value:\t" << *testarr << endl;
    delete testarr;
    
  

    int* pointer = new int(10);
    cout << "pointer: " << pointer << endl;
    cout << "*pointer: " << *pointer << endl; // this grabs the value

    delete pointer;

    cout << "pointers value: " << pointer << endl; // this keeps the same value

    cout << "reallocating memory... " << endl;
    pointer = new int(100);

    cout << "pointer: " << pointer << endl;
    cout << "*pointer: " << *pointer << endl; // this grabs the value

    delete pointer;
    pointer = nullptr; // safety measure
    delete pointer;

    // cout << "DEREF NULL: " << *pointer << endl; //this crashes your program
    // you just tried to return to me memory that you don't own
    


}
