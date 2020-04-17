#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
#include "tile.h"

class Block {
	char type;
	int initLevel;
	Tile tiles[4];

	public:
	//constructors
	Block(string type);
	Block(char type, int initLevel, int x, int y);
	~Block();

	//set block types
	void iBlock(int x, int y);
	void jBlock(int x, int y);
	void lBlock(int x, int y);
	void oBlock(int x, int y);
	void sBlock(int x, int y);
	void zBlock(int x, int y);
	void tBlock(int x, int y);

	//movement
	void move(int deltaX, int deltaY);
	void clockwise();
	void counterClockwise();

	//accessors
	char getType() const {return type;};
	Tile (&getTiles())[4] {return tiles;};

	//maintainence
	bool alive();
};


#endif
