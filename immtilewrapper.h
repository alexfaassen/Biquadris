#ifndef IMMTILEWRAPPER_H
#define IMMTILEWRAPPER_H

#include "tilewrapper.h"

class ImmTilewrapper : public Tilewrapper {

    int x, y;

    public:
    ImmTilewrapper(int x, int y, PlayerWindow *w): Tilewrapper(w), x{x}, y{y} {};
    void operator=(Tile* t) override;
    virtual ImmTilewrapper& operator=(Tilewrapper &other) override;
    void draw() const override;
    void undraw() const override;
};

#endif