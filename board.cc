#include <vector>
#include <string>
#include <iostream>
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
			immobileTiles[x][y] = immobileTiles[x][y - 1];
		}
	}
	//make top row empty
	for(int x = 0; x < 11; ++x){
		immobileTiles[x][0] = nullptr;
	}
}

Board::Board(Level* level)
: level{level} {
	//cout << "test: Board ctor starting" << endl;
	for(auto &x : immobileTiles){
		for(auto &p : x){
			p = nullptr;
		}
	}
	nextBlock = level->CreateBlock();
}

Board::~Board(){
	delete currentBlock;
	delete nextBlock;
	for(auto p : placed){
		delete p;
	}
}

bool Board::pushNextBlock(bool safe){
	//cout << "test: if(safe && currentBlock)" << endl;
	if(safe && currentBlock) return false;
	if(!nextBlock)nextBlock = level->CreateBlock();
	//cout << "test: nextBlock type (before switch): " << string(1, nextBlock->getType()) << endl;
	currentBlock = nextBlock;
	//cout << "test: currentBlock type: " << string(1, currentBlock->getType()) << endl;
	//cout << "test: second createBlock" <<endl;
	//cout << "level: " << level->getIdentifier() << endl;
	nextBlock = level->CreateBlock();
	//cout << "test: after second createBlock" <<endl;
	if (isCurrentBlocked()) kill();
	return true;
}

void Board::placeCurrent(){
	//cout << "test: in placeCurrent()" << endl;
	placeBlock(currentBlock);
	currentBlock = nullptr;
}

void Board::placeBlock(Block* b){
	//cout << "test: in placeBlock(b)" << endl;
	placed.emplace_back(b);
	//cout << "test: for (auto p : b->getTiles())" << endl;
	for (auto p : b->getTiles()){
		immobileTiles[p->getX()][p->getY()] = p;
	}
}

int Board::eotClean(int *score) {
	//remove completed rows
	int rowsRemoved = 0;
	for(int y = 0; y < 15; y++){
		if(rowIsFull(y)){
			clearRow(y);
			rowsRemoved++;
		}
	}

	//erase dead blocks and score them
	for(size_t i = 0; i < placed.size(); i++){
        	if(!placed.at(i)->alive()){
			*score += (placed.at(i)->getInitLevel() + 1) * (placed.at(i)->getInitLevel() + 1);
        	    	delete placed.at(i);
            		placed.erase(placed.begin()+i);
           		i--;
       		}
   	}

	//scores removed rows
	int rowsScore = (rowsRemoved + level->getIdentifier()) * (rowsRemoved + level->getIdentifier());
    	*score += rowsScore;
	return rowsRemoved;
}

void Board::changeCurrent(char newType) {
	cout << "test: in board, changeCurrent()" << endl;
	Block *newBlock = new Block(newType, level->getIdentifier());
	Block *oldCurrBlock = currentBlock;
	currentBlock = newBlock;
	if(oldCurrBlock) delete oldCurrBlock;
	if (isCurrentBlocked()) kill();
	cout << "test: end of changeCurrent()" << endl;
}

int Board::moveCurrent(Direction dir, int amount) {
	int deltaX = 0, deltaY = 0;
	if (dir == Left) deltaX = -1;
	else if (dir == Right) deltaX = 1;
	else if (dir == Down) deltaY = 1;
	int moveCount = 0;
	cout << "test: moveCurrent() called" << endl;
	while(moveCount < amount) {
		//cout << "test: isMoveBlocked() called" << endl;
		if(isMoveBlocked(deltaX, deltaY)){
			break;
		}
		//cout << "test: currentBlock->move(deltaX, deltaY) called" << endl;
		currentBlock->move(deltaX, deltaY);
		moveCount++;
	}
	//cout << "test: ENDING WHILE (moveCount < amount) LOOP" << endl;
	return moveCount;	
}

bool Board::clockwiseCurrent() {
	currentBlock->clockwise();
	if(isCurrentBlocked()) {
		currentBlock->counterClockwise();
		return false;
	}
	return true;
}

bool Board::counterClockwiseCurrent() {
	currentBlock->counterClockwise();
	if(isCurrentBlocked()) {
		currentBlock->clockwise();
		return false;
	}
	return true;
}

void Board::dropCurrent() {
	while(moveCurrent(Down, 1)){
		//cout << "test: dropping..." <<endl;
	}
	//cout << "test: before placeCurrent()" << endl;
}

bool Board::isCurrentBlocked(){
	for(auto t : currentBlock->getTiles()){
		if(!isEmpty(t->getX(), t->getY())) return true;
	}
	return false;
}

bool Board::isMoveBlocked(int deltaX, int deltaY){
	for (auto t : currentBlock->getTiles()) {
		if (!isEmpty(t->getX() + deltaX, t->getY() + deltaY)) return true;
	}
	return false;
}

bool Board::isEmpty(int x, int y) {
	if(x < 0 || x > 10 || y > 14 || y < -3) return false;		//bounds checking sides
	if(y >= -3 && y < 0) return true;				//exception for the 3 extra lines on top
	if(!immobileTiles[x][y])return true;				//checking for empty tile within bounds
	return false;							//otherwise fail
}

vector<vector<char>> Board::renderCharArray() {
	vector<vector<char>> vec; 
	//cout << "test: before first for loop" << endl;
	for(int i = 0; i < 3; ++i){
		vec.emplace_back(vector<char>(11, ' '));
	}
	vec.emplace_back(vector<char>());
	//cout << "test: before second for loop" << endl;
	for(int y = 0; y < 15; ++y) {
		for(int x = 0; x < 11; ++x) {
			if(!immobileTiles[x][y]){ 
				vec.at(y + 3).emplace_back(' ');
			} else {
				vec.at(y + 3).emplace_back(immobileTiles[x][y]->getLetter());
			}
		}
		if (y < 14) vec.emplace_back(vector<char>());
	}	
	int currX, currY;
	//cout << "test: before third for loop" << endl;
	if(currentBlock){
		for(auto t : currentBlock->getTiles()) {
			currX = t->getX();
			currY = t->getY();
			vec.at(currY + 3).at(currX) = currentBlock->getType();
		}
	}
	//cout << "test: about to return vec" << endl;
	return vec;
}

void Board::forceTopColumnTile(const char b, const int col) {
	if (!isEmpty(col, 0)) {
		kill();
	} else {
		int row = 14;
		for (int y = 0; y < 15; ++y) {
			if (!isEmpty(col, y)) {
				row = y - 1;
				break;
			}
		}
		//cout << "test: !isEmpty() at row = " << row << endl;
		placeBlock(new Block(b, -1, col, row));
	}
}

string Board::printNextBlock() {	
	if (!nextBlock) return "           \n           \n";
	else return nextBlock->printBlock();
}

void Board::kill() {
	alive = false;
}

void Board::setNewLevel(Level *newLevel) { level = newLevel; }
