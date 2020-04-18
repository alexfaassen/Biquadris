#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"

class Level0 : public Level {
	public:
	Level0(const int playerSide, int identifier = 0);
	Level0(const Level &other);
	~Level0();

	Block *CreateBlock() override;
};

#endif
