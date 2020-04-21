#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <string>
#include "tile.h"
#include "direction.h"
#include "block.h"
#include "immtilewrapper.h"

class Level;
class PlayerWindow;

class Board {
	// Board has ownership of the following
	Block *currentBlock = nullptr;	
	Block *nextBlock = nullptr;
	std::vector <Block *> placed;

	//Board DOES NOT have ownership of the following. DO NOT call delete on these
	//Tilewrapper immobileTiles[11][15];
	std::vector<std::vector<ImmTilewrapper>> immobileTiles;
	Level* level = nullptr;
	PlayerWindow* window = nullptr;

	
	bool rowIsFull(int row);	//checks if the given row is complete
	void clearRow(int row);		//kills all the tiles in the row drops everything down

	bool alive = 1;

	void initImmobileTiles(PlayerWindow* = nullptr);
	Block* CreateBlock();
	
	public:
	//constructor and destructor
	Board(Level*, PlayerWindow* = nullptr);
	~Board();

	bool isAlive() const{return alive;};
	char getNextBlockType() const {return nextBlock->getType();};

	// moves currentBlock into placed, nextBlock into currentBlock, and generates nextBlock. 
	// Return false if isBlocked
	bool pushNextBlock(bool safe = true);

	// moves currentBlock into placed and its tiles into immobileTiles. Sets currentBlock to nullptr
	// fails if isBlocked
	bool placeCurrent();

	//moves the given block into placed and its tiles into immobileTiles
	// fails if isBlocked
	bool placeBlock(Block*, bool draw = false);

	// handles everything that needs to be called at end of turn
	int eotClean(int *score);

	// changes the current block
	// Returns false if isBlocked
	bool changeCurrent(char newType);
	void setNext(Block *nex);
	int moveCurrent(Direction, int amount, bool redraw = true);
	int clockwiseCurrent(int amount = 1, bool redraw = true);
	int counterClockwiseCurrent(int amount = 1, bool redraw = true);
	void dropCurrent(bool redraw = true);

	// deals with the heaviness stuff
	void weighDownCurrent();

	// are any of block's tiles on an occupied tile?
	bool isBlocked(Block* b);
	bool isCurrentBlocked();

	//will moving currentBlock by the given coords cause it to collide with a tile?
	bool isMoveBlocked(int deltaY, int deltaX);	

	// returns if the given coord isn't occupied by a tile and isn't out of bounds
	bool isEmpty(int y, int x);

	std::vector<std::vector<char>> renderCharArray();
	void forceTopColumnTile(const char b, const int col);
	std::string printNextBlock();

	//forces all immobileTiles to redraw
	void redrawBoard();

	void kill();
	void setNewLevel(Level *newLevel);
};

#endif
