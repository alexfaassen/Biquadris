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
    activePlayer = new Player(window, loffsetX, loffsetY, -1, scriptFile1, startlevel);
    nonActivePlayer = new Player(window, roffsetX, roffsetY, 1, scriptFile2, startlevel);
}

int GameState::cleanStreams(){
    int n = 0;
    for(size_t i = 0; i < ifstreams.size(); i++){
        if(ifstreams.at(i).eof()){
            ifstreams.erase(ifstreams.begin()+i);
            i--;
            ++n;
        }
    }
    return n;
}

int GameState::getLoser(){
    if(activePlayer->isDead()) return activePlayer->getSide();
    if(nonActivePlayer->isDead()) return nonActivePlayer->getSide();
    return 0;
}

bool GameState::handleGameOver(){
	cout << "in handleGameOver()" << endl;
    int loser = getLoser();
    if(loser == 0) return true;     //if nobody loses, return true
    int winner = (loser == -1 ? 2 : 1);
    cout << "Player" << winner << " wins!" << endl;
    cout << "The highscore is " << highscore << endl;
    if(window){
	    window->fillRectangle(windowWidth/2 - 30, windowHeight/2 - 20, 60, 40, Xwindow::Black);
	    window->fillRectangle(windowWidth/2 - 31, windowHeight/2 - 21, 3, 42, Xwindow::White);
	    window->fillRectangle(windowWidth/2 + 28, windowHeight/2 - 21, 3, 42, Xwindow::White);
	    window->fillRectangle(windowWidth/2 - 31, windowHeight/2 - 21, 62, 3, Xwindow::White);
	    window->fillRectangle(windowWidth/2 - 31, windowHeight/2 + 18, 62, 3, Xwindow::White);
	    window->drawBigString(windowWidth/2 - 20, windowHeight/2, "GAMEOVER", Xwindow::White);
    }
    return beginGameOverLoop();
}

bool GameState::beginGameOverLoop(){
    cout << "Play again? y/n" << endl;
    string s;
    while(readFromStream(s)){
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

GameState::GameState(bool hasWindow, string scriptFile1, string scriptFile2, int startlevel, bool simul)
: scriptFile1{scriptFile1}, scriptFile2{scriptFile2}, startlevel{startlevel}, simul{simul} {
    if(hasWindow){
        window = new Xwindow(windowWidth, windowHeight);
    }
    restart();
}

GameState::~GameState(){
    if(commandList) delete commandList;
    if(activePlayer) delete activePlayer;
    if(nonActivePlayer) delete nonActivePlayer;
    if(window) delete window;
}

bool GameState::pushToStreams(const string file){
    cleanStreams();
    ifstreams.emplace_back(ifstream(file));
    if(!ifstreams.back().good()){
        cout << "Error: " << file << " is missing or unreadable" << endl;
        ifstreams.pop_back();
        return false;
    }
    return true;
}

istream& GameState::getStream(){
    cleanStreams();
    if(ifstreams.empty()){
        return cin;
    } else {
        return ifstreams.back();
    }
}

bool GameState::readFromStream(string &str){
    while(!ifstreams.empty()){
        if(getStream() >> str) {
            cout << str << endl;
            return true;
        }
    }
    return bool(cin >> str);
}

bool GameState::readFromStream(char &c){
    while(!ifstreams.empty()){
        if(getStream() >> c){
            cout << string(1,c) << endl;
            return true;
        }
    }
    return bool(cin >> c);
}

bool GameState::beginReadLoop(){
    string s;
    while (readFromStream(s)) {
        int multiplier = 1;
        if(isdigit(s[0])){          // test if s starts with an int
            multiplier = atoi(s.c_str());   // http://www.cplusplus.com/reference/cstdlib/atoi/

            // clear all digits from front of string
            while(isdigit(s[0])){
		s = s.erase(0, 1);
            }
        }
        runInput(s, multiplier);

        //game over stuff
        if(!handleGameOver()){
            break;
        }

        if(activePlayer->getInputState() == SA){
		int i = 0;
		for(auto c : "Special Action"){
			string s(1, c);
			window->drawBigString(95 + i + 3, 40, s, Xwindow::White);
			++i;
		}
		cout << "Choose a Special Action!" << endl;
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
    
    if(simul){
        switchActive();
        if(activePlayer->getInputState() == END_TURN) activePlayer->startTurn();
    } else {
        //switch active player if turn has ended
        if(activePlayer->getInputState() == END_TURN){
            switchActive();
            activePlayer->startTurn();  //note: this is where startTurn() is called
        }
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
    string lp, rp;
    if(activePlayer->getSide() == -1){
        lp = activePlayer->printToString(true);
        rp = nonActivePlayer->printToString(false);
    } else {
        lp = nonActivePlayer->printToString(false);
        rp = activePlayer->printToString(true);
    }

    while(true){
        if(!printAndRemoveLine(lp)){    //breaks out of loop once either string runs out of lines
            break;
        }
        cout << "     ";
        if(!printAndRemoveLine(rp)){    //note: weird things will happen if strings have different # of lines
            break;
        }
        cout << endl;
    }
}

void GameState::restart(){
    if(activePlayer) delete activePlayer;
    if(nonActivePlayer) delete nonActivePlayer;
    if(window) window->fillRectangle(0, 0, windowWidth, windowHeight);
    cout << "test: to_string() = " << to_string(4) << endl;
    createPlayers();
    activePlayer->startTurn();
    printGame();
}

bool GameState::updateHighscore(int score){
    if(score > highscore){
        highscore = score;
        return true;
    }
    return false;
}
