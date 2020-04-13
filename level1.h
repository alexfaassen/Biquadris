#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(bool customSeed, int seed, int identifier = 1, std::ifstream *file, const int playerSide);
	Level1(Level &&other);
	~Level1();

	Block *CreateBlock() override;
};

#endif
