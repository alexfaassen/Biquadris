#ifdef _TILE_H_
#define _TILE_H_

class Tile {
	bool immobile;
	char letter;
	int x;
	int y;

	public:
	char getLetter();
	void setLetter(char newLetter);
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);
	void invert(Tile&& t);
}


#endif
