#include <vector>
#include <string>
#include <iostream>
#include "board.h"
#include "block.h"
#include "level.h"
#include "tilewrapper.h"
#include "immtilewrapper.h"
#include "blocktilewrapper.h"

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

Block* Board::CreateBlock(){
	//cout << "test: level->CreateBlock" << endl;
	Block* b = level->CreateBlock();
	//cout << "test: b->attachWindow(window)" << endl;
	b->attachWindow(window);
	return b;
}

void Board::initImmobileTiles(PlayerWindow* w){
	for(int x = 0; x < 11; x++){
		immobileTiles.emplace_back(vector<ImmTilewrapper>());
		for(int y = 0; y < 15; y++){
			immobileTiles[x].emplace_back(ImmTilewrapper(x,y,w));
		}
	}
}

Board::Board(Level* level, PlayerWindow* w)
: level{level}, window{w} {
	//cout << "test: initImmobileTiles" << endl;
	initImmobileTiles(w);
	//cout << "test: nextBlock = CreateBlock" << endl;
	nextBlock = CreateBlock();
}

Board::~Board(){
	delete currentBlock;
	delete nextBlock;
	for(auto p : placed){
		delete p;
	}
}

bool Board::pushNextBlock(bool safe){
	//cout << "test: in pushNextBlock(), current nextblock type is " << nextBlock->getType() << endl;
	if(safe && currentBlock) return true;
	if(!nextBlock)nextBlock = CreateBlock();
	//cout << "test: nextBlock type (before switch): " << string(1, nextBlock->getType()) << endl;
	currentBlock = nextBlock;
	if (window) currentBlock->draw();
	//cout << "test: currentBlock type: " << string(1, currentBlock->getType()) << endl;
	//cout << "test: second createBlock" <<endl;
	//cout << "level: " << level->getIdentifier() << endl;
	//cout << "test: Attempting to create next block" << endl;
	nextBlock = CreateBlock();
	//cout << "test: after second createBlock" <<endl;
	if (isCurrentBlocked()){
		 kill();
		 return false;
	}
	return true;
}

bool Board::placeCurrent(){
	//cout << "test: in placeCurrent()" << endl;
	if(isCurrentBlocked()) return false; 
	placeBlock(currentBlock);
	currentBlock = nullptr;
	return true;
}

bool Board::placeBlock(Block* b, bool draw){
	if(!b) return false;
	if(isBlocked(b)) return false;
	//cout << "test: in placeBlock(b)" << endl;
	placed.emplace_back(b);
	//cout << "test: for (auto p : b->getTiles())" << endl;
	for (Tilewrapper &p : b->getTiles()){
		immobileTiles[p->getX()][p->getY()] = p;
		if(draw) p.draw();
	}
	return true;
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
	if(rowsRemoved > 0) {
		int rowsScore = (rowsRemoved + level->getIdentifier()) * (rowsRemoved + level->getIdentifier());
   		*score += rowsScore;
	}
	return rowsRemoved;
}

bool Board::changeCurrent(char newType) {
	//cout << "test: in board, changeCurrent()" << endl;
	Block *newBlock = new Block(newType, level->getIdentifier());
	Block *oldCurrBlock = currentBlock;
	currentBlock = newBlock;
	if(oldCurrBlock) delete oldCurrBlock;
	currentBlock->draw();
	if (isCurrentBlocked()){
		kill();
		return false;
	}
	return true;
	//cout << "test: end of changeCurrent()" << endl;
}

int Board::moveCurrent(Direction dir, int amount, bool redraw) {
	if(amount == 0) return 0;
	if(redraw) currentBlock->undraw();
	int deltaX = 0, deltaY = 0;
	if (dir == Left) deltaX = -1;
	else if (dir == Right) deltaX = 1;
	else if (dir == Down) deltaY = 1;
	int moveCount = 0;
	//cout << "test: moveCurrent() called" << endl;
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
	if(redraw) currentBlock->draw();
	return moveCount;	
}

int Board::clockwiseCurrent(int amount, bool redraw) {
	if(amount == 0) return 0;
	if(redraw) currentBlock->undraw();
	int moveCount = 0;
	while(moveCount < amount){
		currentBlock->clockwise();
		if(isCurrentBlocked()) {
			currentBlock->counterClockwise();
			break;
		}
		moveCount++;
	}
	if(redraw) currentBlock->draw();
	return moveCount;
}

int Board::counterClockwiseCurrent(int amount, bool redraw) {
	if(amount == 0) return 0;
	if(redraw) currentBlock->undraw();
	int moveCount = 0;
	while(moveCount < amount){
		currentBlock->counterClockwise();
		if(isCurrentBlocked()) {
			currentBlock->clockwise();
			break;
		}
		moveCount++;
	}
	if(redraw) currentBlock->draw();
	return moveCount;
}

void Board::dropCurrent(bool redraw) {
	if(redraw) currentBlock->undraw();
	while(moveCurrent(Down, 1, false) && !isCurrentBlocked()){
		//cout << "test: dropping..." <<endl;
	}
	if(redraw) currentBlock->draw();
	//cout << "test: before placeCurrent()" << endl;
}

void Board::weighDownCurrent(){
	moveCurrent(Down, currentBlock->getHeaviness(), true);
}

bool Board::isBlocked(Block* b){
	for(auto &t : b->getTiles()){
		if(!isEmpty(t->getX(), t->getY())) return true;
	}
	return false;
}

bool Board::isCurrentBlocked(){
	return isBlocked(currentBlock);
}

bool Board::isMoveBlocked(int deltaX, int deltaY){
	for (auto &t : currentBlock->getTiles()) {
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
	//cout << "test: before third for loop" << endl;s
	if(currentBlock){
		for(auto &t : currentBlock->getTiles()) {
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
		placeBlock(new Block(b, -1, 0, col, row), true);
	}
}

string Board::printNextBlock() {	
	if (!nextBlock) return "           \n           \n";
	else return nextBlock->printBlock();
}

void Board::redrawBoard(){
	for(auto &x : immobileTiles){
		for(auto &y: x){
			y.draw();
		}
	}
}

void Board::kill() {
	alive = false;
}

void Board::setNewLevel(Level *newLevel) { level = newLevel; }
