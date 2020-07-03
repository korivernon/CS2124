#include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>

#include "world.h"
#include "organisms.h"

using namespace std;

int main() {
  srand(time(NULL)); //so we can use random
  World world;
  world.printBoard();
  world.loadBoard();
  world.printBoard();
  world.passTime();
}
