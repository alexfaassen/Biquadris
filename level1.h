#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(bool customSeed = 0, int seed = 1, int identifier = 1, std::ifstream *file = NULL, const int playerSide);
	Level1(const Level &other);
	~Level1();

	Block *CreateBlock() override;
};

#endif
