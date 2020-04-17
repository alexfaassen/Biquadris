#include "player.h"
#include "observer.h"
#include <iostream>
#include <array>

using namespace std;

void Player::initGraphicsObservers(){
    //TODO once GraphicsObserver is implemented
}

int Player::cleanObservers(){
    for(int i = 0; i < observers.size(); i++){
        if(!observers.get(i)->isAlive()){
            delete observers.get(i);
            observers.erase(i);
            i--;
        }
    }
}

void Player::notifyObservers(Event ev, int n = 0){
    for(auto p : observers){
        p->notify(ev, n);
    }
}

void Player::notifyObservers(Event ev, char[][]& arr){
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
}

Player::Player(Xwindow* w, int offsetX, int offsetY, int side)
: window{PlayerWindow(w, offsetX, offsetY)}, side{side} {
    if(window.hasWindow()){
        initGraphicsObservers();
    }
}

Player::~Player(){
    delete level;
    for(auto p : observers){
        delete p;
    }
}

int Player::moveBlock(Direction dir, int times, bool isInput = false){
    return board.moveCurrent(dir, times);
}

int Player::rotateClockWise(int times, bool isInput = false){
    for (int i = 0; i < times; ++i) {
	    if (!board.clockwiseCurrent()) return i + 1;
    }
    return times;
}

int Player::rotateCounterClockwise(int times, bool isInput = false){
    for (int i = 0; i < times; ++i) {
	    if (!board.counterClockwiseCurrent()) return i + 1;
    }
    return times;
}

void Player::drop(bool isInput = false){
    board.dropCurrent();
}

bool Player::incLevel(int n){
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
    notifyObservers(onTurnStart);
}

void Player::endTurn(){
    setInputState(END_TURN);
    notifyObservers(onTurnEnd);
}

bool Player::setLevel(int n){
    if (!level) {
	    if (n == 0) {
		    level = new Level0(side);
	    } else if (n == 1) {
        	    level = new Level1(side);
	    } else if (n == 2) {
		    level = new Level2(side);
	    } else if (n == 3) {
	            level = new Level3(side);
	    } else if (n == 4) {
		    level = new Level4(side);
	    } else {
	 	    // Error, Invalid Input
		    return 0;
    	    }
     } else {
	     if (n < 0 || n > 4 || n == level->getIdentifier()) {
		     // Error, Invalid Input
	             return 0;
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
	     } else if (n == 4) {
		     level = new Level4(*temp);
	     }
             delete temp;
	     temp = NULL;
	     }
    }
    return 1;
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

void Player::changeCurrentBlock(Block* block){
    board.changeCurrent(block);
}

string charArrToString(const char[][]& arr){
    stringstream ss;
    for(auto y : arr){
        for(auto x : y){
            ss << x;
        }
        ss < '\n';
    }
    return ss.str();
}

string Player::printToString(){
    stringstream ss;
    ss << "Level:" << setw(5) << level->getIdentifier() << '\n';
    ss << "Score:" << setw(5) << score << '\n';
    ss < "-----------" << '\n';
    char[][] boardarr = board.renderCharArray();
    notifyObservers(beforeTextDisplay, boardarr);
    ss << charArrToString(boardarr);
    ss < "-----------" << '\n';
    ss < "Next:      " << '\n';
    ss < board.printNextBlock();
    return ss.str();
}

void Player::forceTopTile(const char b, const int col){
	board->forceTopColumnTile(b, col);
}
