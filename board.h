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
	Block *currentBlock = nullptr;	
	Block *nextBlock = nullptr;
	std::vector <Block *> placed;

	//Board DOES NOT have ownership of the following. DO NOT call delete on these
	Tile* immobileTiles[11][15];
	Level* level = nullptr;

	
	bool rowIsFull(int row);	//checks if the given row is complete
	void clearRow(int row);		//kills all the tiles in the row drops everything down

	bool alive = 1;
	
	public:
	//constructor and destructor
	Board(Level*);
	~Board();

	bool isAlive() const{return alive;};

	// moves currentBlock into placed, nextBlock into currentBlock, and generates nextBlock. 
	// Returns if successful. If safe, will not do anything if currentBlock is not nullptr
	bool pushNextBlock(bool safe = true);

	// moves currentBlock into placed and its tiles into immobileTiles. Sets currentBlock to nullptr
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

	// deals with the heaviness stuff
	void weighDownCurrent();

	// are any of currentBlock's tiles on an occupied tile?
	bool isCurrentBlocked();

	//will moving currentBlock by the given coords cause it to collide with a tile?
	bool isMoveBlocked(int deltaY, int deltaX);	

	// returns if the given coord isn't occupied by a tile and isn't out of bounds
	bool isEmpty(int y, int x);

	void setNewLevel(Level *newLevel);

	std::vector<std::vector<char>> renderCharArray();
	void forceTopColumnTile(const char b, const int col);
	std::string printNextBlock();
	void kill();
};

#endif
