#include "level2.h"
#include <stdlib>
#include <ctime>

Level2::~Level2() { delete this; }

Level2::Level2(Level &&other) : Level(other) {}

Level2::Level2(bool customSeed, int seed, int identifier, ifstream *file, const int playerSide) : Level(customSeed, seed, identifier, file, playerSide) {}

Block *Level2::CreateBlock() {	
	if (customSeed) {
		srand(seed);
	} else {
		srand(time(0));
	}
	int num = 1 + (rand() % 7);
	if (num == 1) {
		return new Block('Z');
	} else if (num == 2) {
		return new Block('S');
	} else if (num == 3) {
		return new Block('I');
	} else if (num == 4) {
		return new Block('J');
	} else if (num == 5) {
		return new Block('O');
	} else if (num == 6) {
		return new Block('L');
	} else {
		return new Block('T');
	}
}
