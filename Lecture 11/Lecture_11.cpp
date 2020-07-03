//lecture 11
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
class Person {
    string name;
public:
    Person(string newname = "") : name(newname) {}
    string getName() const {return name; }

};
ostream& operator<<(ostream& outs, const Person& p){
    outs << p.getName();
    return outs;
}
template<class T>
void mySwap(T& first, T& second){
    T temp = first;
    first = second;
    second = temp;
}

template<class T>
class myClass { // when you add a template modifier, it is now named myClass <T>
    T data;
public:
    myClass(T newdata = T()); //pass in a default
    void printVal() const;
};
template <class T>
myClass<T>::myClass(T newdata){
    data = newdata;
}

template <class T>
void myClass<T>::printVal() const {
    cout << data << endl;
}

// emptyvec error

class EmptyVectorError {};

template<class T> 
class Vector {
    size_t cap, num;
    T* data;
public:
    Vector(): cap(5), num(0), data(new T[5]) {}
    virtual ~Vector();
    Vector(const Vector<T>& self):data(nullptr),cap(0), num(0) {*this = self;}
    Vector<T>& operator=(const Vector<T>& self);

    size_t size() const { return num; }
    size_t capacity() const {return cap;}
    size_t min(T first, T second) const;
    
    T* begin(){return data;}
    const T* begin() const {return data;}
    T* end(){return &data[num];}
    const T* end() const {return &data[num];}

    void push_back(const T& val);
    void clear();
    T pop_back();
    void resize(size_t newsize);
    T operator[](int pos)const {return data[pos];}
    T& operator[](int pos) {return data[pos];}
};
template<class T>
size_t Vector<T>::min(T first, T second) const{
    if (first < second) return first;
    return second;
}
template<class T>
void Vector<T>::resize(size_t newsize){
    T* temp = new T[newsize];
    num = min(num, newsize);
    for (size_t i = 0; i < num; i ++)
        temp[i] = data[i];
    cap = newsize;
    delete[] data;
    data = temp;
    // temp = nullptr; line 113??
}

template<class T>
void Vector<T>::clear() {
    delete [] data;
    cap = 5;
    num = 0;
    data = new T[cap];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& self){
    if (this == &self) return *this;
    delete [] data;
    cap = self.num;
    num = self.num;
    data = new T[cap];
    for (size_t i = 0; i < num; i++){
        data[i] = self.data[i];
    }
}

template<class T>
void Vector<T>::push_back(const T& val){
    if (cap == num) resize(cap*2);
    data[num++] = val;
}

template<class T>
T Vector<T>::pop_back() {
    if (num == 0) throw EmptyVectorError();
    return data[--num];
}
/*
template<class T>
Vector<T>::Vector(){
    cap = 5;
    num = 0;
    data = new T[cap];
}
*/
int main(){
    myClass<int> one(100);
    myClass<string> two("Daniel");
    myClass<Person> three(Person("Daniel"));
    
}
