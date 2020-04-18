#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "inputstate.h"
#include "direction.h"
#include "playerwindow.h"
#include "board.h"
#include "event.h"
#include "level0.h"

class Observer;
class Level;
class Level0;

class Player {
    private:
    int side, score = 0;
    Board board;
    Level* level = new Level0(side);
    PlayerWindow window;
    std::vector<Observer*> observers;
    InputState inputState = NORMAL;
    std::string scriptFile;

    void initGraphicsObservers();   //creates and attaches all of the graphicObserver objects
    int cleanObservers();           //removes all dead observers from the vector
    void notifyObservers(Event, int);      //calls notify() with the given parameters on all observers
    void notifyObservers(Event, std::vector<std::vector<char>>&);

    void preMove();     //called right before movement
    void postMoveClean();    //called after movement. Handles cleaning and stuff

    public:
    Player();
    Player(Xwindow*, int offsetX, int offsetY, int side, std::string scriptfile, int startlevel);
    ~Player();

    //accessors
    int isLevel() {return level ? level->getIdentifier() : 0;};
    int getSide() {return side;};
    int getScore() {return score;};
    int incScore(int n) {score += n; return score;};
    void setInputState(InputState state) {inputState = state;};
    InputState getInputState() {return inputState;};
    std::string getScriptFile() {return scriptFile;};
    void setScriptFile(std::string s) {scriptFile = s;};

    //movement commands
    int moveBlock(Direction, int, bool);
    int rotateClockwise(int, bool);
    int rotateCounterClockwise(int, bool);
    void drop(bool = false);
    int incLevel(int);

    //turn triggers
    void startTurn();   // executes start of turn procedures
    void endTurn();     // executes end of turn procedures
    
    //other stuff
    bool setLevel(int);
    bool setFileInput(std::ifstream*);
    void specialAction();               //queries special action
    void pushToObservers(Observer*);
    void changeCurrentBlock(char);
    std::string printToString();
    void forceTopTile(const char b, const int col);
};

#endif
