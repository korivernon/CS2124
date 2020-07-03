#include "world.h"
#include "organisms.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

World::World() : t(0){
    for (size_t y = 0; y < dim; y++){
        for (size_t x = 0; x < dim; x++){
            board[y][x] = nullptr;
            //board.push_back(nullptr);
        }
             
    }
}
vector<int> World::validMoveVec(int x, int y) const{
  vector<int> moves;
  if(y != 0 && board[y-1][x] == nullptr){moves.push_back(1);}
  if(x != 19 && board[y][x+1] == nullptr){moves.push_back(2);}
  if(x != 0 && board[y][x-1] == nullptr){moves.push_back(3);}
  if(y != 19 && board[y+1][x] == nullptr){moves.push_back(4);}
  return moves;
}



void World::loadBoard(){
    int loc;
    cout << "Initializing Board..." << endl;
    for (size_t ants = 0; ants < 100; ants++){
        loc = randomize();
        Ant ant(this,loc);
        board[loc%20][loc/20] = &ant;
    }
    
    for (size_t dbs = 0; dbs < 5; dbs++){
        loc = randomize();
        DoodleBug db(this,loc);
        board[loc%20][loc/20] = &db;
    }
    printBoard();
    cout << "Successfully Initialized Board!" << endl;
}

void World::passTime() {
    char stop;
    do {
        int ants, doodlebugs; ants = doodlebugs = 0;
        //move doodlebugs first
        for (size_t y = 0; y < dim; y++){
            for (size_t x = 0; x < dim; x++){
                if (board[y][x] == nullptr) continue;
                if (board[y][x]->value() == 'X'){
                    board[y][x]->move();
                    doodlebugs++;
                }
            }
        }
        
        //move ants second
        for (size_t y = 0; y < dim; y++){
            for (size_t x = 0; x < dim; x++){
                if (board[y][x] == nullptr) continue;
                if (board[y][x]->value() == 'o'){
                    board[y][x]->move();
                    ants++;
                }
            }
        }
        //breed
        for (size_t y = 0; y < dim; y++){
            for (size_t x = 0; x < dim; x++){
                if (board[y][x]->canbreed()){ //if can breed
                    
                    board[y][x]->breed();

                    if (board[y][x]->value() == 'o'){
                        ants++;
                    }
                    if (board[y][x]->value() == 'X'){
                        doodlebugs++;
                    }
                }
                else continue;
            }
        }
        //starve and delete
        for (size_t y = 0; y < dim; y++){
            for (size_t x = 0; x < dim; x++){
                if (board[y][x]->starve()){
                    
                    board[y][x] = nullptr;
                    doodlebugs--; // decrement doodlebugs
                    //reset
                }
            }
        }
        printBoard();
        cout << "Time: " << t << endl << "Ants: " << ants << endl << "DoodleBugs: " << doodlebugs << endl;
        cout << "Press 'Enter' to pass the time!";
        cin.get(stop);
    } while (stop == '\n');
}
//check whether or not this is occupied
bool World::occupied(const int& elem) const{
    if (board[elem%20][elem/20] == nullptr ) return false;
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

//print the board
void World::printBoard() const {
    cout <<"+-----------------------------------------+"<< endl;
    for (size_t y = 0; y < dim; y++){
        cout << "| ";
        for (size_t x = 0; x < dim; x++){
            if (board[y][x] == nullptr){
                cout << "- ";
            }
            else {
                cout << board[y][x]->value() << " ";
            }
        }
        cout << "|" << endl;
    }
    cout <<"+-----------------------------------------+"<< endl;
}