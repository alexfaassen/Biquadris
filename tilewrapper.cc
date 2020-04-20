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
    //TODO: drawing code for drawing a blank space
}

void Tilewrapper::drawTileAt(int x, int y) const{
    //TODO: drawing code for drawing an occupied space
}

void Tilewrapper::draw() const{
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw() const{
    drawEmptyAt(tile->getX(), tile->getY());
}