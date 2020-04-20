#include "blocktilewrapper.h"
#include "tile.h"
#include "playerwindow.h"

using namespace std;

BlockTilewrapper::~BlockTilewrapper(){
    if(tile) delete tile;
}
