#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>

class Tile;
class PlayerWindow;
class BlockTilewrapper;

class Block {
	char type;
	int initLevel, heaviness = 0;
	bool curr = false;
	std::vector<BlockTilewrapper> tiles;
	PlayerWindow* window = nullptr;

	//set block types
	void IBlock(int x, int y);
	void JBlock(int x, int y);
	void LBlock(int x, int y);
	void OBlock(int x, int y);
	void SBlock(int x, int y);
	void ZBlock(int x, int y);
	void TBlock(int x, int y);
	void tileDropBlock(int x, int y);

	public:
	//constructors
	Block(char type, int initLevel, int heavy = 0, int x = 0, int y = 0);
	~Block();

	//movement
	void move(int deltaX, int deltaY);
	void clockwise();
	void counterClockwise();

	//accessors
	char getType() const {return type;};
	int getInitLevel() const {return initLevel;};
	std::vector<BlockTilewrapper>& getTiles() {return tiles;};
	int getHeaviness() const {return heaviness;};
	void attachWindow(PlayerWindow* w = nullptr);
	void nowCurr() {curr = true;};

	//maintainence
	bool alive();
	bool deleteTiles();

	//text
	std::string printBlock() const;

	//drawing
	void draw();
	void undraw();
	void customDraw(int deltaX, int deltaY);
};


#endif
