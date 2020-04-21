#include "tilewrapper.h"
#include "tile.h"
#include "playerwindow.h"
#include <iostream>

using namespace std;

void Tilewrapper::drawAt(int x, int y){
    if(!window) return;
    if(!tile){
        drawEmptyAt(x, y);
    } else {
        drawTileAt(x, y);
    }
}

void Tilewrapper::drawEmptyAt(int x, int y){
    if(!window) return;
    window->fillRectangle(x * 20 + x - 1, (y * 20) + 100 + y - 1, 22, 22, PlayerWindow::Brown);
}

void Tilewrapper::drawTileAt(int x, int y){
    int colour = PlayerWindow::White;
    if (tile->getLetter() == 'I') colour = PlayerWindow::Yellow;
    else if (tile->getLetter() == 'J') colour = PlayerWindow::Magenta;
    else if (tile->getLetter() == 'L') colour = PlayerWindow::Brown;
    else if (tile->getLetter() == 'O') colour = PlayerWindow::Green;
    else if (tile->getLetter() == 'S') colour = PlayerWindow::Cyan;
    else if (tile->getLetter() == 'Z') colour = PlayerWindow::Orange;
    else if (tile->getLetter() == '*') colour = PlayerWindow::Black;
    window->fillRectangle(x * 20 + x, (y * 20) + 100 + y, 20, 20, colour);
    window->drawLine(x * 20 + x, (y * 20) + 100 + y, (x * 20) + 20 + x, (y * 20) + 100 + y);
    window->drawLine(x * 20 + x, (y * 20) + 120 + y, (x * 20) + 20 + x, (y * 20) + 120 + y);
    window->drawLine(x * 20 + x, (y * 20) + 100 + y, x * 20 + x, (y * 20) + 120 + y);
    window->drawLine((x * 20) + 20 + x, (y * 20) + 100 + y, (x * 20) + 20 + x, (y * 20) + 120 + y);
}

void Tilewrapper::draw(){
	std::cout << "test: in draw() method, tile->getX() =" << tile->getX() << std::endl;
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw(){
    drawEmptyAt(tile->getX(), tile->getY());
}

void Tilewrapper::customDraw(int deltaX, int deltaY){
    if(!window) return;
    int colour = PlayerWindow::White;
    if (tile->getLetter() == 'I') colour = PlayerWindow::Yellow;
    else if (tile->getLetter() == 'J') colour = PlayerWindow::Magenta;
    else if (tile->getLetter() == 'L') colour = PlayerWindow::Brown;
    else if (tile->getLetter() == 'O') colour = PlayerWindow::Green;
    else if (tile->getLetter() == 'S') colour = PlayerWindow::Cyan;
    else if (tile->getLetter() == 'Z') colour = PlayerWindow::Orange;
    else if (tile->getLetter() == '*') colour = PlayerWindow::Black;
    int x = tile->getX();
    int y = tile->getY();
    window->fillRectangle(x * 20 + x + deltaX, (y * 20) + y + deltaY, 20, 20, colour);
    window->drawLine(x * 20 + x + deltaX, (y * 20) + y + deltaY, (x * 20) + 20 + x + deltaX, (y * 20) + y + deltaY);
    window->drawLine(x * 20 + x + deltaX, (y * 20) + y + deltaY, (x * 20) + 20 + x + deltaX, (y * 20) + y + deltaY);
    window->drawLine(x * 20 + x + deltaX, (y * 20) + y + deltaY, x * 20 + x + deltaX, (y * 20) + y + deltaY);
    window->drawLine((x * 20) + 20 + x + deltaX, (y * 20) + y + deltaY, (x * 20) + 20 + x + deltaX, (y * 20) + y + deltaY);
}
