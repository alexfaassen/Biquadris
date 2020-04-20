#ifndef BLOCKTILEWRAPPER_H
#define BLOCKTILEWRAPPER_H

#include "tilewrapper.h"
#include <iostream>

class BlockTilewrapper : public Tilewrapper {

    public:
    BlockTilewrapper(PlayerWindow *w, Tile* t): Tilewrapper(w, t) {};
    BlockTilewrapper(BlockTilewrapper &other): Tilewrapper(other) {std::cout << "copy ctor" << std::endl;};
    BlockTilewrapper(BlockTilewrapper &&other): Tilewrapper(other) {std::cout << "move ctor" << std::endl;};
    
    //BlockTilewrapper DOES have ownership of tile
    ~BlockTilewrapper();
    
};

#endif