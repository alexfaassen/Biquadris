#ifdef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include "tile.h"

class Block {
	char type;
	int initLevel;
	Tile tiles[4];

	public:
	Block(string type);
	Tile[4] iBlock(int x, int y);
	Tile[4] jBlock(int x, int y);
	Tile[4] lBlock(int x, int y);
	Tile[4] oBlock(int x, int y);
	Tile[4] sBlock(int x, int y);
	Tile[4] zBlock(int x, int y);
	Tile[4] tBlock(int x, int y);
	Block(char type, initLevel, tiles);
	void move(int deltaX, int deltaY);
	void clockwise();
	void counterClockwise();
	bool alive();
}


#endif
