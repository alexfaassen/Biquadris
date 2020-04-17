#include "level3.h"
#include <stdlib>
#include <ctime>
#include <iostream>

Level3::~Level3() { delete heavy; delete file; }

Level3::Level3(const Level &other) : Level(other), heavy{new HeavyEffect(1)} {}

Level3::Level3(const Level4 &other) : Level(other), heavy{other.heavy} {}

Level3::Level3(const int playerSide, bool customSeed, int seed, ifstream *file, Effect *heavy, int identifier) : Level(playerSide, identifier, customSeed, seed, file), heavy{new HeavyEffect(1)} {}

void Level3::generateEffects(std::vector<Observer*> &vec) const override { vec.emplace_back(heavy); }

Block *Level3::CreateBlock() {	
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
