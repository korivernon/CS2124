#include "organisms.h"
#include "world.h"
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

char Organism::value() const {return 'r';}
char Ant::value() const {return 'o';}
char DoodleBug::value() const {return 'X';}

void Organism::setX(const int& newx){x = newx;}
void Organism::setY(const int& newy) {y = newy;}
int Organism::getX() const {return x;}
int Organism::getY() const {return y;}

bool Organism::breed(World& world, const int& dir){
  int newx = 0; int newy = 0; bool bred = false;
  if (iter >= 3){
    if (dir == 1){ //check up
      if (y != 0 && world.board[y-1][x] == '-'){
        newy = y-1; newx = x; bred = true;
      }
    }
    else if (dir == 2){ //check right
      if (x != 19 && world.board[y][x+1] == '-'){
        newx = x+1; newy = y; bred = true;
      }
    }
    else if (dir == 3){ // check left
      if (x != 0 && world.board[y][x-1] == '-'){
        newx = x-1; newy = y; bred = true;
      }
    }
    else if (dir == 4){//check down
      if (y != 19 && world.board[y+1][x] == '-'){
        newy = y+1; newx = x; bred = true;
      }
    }
    if (bred == true){
      cout << "Successfully bred" << endl;
      Organism* org = new Organism(newx,newy);
      world.org.push_back(*org);
      world.board[org->y][org->x] = org->value();
      iter = 0;
      return true;
    }
  }
  return false;
}

void Organism::move(World& world,const int& dir){
  if (dir == 1){ // check up
    if (y != 0 && world.board[y-1][x] == '-'){
      world.board[y-1][x] = world.board[y][x];
      world.board[y][x] = '-';
      y--;
    }
  }
  else if (dir == 2){ //check up right
    if ( x != 19 && world.board[y][x+1] == '-'){
      world.board[y][x+1] = world.board[y][x];
      world.board[y][x] = '-';
      x++;
    }
  }
  else if (dir == 3){ //check left
    if (x != 0 && world.board[y][x-1] == '-'){
      world.board[y][x-1] = world.board[y][x];
      world.board[y][x] = '-';
      x--;
    }
  }
  else if (dir == 4){//check down
    if (y != 19 && world.board[y+1][x] == '-'){
      world.board[y+1][x] = world.board[y][x];
      world.board[y][x] = '-';
      y++;
    }
  }
  iter++;
  //}
}
bool Ant::breed(World& world, const int& dir){
  int newx = 0; int newy = 0; bool bred = false;
  if (iter >= 3){
    if (dir == 1){ //check up
      if (y != 0 && world.board[y-1][x] == '-'){
        newy = y-1; newx = x; bred = true;
      }
    }
    else if (dir == 2){ //check right
      if (x != 19 && world.board[y][x+1] == '-'){
        newx = x+1; newy = y; bred = true;
      }
    }
    else if (dir == 3){ // check left
      if (x != 0 && world.board[y][x-1] == '-'){
        newx = x-1; newy = y; bred = true;
      }
    }
    else if (dir == 4){//check down
      if (y != 19 && world.board[y+1][x] == '-'){
        newy = y+1; newx = x; bred = true;
      }
    }
    if (bred == true){
      Ant* ant = new Ant(newx,newy);
      world.ants.push_back(*ant);
      world.board[ant->y][ant->x] = ant->value();
      iter = 0;
      return true;
    }
  }
  return false;
}
void Ant::move(World& world){
  srand(time(NULL));
  int dir = rand() % 4 + 1;
  Organism::move(world, dir);
  if (iter >= 3){
    //dir = rand() % 4 + 1;
    breed(world, dir);
  }
}

/*
bool DoodleBug::breed(World& world, const int& dir){
  int newx = 0; int newy = 0; bool bred = false;
  if (iter >= 8){
    if (dir == 1){ //check up
      if (y != 0 && world.board[y-1][x] == '-'){
        newy = y-1; newx = x; bred = true;
      }
    }
    else if (dir == 2){ //check right
      if (x != 19 && world.board[y][x+1] == '-'){
        newx = x+1; newy = y; bred = true;
      }
    }
    else if (dir == 3){ // check left
      if (x != 0 && world.board[y][x-1] == '-'){
        newx = x-1; newy = y; bred = true;
      }
    }
    else if (dir == 4){//check down
      if (y != 19 && world.board[y+1][x] == '-'){
        newy = y+1; newx = x; bred = true;
      }
    }
    if (bred == true){
      cout << "Successfully bred" << endl;
      DoodleBug* db = new DoodleBug(newx,newy);
      world.dbs.push_back(*db);
      world.board[db->y][db->x] = db->value();
      iter = 0;
      return true;
    }
  }
  return false;
}
void DoodleBug::move(World& world){
  bool ate = false;
  if (world.board[y-1][x] == 'o'){
    for(int i = 0; i < world.ants.size(); i++){
      if (world.ants[i].getX() == x && world.ants[i].getY() == y-1){
        swap(world.ants[i],world.ants[world.ants.size()-1]);
        world.ants.pop_back();
        ate = true; notEaten = 0;
        world.board[y-1][x] = value();
      }
    }
  }
  else if (world.board[y+1][x] == 'o'){
    for(int i = 0; i < ants.size(); i++){
      if (world.ants[i].getX() == x && world.ants[i].getY() == y+1){
        swap(world.ants[i],world.ants[world.ants.size()-1]);
        world.ants.pop_back();
        ate = true; notEaten = 0;
        world.board[y+1][x] = value();
      }
    }
  }
  else if (world.board[y][x-1] == 'o'){
    for(int i = 0; i < ants.size(); i++){
      if (world.ants[i].getX() == x-1 && world.ants[i].getY() == y){
        swap(world.ants[i],world.ants[world.ants.size()-1]);
        world.ants.pop_back();
        ate = true; notEaten = 0;
        world.board[y][x-1] = value();
      }
    }
  }
  else if (world.board[y][x+1] == 'o'){
    for(int i = 0; i < world.ants.size(); i++){
      if (world.ants[i].getX() == x+1 && world.ants[i].getY() == y){
        swap(world.ants[i],world.ants[world.ants.size()-1]);
        world.ants.pop_back();
        ate = true; notEaten = 0;
        world.board[y][x+1] = value();
      }
    }
  }
  
  if (ate == false){
    notEaten++;
    if (notEaten == 3){ //starve attribute
        for(int i = 0; i < world.dbs.size();i++){
          if(dbs[i].getX() == x && dbs.[i].getY() == y){
            swap(world.dbs[i],world.dbs[world.dbs.size()-1]);
            world.dbs.pop_back();
            world.board[y][x] = '-'
          }
        }
    }
    else {
      srand(time(NULL));
      int dir = rand() % 4 + 1;
      Organism::move(world, dir);
      if (iter >= 8){
          //dir = rand() % 4 + 1;
          breed(world, dir);
      }
    }
  }  
}*/