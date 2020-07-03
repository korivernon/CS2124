#ifndef ORGANISMS_H
#define ORGANISMS_H
#include<vector>

class World;
/*
In the Organisms header file I have Organisms which
contain the x, y, iter, and world class as protected members.

The function has two constructors. Both take in a pointer
to the world which contains the organism. One takes in the
location as a number 0-399, and the other takes in a coordinate
0-19 for y, and 0-19 for x.

The x, y, iter, and world class are protected to ensure use throughout the 
Organism's derived class. World is also added
as a friend class so that I can alter the board inside of the
organism functions (move,breed,value).
*/
class Organism {
    friend class World;
protected:
    int x,y,iter;
    World* world;
    //std::vector<int> validMoves(int x, int y) const;
public:
    //Organism() : x(-1), y(-1), iter(0), world(nullptr){}
    Organism(World* nworld, int location) : iter(0), y(location%20), x(location/20), world(nworld) {}
    Organism(World* nworld, int newx, int newy) : iter(0), x(newx), y(newy), world(nworld){}
    virtual void move(); // basic move function
    virtual bool breed(); // basic breed function 
    virtual char value() const = 0;
    virtual bool starve(); // basic starve function, which by default returns false
    virtual bool canbreed() const; // basic can breed function, which by default returns false
    /*
    void setX(const int& newx);
    void setY(const int& newy);
    int getX() const;
    int getY() const;
    */
    
};
/*
For the Ant class, we don't need much since the ant moves in a 
basic way. We will pass function like move and breed to the Base 
class. We will use canbreed to control when the ant breeds. 
*/
class Ant: public Organism {
    friend class World;
public:
    Ant(World* nworld, int newx, int newy) : Organism(nworld, newx,newy){}
    //Ant() : Organism() {}
    Ant(World* nworld, int location) : Organism(nworld, location){}
    
    char value() const;
    /*
    value function, which returns 'o' as the value 
    of the ant. this is used in comparisons.
    */
    bool canbreed() const;
    
};
/*
The DoodleBug is more complicated than the ant class in the sense
that it prefers to eat an ant than to just move
normally. In the class, the DoodleBug will eat
an ant when it can, otherwise it will move normally!

We also keep track of whether or not the DoodleBug
has eaten. Through a privately declared variable,
we will keep track of whether or not the DoodleBug
has eaten, which will be checked at the end of each
move cycle. notEaten is updated through the move function. 
*/
class DoodleBug: public Organism {
    friend class World;
private:
    int notEaten;
public:
    DoodleBug(World* nworld, int newx, int newy) : Organism(nworld,newx,newy), notEaten(0){}
    //DoodleBug() : Organism() {}
    DoodleBug(World* nworld, int location) : Organism(nworld, location){}
    bool eatAnt(int x, int y);
    void move(); 
    /*
    the move function for doodlebug prefers to eat 
    an ant, however if it cannot it moves normally
    */
    char value() const;
    bool starve();

    bool canbreed() const;
    /*
    value function, which returns 'X' as the value 
    of the ant. this is used in comparisons.
    */

    //std::vector<int> eatAnts(int x, int y) const; //returns list of ants that can be eaten
};
#endif