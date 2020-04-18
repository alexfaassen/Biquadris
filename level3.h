#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3 : public Level {
	public:
	Level3(const int playerSide, int identifier = 3);
	Level3(const Level &other);
	Level3(const Level4 &other);
	~Level3();

	void generateEffects(std::vector<Observer*> &vec) const override;
	Block *CreateBlock() override;
};

#endif
