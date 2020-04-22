#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Level2 : public Level {
	public:
	Level2(const int playerSide, int identifier = 2);
	Level2(const Level &other);

	Block *CreateBlock() override;
};

#endif

