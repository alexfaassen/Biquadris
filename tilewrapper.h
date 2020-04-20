#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <vector>;

class Tile;
class PlayerWindow;

class Tilewrapper {
    protected:
    // Tilewarpper DOES NOT have ownership of these. DO NOT delete
    Tile* tile = nullptr;
    PlayerWindow* window = nullptr;

    virtual void drawAt(int x, int y);
    virtual void drawEmptyAt(int x, int y);
    virtual void drawTileAt(int x, int y);

    public:

    Tilewrapper(PlayerWindow* w = nullptr, Tile* t = nullptr) : window{w}, tile{t}{};
    virtual ~Tilewrapper(){;};

    //copy assignment operator
    virtual Tilewrapper& operator=(Tilewrapper &other) {tile = other.tile;};  

    //implicit conversions
    virtual operator bool() const {return tile;};

    //operator overloads
    virtual Tile* operator->(){return tile;};
    virtual void operator=(Tile* t){tile = t;};

    //draws to screen
    virtual void draw();
    virtual void undraw();   //erases the current spot
};


#endif