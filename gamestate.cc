#include "gamestate.h"

#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "player.h"
#include "window.h"
#include "commandlist.h"
#include "command.h"

using namespace std;

void GameState::switchActive(){
    swap(activePlayer, nonActivePlayer);
}

void GameState::createPlayers(){
    cout << "test: constructing player 1" << endl;
    activePlayer = new Player(window, loffsetX, loffsetY, -1, scriptFile1, startlevel);
    cout << "test: constructing player 2" << endl;
    nonActivePlayer = new Player(window, roffsetX, roffsetY, 1, scriptFile2, startlevel);
    cout << "test: finished constructing players" << endl;
}

int GameState::cleanStreams(){
    int n = 0;
    while(!ifstreams.empty()){
        ifstream &s = ifstreams.back();
        if(s.eof()){ 
            ifstreams.pop_back();
        } else {
            break;
        }
        ++n;
    }
    return n;
}

int GameState::getLoser(){
    if(activePlayer->getInputState() == LOSS) return activePlayer->getSide();
    if(nonActivePlayer->getInputState() == LOSS) return nonActivePlayer->getSide();
    return 0;
}

bool GameState::handleGameOver(){
    int loser = getLoser();
    if(loser == 0) return true;     //if nobody loses, return true
    int winner = (loser == -1 ? 1 : 2);
    cout << "Player" << winner << " wins!" << endl;
    cout << "The highscore is " << highscore << endl;
    return beginGameOverLoop();
}

bool GameState::beginGameOverLoop(){
    cout << "Play again? y/n" << endl;
    string s;
    while(getStream() >> s){
        if (s == "y" || s == "Y"){
            cout << "Restarting game..." << endl;
            restart();
            return true;
        } else if (s == "n" || s == "N"){
            cout << "Thank you for playing!" << endl;
            return false;
        } else {
            cout << "Error: Invalid Input" << endl;
            cout << "Play again? y/n" << endl;
        }
    }
    return false;
}

GameState::GameState(bool hasWindow, string scriptFile1, string scriptFile2, int startlevel)
: scriptFile1{scriptFile1}, scriptFile2{scriptFile2}, startlevel{startlevel} {
    if(hasWindow){
        window = new Xwindow();
    }
    cout << "test: before restart" << endl;
    restart();
}

GameState::~GameState(){
    if(window) delete window;
    if(activePlayer) delete activePlayer;
    if(nonActivePlayer) delete nonActivePlayer;
    delete commandList;
}

void GameState::pushToStreams(ifstream& stream){
    cleanStreams();
    reference_wrapper<ifstream> in(stream);
    ifstreams.emplace_back(in);
}

istream& GameState::getStream(){
    cout  << "test : before CleanStreams()" << endl;
    cleanStreams();
    if(ifstreams.empty()){
        cout  << "test : returning cin" << endl;
        return cin;
    } else {
        cout  << "test : ifstreams.back" << endl;
        return ifstreams.back();
    }
}

bool GameState::beginReadLoop(){
    string s;
    while (getStream() >> s) {
        cout << "test: passed getStream" << endl;
        int multiplier = 1;
        if(isdigit(s[0])){          // test if s starts with an int
            multiplier = atoi(s.c_str());   // http://www.cplusplus.com/reference/cstdlib/atoi/

            // clear all digits from front of string
            while(isdigit(s[0])){
                s.erase(s[0]);
            }
        }
        runInput(s, multiplier);

        //game over stuff
        if(!handleGameOver()){
            break;
        }
    }
    return true;
}

bool GameState::runInput(string input, int multiplier){

    //commandList figures out which vector of commands to loop through
    vector<Command*> &commands = commandList->selectVector(activePlayer->getInputState());

    Command* cmd = nullptr;
    bool duplicate_found = false;
    for(const auto &p : commands){     // loops through commands vector to find a match
        if(p->hasSubstring(input)){
            if(!cmd){
                 cmd = p;
            } else {                    //if multiple matches are found then it fails
                duplicate_found = true;
            }
        }
    }

    //runs the command if it succeeds, and prints error msg if it fails
    if(cmd && !duplicate_found){
        cmd->execute(*this, multiplier);
        return true;
    } else if (!cmd) {
        cout << "Error: Invalid command" << endl;
    } else if (duplicate_found){
        cout << "Error: Ambiguous command" << endl;
    }
    return false;
}

bool GameState::runInputOnNAP(string input, int multiplier){
    //switch activePlayer, call runInput, then switch back
    switchActive();
    bool success = runInput(input, multiplier);
    switchActive();
    return success;
}

bool GameState::runInputOnBoth(string input, int multiplier){
    Player* oldActivePlayer = activePlayer;
    bool success1 = runInput(input, multiplier);

    //determine if runInput won't automatically caused activePlayer to switch
    bool noSwitch = false;      
    if(oldActivePlayer == activePlayer){
        noSwitch = true;
    }

    //switch activePlayer, call runInput, then switch back
    if(noSwitch){
        switchActive();
    }
    bool success2 = runInput(input, multiplier);
    if(noSwitch){
        switchActive();
    }
    return success1 && success2;
}

void GameState::cleanup(){

    //update highscore
    updateHighscore(activePlayer->getScore());
    
    //switch active player if turn has ended
    if(activePlayer->getInputState() == END_TURN){
        switchActive();
        activePlayer->startTurn();  //note: this is where startTurn() is called
    }

    //handle textDisplay
    printGame();
}

// prints everything until the first \n in str and removes everything up to and including that \n
// returns false if there are no \n left in str
bool printAndRemoveLine(string &str){
    size_t linepos = str.find_first_of('\n');
    if(linepos != string::npos){
        cout << str.substr(0, linepos);
        str.erase(0, ++linepos);
        return true;
    }
    return false;
}

void GameState::printGame(){
    cout << "test: before player.printToString" << endl;
    string lp, rp;
    if(activePlayer->getSide() == -1){
        cout << "test: active == -1" << endl;
        string lp = activePlayer->printToString();
        string rp = nonActivePlayer->printToString();
    } else {
        cout << "test: active == 1" << endl;
        string lp = nonActivePlayer->printToString();
        string rp = activePlayer->printToString();
    }
    cout << "test: after player.printToString" << endl;

    cout << "lp size: " << lp.size() << endl;
    cout << "rp size: " << rp.size() << endl;

    while(true){
        cout << "while(true)" <<endl;
        if(!printAndRemoveLine(lp)){    //breaks out of loop once either string runs out of lines
            break;
        }
        cout << "     ";
        if(!printAndRemoveLine(rp)){    //note: weird things will happen if strings have different # of lines
            break;
        }
        cout << endl;
    }

    cout << "test: after printing" << endl;
}

void GameState::restart(){
    if(activePlayer) delete activePlayer;
    if(nonActivePlayer) delete nonActivePlayer;
    cout << "test : before createPlayers" << endl;
    createPlayers();
    cout << "test : activePlayer->startTurn" << endl;
    activePlayer->startTurn();
    cout << "test : printgame" << endl;
    printGame();
}

bool GameState::updateHighscore(int score){
    if(score > highscore){
        highscore = score;
        return true;
    }
    return false;
}
