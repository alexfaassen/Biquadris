#include "level0.h"
#include <iostream>

using namespace std;

Level0::Level0(const Level &other, string sf) 
: Level(other) { 
	identifier = 0; 
	scriptfile = new ifstream(sf);
}

Level0::Level0(const int playerSide, string sf, int identifier) 
: Level(playerSide, identifier) {
	scriptfile = new ifstream(sf);
}

Level0::~Level0(){
	delete scriptfile;
}

Block *Level0::CreateBlock() {
	if (file) {
		// No random
		char b = ' ';
		if (!(*file >> b)) {
			file->clear();
			file->seekg(0);
		}
		while (b == ' ') *file >> b;
		return new Block(b, identifier);
	} else {
		char b = ' ';
		while (b == ' '){
			if (!(*scriptfile >> b)) {
				scriptfile->clear();
				scriptfile->seekg(ios::beg);
			}
		}
		return new Block(b, identifier);
	}
}

