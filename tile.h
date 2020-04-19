#ifndef _TILE_H_
#define _TILE_H_

class Tile {
	bool immobile = false, alive = true;
	char letter;
	int x;
	int y;

	public:
	Tile(char letter = ' ', int x = 0, int y = 0) : letter{letter}, x{x}, y{y} {};
	~Tile();
	char getLetter();
	void setLetter(char newLetter);
	int getX();
	int getY();
	bool isAlive() {return alive;};
	void kill();
	void setX(int newX);
	void setY(int newY);
	void invert();
};

#endif
