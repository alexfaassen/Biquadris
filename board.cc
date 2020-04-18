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

bool Board::pushNextBlock(bool safe){
	if(safe && currentBlock) return false;
	currentBlock = nextBlock;
	nextBlock = level->CreateBlock();
	return true;
}

void Board::placeCurrent(){
	placeBlock(currentBlock);
	currentBlock = nullptr;
}

void Board::placeBlock(Block* b){
	placed.emplace_back(b);
	for (auto p : b->getTiles()){
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
	for(size_t i = 0; i < placed.size(); i++){
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
	Block *newBlock = new Block(newType, level->getIdentifier());
	Block *oldCurrBlock = currentBlock;
	currentBlock = newBlock;
	delete oldCurrBlock;
	if (isCurrentBlocked()) kill();
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
	while(moveCurrent(Down, 1)){}
	placeCurrent();
}

bool Board::isCurrentBlocked(){
	for(auto t : currentBlock->getTiles()){
		if(!isEmpty(t.getX(),t.getY())) return true;
	}
	return false;
}

bool Board::isMoveBlocked(int deltaX, int deltaY){
	for (auto t : currentBlock->getTiles()) {
		if (!isEmpty(t.getX() + deltaX, t.getY() + deltaY)) return true;
	}
	return false;
}

bool Board::isEmpty(int x, int y) {
	if(x < 0 || x > 10 || y > 14 || y < -3) return false;	//bounds checking sides
	if(y >= -3 && y < 0) return true;						//exception for the 3 extra lines on top
	if(!immobileTiles[x][y])return true;					//checking for empty tile within bounds
	return false;											//otherwise fail
}

vector<vector<char>> Board::renderCharArray() {
	vector<vector<char>> vec; 
	cout << "test: before first for loop" << endl;
	for(int i = 0; i < 3; i ++){
		vec.emplace_back(vector<char>(11, ' '));
	}
	cout << "test: before second for loop" << endl;
	vec.emplace_back(vector<char>());
	for(int y = 0; y < 15; y++) {
		cout << "test: y = " << y << endl;
		for(int x = 0; x < 11; x++) {
			cout << "test: x = " << x << endl;
			if(!immobileTiles[y][x]){ 
				cout << "if(!immobileTiles[y][x])" << endl;
				vec.at(y + 3).emplace_back(' ');
			} else {
				cout << "else" << endl;
				vec.at(y + 3).emplace_back(immobileTiles[x][y]->getLetter());
			}
		}
		vec.emplace_back(vector<char>());
	}
	int currX, currY;
	cout << "test: third second for loop" << endl;
	for(int i = 0; i < 4; i++) {
		currX = currentBlock->getTiles()[i].getX();
		currY = currentBlock->getTiles()[i].getY();
		vec.at(currY + 3).at(currX) = currentBlock->getType();
	}
	return vec;
}

void Board::forceTopColumnTile(const char b, const int col) {
	if (!isEmpty(5, 0)) kill(); 
	int row = 0;
	for (int i = 1; i < 15; ++i) {
		if (!isEmpty(5, i)) row = i - 1;
	}
	placeBlock(new Block(b, -1, col, row));
}

//TODO: needs some rewriting
string Board::printNextBlock() {	
	string str = "";
	bool isTile = false;
	for(int i = 2; i > 0; i++) {
		for(int j = 0; j < 11; j++) {
			for(int k = 0; k < 4; k++) {
				if(nextBlock->getTiles()[i].getX() == j && nextBlock->getTiles()[k].getY() == i) {
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
	return str;
}

void Board::kill() {
	alive = false;
}



