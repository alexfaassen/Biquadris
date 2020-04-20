#include "blocktilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

BlockTilewrapper::BlockTilewrapper(PlayerWindow *w, Tile* t)
: Tilewrapper(w, t) {
    draw();
};

BlockTilewrapper::~BlockTilewrapper(){
    if(tile) delete tile;
}
