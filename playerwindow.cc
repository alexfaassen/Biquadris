#include "playerwindow.h"
#include "window.h"

using namespace std;

PlayerWindow::PlayerWindow(){}

PlayerWindow::PlayerWindow(Xwindow* window, int offsetX, int offsetY, int width, int height)
: window{window}, offsetX{offsetX}, offsetY{offsetY}, width{width}, height{height} {
	window->drawBigString(offsetX, 10, "Level:", Black);
	window->drawBigString(offsetX, 30, "Score:", Black);
	window->drawLine(offsetX, 40, offsetX + 220, 40);
	window->drawLine(offsetX, 400, offsetX + 220, 400);
	window->drawBigString(offsetX, 415, "Next:", Black);
}

PlayerWindow::~PlayerWindow(){}

void PlayerWindow::drawString(int x, int y, string msg, int colour){
    if(window) window->drawString(offsetX+x, offsetY+y, msg, colour);
}

void PlayerWindow::drawBigString(int x, int y, string msg, int colour){
    if(window) window->drawBigString(offsetX+x, offsetY+y, msg, colour);
}

void PlayerWindow::drawStringFont(int x, int y, string msg, string font, int colour){
    if(window) window->drawStringFont(offsetX+x, offsetY+y, msg, font, colour);
}

void PlayerWindow::fillRectangle(int x, int y, int width, int height, int colour){
    if(window) window->fillRectangle(offsetX+x, offsetY+y, width, height, colour);
}

void PlayerWindow::fillPolygon(int x, int y, int num, int side, int rotate, int colour){
    if(window) window->fillPolygon(offsetX+x, offsetY+y, num, side, rotate, colour);
}

void PlayerWindow::drawLine(int x1, int y1, int x2, int y2){
    if(window) window->drawLine(offsetX+x1, offsetY+y1, offsetX+x2, offsetY+y2);
}

void PlayerWindow::drawArc(int x, int y, int width, int height, int angle1, int angle2){
    if(window) window->drawArc(offsetX+x, offsetY+y, width, height, angle1, angle2);
}

void PlayerWindow::fillArc(int x, int y, int width, int height, int angle1, int angle2, int colour){
    if(window) window->fillArc(offsetX+x, offsetY+y, width, height, angle1, angle2, colour);
}

void PlayerWindow::fillCircle(int x, int y, int d, int colour){
    if(window) window->fillCircle(offsetX+x, offsetY+y, d, colour);
}

void PlayerWindow::showAvailableFonts(){
    if(window) window->showAvailableFonts();
}
