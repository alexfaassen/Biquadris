#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "inputstate.h"
#include "direction.h"
#include "playerwindow.h"
#include "board.h"
#include "event.h"

class Observer;
class Level;

class Player {
    private:
    int side, score = 0;
    Board board;
    Level* level = new Level0();
    PlayerWindow window;
    std::vector<Observer*> observers;
    InputState inputState = NORMAL;

    void initGraphicsObservers();   //creates and attaches all of the graphicObserver objects
    int cleanObservers();           //removes all dead observers from the vector
    void notifyObservers(Event, int = 0);      //calls notify() with the given parameters on all observers
    void notifyObservers(Event, char[][]&);

    void preMove();     //called right before movement
    void postMoveClean();    //called after movement. Handles cleaning and stuff

    public:
    Player(Xwindow*, int offsetX, int offsetY, int side);
    ~Player();

    //accessors
    int isLevel() {return level ? level->getIdentifier() : 0;};
    int getSide() {return side;};
    int getScore() {return score;};
    int incScore(int n) {score += n; return score;};
    void setInputState(InputState state) {inputState = state;};

    //movement commands
    int moveBlock(Direction, int, bool = false);
    int rotateClockWise(int, bool = false);
    int rotateCounterClockwise(int, bool = false);
    void drop(bool = false);
    int incLevel(int);

    //turn triggers
    void startTurn();   // executes start of turn procedures
    void endTurn();     // executes end of turn procedures
    
    //other stuff
    bool setLevel(int);
    bool setFileInput(fstream*);
    void specialAction();               //queries special action
    void pushToObservers(Observer*);
    void changeCurrentBlock(Block*);
    std::string printToString();
    void forceTopTile(Tile*);
}

#endif
