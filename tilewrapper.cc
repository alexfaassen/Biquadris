#include "tilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

void Tilewrapper::drawAt(int x, int y) const{
    if(!window) return;
    if(!tile){
        drawEmptyAt(x, y);
    } else {
        drawTileAt(x, y);
    }
}

void Tilewrapper::drawEmptyAt(int x, int y) const{
    window->fillRectangle(x, y, 20, 20, PlayerWindow::White);
}

void Tilewrapper::drawTileAt(int x, int y) const{
    int colour = PlayerWindow::White;
    if (tile->getLetter() == 'I') colour = PlayerWindow::Yellow;
    else if (tile->getLetter() == 'J') colour = PlayerWindow::Magenta;
    else if (tile->getLetter() == 'L') colour = PlayerWindow::Brown;
    else if (tile->getLetter() == 'O') colour = PlayerWindow::Green;
    else if (tile->getLetter() == 'S') colour = PlayerWindow::Cyan;
    else if (tile->getLetter() == 'Z') colour = PlayerWindow::Orange;
    else if (tile->getLetter() == '*') colour = PlayerWindow::Black;
    window->fillRectangle(x, y, 20, 20, colour);
}

void Tilewrapper::draw() const{
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw() const{
    drawEmptyAt(tile->getX(), tile->getY());
}
