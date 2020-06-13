#include<vector>
#include<iostream>
#include<string>

using namespace std;
class PhoneNumber{
    private:
        string type;
        long int num; 
    public:
        PhoneNumber(string newtype, long int newnum) : type(newtype), num(newnum) {}
        PhoneNumber();
        PhoneNumber(long int newnum): num(newnum) {
            type = "Mobile";
            //setting default to mobile
        }
        long int getNum()const {return num;}
        string getType() const {return type;}

        void setNum(long int newnum) { num = newnum; }
        void setType(string newtype) { type = newtype; }
        friend ostream& operator<<(ostream& outs, const PhoneNumber& pn);
};
ostream& operator<<(ostream& outs, const PhoneNumber& pn){
    outs << "Type: " << pn.getType() << "\tMobile: " << pn.getNum();
    return outs;
}
class Person {
    private:
        string name;
        vector<PhoneNumber> numbers;
    public:
        Person(string newname) : name(newname) {
            vector<PhoneNumber> nums;
            numbers = nums;
        }
        string getName() const  {return name; }
        void addNum(const string type, const long int number);
        long int searchType(string find) const;
        friend ostream& operator<<(ostream& outs, const Person& p);
        bool searchNum(const long int num);

};

bool Person::searchNum(const long int num){
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i].getNum() == num){
            return true;
        }
    }
    return false;
}
long int Person:: searchType(string find) const {
    for(int i = 0 ; i < numbers.size(); i++){
        if (find == numbers[i].getType()){
            return numbers[i].getNum();
        }
    }
    return 0;
}
void Person::addNum(const string type, const long int number){
   PhoneNumber temp(type,number);
   numbers.push_back(temp); 
}
ostream& operator<<(ostream& outs, const Person& p){
    outs << "Name:\t" << p.getName() << endl;
    outs << "Phone Numbers" << endl;
   for (size_t i = 0; i < p.numbers.size(); i++){
        outs << p.numbers[i] << endl;
    }
    outs << endl;
    return outs;
}

class PhoneBook {
    private:
        vector<Person> pb; // phonebook
    public:
        PhoneBook(){
            vector<Person> phonebook;
            pb = phonebook;
        }
        void addPerson(const Person& p){ pb.push_back(p);}
        Person searchNum(const long int num);
        Person search(const string name);

};
Person PhoneBook::search(const string name){
    // assuming that the person does exist
    for(size_t i = 0; i < pb.size(); i++){
        if (pb[i].getName() == name){
            return pb[i];
        }
    }
}
Person PhoneBook::searchNum(long int num){
    for(size_t i = 0; i < pb.size(); i++){
        if (pb[i].searchNum(num) == true){
            return pb[i];
        }
    }
}

int main() {
    PhoneNumber kori(9194102217);
    cout << kori << endl;

    Person temp("Kori Vernon");
    temp.addNum("Mobile",9194102217);

    cout << "Found: "  << temp.searchType("Mobile") << endl;
    cout << temp;

    PhoneBook pb;
    pb.addPerson(temp);

    cout <<  pb.search("Kori Vernon") << endl;

    cout << pb.searchNum(9194102217) << endl;

}