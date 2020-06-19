#include<vector>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class PhoneNumber{
    private:
        string type;
        long int num; 
    public:
        PhoneNumber(string newtype, long int newnum) : type(newtype), num(newnum) {}
        PhoneNumber(); // default constructor
        PhoneNumber(long int newnum): num(newnum) {} // type is defaulted to ""
        long int getNum()const {return num;} //getter
        string getType() const {return type;} //getter

        void setNum(long int newnum) { num = newnum; } //setter
        void setType(string newtype) { type = newtype; } //setter

        friend ostream& operator<<(ostream& outs, const PhoneNumber& pn); //helps for output
};

ostream& operator<<(ostream& outs, const PhoneNumber& pn){
    outs << "Type: " << pn.getType() << "\tNumber: " << pn.getNum();
    return outs;
}
class Person {
    private:
        string name;
        vector<PhoneNumber> numbers;
    public:
        Person(string newname) : name(newname) {}
        string getName() const  {return name; } //getter
        void addNum(const PhoneNumber& number); //adder
        long int searchType(const string& find) const; //search
        friend ostream& operator<<(ostream& outs, const Person& p); //helps for output
        bool searchNum(const PhoneNumber& num); //searchnum

};

bool Person::searchNum(const PhoneNumber& num){
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i].getNum() == num.getNum()){ //if the number is equal to the current number then that's our boy!
            return true;
        }
    }
    return false;
}
long int Person:: searchType(const string& find) const {
    for(int i = 0 ; i < numbers.size(); i++){ //if the type is equal to the current type then that's our girl!
        if (find == numbers[i].getType()){  //if there are two of the same types it will just return the first one :)
            return numbers[i].getNum();
        }
    }
    return -1;
}

void Person::addNum(const PhoneNumber& number){
   numbers.push_back(number); 
}
ostream& operator<<(ostream& outs, const Person& p){
    outs << "Name:\t" << p.getName() << endl;
    outs << "Phone Numbers: " << endl;
   for (size_t i = 0; i < p.numbers.size(); i++){
        outs << p.numbers[i] << endl;
    }
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
        friend ostream& operator<<(ostream& outs, const PhoneBook& pb);
        void addPerson(const Person& p){ pb.push_back(p);}
        Person searchNum(const PhoneNumber& num);
        Person search(const string& name);

};
ostream& operator<<(ostream& outs, const PhoneBook& pb){
    outs << "PhoneBook" << endl << endl;
    for( Person p : pb.pb){
        outs << p << endl;
    }
    return outs;
}
Person PhoneBook::search(const string& name){
    // assuming that the person does exist
    for(size_t i = 0; i < pb.size(); i++){
        if (pb[i].getName() == name){
            return pb[i];
        }
    }
}
Person PhoneBook::searchNum(const PhoneNumber& num){
    // assuming we will get a number that is inside
    for(size_t i = 0; i < pb.size(); i++){
        if (pb[i].searchNum(num) == true){
            return pb[i];
        }
    }
}

int main() {
    PhoneNumber rand(12940203910);
    PhoneNumber temp(9194102217);
    Person kori("Kori");
    kori.addNum(temp);

    PhoneNumber temp2(9192049203);
    Person katz("Katz");
    temp2.setType("Your Mom");
    katz.addNum(temp2);
    // cout << katz;

    PhoneNumber temp3(9930130492);
    PhoneNumber temp4(9402103910);
    Person joey("Joey");
    temp3.setType("Mobile");
    joey.addNum(temp3);
    joey.addNum(temp4);
    // cout << joey;

    PhoneBook pb;
    pb.addPerson(kori);
    pb.addPerson(joey);
    pb.addPerson(katz);
    // cout << pb;
    //random number;
    
    
    // cout << kori.searchType("new") << endl;
    // cout << kori.searchNum(rand) << endl;


    
}