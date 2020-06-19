#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Adopter; 
// forward declaration so we can use Adopter. Note that Pet is not doing anything to Adopter, it is just keeping track.

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
        vector<string> getAdopterNames(){return names;}

        friend ostream& operator<<(ostream& outs, const Pet& pet);
};
ostream& operator<<(ostream& outs, const Pet& pet){
    outs << "Pet Name: " << pet.name;
    for (size_t i = 0; i < pet.names.size(); i++){
        outs << "Adopter Name: " << pet.names[i] << endl;
    }
    return outs;
}

class Adopter {
    private:
        string name;
        Pet* petnm;
    public:
        Adopter(const string& newname = "") : name(newname) , petnm(nullptr) {} // init petnm to nullptr, assuming that a person does not have a pet
        void setName(const string newname){ name = newname; }
        string getName() const {return petnm->name; } // returning the name of the pet that we can access bc Adopter is a friend
        bool isAdopting() const;
        string getPetName() const {return petnm->getName();} //assuming we will always have a pet name 
        bool adopt(Pet& newpetnm);

        friend ostream& operator<<(ostream& outs, const Adopter& ad); // ostream for output
};
ostream& operator<<(ostream& outs, const Adopter& ad){
    if (!ad.isAdopting())
        outs << "Name: " << ad.name;
    else
        outs << "Name: " << ad.name << "\tPet: " << ad.getPetName();
    return outs; 
}
bool Adopter::isAdopting() const {
    if (petnm) return true;
    return false;
}
bool Adopter::adopt(Pet& newpetnm){ 
    if (petnm) return false;
    newpetnm.names.push_back(name); // pushing to pet list
    newpetnm.ad.push_back(this); // adding pet to the adopter 
    petnm = &newpetnm; // having our Pet* equal to our Pet that is being passed in
    return true;
}

vector<Adopter> findFreeAdopter(vector<Adopter>& adopters){
    vector<Adopter> free;
    for (size_t i = 0; i < adopters.size(); i++){
        if (!adopters[i].isAdopting()){ // for some reason, this is not working as expected -->fixed
            free.push_back(adopters[i]);
        }
    }
    return free;
}

vector<Pet> findFreePet(vector<Pet>& pets){
    vector<Pet> free;
    for (size_t i = 0; i < pets.size(); i++){
        if (pets[i].numberOfAdopters() == (size_t)0){ //for some reason this is not working as expected -->fixed
            // cout << "Adding:  " << pets[i] << " NUM OF ADOPTERS: " << pets[i].getAdopterNames().size() << endl;
            free.push_back(pets[i]);
        }
    }
    return free;
}


int main(){

    vector<Adopter> adopters; // declare our 
    vector<Pet> pets;
    
    Adopter betty("Betty"); 
    Adopter tom("Tom"); 
    Adopter alice("Alice");
    Adopter bob("Bob"); 
    Adopter kori("Kori"); 

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

    adopters.push_back(betty);
    adopters.push_back(tom);
    adopters.push_back(alice);
    adopters.push_back(bob);
    adopters.push_back(kori);

    pets.push_back(fido);
    pets.push_back(fluffy);
    pets.push_back(smellyCat);

    vector<Pet> freePets;
    vector<Adopter> freeAdopters;

    freePets = findFreePet(pets);
    freeAdopters = findFreeAdopter(adopters);

    cout << "Free Pets: " << endl;
    for (Pet P : freePets){
        cout << P << endl;
    }
    cout << "Free Adopters: " << endl;
    for (Adopter A : freeAdopters) {
        cout << A << endl;
    }
    /*
    cout << "Size:  " << freeAdopters.size() << endl;
    cout << "Free Adopters: " << endl; 
    cout << "Size:  " << freeAdopters.size();
    */
    

    /*
    for (size_t i = 0; i < findFreePet(pets).size(); i++){
        cout << i+1 << ") " << findFreePet(pets)[i] << endl;
    } 
    cout << "Free Adopters: " << endl;
    for (size_t i = 0; i < findFreeAdopter(adopters).size(); i++){
        cout << i+1 << ") " << findFreeAdopter(adopters)[i] << endl;
    } */
}
