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

void Board::changeCurrent(char newType) {
	Block *newBlock = new Block{newType, level->getIdentifier(), 0, 2};
	Block *oldCurrBlock = currentBlock;
	currentBlock = newBlock;
	delete oldCurrBlock;
}

int Board::moveCurrent(Direction dir, int amount) {
	int deltaX = 0, deltaY = 0;
	switch(dir) {
		case Left: deltaX = -1;
		case Right: deltaX = 1;
		case Down: deltaY = 1; 
	}
	int moveCount = 0;
	while(moveCount < amount) {
		if(isMoveBlocked(deltaX, deltaY)){
			break;
		}
		currentBlock->move(deltaX, deltaY);
		moveCount++;
	}
	return moveCount;	
}

bool Board::clockwiseCurrent() {
	currentBlock->clockwise();
}

bool Board::counterClockwiseCurrent() {
	currentBlock->counterClockwise();
}

void Board::dropCurrent() {
	while(moveCurrent(Down, 1)){}
}


bool Board::isMoveBlocked(int deltaX, int deltaY){
	for (int i = 0; i < 4; ++i) {
		if (!isEmpty(currentBlock->getTiles[i].getX(), currentBlock->getTiles()[i].getY())) return true;
	}
	return false;
}

bool Board::isEmpty(int x, int y) {
	if(x < 0 || x > 10 || y > 14 || y < -3) return false;	//bounds checking sides
	if(y >= -3 && y < 0) return true;						//exception for the 3 extra lines on top
	if(!immobileTiles[x][y])return true;					//checking for empty tile within bounds
	return false;											//otherwise fail
}

vector<vector<char>> &Board::renderCharArray() {
	vector<vector<char>> vec; 
	for(int i = 0; i < 3; i ++){
		vec.emplace_back(vector<char>(11, ' '));
	}
	for(int y = 0; y < 15; y++) {
		for(int x = 0; x < 11; x++) {
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


