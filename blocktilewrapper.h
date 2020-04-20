#ifndef BLOCKTILEWRAPPER_H
#define BLOCKTILEWRAPPER_H

#include "tilewrapper.h"

class BlockTilewrapper : public Tilewrapper {

    public:
    BlockTilewrapper(PlayerWindow *w, Tile* t);
    ~BlockTilewrapper();
    
};

#endif