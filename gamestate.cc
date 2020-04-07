#include "gamestate.h"

#include <utility>

using namespace std;

void GameState::switchActive(){
    swap(activePlayer, nonActivePlayer);
}

void GameState::createPlayers(){
    leftPlayer = Player(window, loffsetX, loffsetY);
    leftPlayer = Player(window, roffsetX, roffsetY);
}

GameState::GameState(bool hasWindow)
: highscore{0} {
    if(hasWindow){
        window = new Xwindow();
    }
    createPlayers();
    activePlayer = &leftPlayer;
    nonActivePlayer = &rightPlayer;
}

GameState::~GameState(){
    delete window;
    activePlayer = nullptr;
    nonActivePlayer = nullptr;
}

bool GameState::runInput(String input, int multiplier){

    //commandList figures out which vector of commands to loop through
    vector<Command*> &commands = commandList.selectVector(activePlayer->getInputState());

    Command* cmd = nullptr;
    bool duplicate_found = false;
    for(const auto &p : commands){     // loops through commands vector to find a match
        if(p->hasSubstring(s)){
            if(!cmd){
                 cmd = p;
            } else {                    //if multiple matches are found then it fails
                duplicate_found = true;
            }
        }
    }

    //runs the command if it succeeds, and prints error msg if it fails
    if(p && !duplicate_found){
        cmd->execute(*this, multiplier);
        return true;
    } else if (!p) {
        cout << "Error: Invalid command" << endl;
    } else if (duplicate_found){
        cout << "Error: Ambiguous command" << endl;
    }
    return false;
}

void GameState::cleanup(){
    //move effects over
    while(!activePlayer->outgoingIsEmpty()){
        nonActivePlayer->pushToObservers(activePlayer->popFromOutgoing());
    }

    //handle textDisplay
    printGame();
    
    //switch active player if turn has ended
    if(activePlayer->getInputState() == END_TURN){
        switchActive();
        activePlayer->startTurn();
    }
}

void GameState::printGame(){
    string lp = leftplayer.printToString();
    string rp = rightplayer.printToString();
    //TODO: finish print
}

void GameState::restart(){
    activePlayer = nullptr;
    nonActivePlayer = nullptr;
    createPlayers();
    activePlayer = &leftPlayer;
    nonActivePlayer = &rightPlayer;
}

bool GameState::updateHighscore(int score){
    if(score > highscore){
        highscore = score;
        return true;
    }
    return false;
}