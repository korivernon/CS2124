#ifndef ORGANISMS_H
#define ORGANISMS_H

class World;

class Organism {
    friend class World;
protected:
    int x,y,iter;
public:
    Organism() : x(-1), y(-1),iter(0){}
    Organism(int location) : iter(0), y(location%20), x(location/20) {}
    Organism(int newx, int newy) : iter(0), x(newx), y(newy){}
    void move(World& world,const int& dir);
    bool breed(World& world, const int& dir);
    virtual char value() const;
    void setX(const int& newx);
    void setY(const int& newy);
    int getX() const;
    int getY() const;
};

class Ant: public Organism {
    friend class World;
public:
    Ant(int newx, int newy) : Organism(newx,newy){}
    Ant() : Organism() {}
    Ant(int location) : Organism(location){}
    bool breed(World& world, const int& dir);

    void move(World& world);
    char value() const;

};

class DoodleBug: public Organism {
    friend class World;
private:
    int notEaten;
public:
    DoodleBug(int newx, int newy) : Organism(newx,newy), notEaten(0){}
    DoodleBug() : Organism() {}
    DoodleBug(int location) : Organism(location){}
    bool breed(World& world, const int& dir);

    void move(World& world);
    char value() const;
};
#endif