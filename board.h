#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <string>
#include "tile.h"
#include "direction.h"

class Block;
class Level;

class Board {
	// Board has ownership of the following
	Block *currentBlock;	
	Block *nextBlock;
	std::vector <Block *> placed;

	//Board DOES NOT have ownership of the following. DO NOT call delete on these
	Tile* immobileTiles[15][11];
	Level* level;
	
	public:
	//constructor and destructor
	Board();
	~Board();

	// moves currentBlock into placed, nextBlock into currentBlock, and generates nextBlock
	void pushNextBlock();

	// moves currentBlock into placed and its tiles into immobileTiles
	void placeCurrent();

	// handles everything that needs to be called at end of turn
	int eotClean(int *score);

	void changeCurrent(char newType);
	void setNext(Block *nex);
	int moveCurrent(Direction, int amount);
	bool clockwiseCurrent();
	bool counterClockwiseCurrent();
	void dropCurrent();

	//will moving currentBlock by the given coords cause it to collide with a tile?
	bool isBlocked(int deltaX, int deltaY);	

	// returns if the given coord isn't occupied by a tile
	bool isEmpty(int x, int y);

	std::vector<std::vector<char>> &renderCharArray();
	void forceTopColumnTile(Tile *colTile);
	std::string printNextBlock();
};

#endif
