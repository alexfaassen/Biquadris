#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "tile.h"

class Block {
	char type;
	int initLevel, heaviness = 0;
	std::vector<Tile*> tiles;

	public:
	//constructors
	Block(char type, int initLevel, int heavy = 0, int x = 0, int y = 0);
	~Block();

	//set block types
	void iBlock(int x, int y);
	void jBlock(int x, int y);
	void lBlock(int x, int y);
	void oBlock(int x, int y);
	void sBlock(int x, int y);
	void zBlock(int x, int y);
	void tBlock(int x, int y);
	void tileDropBlock(int x, int y);

	//movement
	void move(int deltaX, int deltaY);
	void clockwise();
	void counterClockwise();

	//accessors
	char getType() const {return type;};
	int getInitLevel() const {return initLevel;};
	std::vector<Tile*>& getTiles() {return tiles;};
	std::string printBlock() const;
	int getHeaviness() const {return heaviness;};

	//maintainence
	bool alive();
	void deleteTiles();
};


#endif
