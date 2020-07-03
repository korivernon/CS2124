#ifndef WORLD_H
#define WORLD_H
#include "organisms.h"
#include<vector>

const int dim = 20; //dimensions

class Organism;
class Ant;
class DoodleBug;
/*
The class world contains Organism, Ant, and DoodleBug
friend classes. We need them so that we can use them in our
function and manipulate them accordingly when stepping through
time.

We have a load board function which loads the world, and a printBoard
function which outputs the board into the console.
*/
class World {
    friend class Organism;
    friend class Ant;
    friend class DoodleBug;
private:
    //std::vector< std::vector<Organism*> > board;
    Organism* board[dim][dim];
    int t;
public:
    World();
    void passTime();

    void loadBoard();
    int randomize() const;
    void printBoard() const;
    
    //determines the safe places that an organism can move to, so long as it is empty
    std::vector<int> validMoveVec(int x, int y) const;

    bool occupied(const int& elem) const;

};
#endif
