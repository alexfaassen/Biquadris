#include <vector>
#include <string>
#include "board.h"

using namespace std;

int Board::eotClean(int *score, int *level) {
	int rowsRemoved = 0;
	bool fullRow = true;
	while(fullRow) {
		for(int i =0; i < 11; i++) {
			if(immobileTiles[14][i].getLetter() == ' ') {
				fullRow = false;
				break;
			}
		}
		if(!fullRow)break;
		rowsRemoved++;
		for(int i = 13; i > 0; i--) {
			for(int j = 0; j < 11; j++) {
				char newLetter = immobileTiles[i][j].getLetter();
				immobileTiles[i + 1][j].setLetter(newLetter);
			}
		}
		for(int i = 0; i < 11; i++) {
			immobileTiles[0][i].setLetter(' ');
		}
		for(vector<Block *>::iterator b = placed.begin() ; b != placed.end(); ++b) {
			b.move(0,-1);
			if(!b.alive()) {
				int blockScore = (b.initLevel + 1) * (b.initLevel + 1);
				score = score + blockScore;
			}
			b.erase();
		}

	}
	int rowsScore = (rowsRemoved * level) * (rowsRemoved * level);
       	score = score + rowsScore;	
	return rowsRemoved;
}

void Board::changeCurrent(Block *cur) {
	int minX = 11, minY = 15;
	for(int i = 0; i < 4; i++) {
		if(cur.tiles[i].getX() < minX) minX = cur.tiles[i].getX();
		if(cur.tiles[i].getY() < minY) minY = cur.tiles[i].getX();
	}
	if(cur.type == 'i')cur.iBlock(minX, minY);
	else if(cur.type == 'j')cur.jBlock(minX, minY);
	else if(cur.type == 'l')cur.lBlock(minX, minY);
	else if(cur.type == 'o')cur.oBlock(minX, minY);
	else if(cur.type == 's')cur.sBlock(minX, minY);
	else if(cur.type == 'z')cur.zBlock(minX, minY);
	else if(cur.type == 't')cur.tBlock(minX, minY);	
}

int Board::moveCurrent(Direction dir, int amount) {
	int deltaX = 0, deltaY = 0;
	switch(dir) {
		case left: deltaX = -1;
		case right: deltaX = 1;
		case down: deltaY = -1; 
	}
	int moveCount = 0, newX, newY;
	while(moveCount < amount) {
		for(int i = 0; i < 4; i++) {
			newX = currentBlock.tiles[i].getX() + deltaX;
			newY = currentBlock.tiles[i].getY() + deltaY;
			if(isBlocked(newX, newY))break;
		}
		if(isBlocked(newX, newY))break;
		else currentBlock.move(deltaX, deltaY);
		moveCount++;
	}	
}

void Board::clockwiseCurrent() {
	currentBlock.clockwise();
}

void Board::counterClockwiseCurrent() {
	currentBlock.counterClockwise();
}

void Board::dropCurrent() {
	bool atBottom = false;
	while(true) {
		for(int i = 0; i < 4; i++) {
			atBottom = isBlocked(currentBlock.getX(), currentBlock.getY() - 1)
			if(atBottom)break;
		}
		if(atBottom)break;
		for(int i = 0; i < 4; i++) {
			currentBlock.setY(currentBlock.getY() - 1);
		}
	}
}

void Board::isBlocked(int x, int y) {
	if(immobileTiles[x][y].getLetter() == ' ')return false;
	return true;	
}

char[15][11] Board::renderCharArray() {
	char[15][11] renderArray; 
	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 11; j++) {
			renderArray[i][j] = immobileTiles[i][j].getLetter();
		}
	}
	int currX, currY;
	for(int i = 0; i < 4; i++) {
		currX = currentBlock.getX();
		currY = currentBlock.getY();
		if(currX >= 0 && currX < 11 & currY >= 0 && currY < 15) {
			renderArray[currY][currX] = currentBlock.getLetter();
		}
	}
	return renderArray;
}

void Board::forceTopColumnTile(Tile *colTile) {
	if(isBlocked(colTile.getX(), colTile.getY() + 1))return;
	immobileTile[colTile.getY()][colTiles.getX()].setLetter(' ');
	colTile.setY(colTile.getY() + 1);
	immobileTile[colTile.getY()][colTiles.getX()].setLetter('*');
}

string Board::printNextBlock() {	
	string str = "";
	bool isTile = false;
	for(int i = 2; i > 0; i++) {
		for(int j = 0; j < 11; j++) {
			for(int k = 0; k < 4; k++) {
				if(nextBlock.tiles[k].getX() == j && nextBlocktiles[k].getY() == i) {
					str += nextBlock.type;
					isTile = true;
					break;
				}
			}
			if(!isTile)str += " ";
			isTile = false;
		}
		str += "\n"
	}
}


