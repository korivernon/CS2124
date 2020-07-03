#include "world.h"
#include "organisms.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;
World::World() : board(new char * [20]),time(0){
    vector<Ant> ant; ants = ant; //initialize vector of ants
    vector<DoodleBug> db; dbs = db; //initialize vector of doodlebugs

    for (size_t i = 0; i < 20; ++i){
        board[i] = new char[20];
    }
}
void World::passTime() {
    char stop;
    do {
        printBoard();
        cout << "Time: " << ++time << endl;
        cout << "Ants: " << ants.size() << endl;
        cout << "DoodleBugs: " << dbs.size() << endl;
        for(size_t i = 0; i < dbs.size(); i++)
            dbs[i].move(*this);
        for(size_t i = 0; i < ants.size(); i++)
            ants[i].move(*this);
        cout << "Press 'c' to pass the time!";
        cin >> stop;
    } while (stop == 'c');
}
//check whether or not this is occupied
bool World::occupied(const int& elem) const{
    if (board[elem%20][elem/20] == '-' ) return false;
    return true;
}
//choose a random element that's not occupied
int World::randomize() const{
    //srand(time(NULL));
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
//place an organism
void World::place(const Organism& orgn){
    board[orgn.y][orgn.x] = orgn.value();
    if (orgn.value() == 'r') org.push_back(orgn);
}
//place an
void World::placeAnt(const Ant& ant){
    board[ant.y][ant.x] = ant.value();
    ants.push_back(ant);
}
void World::placeDoodleBug(const DoodleBug& db){
    board[db.y][db.x] = db.value();
    dbs.push_back(db);
}

World::~World(){
    for(size_t i = 0; i < 20; ++i ){
        delete [] board[i];
    }
    delete [] board;
}

void World::loadBoard() {
    for (size_t y = 0; y < 20; ++y){
        for (size_t x = 0; x < 20; ++x){
            board[y][x] = '-';
        }
    }
}
void World::printBoard() const {
    cout <<"+-----------------------------------------+"<< endl;
    for (size_t y = 0; y < 20; ++y){
        cout << "| ";
        for (size_t x = 0; x < 20; ++x){
            cout << board[y][x] << " ";
        }
        cout << "|" << endl;
    }
    cout <<"+-----------------------------------------+"<< endl;
}
