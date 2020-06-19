#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class StringSet {
    private:
        string *set;
        size_t size,cap;
        void resize(const size_t& newsize); // helper function to resize the array
        bool inset(const string& str); // helper function to tell us if an element is inide
    public:
        StringSet(string * arr, size_t newsize);
        StringSet():set(new string[5]),size(0),cap(5){} //default constructor
        //copy control
        ~StringSet(){delete [] set;}
        StringSet& operator=(const StringSet& self);
        StringSet(const StringSet* self):set(nullptr){*this = self;}
        //pop, and remove, and add functions
        void remove(const string& rm); //removing a specific string
        string pop() {return set[--size];} // popping from the back
        void add(const string& add);
        //overloaded functions
        StringSet operator+(const StringSet& self);
        StringSet operator*(const StringSet& self);
        string& operator[](const int i) {return set[i];} //return by value
        string operator[](const int i) const {return set[i];} //return by reference
        //clear function
        void clear();
        //return the size of the string set
        int sizeset()const {return (int)size;}
        friend ostream& operator<<(ostream& outs, const StringSet& ss);
};

StringSet& StringSet::operator=(const StringSet& self){
    if(this == &self)// if self assignment
        return *this;
    delete [] set; // delete current
    cap = self.size; //rewrite with self's elements
    set = new string[cap];
    size = self.size;

    for (size_t i = 0; i < size; i++) //place elements
        set[i] = self.set[i];
    return *this; // return *this
}
bool StringSet::inset(const string& str){
    for(size_t i = 0; i < size; i++ ){
        if(set[i] == str)
            return true;
    }
    return false;
}
StringSet::StringSet(string * arr, size_t newsize){
    string * temp = new string[newsize];
    size = newsize;
    for (size_t i = 0; i < newsize; i++){
        temp[i] = arr[i];
    }
    set = temp;
        /*
    cout << arr[0] << endl; 
    cout << *(&arr+1)-arr << endl;
    cout << sizeof(arr)<< endl;
    cout << &arr[1] << endl;
    cout << &arr+1 << endl;
    printf("Length of arr: %d\n",sizeof(arr)/sizeof(string));
    */
}
StringSet StringSet::operator*(const StringSet& self){
    StringSet temp;
    temp.resize(size+self.size);//go ahead and make the capacity both
    for(int i = 0; i < size; i++)
        temp.add(set[i]); // we can add everything in here, assuming that there will be no duplicates
    for(int i = 0; i < self.size;i++){
        //our add function already accounts for duplicates, but we can take care of them again anyways
        if (!temp.inset(self.set[i]))
            temp.add(self.set[i]);
    }
    return temp;
}
StringSet StringSet::operator+(const StringSet& self){
    StringSet temp;
    temp.resize(size + self.size);
    for(size_t i = 0; i < size; i++)
        temp.add(set[i]);
    for(size_t i = 0; i < self.size; i++)
        temp.add(self.set[i]);
    return temp;
}

ostream& operator<<(ostream& outs, const StringSet& ss){
    outs << "{";
    for (size_t i = 0; i < ss.size; i++){
        if (i != ss.size-1) {cout << ss.set[i] << ",";}
        else {cout << ss.set[i];}
    }
    outs << "}";
    return outs;
}
void StringSet::resize(const size_t& newsize){
    string * temp = new string[newsize];
    if(newsize > size){
        for(size_t i = 0; i < size; i++)
            temp[i] = set[i];
    }
    else {
        for (int i = 0; i < newsize; i++)
            temp[i] = set[i];
    }
    cap = newsize;
    delete [] set;
    set = temp;
}
void StringSet::add(const string& add){
    if (size == cap)
        resize(cap*2);
    if (!inset(add))
        set[size++] = add;
    else
        cout << "String already in set. " << endl;
}
void StringSet::remove(const string& rm){
    if (!inset(rm)) //assuing there will only be one string that we are removing and not multiple --  the first instance of the string will be removed
        cout << "Error: Element does not exist." << endl;
    else {
        bool found = false;

        for (size_t i = 0; i < size-1; i++){
            if (found == true){
                set[i] = set[i+1];
            }
            else if (rm == set[i] && found == false){
                set[i] = set[i+1];
                found = true;
                //decrement the size if found
            }
        }
        if (found == false){
            size--; // if it is the last element
        }
        else {
            set[--size] = set[size-1];
        }
    }
}
void StringSet::clear() {
    delete [] set;
    size = cap = 0; //assuming that nothing will be readded
}
int main(){
    string * set = new string[3];
    set[0] = "ko";
    set[2] = "hi";
    set[1] = "nemo";
    cout << set[1] << set[2] << set[0] << endl;
    StringSet test(set,3);
    cout << test << endl;
    test.add("awesome");
    cout << test << endl;
    cout << test.sizeset() << endl;
    test.remove("ko");
    cout << test << endl;
}
