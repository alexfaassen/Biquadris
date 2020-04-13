#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Level3 : public Level {
	public:
	Level3(bool customSeed, int seed, int identifier = 3, std::ifstream *file, const int playerID, Effect *heavy);
	Level3(Level &&other);
	~Level3();

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
