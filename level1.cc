#include "level1.h"
#include <stdlib>

Level1::Level1(int seed, int identifier, ifstream *file, const int playerID) : Level(seed, identifier, file, playerID) { identifier = 1; }

Block *Level1::CreateBlock() {
