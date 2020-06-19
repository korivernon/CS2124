//lecture 9
#include<iostream>
using namespace std;

class DynArray{ //similar to vector<int>
    private:
        int * data; //array of data
        int cap; //capacity
        int numElements; // size of array
    public:
        DynArray():cap(5),numElements(0),data(new int [5]){}
        //DynArray():data(nullptr){clear();}
        ~DynArray(){delete[] data;}
        DynArray(const DynArray* self):data(nullptr){*this = self;}
       
        int capacity() const {return cap;}
        int size() const {return numElements;}
        int pop_back() {return data[--numElements];}
        int& operator[](const int pos){return data[pos];}//return by val 
        int operator[](const int pos) const { return data[pos]; } //return by ref

        void push_back(int newval);
        void resize(int newsize);
        void clear();
        DynArray operator+(const DynArray& self);
        DynArray operator*(const int mult);
        DynArray operator=(const DynArray& self);

        int* begin() {return data;} //return a pointer and C++ automaticaly deref
        int* end() {return &data[numElements];} 

        const int* begin() const{return data;}
        const int* end() const {return &data[numElements];}
};

DynArray& DynArray::operator=(const DynArray& self){
    if(this == &self)//if self assignment
        return *this;
    delete [] this->data;
    
    this->cap = self.numElements;
    this->data = new int[this->cap];
    this->numElements = self.numElements;
    
    for (int i = 0; i < self.numElements; i++)
        this->data[i] = self.data[i];
   
    return *this;
}

DynArray DynArray::operator*(const int mult){
    DynArray temp;
    temp.resize(mult*numElements);
    for (int i = 0; i < mult; i++){
        for (int j = 0; j < numElements; j++)
            temp.push_back(data[j]);
    }
    return temp;
}

DynArray DynArray::operator+(const DynArray& self){
    DynArray temp;
    temp.resize(numElements+self.numElements);
    for (int i = 0; i < numElements; i++)
        temp.push_back(data[i]);
    for (int i = 0; i < self.numElements; i++)
        temp.push_back(data[i]);
    return temp;
}

void DynArray::push_back(int newval){
    if (cap == numElements)
        resize(cap*2+1);
    data[numElements++] = newval;
}
void DynArray::clear() {
    delete[] data;
    data = new int[5];
    cap = 5;
    numElements = 0;
}
void DynArray::resize(int newsize){
    int * temp = new int[newsize];
    if(newsize>numElements){
        for(int i = 0; i < numElements; i++)
            temp[i] = data[i];
    }
    else{
        for (int i = 0; i < newsize; i++)
            temp[i] = data[i];
        numElements = newsize;
    }
    cap = newsize;
    delete[] data;
    data = temp;
}
class Thing {
    private:
        int* ptr;
    public:
        Thing(int newp=0):ptr(new int (newp)) {}
       
        void setVal(int newval){*ptr = newval;}
        int getVal() const {return *ptr;}

        Thing& operator=(const Thing& self); //assignment
        Thing(const Thing& self); //copy constructor
        ~Thing(){delete ptr;} // destructor
};
Thing::Thing(const Thing& self){
    ptr = nullptr;
    *this = self;
    //Thing t4(t);
}

Thing& Thing::operator=(const Thing& self){
    //Thing t4 = t;
    // *ptr = *self.ptr;
    // return *ptr;
    if (this == &self)
        return *this; // tests for self assignment 
    delete this->ptr;
    this->ptr = new int(*self.ptr);
    return *this;
}

void demo(){
    Thing t;
    //with copy control you delete the same ptr on the heap twice
    Thing t2 = t;
}
int main(){


    for(int i = 0; i < 100000000; i++)
        demo();
    
}
