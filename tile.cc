#include "tile.h"

char Tile::getLetter() {
	return letter;
}

void Tile::setLetter(char newLetter) {
	letter = newLetter;
}

int Tile::getX() {
	return x;
}

int Tile::getY() {
	return y;
}

void Tile::setX(int newX) {
	x = newX;
}

void Tile::setY(int newY) {
	y = newY;
}

void Tile::invert() {
	int hold = x;
	x = y;
	y = hold;
}

void Tile::kill() { alive = false; }
