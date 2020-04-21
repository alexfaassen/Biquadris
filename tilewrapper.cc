#include "tilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

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
    window->fillRectangle(x, y, 20, 20, PlayerWindow::White);
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
    window->fillRectangle(x, y, 20, 20, colour);
    window->drawLine(x, y, x + 20, y);
    window->drawLine(x, y + 20, x + 20, y + 20);
    window->drawLine(x, y, x, y + 20);
    window->drawLine(x + 20, y, x + 20, y + 20);
}

void Tilewrapper::draw(){
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw(){
    drawEmptyAt(tile->getX(), tile->getY());
}
