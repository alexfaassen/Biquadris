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

	
	bool rowIsFull(int row);	//checks if the given row is complete
	void clearRow(int row);		//kills all the tiles in the row drops everything down

	bool alive = 1;
	
	public:
	//constructor and destructor
	Board();
	~Board();

	// moves currentBlock into placed, nextBlock into currentBlock, and generates nextBlock
	void pushNextBlock();

	// moves currentBlock into placed and its tiles into immobileTiles
	void placeCurrent();

	//moves the given block into placed and its tiles into immobileTiles
	void placeBlock(Block*);

	// handles everything that needs to be called at end of turn
	int eotClean(int *score);

	void changeCurrent(char newType);
	void setNext(Block *nex);
	int moveCurrent(Direction, int amount);
	bool clockwiseCurrent();
	bool counterClockwiseCurrent();
	void dropCurrent();

	//will moving currentBlock by the given coords cause it to collide with a tile?
	bool isMoveBlocked(int deltaX, int deltaY);	

	// returns if the given coord isn't occupied by a tile
	bool isEmpty(int x, int y);

	std::vector<std::vector<char>> &renderCharArray();
	void forceTopColumnTile(const char b, const int col);
	std::string printNextBlock();
};

#endif
