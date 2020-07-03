#include<iostream>
#include<ctime>
#include<list>
using namespace std;
const double PERC80 = .8; // it's an inside joke

class IntHasher {
private:
    list<int> * htm;
    size_t sz,cap;
    
    int * nums; // this is to aid in the resize function
    void resize(const size_t& newSz); //resize function
    void fillNums();
public:
    IntHasher(): htm(new list<int>[5]), cap(5), sz(0), nums(new int[5]) {}
    virtual ~IntHasher();
    void insert(const int& value);
    void remove(const int& value);
    bool find(const int& value) const;
    
    friend ostream& operator<<(ostream& outs, const IntHasher& htm);
    IntHasher operator+(const IntHasher& self);
};

IntHasher IntHasher::operator+(const IntHasher& self){
    IntHasher temp;
    for (size_t i = 0; i < sz; i++){
        temp.insert(nums[i]);
    }
    for (size_t i = 0; i < self.sz; i++){
        temp.insert(self.nums[i]);
    }
    
    return temp;
}

IntHasher::~IntHasher(){ // reset everyting
    delete [] htm;
    htm = new list<int>[5];
    cap = 5;
    sz = 0;
    delete [] nums;
    nums = new int[5];
}
ostream& operator<<(ostream& outs, const IntHasher& m){
    for(size_t i = 0; i < m.cap; i++){ //i prefer this output
        outs << "HashTableMap[" << i << "] = \n    {\n";
        for(list<int>::iterator j =  m.htm[i].begin(); j != m.htm[i].end(); j++){
            outs << *j << endl; 
        }
        outs << "    }" << endl;
    }
    return outs;
}
void IntHasher::fillNums(){ //created this function in order to easily load elements and resize
    nums = new int[cap]; //manage our tnums arr
    size_t index = 0;
    for(size_t i = 0; i < cap; i++){
        for(list<int>::iterator j = htm[i].begin(); j != htm[i].end(); j++){
            nums[index] = *j; 
            index++;
            if (index == sz-1) break;
        }
    }
}

void IntHasher::resize(const size_t& newSz){
    fillNums();
    list<int> * temp = new list<int>[newSz];
    delete [] htm; //delete previous
    htm = temp; //reassign
    cap = newSz; // the capacity must be changed immediately
    for(size_t i = 0; i < sz; i++){
        htm[nums[i]%cap].push_back(nums[i]);
    }
    
    //resize never does something twice, so this should be an n operation
}

void IntHasher::insert(const int& value){ //if we have a 10 element array, and want to store the value 103, we would store it in position 3 (103%10=3)
    if (((double)sz / (double)cap) > PERC80) resize(2*cap); //when the array gets more than 80% full so, > 80
    htm[value%cap].push_back(value);
    sz++;
    fillNums();
}

void IntHasher::remove(const int& value){ //Remove (take an int out of the table; do nothing if it doesn’t exist)
    for(list<int>::iterator i = htm[value%cap].begin(); i != htm[value%cap].end(); i++){
        if (*i == value){
            htm[value%cap].remove(value);
            sz--;
            break;
        }
    }
    fillNums();
}

bool IntHasher::find(const int& value) const{ //Find (return true or false if it exists)
    for(list<int>::const_iterator i = htm[value%cap].begin(); i != htm[value%cap].end(); i++){
        if (*i == value)
            return true;
    }
    return false;
}

int main(){
   IntHasher htm; 
   srand(time(NULL));
   htm.insert(5);
   cout << htm;
   htm.insert(4);
   cout << htm;
   htm.insert(6);
   htm.insert(7);
   htm.insert(9);
   cout << "Testing..." << endl << htm;
   htm.insert(8);
   cout << htm;
   htm.insert(24);
   for (size_t i = 0; i < 20; i++){
       htm.insert(rand()%200+1);
   }
   cout << htm;
   cout << htm.find(156) << endl;
   htm.remove(5);
   cout << htm;
   IntHasher htm2;
   for (size_t i = 0; i < 20; i++){
       htm2.insert(rand()%943+500);
   }
   IntHasher htm3 = htm + htm2;
   cout << htm3;

   IntHasher htm4;
   cout << htm4.find(5) << endl;
   
}
