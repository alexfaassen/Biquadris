#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "inputstate.h"
#include "direction.h"
#include "event.h"
#include "move.h"

class Observer;
class Level;
class Board;
class PlayerWindow;
class Xwindow;

class Player {
    private:
    PlayerWindow* window = nullptr;
    int side, score = 0;
    Board* board = nullptr;
    Level* level = nullptr;
    std::vector<Observer*> observers;
    InputState inputState = END_TURN;
    std::string scriptFile;

    void initGraphicsObservers();   //creates and attaches all of the graphicObserver objects
    int cleanObservers();           //removes all dead observers from the vector
    //calls notify() with the given parameters on all observers
    void notifyObservers(Event, Move);   
    void notifyObservers(Event, int);      
    void notifyObservers(Event, char);
    void notifyObservers(Event, std::vector<std::vector<char>>&);
    void notifyObservers(Event, PlayerWindow&);

    void preMove();     //called right before movement
    void postMoveClean(Move);    //called after movement. Handles cleaning and stuff
    void checkEndTurn();

    public:
    Player();
    Player(Xwindow*, int offsetX, int offsetY, int side, std::string scriptFile, int startlevel);
    ~Player();

    //accessors
    int isLevel();
    int getSide() {return side;};
    int getScore() {return score;};
    int incScore(int n) {score += n; return score;};
    void setInputState(InputState state) {inputState = state;};
    InputState getInputState() {return inputState;};
    std::string getScriptFile() {return scriptFile;};
    void setScriptFile(std::string s) {scriptFile = s;};

    //movement commands
    int moveBlock(Direction dir, int times, bool isInput = true);
    int rotateClockwise(int times, bool isInput = true);
    int rotateCounterClockwise(int times, bool isInput = true);
    void drop(int times = 1, bool isInput = true);
    int incLevel(int);

    //turn triggers
    void startTurn();   // executes start of turn procedures
    void endTurn();     // sets inputstate to END_TURN
    void handleEndTurn();   // executes end of turn procedures if inputstate is END_TURN
    
    //other stuff
    bool setLevel(int);
    bool setFileInput(std::ifstream*);
    void specialAction();               //queries special action
    void pushToObservers(Observer*);
    void changeCurrentBlock(char);
    std::string printToString(bool active);
    void forceTopTile(const char b, const int col);

    void redrawBoard();
};

#endif
