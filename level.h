#ifndef LEVEL_H
#define LEVEL_H
#include "observer.h"
#include "block.h"

#include <fstream>
#include <vector>

class Level {
	protected:
	const int playerSide;
	int identifier;
	bool customSeed = 0;
	int seed = 1;
	std::ifstream *file = nullptr;

	Level(const int playerSide, int identifier) : playerSide{playerSide}, identifier{identifier} {}
	Level(const Level &other) : playerSide{other.playerSide}, customSeed{other.customSeed}, seed{other.seed}, file{other.file} {}

	public:
	virtual ~Level();
	
	// accessors
	int getIdentifier() const;
	bool setFile(std::ifstream *newFile);
	void updateSeed(const int newSeed);

	virtual void generateEffects(std::vector<Observer*> &vec) const;
	virtual Block *CreateBlock() = 0;
};

#endif
