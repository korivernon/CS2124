#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class StringSet {
    private:
        string *set;
        size_t size,cap;
        void resize(const size_t& newsize); // helper function to resize the array
        bool inSet(const string& str) const; // helper function to tell us if an element is inide
    public:
        StringSet(string arr []);
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
        bool operator==(const StringSet& self); //equivalence operator
        //clear function
        void clear();
        //return the size of the string set
        int sizeset()const {return (int)size;}
        friend ostream& operator<<(ostream& outs, const StringSet& ss);
        // getters 
        int getCap() const {return (int)cap;}
        int find(const string& elem) const; // find function just because..
};

int StringSet::find(const string& elem) const{
    for (size_t i = 0; i < size; i++){
        if (elem == set[i])
            return i;
    }
    return -1; // if not found 
}

bool StringSet::inSet(const string& str) const{ // determine whether or not an element is inside of the set
    for(size_t i = 0; i < size; i++ ){
        if(set[i] == str)
            return true;
    }
    return false;
}
StringSet::StringSet(string arr []) : cap(5), size(0), set(new string[5]) { // initialize set to 5, cap to 5, and size to 0
    int i = 0;
    while (arr[i] != "-1"){ // enter in a string array where the last element will be "-1". 
        if (i == cap){ // continue to iterate through the array until we reach the -1, which is the last element
            resize(2*cap); // resize if necessary
        }
        set[i] = arr[i];
        size++;
        i++;
    }
}


// copy operator
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
//overloaded operators
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
StringSet StringSet::operator+(const StringSet& self){ // addition operator for stringset
    StringSet temp;
    temp.resize(size + self.size);
    for(size_t i = 0; i < size; i++) // iterate through both and add them both to temp
        temp.add(set[i]);
    for(size_t i = 0; i < self.size; i++)
        temp.add(self.set[i]);
    return temp;
}
// extra
bool StringSet::operator==(const StringSet& self){
    for (size_t i = 0; i < size; i++){
        if (!self.inSet(set[i]))
            return false;
    }
    return true;
}
// ostream operator
ostream& operator<<(ostream& outs, const StringSet& ss){ // prefer this for output
    outs << "{";
    for (size_t i = 0; i < ss.size; i++){
        if (i != ss.size-1) {outs << ss.set[i] << ",";}
        else {outs << ss.set[i];}
    }
    outs << "}";
    return outs;
}
// resize function
void StringSet::resize(const size_t& newsize){ //resize function to change the size if size reaches cap
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
        resize(cap*2); // if cap is the same as size then resize 
    set[size++] = add; // add the value and then increment 
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
// clear function
void StringSet::clear() {
    delete [] set;
    string * temp = new string[5]; //reset cap
    set = temp; // make set temp
    size = 0;
    cap = 5; //assuming that nothing will be readded
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
    set2[3] = "for";
    set2[4] = "this";
    set2[5] = "-1";
    cout << "hi" << endl;
    StringSet xinyu(set2);

    //intersection set == {give, for this}
    

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
    // this produces the intersection, but for some reason it does not output it.. and I dont know
    cout << katz.sizeset() << endl;
    cout << katz << endl;
    katz.add("kori"); // this is being added but the element before isn't

    cout << katz[1] << endl;
    cout << "Capacity: " << katz.getCap() << endl;
    katz.add("new");
    cout << "Capacity: " << katz.getCap() << endl;
    kori.clear();
    std::cout << "Cleared Function: " << kori << std::endl;
}

