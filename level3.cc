#include "level3.h"
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Level3::~Level3() {
}

Level3::Level3(const Level &other) : Level(other) {
	identifier = 3;
}

Level3::Level3(const int playerSide, int identifier) : Level(playerSide, identifier) {
}

void Level3::generateEffects(Player &p) const { 
}

Block *Level3::CreateBlock() {	
	if (file) {
		// No random
		char b = ' ';
		if (!(*file >> b)) {
			file->clear();
			file->seekg(ios::beg);
		}
		while (b == ' ') *file >> b; 
		return new Block(b, identifier);
	} else {
		// Random
		int num = 1 + (rand() % 9);
		if (num == 1 || num == 2) {
                        return new Block('Z', identifier);
		} else if (num == 3 || num == 4) {
			return new Block('S', identifier, 1);
		} else if (num == 5) {
			return new Block('I', identifier, 1);
		} else if (num == 6) {
			return new Block('J', identifier, 1);
		} else if (num == 7) {
			return new Block('O', identifier, 1);
		} else if (num == 8) {
			return new Block('L', identifier, 1);
		} else {
			return new Block('T', identifier, 1);
		}
	}
}
