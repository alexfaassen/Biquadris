#include <string>
#include "block.h"
#include "tile.h"

using namespace std;

void Block::iBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 0);
    tiles[1].setX(initX + 1);
    tiles[1].setY(initY + 0);
    tiles[2].setX(initX + 2);
    tiles[2].setY(initY + 0);
    tiles[3].setX(initX + 3);
    tiles[3].setY(initY + 0);
}

void Block::jBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 1);
    tiles[1].setX(initX + 0);
    tiles[1].setY(initY + 0);
    tiles[2].setX(initX + 1);
    tiles[2].setY(initY + 0);
    tiles[3].setX(initX + 2);
    tiles[3].setY(initY + 0);
}

void Block::lBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 0);
    tiles[1].setX(initX + 1);
    tiles[1].setY(initY + 0);
    tiles[2].setX(initX + 2);
    tiles[2].setY(initY + 0);
    tiles[3].setX(initX + 2);
    tiles[3].setY(initY + 1);
}

void Block::oBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 0);
    tiles[1].setX(initX + 1);
    tiles[1].setY(initY + 0);
    tiles[2].setX(initX + 1);
    tiles[2].setY(initY + 1);
    tiles[3].setX(initX + 2);
    tiles[3].setY(initY + 1);
}

void Block::sBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);     
	tiles[0].setY(initY + 0);
	tiles[1].setX(initX + 0);
	tiles[1].setY(initY + 1);
	tiles[2].setX(initX + 1);
	tiles[2].setY(initY + 1);
	tiles[3].setX(initX + 1);
	tiles[3].setY(initY + 0);
}

void Block::zBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 1);
    tiles[1].setX(initX + 1);
    tiles[1].setY(initY + 1);
    tiles[2].setX(initX + 1);
    tiles[2].setY(initY + 0);
    tiles[3].setX(initX + 2);
    tiles[3].setY(initY + 0);
}

void Block::tBlock(int initX, int initY) {
	tiles[0].setX(initX + 0);
    tiles[0].setY(initY + 1);
    tiles[1].setX(initX + 1);
    tiles[1].setY(initY + 1);
    tiles[2].setX(initX + 1);
    tiles[2].setY(initY + 0);
    tiles[3].setX(initX + 2);
    tiles[3].setY(initY + 1);
}

void Block::tileDropBlock(int initX, int initY) {
	tiles[0].setX(initX);
	tiles[0].setY(initY);
	tiles[1].kill();
	tiles[2].kill();
	tiles[3].kill();
}

Block::Block(char type, int initLevel, int x, int y):
type{type}, initLevel{initLevel} {
	if(type == '*') tileDropBlock(x, y);
	else if(type == 'i') iBlock(x, y);
	else if(type == 'j') jBlock(x, y);
	else if(type == 'l') lBlock(x, y);
	else if(type == 'o') oBlock(x, y);
	else if(type == 's') sBlock(x, y);
	else if(type == 'z') zBlock(x, y);
	else tBlock(x, y);	
}

Block::~Block(){
}

void Block::move(int deltaX, int deltaY) {
	for(int i = 0; i < 4; i++) {
		tiles[i].setX(tiles[i].getX() + deltaX);
		tiles[i].setY(tiles[i].getY() + deltaY);
	}
}

void Block::clockwise() {
	int max = 0;
	for(int i = 0; i < 4; i++) {
		tiles[i].invert();
		if(tiles[i].getY() > max) {
			max = tiles[i].getY();
		}
	}
	int upperMid, lowerMid;
	upperMid = (max + 1) / 2;
	if((max + 1) % 2 == 0) lowerMid = (max + 1) / 2 - 1;
	else lowerMid = upperMid;
	int newY;
	for(int i = 0; i < 4; i++) {
		if(i > upperMid) {
			newY = lowerMid - tiles[i].getY() + upperMid;
			tiles[i].setY(newY);
		} 
		else if(i < lowerMid) {
			newY = upperMid + tiles[i].getY() - upperMid;
			tiles[i].setY(newY);
		}
	}
}

void Block::counterClockwise() {
	int max = 0;
	for(int i = 0; i < 4; i++) {
		tiles[i].invert();
		if(tiles[i].getX() > max) {
			max = tiles[i].getX();
		}
	}
	int upperMid, lowerMid;
        upperMid = (max + 1) / 2;
        if((max + 1) % 2 == 0) lowerMid = (max + 1) / 2 - 1;
        else lowerMid = upperMid;
	int newX;
	for(int i = 0; i < 4; i++) {
                if(i > upperMid) {
                        newX = lowerMid - tiles[i].getX() + upperMid;
                        tiles[i].setX(newX);
                }
                else if(i < lowerMid) {
                        newX = upperMid + tiles[i].getX() - upperMid;
                        tiles[i].setX(newX);
                }
	}
}

bool Block::alive() {
	for(auto t : tiles){
		if(t.isAlive()){
			return true;
		}
	}
	return false;
}


