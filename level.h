#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include <vector>
#include "observer.h"
#include "block.h"

class Level {
	bool customSeed;
	int seed;
	int identifier;
	std::ifstream *file;
	const int playerSide;
	
	public:
	Level(const int playerSide, int identifier, bool customSeed = false, int seed = 1, std::ifstream *file = NULL) : playerSide{playerSide}, identifier{identifier}, customSeed{customSeed}, seed{seed}, file{file} {}
	Level(const Level &other) : playerSide{other.playerSide}, identifier{other.identifier}, customSeed{other.customSeed}, seed{other.seed}, file{other.file} {}
	virtual ~Level();

	// getters/setters
	int getIdentifier() const;
	bool setFile(std::ifstream *newFile);
	void updateSeed(const int newSeed);

	virtual void generateEffects(std::vector<Observer*> &vec) const = 0;
	virtual Block *CreateBlock() = 0;
};

#endif
