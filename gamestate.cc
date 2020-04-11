#include "gamestate.h"

#include <utility>
#include <string>

using namespace std;

void GameState::switchActive(){
    swap(activePlayer, nonActivePlayer);
}

void GameState::createPlayers(){
    leftPlayer = Player(window, loffsetX, loffsetY);
    leftPlayer = Player(window, roffsetX, roffsetY);
}

int GameState::cleanStreams(){
    int n = 0;
    while(!istreams.empty() && istreams.back().eof){
        istreams.pop_back();
        ++n;
    }
    return n;
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
    if(window){
        delete window;
    }
    activePlayer = nullptr;
    nonActivePlayer = nullptr;
}

void GameState::pushToStreams(istream& stream){
    cleanStreams();
    reference_wrapper<istream> in(stream);
    istreams.emplace_back(in);
}

istream& GameState::getStream(){
    cleanStreams();
    if(istreams.empty()){
        return cin;
    } else {
        return istreams.back();
    }
}

bool GameState::beginReadLoop(){
    string s;
    while (getStream() >> s) {
        int multiplier = 1;
        
        if(isdigit(s[0])){          // test if s starts with an int
            multiplier = atoi(s);   // http://www.cplusplus.com/reference/cstdlib/atoi/

            // clear all digits from front of string
            while(isdigit(s[0])){
                s.erase(s[0]);
            }
        }
        gamestate.runInput(s, multiplier);
    }

    return true;
}

bool GameState::runInput(String input, int multiplier = 1){

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

bool GameState::runInputOnNAP(String input, int multiplier = 1){
    //switch activePlayer, call runInput, then switch back
    switchActive();
    bool success = runInput(input, multiplier);
    switchActive();
    return success;
}

bool GameState::runInputOnBoth(String input, int multiplier = 1){
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
    //move effects over
    while(!activePlayer->outgoingIsEmpty()){
        nonActivePlayer->pushToObservers(activePlayer->popFromOutgoing());
    }

    //handle textDisplay
    printGame();
    
    //switch active player if turn has ended
    if(activePlayer->getInputState() == END_TURN){
        switchActive();
        activePlayer->startTurn();  //note: this is where startTurn() is called
    }
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
    string lp = leftplayer.printToString();
    string rp = rightplayer.printToString();

    while(true){
        if(!printAndRemoveLine(lp)){    //breaks out of loop once either string runs out of lines
            break;
        }
        cout < "     ";
        if(!printAndRemoveLine(rp)){    //note: weird things will happen if strings have different # of lines
            break;
        }
        cout < endl;
    }
}

void GameState::restart(){
    activePlayer = nullptr;
    nonActivePlayer = nullptr;
    createPlayers();
    activePlayer = &leftPlayer;
    nonActivePlayer = &rightPlayer;
}

int GameState::getActiveSide(){
    if(activePlayer == &leftPlayer){
        return -1;
    } else if (activePlayer == &rightPlayer){
        return 1;
    } else {
        return 0;
    }
}

bool GameState::updateHighscore(int score){
    if(score > highscore){
        highscore = score;
        return true;
    }
    return false;
}