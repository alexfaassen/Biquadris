#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <vector>

class Tile;
class PlayerWindow;

class Tilewrapper {
    protected:
    // Tilewarpper DOES NOT have ownership of these. DO NOT delete
    PlayerWindow* window = nullptr;
    Tile* tile = nullptr;

    virtual void drawAt(int x, int y) const;
    virtual void drawEmptyAt(int x, int y) const;
    virtual void drawTileAt(int x, int y) const;

    

    public:

    Tilewrapper(PlayerWindow* w = nullptr, Tile* t = nullptr) : window{w}, tile{t}{};
    virtual ~Tilewrapper(){;};

    virtual Tile* getTile() const {return tile;};

    //copy assignment operator
    virtual Tilewrapper& operator=(Tilewrapper &other) {tile = other.tile; return *this;};  

    //implicit conversions
    virtual operator bool() const {return tile;};

    //operator overloads
    virtual Tile* operator->(){return tile;};
    virtual Tile* operator->() const {return tile;};
    virtual void operator=(Tile* t){tile = t;};

    //draws to screen
    virtual void draw() const;
    virtual void undraw() const;   //erases the current spot
};


#endif