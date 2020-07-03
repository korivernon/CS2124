#include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>

#include "world.h"
#include "organisms.h"

using namespace std;

int main() {
  World world;
  //world.printBoard();
  world.loadBoard();
  //world.printBoard();
  for (int i = 0; i < 100; i++){
    int loc = world.randomize();
    Ant org(loc);
    world.placeAnt(org);
  }
  for (int i = 0; i < 5; i++){
    int loc = world.randomize();
    DoodleBug org(loc);
    world.placeDoodleBug(org);
  }
  world.passTime();
}
