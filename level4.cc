#include "level4.h"
#include <stdlib>
#include <ctime>
#include <iostream>

Level4::~Level4() { delete heavy; delete centreDrop; delete file; }

Level4::Level4(const Level &other) : Level(other), heavy{new HeavyEffect(1)}, centreDrop{new CentreDropEffect()} {}

Level4::Level4(const Level3 &other) : Level(other), heavy{other.heavy}, centreDrop{new CentreDropEffect()} {}

Level4::Level4(bool customSeed, int seed, int identifier, ifstream *file, const int playerSide, Effect *heavy, Effect *centreDrop) : Level(customSeed, seed, identifier, file, playerSide), heavy{new HeavyEffect(1)}, centreDrop{new CentreDropEffect()} {}

void Level4::generateEffects(std::vector<Observer*> &vec) const override { vec.emplace_back(heavy); vec.emplace_back(centreDrop); }

Block *Level4::CreateBlock() {	
	if (file) {
		// No random
		char b;
		file >> b;
		return new Block(b);
	} else {
		// Random
		if (customSeed) {
			srand(seed);
		} else {
			srand(time(0));
		}
			int num = 1 + (rand() % 9);
		if (num == 1 || num == 2) {
			return new Block('Z');
		} else if (num == 3 || num == 4) {
			return new Block('S');
		} else if (num == 5) {
			return new Block('I');
		} else if (num == 6) {
			return new Block('J');
		} else if (num == 7) {
			return new Block('O');
		} else if (num == 8) {
			return new Block('L');
		} else {
			return new Block('T');
		}
	}
}
