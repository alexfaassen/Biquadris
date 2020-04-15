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
	
	// abstract ctor
	Level(bool customSeed = 0; int seed = 1, int identifier, std::fstream *file = NULL, const int playerSide) : customSeed{customSeed}, seed{seed}, identifier{identifier}, file{file}, playerSide{playerSide} {}
	Level(const Level &other) : customSeed{other.customSeed}, seed{other.seed}, identifier{other.identifier}, file{other.file}, playerSide{other.playerSide} {}

	public:
	virtual ~Level();

	// getters/setters
	int getIdentifier() const;
	bool setFile(std::ifstream *newFile);
	void updateSeed(const int newSeed);

	virtual void generateEffects(std::vector<Observer*> &vec) const = 0;
	virtual Block *CreateBlock() = 0;
};

#endif
