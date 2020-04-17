#ifndef _TILE_H_
#define _TILE_H_

class Tile {
	bool immobile = false, alive = true;
	char letter;
	int x;
	int y;

	public:
	char getLetter();
	void setLetter(char newLetter);
	int getX();
	int getY();
	bool isAlive() {return alive;};
	void setX(int newX);
	void setY(int newY);
	void invert();
	void kill();
};

#endif
