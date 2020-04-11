#include "level1.h"
#include <stdlib>
#include <ctime>

Level1::Level1(bool customSeed, int seed, int identifier, ifstream *file, const int playerID) : Level(customSeed, seed, identifier, file, playerID) {}

Block *Level1::CreateBlock() {	
	if (customSeed) {
		srand(seed);
	} else {
		srand(time(0));
	}
	int num = 1 + (rand() % 12);
	if (num == 1) {
		return new Block('Z');
	} else if (num == 2) {
		return new Block('S');
	} else if (num == 3 || num == 4) {
		return new Block('I');
	} else if (num == 5 || num == 6) {
		return new Block('J');
	} else if (num == 7 || num == 8) {
		return new Block('O');
	} else if (num == 9 || num == 10) {
		return new Block('L');
	} else {
		return new Block('T');
	}
}
