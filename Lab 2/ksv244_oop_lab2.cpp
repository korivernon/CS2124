#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

struct Package{
   double weight; 
   int id;
};

class DeliveryTruck{
    private:
        string ad;
        string truckID;
        vector<Package> thePackages;
        int size;
        int load;
        double packageWt;
    public:
        friend ostream& operator<<(ostream& outs, const DeliveryTruck& dt);
        DeliveryTruck(string idNum){
            size = 50;
            truckID = idNum;
        }
        string getTruckID(){
            return truckID;
        }
        int getSize() const {return size;}
        string getAd() const {return ad;}

        //find the total weight
        double getWeight(){
            double pw = 0;
            for (size_t i=0; i<thePackages.size(); i++){
                pw += thePackages[i].weight;
            }
            packageWt = pw;
            return pw;
        }
        //change advertisment
        void changeAd(string adv){
            ad = adv;
        }

        bool onTruck(int id) const{
            for (size_t i = 0; i < thePackages.size(); i++ ){
                if (thePackages[i].id == id){
                    return true;
                }
            }
            return false;
        }

        void readInFromFile(string filename){
            Package temp;
            ifstream inFile;
            inFile.open(filename);
            if (!inFile) {cout << "Error, incorrect filename";}
            while (inFile >> temp.id >> temp.weight){
                thePackages.push_back(temp);
                size-=1;
                load+=1;
            }
        }
};

class DeliveryCompany{
    private:
    // dc is vector of delivery trucks
        vector<DeliveryTruck> dc;
    public:
        DeliveryCompany(){
            vector<DeliveryTruck> dcp;
            dc = dcp;
        }
        void loadPackage(vector<string>& num){
            string temp;
            for (size_t i=0; i<num.size(); i++){
                temp = "Truck"+num[i]+".txt";
                DeliveryTruck dt(num[i]);
                dt.readInFromFile(temp);
                dc.push_back(dt);
            }
        }
        bool searchCompany(int packageId){
            for(size_t i = 0; i < dc.size(); i++){
                if(dc[i].onTruck(packageId)){
                    return true;
                }
            }
            return false;
        }
};

ostream& operator<<(ostream& outs, const DeliveryTruck& dt){
    outs << "Ad: " << dt.getAd() << " Size: " << dt.getSize();
    return outs;
}

int main(){ 
    string input; 
    string cont;
    
    // creating delivery company
    DeliveryCompany dc;
    cout << "1) Default Delivery Truck" << endl;
    cout << "2) Change Advertisment on Truck" << endl; 
    cout << "3) Insert Package Weights from Filename" << endl;
    cout << "4) Display Cargo Weight" << endl;
    cout << "5) Search by ID" << endl;
    cout << "6) Enter in truck numbers (end w/ a negative number)" << endl;
    cout << "7) Search Company for Package using ID Number" << endl;

    do {
        
        DeliveryTruck dt("0");
        
        cout << "What would you like to do? ";
        cin >> input;

        //menu start
         
        cout << "1) Default Delivery Truck" << endl;
        cout << "2) Change Advertisment on Truck" << endl; 
        cout << "3) Insert Package Weights from Filename" << endl;
        cout << "4) Display Cargo Weight" << endl;   
        cout << "5) Search by ID" << endl;
        cout << "6) Enter in truck numbers (end w/ a negative number)" << endl; 
        cout << "7) Search Company for Package using ID Number" << endl;
        if (input == "1"){
           
            cout << dt << endl;}
        else if (input == "2"){
            string adv;
            cout << "What is the name of the advertisment? ";
            cin >> adv;
            // getline(cin, adv); // this only put's in the first word... why ?
            DeliveryTruck dt("0");
            dt.changeAd(adv);
            cout << dt << endl;
        }
        else if (input == "3"){
            cout << "Enter a filename: ";
            string filename;
            cin >> filename;
       
            dt.readInFromFile(filename);
            cout << dt << endl;
        }
        else if(input == "4"){
      
            cout << "Cargo Weight: " << dt.getWeight() << endl;
        }
        else if(input == "5"){
            cout << "Package ID: ";
            string id;
            cin >> id;
     
            dt.onTruck(stoi(id));
        }
        else if(input == "6"){
            // continue as long as there are not negative numbers
            string trucknum;
            vector<string> trucknums;
            int stop;
            do {
                cout << "Enter a truck number: ";
               
                cin >> trucknum;
                stop = stoi(trucknum);
                if (stop < 0){
                    break;
                }
                trucknums.push_back(trucknum);

               
                // convert to integer and check condition
            } while (stop >= 0);
            // add the packages to the delivery company
            dc.loadPackage(trucknums);
        }
        else if(input == "7"){
            cout << "What is your package ID? ";
            string packID;
            cin >> packID;
            int retVal;
            retVal = stoi(packID);
            dc.searchCompany(retVal);
        }
        
        //menu end
        cout << "Would you like to continue?(y/n) ";
        cin >> cont;
    } while(cont[0]=='y' || cont[0]=='Y');
   
    // menu end
    return 0;
}
