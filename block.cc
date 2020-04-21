#include <string>
#include <iostream>
#include "block.h"
#include "tile.h"
#include "blocktilewrapper.h"

using namespace std;

void Block::IBlock(int initX, int initY) {
	deleteTiles();
	//cout << "test: in iBlock ctor, initX = "<< initX << ", initY = " << initY << endl;
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 2, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('I', initX + 3, initY - 0)));
}

void Block::JBlock(int initX, int initY) {
	deleteTiles();
	cout << "in JBlock ctor, initX = " << initX << ", initY = " << initY << endl;
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('J', initX + 2, initY - 0)));
}

void Block::LBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 2, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('L', initX + 2, initY - 1)));
}

void Block::OBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('O', initX + 1, initY - 1)));
}

void Block::SBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 0, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 1, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('S', initX + 2, initY - 1)));
}

void Block::ZBlock(int initX, int initY) {
	deleteTiles();
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 0, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 1, initY - 1)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 1, initY - 0)));
	tiles.emplace_back(BlockTilewrapper(window, new Tile('Z', initX + 2, initY - 0)));
}

void Block::TBlock(int initX, int initY) {
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
	//cout << "Block ctor is run with " << string(1,type) << endl;
	if(type == '*') tileDropBlock(x, y);
	else if(type == 'I') IBlock(x, y);
	else if(type == 'J') JBlock(x, y);
	else if(type == 'L') LBlock(x, y);
	else if(type == 'O') OBlock(x, y);
	else if(type == 'S') SBlock(x, y);
	else if(type == 'Z') ZBlock(x, y);
	else TBlock(x, y);
	// Block constructed with tile size = " << tiles.size() << endl;
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

	int maxX = 0, maxY = -3, minX = 11, minY = 18;
	for(auto &t : tiles) {
		if(t->getX() > maxX)maxX = t->getX();
		if(t->getY() > maxY)maxY = t->getY();
		if(t->getX() < minX)minX = t->getX();
		if(t->getY() < minY)minY = t->getY();
	}
	
	for(auto &t : tiles) {
		t->setX(t->getX() - minX);
		t->setY(t->getY() - maxY);
		t->invert();
		t->setX(-t->getX());
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
		t->setY(t->getY() - maxY);
		t->invert();
		t->setY(-t->getY());
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
	cout << type << "Block drawing" << endl;
	for(auto &t : tiles){
		t.draw();
	}
}

void Block::undraw(){
	for(auto &t : tiles){
		t.undraw();
	}
}

void Block::customDraw(int deltaX, int deltaY){
	for(auto &t : tiles){
		t.customDraw(deltaX, deltaY);
	}
}
