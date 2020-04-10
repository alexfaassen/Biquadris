#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include "block.h"

class Level {
	int seed;
	int identifier;
	fstream *file;
	public:
	void updateSeed(const int newSeed);

	virtual Block *CreateBlock() = 0;
};

#endif
