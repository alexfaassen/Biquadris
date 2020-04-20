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

void ImmTilewrapper::draw(){
    drawAt(x, y);
}

void ImmTilewrapper::undraw(){
    drawEmptyAt(x, y);
}