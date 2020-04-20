#include "tile.h"
#include <iostream>

using namespace std;

Tile::~Tile(){
	//cout << "test: running Tile destructor" << endl;
}

char Tile::getLetter() const {
	return letter;
}

void Tile::setLetter(char newLetter) {
	letter = newLetter;
}

int Tile::getX() const{
	return x;
}

int Tile::getY() const{
	return y;
}

void Tile::kill() {
	alive = false;
}

void Tile::setX(const int newX) {
	x = newX;
}

void Tile::setY(const int newY) {
	y = newY;
}

void Tile::setXY(const int newX, const int newY){
	x = newX;
	y = newY;
}

void Tile::invert() {
	int hold = x;
	x = y;
	y = hold;
}
