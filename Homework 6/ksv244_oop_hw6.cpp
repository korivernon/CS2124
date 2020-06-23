#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class StringSet {
    private:
        // double weight; // kg -> 90.9
        // int dob; // 07232000
        // string name; // kori
        string *set;
        size_t size,cap;
        void resize(const size_t& newsize); // helper function to resize the array
        bool inSet(const string& str) const; // helper function to tell us if an element is inide
    public:
        StringSet(string arr []);
        StringSet():set(new string[5]),size(0),cap(5){} //default constructor
        //copy control
        //~StringSet(){delete [] set;}
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
bool StringSet::inSet(const string& str) const{
    for(size_t i = 0; i < size; i++ ){
        if(set[i] == str)
            return true;
    }
    return false;
}
StringSet::StringSet(string arr []) : cap(5), size(0), set(new string[5]) {
    int i = 0;
    while (arr[i] != "-1"){
        if (i == cap){
            resize(2*cap);
        }
        set[i] = arr[i];
        size++;
        i++;
    }
}
StringSet StringSet::operator*(const StringSet& self){
    StringSet temp;
    temp.resize(size+self.size);//go ahead and make the capacity both
    for(int i = 0; i < size; i++){
        if (self.inSet(set[i])){
            cout << "adding: " << set[i] << endl;
            temp.add(self.set[i]);
        }
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
    if (!inSet(add))
        set[size++] = add;
    else
        cout << "String already in set. " << endl;
}
void StringSet::remove(const string& rm){
    if (!inSet(rm)) //assuing there will only be one string that we are removing and not multiple --  the first instance of the string will be removed
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
    std::string set[5];
    set[0] = "give";
    set[1] = "me";
    set[2] = "a";
    set[3] = "sixty-nine%";
    set[4] = "-1";
    StringSet kori(set);
    cout << kori << endl;
    cout << kori.sizeset() << endl;
    
    
    std::cout << "StringSet 1: " << kori << std::endl;
    kori[3] = "100%";
    std::cout << "SIIIIIKE";
    kori.add("for");
    kori.add("this");
    kori.add("10/10");
    kori.add("pun");
    std::cout << kori << std::endl;
    kori.remove("give");
    std::cout << "'give' is gone: " << kori << std::endl;
    std::cout << kori.sizeset() << std::endl;
    std::cout << kori.pop() << std::endl;
    std::cout << "Pop from back: " << kori << std:: endl;
    std::cout << kori.sizeset() << std::endl;
    kori.add("give");

    string set2[6];
    set2[0] = "give";
    set2[1] = "I'll";
    set2[2] = "think";
    set2[3] = "about";
    set2[4] = "pun";
    set2[5] = "-1";
    cout << "hi" << endl;
    StringSet xinyu(set2);
    

    cout << "xinyu: " << xinyu << endl;
    StringSet qin;
    qin = kori + xinyu;
    cout << "qin" << qin << endl;
    std::cout << "Adding Together: " << qin << std::endl;

    cout << kori << endl;
    cout << xinyu << endl; 
    StringSet katz;
    katz = kori * xinyu;

    std::cout << "Intersection: " << katz << std::endl;
    cout << katz.sizeset() << endl;
    cout << katz << endl;
    katz.add("kori"); // this is being added but the element before isn't
    cout << katz[1] << endl;
    //kori.clear();
    //std::cout << "Cleared Function: " << kori << std::endl;
    //delete [] set;
    //delete [] set2;
}

