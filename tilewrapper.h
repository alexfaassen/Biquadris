#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <vector>;

class Tile;
class PlayerWindow;

class Tilewrapper {
    // Tilewarpper DOES NOT have ownership of these. DO NOT delete
    Tile* tile = nullptr;
    PlayerWindow* window = nullptr;

    int x = 0, y = 0;

    public:

    Tilewrapper(int x, int y, PlayerWindow* w = nullptr);
    ~Tilewrapper(){;};

    //copy assignment operator
    Tilewrapper& operator=(Tilewrapper &other);  

    //implicit conversions
    operator bool() const {return tile;};

    //operator overloads
    Tile* operator->(){return tile;};
    void operator=(Tile* t){tile = t;};

    //draws to screen
    void draw();

};


#endif