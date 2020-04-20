#include "tilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

Tilewrapper::Tilewrapper(int x, int y, PlayerWindow* w = nullptr)
: x{x}, y{y}, window{w} {
    draw();
}

Tilewrapper& Tilewrapper::operator=(Tilewrapper &other) {
    tile = other.tile;
    draw();
}

void Tilewrapper::draw(){
    if(!window) return;
    //TODO: drawing code
    if(!tile){
        //draw black
    } else {
        //draw according to tile
    }
}