#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2 : public Level {
	public:
	Level2(bool customSeed, int seed, int identifier = 2, std::ifstream *file, const int playerSide);

	Block *CreateBlock() override;
};

#endif
