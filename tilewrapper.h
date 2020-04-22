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

    virtual void drawAt(int x, int y);
    virtual void drawEmptyAt(int x, int y);
    virtual void drawTileAt(int x, int y, int deltaX = 0, int deltaY = 103); 

    public:

    Tilewrapper(PlayerWindow* w = nullptr, Tile* t = nullptr) : window{w}, tile{t}{};
    virtual ~Tilewrapper(){;};

    //copy constructor
    Tilewrapper(const Tilewrapper& other): window{other.window}, tile{other.tile}{};
    //move constructor 
    Tilewrapper(const Tilewrapper&& other): window{other.window}, tile{other.tile}{};

    //copy assignment operator
    virtual Tilewrapper& operator=(Tilewrapper &other) {tile = other.tile; return *this;}; 

    virtual Tile* getTile() const {return tile;};
    virtual void setWindow(PlayerWindow* w) {window = w;};

    //implicit conversions
    virtual operator bool() const {return tile;};

    //operator overloads
    virtual Tile* operator->(){return tile;};
    virtual Tile* operator->() const {return tile;};
    virtual void operator=(Tile* t){tile = t;};

    //draws to screen
    virtual void draw();
    virtual void undraw();   //erases the current spot
    void customDraw(int deltaX, int deltaY);
};


#endif
