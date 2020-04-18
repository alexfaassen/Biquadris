#include "level1.h"
#include <stdlib>
#include <ctime>

Level1::~Level1() { delete file; }

Level1::Level1(const Level &other) : Level(other) { identifier = 1; }

Level1::Level1(const int playerSide, int identifier) : Level(playerSide, identifier) {}

Block *Level1::CreateBlock() {	
	if (customSeed) {
		srand(seed);
	} else {
		srand(time(0));
	}
	int num = 1 + (rand() % 12);
	if (num == 1) {
		return new Block('Z', identifier);
	} else if (num == 2) {
		return new Block('S', identifier);
	} else if (num == 3 || num == 4) {
		return new Block('I', identifier);
	} else if (num == 5 || num == 6) {
		return new Block('J', identifier);
	} else if (num == 7 || num == 8) {
		return new Block('O', identifier);
	} else if (num == 9 || num == 10) {
		return new Block('L', identifier);
	} else {
		return new Block('T', identifier);
	}
}
