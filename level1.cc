#include "level1.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Level1::Level1(const Level &other) : Level(other) { identifier = 1; }

Level1::Level1(const int playerSide, int identifier) : Level(playerSide, identifier) {}

Block *Level1::CreateBlock() {	
	cout << "test: level1 calling CreateBlock()" << endl;
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
