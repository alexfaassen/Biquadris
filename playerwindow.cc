#include "playerwindow.h"
#include "window.h"

using namespace std;

PlayerWindow::PlayerWindow(Xwindow* window, int offsetX, int offsetY, int width = 200, int height = 400)
: window{window}, offsetX{offsetX}, offsetY{offsetY}, width{width}, height{height} {
    if(window){
        hasWindow = true;
    } else {
        hasWindow = false;
    }
}

PlayerWindow::~PlayerWindow(){}

void PlayerWindow::drawString(int x, int y, string msg, int colour = Black){
    window->drawString(offsetX+x, offsetY+y, msg, colour);
}

void PlayerWindow::drawBigString(int x, int y, string msg, int colour = Black){
    window->drawBigString(offsetX+x, offsetY+y, msg, colour);
}

void PlayerWindow::drawStringFont(int x, int y, string msg, string font, int colour = Black){
    window->drawStringFont(offsetX+x, offsetY+y, msg, font, colour);
}

void PlayerWindow::fillRectangle(int x, int y, int width, int height, int colour=Black){
    window->fillRectangle(offsetX+x, offsetY+y, width, height, colour);
}

void PlayerWindow::fillPolygon(int x, int y, int num, int side, int rotate = 0, int colour = Black){
    window->fillPolygon(offsetX+x, offsetY+y, num, side, rotate, colour);
}

void PlayerWindow::drawLine(int x1, int y1, int x2, int y2){
    window->drawLine(offsetX+x1, offsetY+y1, offsetX+x2, offsetY+y2);
}

void PlayerWindow::drawArc(int x, int y, int width, int height, int angle1, int angle2){
    window->drawArc(offsetX+x, offsetY+y, width, height, angle1, angle2);
}

void PlayerWindow::fillArc(int x, int y, int width, int height, int angle1, int angle2, int colour){
    window->fillArc(offsetX+x, offsetY+y, width, height, angle1, angle2, colour);
}

void PlayerWindow::fillCircle(int x, int y, int d, int colour = Black){
    window->fillCircle(offsetX+x, offsetY+y, d, colour);
}

void PlayerWindow::showAvailableFonts(){
    window->showAvailableFonts();
}