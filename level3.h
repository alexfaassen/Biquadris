#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include "heavyeffect.h"
#include "level4.h"

class Level3 : public Level {
	HeavyEffect *heavy = nullptr;

	public:
	Level3(const int playerSide, int identifier = 3);
	Level3(const Level &other);
	~Level3();

	void generateEffects(std::vector<Observer*> &vec) const override;
	Block *CreateBlock() override;
};

#endif
