#ifdef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "block.h"
#include "tile.h"

class Board {
	Block *currentBlock;
	Block *nextBlock;
	Tiles immobileTiles[15][11];
	vector <Block *> placed;
	
	public:
	enum Direction {left, right, down}
	int eotClean(int *score);
	void changeCurrent(Block *cur);
	void setNext(Block *nex);
	int moveCurrent(Direction, int amount, bool );
	void clockwiseCurrent();
	void counterclockwiseCurrent();
	void dropCurrent();
	bool isBlocked(int x, int y);
	char[][] renderCharArray();
}

#endif


