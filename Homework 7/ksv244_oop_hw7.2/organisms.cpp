#include "organisms.h"
#include "world.h"
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

int chooseMove(const vector<int> move){ // randomly choose a move based on a vector that is passed in
  if (move.size()==0) return -1; //extra safety -- this should never happen
  int dir = rand() % (move.size()-1) + 0;
  return move[dir]; // this outputs the move of the index
}

bool Ant::canbreed() const{return iter >= 3;}
bool DoodleBug::canbreed() const{return iter >= 8;}
bool Organism::canbreed() const {return false;}

char Organism::value() const{return 'r';}
char Ant::value() const{return 'o';}
char DoodleBug::value() const{return 'X';}

/* These ultimately do not serve any use, so I am going to omit!
void Organism::setX(const int& newx){x = newx;}
void Organism::setY(const int& newy){y = newy;}
int Organism::getX() const{return x;}
int Organism::getY() const{return y;}
*/

bool DoodleBug::starve(){return notEaten == 3;}
bool Organism::starve(){return false;} //by default an organism will not starve

void Organism::move(){
  if (world->validMoveVec(x,y).size() > 0){ // valid move vec will return a 0 if there are no possible valid moves
    int dir = chooseMove(world->validMoveVec(x,y));
  
    if (dir == 1){ // check up
        world->board[y-1][x] = world->board[y][x];
        world->board[y][x] = nullptr;
        y--;
    }
    else if (dir == 2){ //check up right
        world->board[y][x+1] = world->board[y][x];
        world->board[y][x] = nullptr;
        x++;
    }
    else if (dir == 3){ //check left
        world->board[y][x-1] = world->board[y][x];
        world->board[y][x] = nullptr;
        x--;
    }
    else if (dir == 4){//check down
        world->board[y+1][x] = world->board[y][x];
        world->board[y][x] = nullptr;
        y++;
    }
  }
  iter++;
}

bool Organism::breed(){
  int newx = 0; int newy = 0; bool bred = false;
  if (world->validMoveVec(x,y).size() == 0) return false;
  int dir = chooseMove(world->validMoveVec(x,y));
  if (dir == 1){ //check up
    if (y != 0 && world->board[y-1][x] == nullptr){
      newy = y-1; newx = x; bred = true;
    }
  }
  else if (dir == 2){ //check right
    if (x != 19 && world->board[y][x+1] == nullptr){
      newx = x+1; newy = y; bred = true;
    }
  }
  else if (dir == 3){ // check left
    if (x != 0 && world->board[y][x-1] == nullptr){
      newx = x-1; newy = y; bred = true;
    }
  }
  else if (dir == 4){//check down
    if (y != 19 && world->board[y+1][x] == nullptr){
      newy = y+1; newx = x; bred = true;
    }
  }
  if (bred == true){
      //cout << "Successfully bred" << endl;
      if (world->board[y][x]->value() == 'o'){
        world->board[newy][newx] = new Ant(world,newx,newy);
      }
      else if (world->board[y][x]->value() == 'X' ){
        world->board[newy][newx] = new DoodleBug(world,newx,newy);
      }
      iter = 0;
      return true;
    }
  return false;
}

//move a doodlebug
void DoodleBug::move(){
  if (eatAnt(x,y) == false){
      notEaten++;
      Organism::move();
  } else notEaten = 0;
}

bool DoodleBug::eatAnt(int x, int y) {
    vector<int> move;
    // determine when to eat the ant
    if (world->board[y-1][x]->value() == 'o'){move.push_back(1); } // push back the location
    else if (world->board[y][x+1]->value() == 'o'){move.push_back(2);}
    else if (world->board[y][x-1]->value() == 'o'){move.push_back(3);}
    else if (world->board[y+1][x]->value() == 'o'){ move.push_back(4);}
    if (move.size() == 0) return false; //if a doodlebug can't eat then return false to exit
    int dir = chooseMove(move); //randomly choose a location out of the existing locations
    if (dir == 1){ //check up
      world->board[y-1][x] = world->board[y][x];
      world->board[y][x] = nullptr;
    }
    else if (dir == 2){ //check right
      world->board[y][x+1] = world->board[y][x];
      world->board[y][x] = nullptr;
    }
    else if (dir == 3){ // check left
      world->board[y][x-1] = world->board[y][x];
      world->board[y][x] = nullptr;
    }
    else if (dir == 4){//check down
      world->board[y+1][x] = world->board[y][x];
      world->board[y][x] = nullptr;
    }
    return true; //return true
}