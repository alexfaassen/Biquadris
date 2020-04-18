#include "level4.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Level4::~Level4() { delete heavy; delete centreDrop; delete file; }

Level4::Level4(const Level &other) : Level(other), heavy{new HeavyEffect()}, centreDrop{new CentreDropEffect()} { identifier = 4; }

Level4::Level4(const Level3 &other) : Level(other), heavy{other.heavy}, centreDrop{new CentreDropEffect()} { identifier = 4; }

Level4::Level4(const int playerSide, int identifier) : Level(playerSide, identifier) { heavy = new HeavyEffect(); centreDrop = new CentreDropEffect(); }

void Level4::generateEffects(std::vector<Observer*> &vec) const { vec.emplace_back(heavy); vec.emplace_back(centreDrop); }

Block *Level4::CreateBlock() {	
	if (file) {
		// No random
		char b;
		file >> b;
		return new Block(b, identifier);
	} else {
		// Random
		if (customSeed) {
			srand(seed);
		} else {
			srand(time(0));
		}
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
