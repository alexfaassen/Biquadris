#ifndef IMMTILEWRAPPER_H
#define IMMTILEWRAPPER_H

#include "tilewrapper.h"

class ImmTilewrapper : public Tilewrapper {

    int x, y;

    public:
    //constructors
    ImmTilewrapper(int x, int y, PlayerWindow *w);
    ImmTilewrapper(const ImmTilewrapper &other): Tilewrapper(other), x{other.x}, y{other.y} {};
    ImmTilewrapper(const ImmTilewrapper &&other): Tilewrapper(other), x{other.x}, y{other.y} {};

    void operator=(Tile* t) override;
    virtual ImmTilewrapper& operator=(Tilewrapper &other) override;
    virtual ImmTilewrapper& operator=(ImmTilewrapper &other);
    void draw() override;
    void undraw() override;
};

#endif