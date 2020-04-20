#include "immtilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

ImmTilewrapper::ImmTilewrapper(int x, int y, PlayerWindow *w)
: Tilewrapper(w), x{x}, y{y} {
    draw();
}

void ImmTilewrapper::operator=(Tile *t){
    tile = t;
    draw();
}

ImmTilewrapper& ImmTilewrapper::operator=(Tilewrapper &other){
    tile = other.getTile(); 
    return *this;
}

ImmTilewrapper& ImmTilewrapper::operator=(ImmTilewrapper &other){
    tile = other.tile;
    return *this;
}

void ImmTilewrapper::draw() const{
    drawAt(x, y);
}

void ImmTilewrapper::undraw() const{
    drawEmptyAt(x, y);
}