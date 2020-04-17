#include <vector>
#include <string>
#include "board.h"
#include "block.h"
#include "level.h"

using namespace std;

bool Board::rowIsFull(int row){
	for(int x = 0; x < 11; ++x){
		if(!immobileTiles[x][row]) return false;
	}
	return true;
}

void Board::clearRow(int row){
	//kill every tile on that row
	for(int x = 0; x < 11; ++x){
		if(immobileTiles[x][row]) immobileTiles[x][row]->kill();
	}
	//move everything above it down
	for(int y = row; y > 0; --y){
		for(int x = 0; x < 11; ++x){
			immobileTiles[x][y] = immobileTiles[x][y+1];
		}
	}
	//make top row empty
	for(int x = 0; x < 11; ++x){
		immobileTiles[x][0] = nullptr;
	}
}

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

int Board::eotClean(int *score) {
	int rowsRemoved = 0;

	//remove completed rows
	for(int y = 0; y < 15; y++){
		if(rowIsFull(y)){
			clearRow(y);
			rowsRemoved++;
		}
	}

	//erase dead blocks and score them
	for(int i = 0; i < placed.size(); i++){
        if(!placed.at(i)->alive()){
			score += (placed.at(i)->getInitLevel() + 1) * (placed.at(i)->getInitLevel() + 1);
            delete placed.at(i);
            placed.erase(placed.begin()+i);
            i--;
        }
    }

	//scores removed rows
	int rowsScore = (rowsRemoved * level->getIdentifier()) * (rowsRemoved * level->getIdentifier());
    score += rowsScore;	
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
		if (!isEmpty(currentBlock->getTiles[i].getX() + deltaX, currentBlock->getTiles()[i].getY() + deltaY)) return true;
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


