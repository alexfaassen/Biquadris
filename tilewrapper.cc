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
    int colour = White;
    if (tile->getType() == 'I') colour = Yellow;
    else if (tile->getType() == 'J') colour = Magenta;
    else if (tile->getType() == 'L') colour = Brown;
    else if (tile->getType() == 'O') colour = Green;
    else if (tile->getType() == 'S') colour = Cyan;
    else if (tile->getType() == 'Z') colour = Orange;
    else if (tile->getType() == '*') colour = Black;
    window->fillRectangle(x, y, 20, 20, colour);
}

void Tilewrapper::draw() const{
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw() const{
    drawEmptyAt(tile->getX(), tile->getY());
}
