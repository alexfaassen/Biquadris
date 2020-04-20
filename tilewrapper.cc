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
    window->fillRectangle(x, y, 20, 20, White);
}

void Tilewrapper::drawTileAt(int x, int y) const{
    int colour = XWindow::White;
    if (tile->getType() == 'I') colour = XWindow::Yellow;
    else if (tile->getType() == 'J') colour = XWindow::Magenta;
    else if (tile->getType() == 'L') colour = XWindow::Brown;
    else if (tile->getType() == 'O') colour = XWindow::Green;
    else if (tile->getType() == 'S') colour = XWindow::Cyan;
    else if (tile->getType() == 'Z') colour = XWindow::Orange;
    else if (tile->getType() == '*') colour = XWindow::Black;
    window->fillRectangle(x, y, 20, 20, colour);
}

void Tilewrapper::draw() const{
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw() const{
    drawEmptyAt(tile->getX(), tile->getY());
}
