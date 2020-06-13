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
        string getName() const  {return name;}
        void addNum(const string type, const long int number);
        friend ostream& operator<<(ostream& outs, const Person& p);

};

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
int main() {
    PhoneNumber kori(9194102217);
    cout << kori << endl;

    Person temp("Kori Vernon");
    temp.addNum("Mobile",9194102217);

    cout << temp;

}