#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3 : public Level {
	public:
	Level3(bool customSeed = 0, int seed = 1, int identifier = 3, std::ifstream *file = NULL, const int playerID, Effect *heavy);
	Level3(const Level &other);
	~Level3();

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
