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
    //TODO: drawing code for drawing a blank space
}

void Tilewrapper::drawTileAt(int x, int y){
    //TODO: drawing code for drawing an occupied space
}

void Tilewrapper::draw(){
    drawAt(tile->getX(), tile->getY());
}

void Tilewrapper::undraw(){
    drawEmptyAt(tile->getX(), tile->getY());
}