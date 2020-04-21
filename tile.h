#ifndef _TILE_H_
#define _TILE_H_

class Tile {
	bool immobile = false, alive = true;
	char letter;
	int x;
	int y;

	public:
	Tile(char letter = ' ', int x = 0, int y = 0) : letter{letter}, x{x}, y{y} {};
	Tile(Tile& other) : Tile(other.letter, other.x, other.y) {};
	~Tile();
	char getLetter() ;
	void setLetter(char newLetter);
	int getX() ;
	int getY() ;
	bool isAlive() const {return alive;};
	void kill();
	void setX(const int newX);
	void setY(const int newY);
	void setXY(const int newX, const int newY);
	void invert();
};

#endif
