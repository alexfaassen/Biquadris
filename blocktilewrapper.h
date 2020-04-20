#ifndef BLOCKTILEWRAPPER_H
#define BLOCKTILEWRAPPER_H

#include "tilewrapper.h"

class BlockTilewrapper : public Tilewrapper {

    public:
    BlockTilewrapper(PlayerWindow *w, Tile* t): Tilewrapper(w, t) {};
    BlockTilewrapper(BlockTilewrapper &other): Tilewrapper(other) {};
    BlockTilewrapper(BlockTilewrapper &&other): Tilewrapper(other) {};
    
    //BlockTilewrapper DOES have ownership of tile
    ~BlockTilewrapper();
    
};

#endif