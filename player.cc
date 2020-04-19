#include "player.h"
#include "observer.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void Player::initGraphicsObservers(){
    //TODO once GraphicsObserver is implemented
}

int Player::cleanObservers(){
    int cleaned = 0;
    for(size_t i = 0; i < observers.size(); i++){
        if(!observers.at(i)->isAlive()){
            delete observers.at(i);
            observers.erase(observers.begin()+i);
            cleaned = 0;
            i--;
        }
    }
    return cleaned;
}

void Player::notifyObservers(Event ev, int n = 0){
    for(auto p : observers){
        p->notify(ev, n);
    }
}

void Player::notifyObservers(Event ev, vector<vector<char>>& arr){
    for(auto p : observers){
        p->notify(ev, arr);
    }
}

void Player::preMove(){
    notifyObservers(beforeMove);
}

void Player::postMoveClean(){
    notifyObservers(afterMove);
    //TODO once board is implemented
    if (!board.isAlive()) setInputState(LOSS);
}

Player::Player(){}

Player::Player(Xwindow* w, int offsetX, int offsetY, int side, string scriptfile, int startlevel)
: window{PlayerWindow(w, offsetX, offsetY)}, side{side}, scriptFile {scriptfile} {
    if(window.hasWindow()){
        initGraphicsObservers();
    }
    if(!setLevel(startlevel)){
        cout << "Error: invalid startlevel. Using Level 0 instead" << endl;
        setLevel(0);
    }
    board.initLevel(level);
}

Player::~Player(){
    delete level;
    for(auto p : observers){
        delete p;
    }
}

int Player::isLevel() {
    return level ? level->getIdentifier() : 0;
}

int Player::moveBlock(Direction dir, int times, bool isInput){
    if(isInput){
        preMove();
    }
    int moves = board.moveCurrent(dir, times);
    if(isInput){
        postMoveClean();
    }
    return moves;
}

int Player::rotateClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = 0;
    for (int i = 0; i < times; ++i) {
	    if (board.clockwiseCurrent()) ++successes;
    }
    if(isInput){
        postMoveClean();
    }
    return successes;
}

int Player::rotateCounterClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = 0;
    for (int i = 0; i < times; ++i) {
	    if (board.counterClockwiseCurrent()) ++successes;
    }
    if(isInput){
        postMoveClean();
    }
    return successes;
}

void Player::drop(bool isInput){
    if(isInput){
        preMove();
    }
    board.dropCurrent();
    if(isInput){
        postMoveClean();
        endTurn();
    }
}

int Player::incLevel(int n){
    if (level) {
	    return setLevel(level->getIdentifier() + n);
    } else {
	    // Error, level not set
	    return 0;
    }
    int successes = 0;
    if(n < 0){
        n *= -1;
        for(int i = 0; i < n; i++){
            successes += setLevel(level->getIdentifier() - 1);
        }
    } else if (n > 0){
        for(int i = 0; i < n; i++){
            successes += setLevel(level->getIdentifier() + 1);
        }
    }
    return successes;
}

void Player::startTurn(){
    setInputState(NORMAL);
    cout << "test: pushNextBlock" << endl;
    board.pushNextBlock();
    cout << "test: notifyObservers(OnTurnStart)" << endl;
    notifyObservers(onTurnStart);
    if (!board.isAlive()) setInputState(LOSS);
}

void Player::endTurn(){
    int linescleared = board.eotClean(&score);
    setInputState(END_TURN);
    if(linescleared >= 2) {
        setInputState(SA);
    }
    notifyObservers(onTurnEnd, linescleared);
    if (!board.isAlive()) setInputState(LOSS);
}

bool Player::setLevel(int n){
    if (!level) {
	    if (n == 0) {
		level = new Level0(side);
		//cout << "test: setting level 0" << endl;
	    } else if (n == 1) {
        	level = new Level1(side);
	    } else if (n == 2) {
		level = new Level2(side);
	    } else if (n == 3) {
	    	level = new Level3(side);
		level->generateEffects(observers);
	    } else if (n == 4) {
		level = new Level4(side);
		level->generateEffects(observers);
	    } else {
	 	    // Error, Invalid Input
		    return false;
    	    }
     } else {
	     if (n < 0 || n > 4 || n == level->getIdentifier()) {
		     // Error, Invalid Input
	             return false;
 	     } else {
		     Level *temp = level;
	     	     if (n == 0) {
			     level = new Level0(*temp);
	             } else if (n == 1) {
	                     level = new Level1(*temp);
	     	     } else if (n == 2) {
	     		     level = new Level2(*temp);
	     	     } else if (n == 3) {
		   	     level = new Level3(*temp);
		    	     level->generateEffects(observers);
	     	     } else if (n == 4) {
		  	     level = new Level4(*temp);
		   	     level->generateEffects(observers);
	    	     }
                     delete temp;
	             temp = NULL;
	     }
    }
    board.setLevel(level);
    return true;
}

bool Player::setFileInput(ifstream* stream){
    return level ? level->setFile(stream) : 0;
}

void Player::specialAction(){
    setInputState(SA);
}   

void Player::pushToObservers(Observer* obs){
    observers.emplace_back(obs);
    obs->attach(this);
}

void Player::changeCurrentBlock(char c){
    board.changeCurrent(c);
    if (!board.isAlive()) setInputState(LOSS);
}

string charArrToString(const vector<vector<char>>& arr){
    stringstream ss;
    for(auto y : arr){
        for(auto x : y){
            ss << x;
        }
        ss << '\n';
    }
    return ss.str();
}

string Player::printToString(){
    stringstream ss;
    cout << "test: before level->getIdentifier" << endl;
    ss << "Level:" << setw(5) << level->getIdentifier() << '\n';
    ss << "Score:" << setw(5) << score << '\n';
    ss << "-----------" << '\n';
    cout << "test: before board.renderCharArray" << endl;
    vector<vector<char>> boardarr = board.renderCharArray();
    cout << "test: before notifyObservers(boardarr)" << endl;
    notifyObservers(beforeTextDisplay, boardarr);
    ss << charArrToString(boardarr);
    ss << "-----------" << '\n';
    ss << "Next:      " << '\n';
    cout << "test: before printNextBlock()" << endl;
    ss << board.printNextBlock();
    return ss.str();
}

void Player::forceTopTile(const char b, const int col){
	board.forceTopColumnTile(b, col);
}
