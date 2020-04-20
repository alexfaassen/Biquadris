#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include "heavyeffect.h"
#include "centredropeffect.h"

class Player;

class Level4 : public Level {
	CentreDropEffect *centreDrop = nullptr;

	public:
	Level4(const int playerSide, int identifier = 4);
	Level4(const Level &other);
	~Level4();

	void generateEffects(Player &p) const override;
	Block *CreateBlock() override;
};

#endif
