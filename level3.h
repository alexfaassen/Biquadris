#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include "heavyeffect.h"

class Player;

class Level3 : public Level {

	public:
	Level3(const int playerSide, int identifier = 3);
	Level3(const Level &other);
	~Level3();

	void generateEffects(Player &p) const override;
	Block *CreateBlock() override;
};

#endif
