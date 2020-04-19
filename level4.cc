#include "level4.h"
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Level4::~Level4() {
	if (heavy) heavy->kill();
	if (centreDrop) centreDrop->kill();
}

Level4::Level4(const Level &other) : Level(other) {
	identifier = 4;
	heavy = new HeavyEffect();
	centreDrop = new CentreDropEffect();
}

Level4::Level4(const int playerSide, int identifier) : Level(playerSide, identifier) {
	heavy = new HeavyEffect();
	centreDrop = new CentreDropEffect();
}

void Level4::generateEffects(Player &p) const { 
	p.pushToObservers(heavy);
	p.pushToObservers(centreDrop);
}

Block *Level4::CreateBlock() {	
	cout << "test: level4 calling CreateBlock()" << endl;
	if (file) {
		// No random
		if (file->eof()) {
			file->clear();
			file->seekg(0);
		}
		char b = ' ';
		while (b == ' ') *file >> b;
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
