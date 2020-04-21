#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <istream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>

#include "commandlist.h"

class Xwindow;
class Player;

class GameState {
    private:
    int highscore = 0;
    Player* activePlayer = nullptr;
    Player* nonActivePlayer = nullptr;
    Xwindow* window = nullptr;
    CommandList *commandList = new CommandList();
    std::vector<std::ifstream> ifstreams;

    const int loffsetX = 0, loffsetY = 0, roffsetX = 270, roffsetY = 0;
    const int windowHeight = 482, windowWidth = 502;
    const std::string scriptFile1 = "biquadris_sequence1.txt", scriptFile2 ="biquadris_sequence2.txt";
    const int startlevel = 0;
    bool running = true, simul = false;

    void switchActive();    //rotates the active player
    void createPlayers();   //creates the two players
    int cleanStreams();     //pops all exauhsted ifstreams off ifstreams and returns # popped

    int getLoser();         //returns side of loser. 0 if no one has lost yet
    bool handleGameOver();  //checks for and handles gameover. Returns whether to continue running the game
    bool beginGameOverLoop();   //starts game over read loop. Returns whether to continue running the game

    public:
    //constructors and destrutors
    GameState(bool hasWindow, std::string scriptFile1, std::string scriptFile2, int startlevel, bool simul);
    ~GameState();

    //accessors
    Player& getActivePlayer() {return *activePlayer;};
    Player& getNAP() {return *nonActivePlayer;};

    bool pushToStreams(const std::string);   //creates a ifstream on filename and pushes it to ifstreams

    // returns the top non-exauhsted istream in ifstreams. Returns cin if ifstreams is empty
    std::istream& getStream();  

    // calls getStream >> str and returns if it succeeded. Prints str if reading from file
    bool readFromStream(std::string &str);     
    bool readFromStream(char &c);       

    bool beginReadLoop();               // starts the read loop

    bool runInput(std::string input, int=1);        // tries to interpret and run given input
    bool runInputOnNAP(std::string input, int=1);   // calls runInput while pretending that NAP is activePlayer
    bool runInputOnBoth(std::string input, int=1);  // calls runInput sequentially on both players as if they were activePlayer
    void cleanup();                     // checks for and handles end-of-turn
    void printGame();                   // prints the game to textdisplay
    void restart();                     // resets everything
    
    // compares score to highscore and updates highscore if needed; returns if update happened
    bool updateHighscore(int score);    
};








#endif
