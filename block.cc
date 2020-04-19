#include <string>
#include <iostream>
#include "block.h"
#include "tile.h"

using namespace std;

void Block::iBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 0);
	tiles[1] = new Tile(initX + 1, initY + 0);
	tiles[2] = new Tile(initX + 2, initY + 0);
	tiles[3] = new Tile(initX + 3, initY + 0);
}

void Block::jBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 1);
	tiles[1] = new Tile(initX + 0, initY + 0);
	tiles[2] = new Tile(initX + 1, initY + 0);
	tiles[3] = new Tile(initX + 2, initY + 0);
}

void Block::lBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 0);
	tiles[1] = new Tile(initX + 1, initY + 0);
	tiles[2] = new Tile(initX + 2, initY + 0);
	tiles[3] = new Tile(initX + 2, initY + 1);
}

void Block::oBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 0);
	tiles[1] = new Tile(initX + 1, initY + 0);
	tiles[2] = new Tile(initX + 1, initY + 1);
	tiles[3] = new Tile(initX + 2, initY + 1);
}

void Block::sBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 0);
	tiles[1] = new Tile(initX + 0, initY + 1);
	tiles[2] = new Tile(initX + 1, initY + 1);
	tiles[3] = new Tile(initX + 1, initY + 0);
}

void Block::zBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 1);
	tiles[1] = new Tile(initX + 1, initY + 1);
	tiles[2] = new Tile(initX + 1, initY + 0);
	tiles[3] = new Tile(initX + 2, initY + 0);
}

void Block::tBlock(int initX, int initY) {
	tiles[0] = new Tile(initX + 0, initY + 1);
	tiles[1] = new Tile(initX + 1, initY + 1);
	tiles[2] = new Tile(initX + 1, initY + 0);
	tiles[3] = new Tile(initX + 2, initY + 1);
}

void Block::tileDropBlock(int initX, int initY) {
	tiles[0] = new Tile(initX, initY);
	tiles[1] = new Tile(-1, -1);
	tiles[2] = new Tile(-1, -1);
	tiles[3] = new Tile(-1, -1);
	tiles[1].kill();
	tiles[2].kill();
	tiles[3].kill();
}

Block::Block(char type, int initLevel, int x, int y):
type{type}, initLevel{initLevel} {
	//cout << "Block ctor is run with " << string(1,type) << endl;
	if(type == '*') tileDropBlock(x, y);
	else if(type == 'I') iBlock(x, y);
	else if(type == 'J') jBlock(x, y);
	else if(type == 'L') lBlock(x, y);
	else if(type == 'O') oBlock(x, y);
	else if(type == 'S') sBlock(x, y);
	else if(type == 'Z') zBlock(x, y);
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


