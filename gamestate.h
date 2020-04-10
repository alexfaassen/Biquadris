#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <istream>

#include "player.h"
#include "window.h"
#include "commandlist.h"

class GameState {
    private:
    int highscore;
    Player leftPlayer;
    Player rightPlayer;
    Player* activePlayer = nullptr;
    Player* nonActivePlayer = nullptr;
    XWindow* window = nullptr;
    CommandList commandList;

    const int loffsetX, loffsetY, roffsetX, roffsetY;

    void switchActive();    //rotates the active player
    void createPlayers();   //creates the two players

    public:
    //constructors and destrutors
    GameState(bool hasWindow = true);
    ~GameState();

    //accessors
    Player& getActivePlayer() {return *activePlayer};
    Player& getNAP() {return *nonActivePlayer};
    Player& getLeftPlayer() {return leftPlayer};
    Player& getRightPlayer() {return rightPlayer};

    bool beginReadLoop(std::istream&)   // starts a read loop with given input stream
                                        // returns true once input stream is exhausted

    bool runInput(string, int=1)        // tries to interpret and run given input
    bool runInputOnNAP(string, int=1)   // calls runInput while pretending that NAP is activePlayer
    bool runInputOnBoth(string, int=1)  // calls runInput sequentially on both players as if they were activePlayer
    void cleanup();                     // checks for and handles end-of-turn
    void printGame();                   // prints the game to textdisplay
    void restart();                     // resets everything
    
    // compares score to highscore and updates highscore if needed; returns if update happened
    bool updateHighscore(int score);    

}








#endif