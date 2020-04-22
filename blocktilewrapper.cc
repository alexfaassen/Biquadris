#include "blocktilewrapper.h"
#include "tile.h"
#include "playerwindow.h"
#include <iostream>

using namespace std;

BlockTilewrapper::BlockTilewrapper(const BlockTilewrapper &other)
: Tilewrapper(other) {
    tile = new Tile(*tile);
    //cout << "copy ctor" << endl;
}

BlockTilewrapper::BlockTilewrapper(const BlockTilewrapper &&other)
: Tilewrapper(other) {
    tile = new Tile(*tile);
    //cout << "move ctor" << endl;
}

BlockTilewrapper::~BlockTilewrapper(){
    if(tile) delete tile;
}

