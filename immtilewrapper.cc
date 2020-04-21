#include "immtilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

ImmTilewrapper::ImmTilewrapper(int x, int y, PlayerWindow *w)
: Tilewrapper(w), x{x}, y{y} {
}

void ImmTilewrapper::operator=(Tile *t){
    tile = t;
    char other = t ? t->getLetter() : ' ';
    if(letter != other) draw();
    letter = other;
}

ImmTilewrapper& ImmTilewrapper::operator=(Tilewrapper &other){
    tile = other.getTile(); 
    return *this;
}

ImmTilewrapper& ImmTilewrapper::operator=(ImmTilewrapper &other){
    tile = other.tile;
    return *this;
}

void ImmTilewrapper::draw(){
    drawAt(x, y);
}

void ImmTilewrapper::undraw(){
    drawEmptyAt(x, y);
}