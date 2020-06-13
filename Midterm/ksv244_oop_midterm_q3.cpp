#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Adopter;

class Pet {
    private:
        string name;
        vector<Adopter*> ad;
        vector<string> names;
    public:
        friend class Adopter;
        Pet(const string& newname) : name(newname) {} 
        void setName(const string newname){name = newname;}
        const string& getName() const {return name;}
        size_t numberOfAdopters() const {return ad.size();}
        vector<string> getAdopterNames();
};

vector<string> Pet::getAdopterNames() {
    return names;
}
class Adopter {
    private:
        string name;
        Pet* petnm;
    public:
        Adopter(const string& newname = "") : name(newname) , petnm(nullptr) {}
        void setName(const string newname){ name = newname; }
        string getName() const {return petnm->name; }
        bool isAdopting() const {
            if (petnm)return true;
            return false;
        }
        string getPetName() const {return petnm->getName();} //assuming we will always have a pet name 
        bool adopt(Pet& newpetnm);
};

bool Adopter::adopt(Pet& newpetnm){ 
    if (petnm) return false;
    newpetnm.names.push_back(name); // pushing to pet list
    newpetnm.ad.push_back(this);
    petnm = &newpetnm;
    return true;
}

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
