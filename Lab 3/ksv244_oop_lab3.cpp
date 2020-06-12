// Kori Vernon
// korivernon@nyu.edu
// Lab 3
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Task 2
// Expected:
// *p1 = 42 (correct)
// *p2 = 42 (correct)
// *p1 = 42 (incorrect)
// --> Because they are pointing to the same place, when we change one,
// we change both! Cool beans. 
// *p2 = 53 (correct)
// *p1 = 88 (correct)
// *p2 = 53 (correct)
//  
// Task 3
// The reason why the code will not compile is when you initialize int* p1,p2;
// only the first value is initialized as an int*. We must change both values
// to reflect that. int* p1,p2 --> int* p1, * p2

// Task 6
void loadArray(int* arr, const int size){
    cout << "Heap Array: {";
    for (int i = 0; i < size; i++){
        if (i != size-1){
            arr[i] = i*i;
            cout << arr[i] << ",";
        }       
        else {
            arr[i] = i*i;
            cout << arr[i];
        }
        
    }
    cout << "}" << endl;
}

void output(char* cstr, int size){
    for (int i = 0; i < size ; i++){
        cout << cstr[i];
    }
    cout << endl;
}
void placecstr(char* cstr, const int& place, const char& chr){
    cstr[place] = chr;
}

void resizecstr(char*& cstr, int& oldsz, const int newsz){
    // we need to account for the two end characters at the end of the cstr
    char * temp = new char[newsz];
    if (newsz-1 < oldsz-1){
        for(int i = 0; i < oldsz; i++){
            temp[i] = cstr[i];
        }
    }
    else {
        for(int i = 0; i < newsz-1; i++){
            temp[i] = cstr[i];
        }
    }
    temp[newsz-1] = '\0'; // end character
    delete [] cstr;
    oldsz = newsz; //passed by reference so I can change size
    cstr = temp;
}

bool isPalindrome(const char* cstr){
   int i = 0;
   int j;
   j = strlen(cstr)-1; // get the length of the string
   // just make a copy and compare...
   cout << "LENGTH: " << j << endl;
   if ((cstr==NULL)|| cstr[0]=='\0')
       return false;
   cout << j << endl;
   while(i < j){
       // this should account for odd numbers as well
       if (cstr[i]!=cstr[j]){
           cout << "inside while" << endl;
           return false; // if at any point in time this is the case then break
       }
       else{
           cout << "iinside while:" << endl;
           i++;
           j--;
       }
   }
   return true;
}
void addcstr(){
    // initialize with term character
    int size = 1;
    char * cstr = new char[size];
    cstr[size] = '\0';
    char cont, chr;
    do {
        cout << "Enter in your character: ";
        cin >> chr;

        resizecstr(cstr, size, size+1);
        placecstr(cstr,size-1, chr);
        
        cout << "Your current word is: ";
        output(cstr, size);
        cout << "Do you want to continue(y/n): ";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
    cout << "Your word is: ";
    output(cstr, size);
    cout << isPalindrome(cstr);
    if (isPalindrome(cstr)==true)
        cout << "Is palindrome." << endl;
    else
        cout << "Is NOT a palindrome." << endl;
}
void resize(int*& arr, int& oldsz, const int newsz){
    int * temp = new int[newsz];
    if (newsz < oldsz){
        for(int i = 0; i < oldsz; i++){
            temp[i] = arr[i];
        }
    }
    else {
        for(int i = 0; i < newsz; i++){
            temp[i] = arr[i];
        }
    }
    delete [] arr;
    oldsz = newsz; //passed by reference so I can change size
    arr = temp;
}
// Task 10
int main(){
    /*
    int* p1,* p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    *p2 = 53;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    p1 = new int;
    *p1 = 88;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    */

    cout << "Task 4: " << endl;

    int a(10);
    int b = 20;
    cout << "a(10): " << a << ", &a: " << &a << endl;
    cout << "b = 20: " << b << ", &b: " << &b << endl;
    int * c;
    c = new int(30);
    cout << "int* c = new int(30): " << c << ", *c: " << *c << endl;

    int * d, e;
    d = new int(30);
    cout << "int* d = new int(30): " << d << ", *d: " << *d << endl;

    e = 50;
    cout << "int e = 50: " << e << ", &e: " << &e << endl;
    int * f;
    f = d;
    cout << "int* f = d: " << f << ", d: " << d << ", *f: "<< *f << ", *d: " << *d << endl; 
    cout << "Task 5: " << endl;

    int* A;
    A = new int(100);
    int * B;
    B = A;

    cout << "The value of A is expected(100): " << *A << endl;
    cout << "A is pointing to the location expected(addrA): " << A << endl;
    cout << "The value of B is expected(100): " << *B << endl;
    cout << "B is pointing to the location expected(AddrA or Addrb): " << B << endl;
    cout << "Returning the memory for A to the heap: " << endl;
    delete A;
    // A = nullptr; 
    //--> this will still print B, but will result in a segmentation fault
    // when we use A.
    
    cout << "The value of A is expected(error?): " << *A << endl;
    cout << "A is pointing to the location expected(error): " << A << endl;
    cout << "The value of B is expected(error?): " << *B << endl;
    cout << "B is pointing to the location expected(error? ): " << B << endl;
    // This will still print *A, A, *B, and B even though we have deleted A.
    
    cout << "Task 6: " << endl;
    int size = 5;
    int * arr = new int[size];
    // I decided to have the display function inside of the loadArray function.
    loadArray(arr, 5);

    cout << "Task 7/8/9: " << endl;
    cout << "Enter in the amount of values that you want in your array: ";
    int newsize;
    cin >> newsize;
    
    resize(arr,size, newsize);
    loadArray(arr, size);
    
    cout << "Task 10: " << endl;
    
    addcstr();
}
