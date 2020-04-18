#include "level2.h"
#include <cstdlib>
#include <ctime>

Level2::Level2(const Level &other) : Level(other) { identifier = 2; }

Level2::Level2(const int playerSide, int identifier) : Level(playerSide, identifier) {}

Block *Level2::CreateBlock() {	
	if (customSeed) {
		srand(seed);
	} else {
		srand(time(0));
	}
	int num = 1 + (rand() % 7);
	if (num == 1) {
		return new Block('Z', identifier);
	} else if (num == 2) {
		return new Block('S', identifier);
	} else if (num == 3) {
		return new Block('I', identifier);
	} else if (num == 4) {
		return new Block('J', identifier);
	} else if (num == 5) {
		return new Block('O', identifier);
	} else if (num == 6) {
		return new Block('L', identifier);
	} else {
		return new Block('T', identifier);
	}
}
