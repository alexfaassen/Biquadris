#ifndef LEVEL_H
#define LEVEL_H
#include "observer.h"
#include "block.h"

#include <fstream>

class Level {
	protected:
	const int playerSide;
	int identifier;
	std::ifstream *file = nullptr;

	Level(const int playerSide, int identifier) : playerSide{playerSide}, identifier{identifier} {}
	Level(const Level &other) : playerSide{other.playerSide}, file{other.file} {}

	public:
	virtual ~Level();
	
	//accessors
	int getIdentifier() const;
	bool setFile(std::ifstream *newFile);
	void deleteFile() {if(file) delete file;};

	//level effects
	virtual void generateEffects(Player &p) const;

	//block factory
	virtual Block *CreateBlock() = 0;
};

#endif

