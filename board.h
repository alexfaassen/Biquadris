#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <string>
#include "tile.h"
#include "direction.h"

class Block;
class Level;

class Board {
	Block *currentBlock;
	Block *nextBlock;
	Tile* immobileTiles[15][11];
	std::vector <Block *> placed;
	Level* level;
	
	public:
	//constructor and destructor
	Board();
	~Board();


	int eotClean(int *score);
	void changeCurrent(Block *cur);
	void setNext(Block *nex);
	int moveCurrent(Direction, int amount);
	void clockwiseCurrent();
	void counterClockwiseCurrent();
	void dropCurrent();
	bool isBlocked(int x, int y);
	std::vector<std::vector<char>> renderCharArray();
	void forceTopColumnTile(Tile *colTile);
	std::string printNextBlock();
};

#endif
