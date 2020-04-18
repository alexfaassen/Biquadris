#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(const int playerSide, int identifier = 1, bool customSeed = false, int seed = 1, std::ifstream *file = NULL);
	Level1(const Level &other);
	~Level1();

	Block *CreateBlock() override;
};

#endif
