#ifndef WORLD_H
#define WORLD_H
#include "organisms.h"
#include<vector>

class Organism;
class Ant;
class DoodleBugs;

class World {
    friend class Organism;
    friend class Ant;
    friend class DoodleBugs;
private:
    char** board;
    std::vector<Organism> org;
    std::vector<Ant> ants;
    std::vector<DoodleBug> dbs;
    int time;
public:
    World();
    ~World();
    void passTime();

    void loadBoard();
    int randomize() const;
    void printBoard() const;

    void place(const Organism& org);
    void placeAnt(const Ant& ant);
    void placeDoodleBug(const DoodleBug& db);

    bool occupied(const int& elem) const;

};
#endif
