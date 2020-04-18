#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"
#include "heavyeffect.h"
#include "centredropeffect.h"
#include "level3.h"

class Level4 : public Level {
	HeavyEffect *heavy = new HeavyEffect();
	CentreDropEffect *centreDrop = new CentreDropEffect();

	public:
	Level4(const int playerSide, int identifier = 4);
	Level4(const Level &other);
	~Level4();

	void generateEffects(std::vector<Observer*> &vec) const override;
	Block *CreateBlock() override;
};

#endif
