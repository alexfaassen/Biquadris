#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"

class Level1 : public Level {
	public:
	Level1(const int playerSide, int identifier = 1);
	Level1(const Level &other);

	Block *CreateBlock() override;
};

#endif

