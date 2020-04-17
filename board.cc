#include <vector>
#include <string>
#include "board.h"
#include "block.h"
#include "level.h"

using namespace std;

Board::Board(){}

Board::~Board(){
	delete currentBlock;
	delete nextBlock;
	for(auto p : placed){
		delete p;
	}
}

void Board::pushNextBlock(){
	placeCurrent();
	currentBlock = nextBlock;
	nextBlock = level->CreateBlock();
}

void Board::placeCurrent(){
	placed.emplace_back(currentBlock);
	for (auto p : currentBlock->getTiles()){
		immobileTiles[p.getX()][p.getY()] = &p;
	}
}

//TODO: needs some rewriting
int Board::eotClean(int *score) {
	int rowsRemoved = 0;
	bool fullRow = true;
	while(fullRow) {
		for(int i =0; i < 11; i++) {
			if(immobileTiles[14][i]->getLetter() == ' ') {
				fullRow = false;
				break;
			}
		}
		if(!fullRow)break;
		rowsRemoved++;
		for(int i = 13; i > 0; i--) {
			for(int j = 0; j < 11; j++) {
				char newLetter = immobileTiles[i][j]->getLetter();
				immobileTiles[i + 1][j]->setLetter(newLetter);
			}
		}
		for(int i = 0; i < 11; i++) {
			immobileTiles[0][i]->setLetter(' ');
		}
		for(auto b : placed) {
			b.move(0,-1);
			if(!b.alive()) {
				int blockScore = (b.initLevel + 1) * (b.initLevel + 1);
				score = score + blockScore;
			}
			b.erase();
		}

	}
	int rowsScore = (rowsRemoved * level->getIdentifier()) * (rowsRemoved * level->getIdentifier());
       	score = score + rowsScore;	
	return rowsRemoved;
}

//TODO: needs some rewriting
void Board::changeCurrent(char newType) {
	Block *newBlock = new Block{newType, level->getIdentifier(), 0, 2};
	Block *oldCurrBlock = currentBlock;
	currentBlock = newBlock;
	delete oldCurrBlock;	
}

//TODO: needs some rewriting
int Board::moveCurrent(Direction dir, int amount) {
	int deltaX = 0, deltaY = 0;
	switch(dir) {
		case Left: deltaX = -1;
		case Right: deltaX = 1;
		case Down: deltaY = -1; 
	}
	int moveCount = 0, newX, newY;
	while(moveCount < amount) {
		for(int i = 0; i < 4; i++) {
			newX = currentBlock.tiles[i].getX() + deltaX;
			newY = currentBlock.tiles[i].getY() + deltaY;
			if(isBlocked(newX, newY))break;
		}
		if(isBlocked(newX, newY))break;
		else currentBlock->move(deltaX, deltaY);
		moveCount++;
	}	
}

bool Board::clockwiseCurrent() {
	currentBlock->clockwise();
}

bool Board::counterClockwiseCurrent() {
	currentBlock->counterClockwise();
}

void Board::dropCurrent() {
	bool atBottom = false;
	while(true) {
		for(int i = 0; i < 4; i++) {
			atBottom = isBlocked(currentBlock->getX(), currentBlock->getY() - 1);
			if(atBottom)break;
		}
		if(atBottom)break;
		for(int i = 0; i < 4; i++) {
			currentBlock->setY(currentBlock->getY() - 1);
		}
	}
}


bool Board::isBlocked(int deltaX, int deltaY){
	Tile &tiles[4] = currentBlock->getTiles();
	int x, y;
	for (int i = 0; i < 4; ++i) {
		x = tiles[i].getX();
		y = tiles[i].getY();
		if (x + deltaX < 0 || x + deltaX > 10 || y + deltaY < 0 || y + deltaY > 14 || immobileTiles[x + deltaX][y + deltaY]) return true;
	}
	return false;
}

bool Board::isEmpty(int x, int y) {
	if(!immobileTiles[x][y])return true;
	return false;	
}

vector<vector<char>> &Board::renderCharArray() {
	vector<vector<char>> vec; 
	for(int i = 0; i < 3; i ++){
		vec.emplace_back(vector<char>(11, ' '));
	}
	for(int x = 0; x < 15; x++) {
		for(int y = 0; y < 11; y++) {
			if(!immobileTiles[x][y]){ 
				vec.at(x).emplace_back(' ');
			} else {
				vec.at(x).emplace_back(immobileTiles[x][y]->getLetter());
			}
		}
		vec.emplace_back(vector<char>());
	}
	int currX, currY;
	for(int i = 0; i < 4; i++) {
		currX = currentBlock->getTiles[i].getX();
		currY = currentBlock->getTiles[i].getY();
		vec.at(currX + 3).at(currY) = currentBlock->getType();
	}
	return vec;
}

void Board::forceTopColumnTile(Tile *colTile) {
	if(isBlocked(colTile.getX(), colTile.getY() + 1))return;
	immobileTile[colTile.getY()][colTiles.getX()].setLetter(' ');
	colTile.setY(colTile.getY() + 1);
	immobileTile[colTile.getY()][colTiles.getX()].setLetter('*');
}

//TODO: needs some rewriting
string Board::printNextBlock() {	
	string str = "";
	bool isTile = false;
	for(int i = 2; i > 0; i++) {
		for(int j = 0; j < 11; j++) {
			for(int k = 0; k < 4; k++) {
				if(nextBlock.getTiles()[k]->getX() == j && nextBlock.getTiles[k]->getY() == i) {
					str += nextBlock->getType();
					isTile = true;
					break;
				}
			}
			if(!isTile)str += " ";
			isTile = false;
		}
		str += "\n";
	}
}


