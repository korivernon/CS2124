#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Business {
    private:
        string name;
        string number;
        string location;
        string email;
        bool active;
    public:
        Business(string ename, string enumber, string elocation = NULL, string eemail = NULL, bool newact = true) : active(newact) name(ename), number(enumber), location(elocation), email(eemail) {}       
        string getName() const { return name;}
        string getLocation() const {return location;}
        friend ostream& operator<<(ostream& outs, const Business& b); 
        void changeLocation(string newloc){location = newloc;}
        void changeEmail(string eemail){email = eemail;}
        void changeNumber(string enumber){number = enumber;}
};
ostream& operator<<(ostream& outs, const Business& b){
     outs << "Business Name: " << name << endl;
     outs << "Business Location: " << location << endl;
     outs << "Business Telephone Number: " << number << endl;
     outs << "Business Email: " << endl;
} 
class Database{
    public:
        vector<Business> DB;
    private:
        DB(){
            vector<Business> newdb;
            DB = newdb;
        }
        void addBusiness(Business b){DB.push_back(b);}
        void deleteBusiness(string n){
            for(size_t i = 0; i < DB.size(); i++){
                if (DB[i].number==n){
                    DB[i].active = false;
                }
            }
        }
};
void addBusiness(vector<Business>& v){

    Business temp(ename, enumber, elocation, eemail);
    DB.push_back(temp);
}
