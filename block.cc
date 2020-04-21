#include <string>
#include <iostream>
#include "block.h"
#include "tile.h"
#include "blocktilewrapper.h"

using namespace std;

void Block::iBlock(int initX, int initY) {
	deleteTiles();
	//cout << "test: in iBlock ctor, initX = "<< initX << ", initY = " << initY << endl;
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 2, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 3, initY - 0)));
}

void Block::jBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 2, initY - 0)));
}

void Block::lBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 2, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 2, initY - 1)));
}

void Block::oBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 1, initY - 1)));
}

void Block::sBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 1, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 2, initY - 1)));
}

void Block::zBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 1, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 2, initY - 0)));
}

void Block::tBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('T', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('T', initX + 1, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('T', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('T', initX + 2, initY - 1)));
}

void Block::tileDropBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('*', initX, initY)));
}

Block::Block(char type, int initLevel, int heavy, int x, int y):
type{type}, initLevel{initLevel}, heaviness{heavy} {
	cout << "Block ctor is run with " << string(1,type) << endl;
	if(type == '*') tileDropBlock(x, y);
	else if(type == 'I') iBlock(x, y);
	else if(type == 'J') jBlock(x, y);
	else if(type == 'L') lBlock(x, y);
	else if(type == 'O') oBlock(x, y);
	else if(type == 'S') sBlock(x, y);
	else if(type == 'Z') zBlock(x, y);
	else tBlock(x, y);
	cout << "test: Block constructed with tile size = " << tiles.size() << endl;
}

Block::~Block(){
	deleteTiles();
}

void Block::move(int deltaX, int deltaY) {
	undraw();
	for(auto &t : tiles) {
		t->setXY(t->getX() + deltaX, t->getY() + deltaY);
	}
	draw();
}

void Block::clockwise() {
 	undraw();

	cout << "before clockwise: ";
	for(auto &t :tiles) {
		cout << "(" << t->getX() << ", " << t->getY() << ") ";
	}
	cout <<endl;

	int maxX = 0, maxY = -3, minX = 11, minY = 18;
	for(auto &t : tiles) {
		if(t->getX() > maxX)maxX = t->getX();
		if(t->getY() > maxY)maxY = t->getY();
		if(t->getX() < minX)minX = t->getX();
		if(t->getY() < minY)minY = t->getY();
	}

	int upperMid, lowerMid;
    upperMid = (maxY + 1) / 2;
    if((maxY + 1) % 2 == 0) lowerMid = (maxY + 1) / 2 - 1;
    else lowerMid = upperMid;
	int newX, count = 0;
	for(auto &t : tiles) {
        if(count > upperMid) {
            newX = lowerMid - t->getY() + upperMid;
			t->setY(newX);
        }
        else if(count < lowerMid) {
            newX = upperMid + t->getY() - upperMid;
			t->setY(newX);
        }
		count++;
	}
	
	cout << "Bottom left: " << minX << ", " << maxY <<endl;

	for(auto &t : tiles) {
		t->setX(t->getX() - minX);
		t->setY(t->getY() - minY);
		cout << "min: " << t->getX() << ", " << t->getY() <<endl;
		t->invert();
		t->setX(-t->getX());
		t->setY(-t->getY());

	}

	cout << "after invert: ";
	for(auto &t :tiles) {
		cout << "(" << t->getX() << ", " << t->getY() << ") ";
	}
	cout <<endl;

	int minInvertX = 11, maxInvertY = 0;
	for(auto &t : tiles) {
		if(t->getX() < minInvertX)minInvertX = t->getX();
		if(t->getY() > maxInvertY)maxInvertY = t->getY();
	}

	cout << "invert values: " << minInvertX << ", " << maxInvertY <<endl;

	int distX = minX - minInvertX;
	int distY = maxY - maxInvertY;

	cout << "dists: " << distX << ", " << distY <<endl;
	
	for(auto &t : tiles) {
		t->setX(t->getX() + distX);
		t->setY(t->getY() + distY);
	}

	cout << "after clockwise: ";
	for(auto &t :tiles) {
		cout << "(" << t->getX() << ", " << t->getY() << ") ";
	}
	cout <<endl;

	draw();
}

void Block::counterClockwise() {
	undraw();

	int maxX = 0, maxY = -3, minX = 11, minY = 18;
	for(auto &t : tiles) {
		if(t->getX() > maxX)maxX = t->getX();
		if(t->getY() > maxY)maxY = t->getY();
		if(t->getX() < minX)minX = t->getX();
		if(t->getY() < minY)minY = t->getY();
	}
	
	for(auto &t : tiles) {
		t->setX(t->getX() - minX);
		t->setY(t->getY() - minY);
		t->invert();
	}

	int minInvertX = 11, maxInvertY = 0;
	for(auto &t : tiles) {
		if(t->getX() < minInvertX)minInvertX = t->getX();
		if(t->getY() > maxInvertY)maxInvertY = t->getY();
	}

	int distX = minX - minInvertX;
	int distY = maxY - maxInvertY;
	for(auto &t : tiles) {
		t->setX(t->getX() + distX);
		t->setY(t->getY() + distY);
	}

	draw();
}

void Block::attachWindow(PlayerWindow* w) {
	window = w;
	for(auto &t : tiles){
		t.setWindow(window);
	}
	draw();
}

bool Block::alive() {
	for(auto &t : tiles){
		if(t->isAlive()){
			return true;
		}
	}
	return false;
}

bool Block::deleteTiles(){
	if(tiles.empty()){
		//cout << "test: deleteTiles is empty" << endl; 
		return false;
	}
	undraw();
	//cout << "test: deleteTiles with n = " << tiles.size() << endl;
	tiles.clear();
	return true;
}

std::string Block::printBlock() const {
	bool isTile = false;
	string str = "";
	for (int row = -1; row <= 0; ++row) {
		for (int col = 0; col < 11; ++col) {
			for (auto& t : tiles) {
				if (t->getY() == row && t->getX() == col) {
					str += string(1, type);	
					isTile = true;
					break;
				}
			}
			if (!isTile) str += " ";
			isTile = false;
		}
		str += "\n";
	}
	return str;
}

void Block::draw(){
	for(auto &t : tiles){
		t.draw();
	}
}

void Block::undraw(){
	for(auto &t : tiles){
		t.undraw();
	}
}
