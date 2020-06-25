#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

class Organism { 
    protected:
        // location
        int location;
        vector<int> moves; // -1 if off the board
    public:
        Organism(const int& loco) : location(loco) {
            vector<int> v;
            moves = v;
            LocVec(); // load the vector
        }
        virtual vector<int> move() = 0;
        virtual char value() const = 0;
        int getLocation() const {return location;}
        void setLocation(const int& loc);
        int getVal(const int& i) const{return moves[i];}

        vector<int> LocVec();
};

void Organism::setLocation(const int& loc){
    location = loc;
    LocVec();
}

vector<int> Organism::LocVec() {
    vector<int> move;
    //check the left
    if ( ( (location) % 20 ) == 0) move.push_back(-1);
    else move.push_back(location-1);
    //check the right
    if ( ( (location+1) % 20 ) == 0) move.push_back(-1);
    else move.push_back(location+1);
    //check the up
    if (location <= 19) move.push_back(-1);
    else move.push_back(location-20);
    //check the down
    if (location >= 380) move.push_back(-1);
    else move.push_back(location+20);
    move.push_back(location); // location will be the last element
    moves = move;
    return moves;
}

class Ant : public Organism {
    private:
        int iter; // iterations of time
    public:
        Ant(const int& loco) : Organism(loco), iter(0) {} 
        //void reproduce(); // how do i create another object and place inside this function
        vector<int> move();
        char value() const {return 'o';} //returns the value
        int getIter() const {return iter;} // get the value of the iteration
        friend ostream& operator<<(ostream& outs, const Ant& ant);
};
ostream& operator<<(ostream& outs, const Ant& ant){
    outs << "o";
    return outs;
}

vector<int> Ant::move(){
    LocVec(); // call the location vector
    if (iter == 3){
        // automatic reset at three
        //reproduce();
        iter = 0;
    }
    iter++;
    return moves; // returning location vector so we can decide to move later
}
class Board {
    private:
        char ** score;
        vector<Organism*> orgs;
    public:
        Board() : score(new char * [20]){
            vector<Organism*> o;
            orgs = o; // initialize vector
            for (size_t i = 0; i < 20; ++i){
                score[i] = new char[20];
            }
        }
        int randomize() const;
        bool occupied(const int& elem) const; // is that place occupied
        void place(const int& location, const char& org);
        void place_org(Organism& org);
        void passTime();
        void move(Organism& org);
        
        bool getUp(const int& elem) const;
        bool getDown(const int& elem) const;
        bool getLeft(const int& elem) const;
        bool getRight(const int& elem) const;
        vector<char> nextToMe(const Organism& org);

        

        virtual ~Board();
        void loadBoard();
        void printBoard() const;
};
void Board::passTime(){
    cout << "orgs size: " << orgs.size() << endl;
    //move(orgs[0]);
    // move(*orgs[0]);
   /* for(size_t i = 0; i < orgs.size(); i++){
        move(*orgs[i]);
    }*/
}
void Board::place_org(Organism& org){ //assuming we will always get a valid place
    score[org.getLocation()%20][org.getLocation()/20] = org.value();
    orgs.push_back(&org);
}
vector<char> Board::nextToMe(const Organism& org){
    //returns a vector of eveyrthing next to an element... similar to getUp,getDown,getLeft, and getRight
    vector<int> locvec;
    //locvec = org.LocVec();
    for (size_t i = 0; i < 5; i++){
        locvec.push_back(org.getVal(i));
    }
    int location = locvec[4]; // location of element

    vector<char> aroundMe;
    for (size_t i = 0; i < locvec.size()-1; i++ ){
        if (locvec[i] == -1) aroundMe.push_back('b'); // if it is a border element
        aroundMe.push_back(score[locvec[i]%20][locvec[i]/20]); // push back this element's value
    }
    return aroundMe;
}
void Board::move(Organism& org){
    int count = 0;
    vector<int> moveVec;
    moveVec = org.move(); // so we don't call the location vector function every time inside of the function... not the wave
    
    vector<char> ntm;
    ntm = nextToMe(org);

    vector<int> validLoc;

    vector<int> chooserand; // choose a random place for it to go
    
    srand(time(NULL));
    if (org.value() == 'o'){ // if it's an ant
        for (size_t i = 0; i < ntm.size(); i++){
            //location vector has form 
            // <[68,70,49,89],69> 
            //<left,right,up,down, current location>
            if (ntm[i] != 'b' || ntm[i] != 'o' || ntm[i] != 'X'){
                validLoc.push_back(moveVec[i]);
                chooserand.push_back(i);
            } 
            else {
                validLoc.push_back(-1); // push back a negative 1 if it's an invalid location
            }
            // valid loc <-1,45,67,8>
            // chooserand <24,67,8>
        }
        int num = rand() % (chooserand.size()-1) + 0;
        if(chooserand.size() != 0){
            org.setLocation(num); //set the location of the organism
            place_org(org); //place the organism on the board
            place(moveVec[4],'-'); // put a dash in the previous location
            cout << "successfully moved! " << endl;
        }

    }
}

bool Board::occupied(const int& elem) const{
    if (score[elem%20][elem/20] == '-' ) return false;
    return true;
}
// these check our left, right, up, and down
bool Board::getLeft(const int& elem) const{
    if ( ( (elem) % 20 ) == 0) return true; // if it is a border element
    if (occupied(elem-1))return true;
    return false;
}
bool Board::getRight(const int& elem) const {
    if ( ( (elem+1) % 20 ) == 0) return true; // if it is a border element
    if (occupied(elem+1)) return true;
    return false;
}
bool Board::getUp(const int& elem) const{
    if ( elem <= 19) return true; // if it is a border element
    if (occupied(elem-20))return true;
    return false;
}
bool Board::getDown(const int& elem) const{
    if ( elem >= 380) return true; // if it is a border element
    if (occupied(elem+20))return true;
    return false;
}
int Board::randomize() const{
    srand(time(NULL));
    int location = rand() % 399 + 0; // random number between 399 and 0
    if (occupied(location)){
        // if the location is occupied
        while(occupied(location)){
            // find a location that is not occupied
            location = rand() % 399 + 0;
        }
    }
    return location;
    // score[location%20][location/20] = org;
}

void Board::place(const int& location , const char& val){ //assuming we will always get a valid place
    score[location%20][location/20] = val;
}
Board::~Board(){
    for(size_t i = 0; i < 20; ++i ){
        delete [] score[i];
    }
    delete [] score;
}

void Board::loadBoard() {
    for (size_t y = 0; y < 20; ++y){
        for (size_t x = 0; x < 20; ++x){
            score[y][x] = '-';
        }
    }
}
void Board::printBoard() const {
    cout <<"+-----------------------------------------+"<< endl;
    for (size_t y = 0; y < 20; ++y){
        cout << "| ";
        for (size_t x = 0; x < 20; ++x){
            cout << score[y][x] << " ";
        }
        cout << "|" << endl;
    }
    cout <<"+-----------------------------------------+"<< endl;
}
int main() {
    
    Board ecosystem;
    ecosystem.loadBoard();
    for (int i = 0; i < 100; i++){
        int loc = ecosystem.randomize();
        Ant temp(loc); // load with this location
        ecosystem.place_org(temp); // place the ant here
    }
    ecosystem.printBoard();
    ecosystem.passTime();
    ecosystem.printBoard();
}