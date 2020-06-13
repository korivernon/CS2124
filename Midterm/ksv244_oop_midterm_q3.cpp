#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Adopter;

class Pet {
    private:
        string name;
        vector<Adopter> ad;
    public:
        friend class Adopter;
        Pet(string newname ) : name(newname) {
            vector<Adopter> ado;
            ad = ado;
        }
        void setName(const string newname){name = newname;}
        string getName() const {return name;}
        int numberOfAdopters() const {return ad.size();}
        vector<string> getAdopterNames() const {
            vector<string> names;
            for (int i = 0; i < ad.size(); i++){
                names.push_back(ad[i].getName());
            }
            return names;
        }
};

class Adopter {
    private:
        string name;
        Pet petnm;
        bool haspet;
    public:
        friend class Pet;
        Adopter(string newname) : name(newname) , haspet(false) {}
        Adopter(){haspet = false;}
        void setName(const string newname){name = newname; }
        string getName() const {return name; }
        bool isAdopting() const {return haspet;}
        bool adopt(const Pet& newpetnm){ 
            if (haspet==true){
                return false;
            }
            else {
                petnm = newpetnm;
                return true;
            }
        }
        string getPetName() const {return petnm.getName();} //assuming we will always have a pet name
};
int main(){
    Adopter betty("Betty");
    Adopter tom("Tom");
    Adopter alice("Alice");
    Adopter bob("Bob");
    Pet fido("Fido");
    Pet fluffy("Fluffy");
    Pet smellyCat("SmellyKatz");

    if(betty.adopt(fido))
        cout << "Betty Adopted Fido" << endl;
    else
        cout << "Betty cannot adopt Fido" << endl;
    if (tom.adopt(fido))
        cout << "Tom Adopted Fido" << endl;
    else
        cout << "Tom cannot adopt Fido" << endl;
    if (alice.adopt(fluffy))
        cout << "Alice adopted Fluffy" << endl;
    else
        cout << "Alice cannot adopt Fluffy" << endl;
    if (alice.adopt(smellyCat))
        cout << "Alice adopted SmellyKatz" << endl;
    else
        cout << "Alice cannot adopt SmellyKatz" << endl;

    cout << "Fido has " << fido.numberOfAdopters() << " Adopters" << endl;
    cout << "Fluffy has " << fluffy.numberOfAdopters() << " Adopters" <<endl;
    cout << "SmellyCat has " << smellyCat.numberOfAdopters() << " Adopters" << endl;
}
