#ifndef GAMESTATE_H
#define GAMESTATE_H

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
    XWindow* window;
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

    bool runInput(string, int)   // tries to run given input
    void cleanup();                 // checks for and handles end-of-turn
    void printGame();               // prints the game to textdisplay
    void restart();                 // resets everything
    
    // compares score to highscore and updates highscore if needed; returns if update happened
    bool updateHighscore(int score);    

}








#endif