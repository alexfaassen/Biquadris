#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <string>

class Xwindow;

class PlayerWindow{
    private:
    Xwindow* window;
    int offsetX, offsetY, width, height;
    bool hasWindow;

    public:
    //constructors and destructors
	PlayerWindow(Xwindow*, int offsetX, int offsetY, int width, int height);  
	~PlayerWindow();              

    //accessors
    int getOffsetX() {return offsetX;};
    int getOffsetY() {return offsetY;};
    int getWidth() {return width;};
    int getHeight() {return height;};   
    bool hasWindow() {return hasWindow};             

	enum { White = 0, Black, Red, Green, Blue, Cyan, Yellow, Magenta,
		Orange, Brown, DarkGreen }; // Available colours.


	// Draws a string
	void drawString(int x, int y, std::string msg, int colour = Black);
	void drawBigString(int x, int y, std::string msg, int colour = Black);

	// if you use this function, make sure font exists on the undergrad environment
    void drawStringFont(int x, int y, std::string msg, std::string font, int colour = Black);

	// Draws a rectangle
	void fillRectangle(int x, int y, int width, int height, int colour=Black);

	// Draw a polygon with the first vertex at (x, y) with num vertices, side length side
	//     and rotated rotate radians. The second vertex is (x + side, y) rotated by
	//     rotate
	void fillPolygon(int x, int y, int num, int side, int rotate = 0, int colour = Black);

	// Draws a line from (x1, y1) to (x2, y2)
	void drawLine(int x1, int y1, int x2, int y2);

	// Draws an arc centered at (x, y) with height and width starting from angle1 to angle2
	//   angle1 being 0 is (x + width, y) and measured in degrees
	void drawArc(int x, int y, int width, int height, int angle1, int angle2);

	void fillArc(int x, int y, int width, int height, int angle1, int angle2,
			int colour);
	// Draws a circle centered at (x, y) with diameter d
	void fillCircle(int x, int y, int d, int colour = Black);

  void showAvailableFonts();
}


#endif