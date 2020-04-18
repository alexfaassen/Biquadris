#ifndef LEVEL_H
#define LEVEL_H
#include "observer.h"
#include "block.h"

#include <fstream>
#include <vector>

class Level {
	const int playerSide;
	const int identifier;
	bool customSeed = 0;
	int seed = 1;
	std::ifstream *file = NULL;
	
	public:
	Level(const int playerSide, int identifier) : playerSide{playerSide}, identifier{identifier} {}
	Level(const Level &other) : playerSide{other.playerSide}, identifier{other.identifier}, customSeed{other.customSeed}, seed{other.seed}, file{other.file} {}
	virtual ~Level();

	// getters/setters
	int getIdentifier() const;
	bool setFile(std::ifstream *newFile);
	void updateSeed(const int newSeed);

	virtual void generateEffects(std::vector<Observer*> &vec) const;
	virtual Block *CreateBlock() = 0;
};

#endif
