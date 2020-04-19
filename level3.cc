#include "level3.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Level3::~Level3() { delete heavy; delete file; }

Level3::Level3(const Level &other) : Level(other) {
	identifier = 3;
	heavy = new HeavyEffect();
}

Level3::Level3(const int playerSide, int identifier) : Level(playerSide, identifier) {}

void Level3::generateEffects(std::vector<Observer*> &vec) const { vec.emplace_back(heavy); }

Block *Level3::CreateBlock() {	
	cout << "test: level3 calling CreateBlock()" << endl;
	if (file) {
		// No random
		char b;
		*file >> b;
		return new Block(b, identifier);
	} else {
		// Random
		int num = 1 + (rand() % 9);
		if (num == 1 || num == 2) {
                        return new Block('Z', identifier);
		} else if (num == 3 || num == 4) {
			return new Block('S', identifier);
		} else if (num == 5) {
			return new Block('I', identifier);
		} else if (num == 6) {
			return new Block('J', identifier);
		} else if (num == 7) {
			return new Block('O', identifier);
		} else if (num == 8) {
			return new Block('L', identifier);
		} else {
			return new Block('T', identifier);
		}
	}
}
