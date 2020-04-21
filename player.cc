#include "player.h"
#include "observer.h"
#include "board.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "playerwindow.h"
#include "scoregraphic.h"
#include "levelgraphic.h"
#include "nextblockgraphic.h"
#include "turngraphic.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void Player::initGraphicsObservers(){
    pushToObservers(new ScoreGraphic(window));
    pushToObservers(new LevelGraphic(window));
    pushToObservers(new NextBlockGraphic(window));
    pushToObservers(new TurnGraphic(window));
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

void Player::notifyObservers(Event ev, int i){
    //cout << "test: observers.size = " <<observers.size() << endl;
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, i);
    }
}

void Player::notifyObservers(Event ev, Move m = mLeft){
    //cout << "test: observers.size = " <<observers.size() << endl;
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, m);
    }
}

void Player::notifyObservers(Event ev, const char c){
    //cout << "test: observers.size = " <<observers.size() << endl;
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, c);
    }
}

void Player::notifyObservers(Event ev, vector<vector<char>>& arr){
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, arr);
    }
}

void Player::notifyObservers(Event ev, PlayerWindow& w){
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, w);
    }
}

void Player::preMove(){
    notifyObservers(beforeMove);
}

void Player::postMoveClean(Move m = mLeft){
    board->weighDownCurrent();
    notifyObservers(afterMove, m);
    checkEndTurn();
}

void Player::checkEndTurn(){
    if (inputState == END_TURN) handleEndTurn();
    if (!board->isAlive()) kill();
}

Player::Player(){}

Player::Player(Xwindow* w, int offsetX, int offsetY, int side, string scriptFile, int startlevel)
: side{side}, scriptFile {scriptFile} {
    //cout << "test: if(window.hasWindow())" <<endl;
    if(w){
        window = new PlayerWindow(w, offsetX, offsetY);
        initGraphicsObservers();
    }
    //cout << "test: if(!setLevel(startlevel))" <<endl;
    if(!setLevel(startlevel)){
        cout << "Error: invalid startlevel. Using Level 0 instead" << endl;
        setLevel(0);
    }
    //cout << "test: constructing board" <<endl;
    board = new Board(level, window);
    notifyObservers(onNextBlockChange, board->getNextBlockType());
}

Player::~Player(){
    if(level){
        level->deleteFile();
        delete level;
    }
    for(auto p : observers){
        if(p) delete p;
    }
    if(board) delete board;
    if(window) delete window;
}

int Player::isLevel() {
    return level ? level->getIdentifier() : 0;
}

int Player::moveBlock(Direction dir, int times, bool isInput){
    if(isInput){
	//cout << "preMove() called" << endl;
        preMove();
    }
    int moves = board->moveCurrent(dir, times);
    if(isInput) {
	    //cout << "test: postMove() called" << endl;
	    Move m = mLeft;
	    if (dir == Right) m = mRight;
	    else if (dir == Down) m = mDown;
	    postMoveClean(m);
    }
    return moves;
}

int Player::rotateClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = 0;
    for (int i = 0; i < times; ++i) {
	    if (board->clockwiseCurrent()) ++successes;
    }
    if(isInput) postMoveClean(mClockwise);
    return successes;
}

int Player::rotateCounterClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = 0;
    for (int i = 0; i < times; ++i) {
	    if (board->counterClockwiseCurrent()) ++successes;
    }
    if(isInput) postMoveClean(mCounterClockwise);
    return successes;
}

void Player::drop(int times, bool isInput){

    if(isInput) preMove();
    //cout << "test: before dropCurrent()" << endl;

    // handles everything except the last drop in a multi drop
    for(int i = 1; i < times; ++i){
        board->dropCurrent();
        board->placeCurrent();
        //if dead, break out of loop and ignore everything else
        if(!pushNextBlockAndCheck()) break;
    }

    // handles the final drop
    if(times > 0){ 
        board->dropCurrent();
        board->placeCurrent();
        endTurn();
    }

    if(isInput && times > 0){
        notifyObservers(onDrop);
        checkEndTurn();
    }
    //cout << "test: after endTurn()" << endl;
}

int Player::incLevel(int n){
    //cout << "test: incLevel()" << endl;
    if (!level) return setLevel(n);
    int successes = 0;
    if(n < 0){ 
        for(int i = 0; i > n; i--){
            successes += setLevel(level->getIdentifier() - 1);
        }
    } else if (n > 0){
        for(int i = 0; i < n; i++){
            successes += setLevel(level->getIdentifier() + 1);
        }
    } 
    //cout << "test: about to finish incLevel()" << endl;
    return successes;
}

bool Player::pushNextBlockAndCheck(){
    bool success = true;
    if(!board->pushNextBlock()){
        success = false;
        kill();
    }
    notifyObservers(onNextBlockChange, board->getNextBlockType());
    return success;
}

void Player::startTurn(){
    setInputState(NORMAL);
    //cout << "test: pushNextBlock" << endl;
    pushNextBlockAndCheck();
    //cout << "test: notifyObservers(OnTurnStart)" << endl;
    if (!board->isAlive()) kill();
}

void Player::endTurn(){
    setInputState(END_TURN);
}

void Player::handleEndTurn(){
    int linescleared = board->eotClean(&score);
    notifyObservers(onScoreChange);
    
    if(linescleared >= 1) notifyObservers(onLinesCleared);
    if(linescleared >= 2) setInputState(SA);
    
    notifyObservers(onTurnEnd);
    cleanObservers();
    if (!board->isAlive()) kill();
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
		level->generateEffects(*this);
	    } else if (n == 4) {
		level = new Level4(side);
		level->generateEffects(*this);
	    } else {
	 	    // Error, Invalid Input
		    return false;
    	    }
     } else {
	     //cout << "test: in setLevel(), level exists, setting it to " << n << endl;
	     if (n < 0 || n > 4) {
		     // Error, Invalid Input
	             return false;
	     } else if (n == level->getIdentifier()) {
		     return true;
 	     } else {
		     Level *temp = level;
	     	     if (n == 0) {
			        level = new Level0(*temp);
	             } else if (n == 1) {
	                level = new Level1(*temp);
	     	     } else if (n == 2) {
			        //cout << "test: in setLevel(), level2 copy ctor" << endl;
	     		    level = new Level2(*temp);
	     	     } else if (n == 3) {
		   	        level = new Level3(*temp);
		    	    level->generateEffects(*this);
	     	     } else if (n == 4) {
		  	        level = new Level4(*temp);
		   	        level->generateEffects(*this);
	    	     }
		     //cout << "test: pre delete temp" << endl;
                     delete temp;
		     //cout << "test: post delete temp" << endl;
	             temp = NULL;
	     }
    }
    cleanObservers();
    //cout << "test: in setLevel(), about to call board->setNewLevel()" << endl;
    if(board) board->setNewLevel(level);
    notifyObservers(onLevelChange);
    return true;
}

bool Player::setFileInput(ifstream* stream){
    if(level){
        level->deleteFile();
        level->setFile(stream);
        return true;
    }
    return false;
}

void Player::specialAction(){
    setInputState(SA);
}   

void Player::pushToObservers(Observer* obs){
    observers.emplace_back(obs);
    obs->attach(this);
}

void Player::changeCurrentBlock(char c){
    board->changeCurrent(c);
    if (!board->isAlive()) kill();
}

string charArrToString(const vector<vector<char>>& arr){
    stringstream ss;
    bool firstLine = true;
    for(auto y : arr) {
        if(!firstLine)ss << '\n';
        for(auto x : y) {
            ss << x;
        }
        firstLine = false;
    }
    return ss.str();
}

string Player::printToString(bool active){
    stringstream ss;
    //cout << "test: before level->getIdentifier" << endl;
    ss << "Level:" << setw(5) << level->getIdentifier() << '\n';
    ss << "Score:" << setw(5) << score << '\n';
    if(active){ 
        ss << "===========" << '\n';
    } else { 
        ss << "-----------" << '\n';
    }
    //cout << "test: before board.renderCharArray" << endl;
    vector<vector<char>> boardarr = board->renderCharArray();
    //cout << "test: before notifyObservers(boardarr)" << endl;
    notifyObservers(beforeTextDisplay, boardarr);
    notifyObservers(beforeTextDisplay, active);
    if(window) notifyObservers(beforeTextDisplay, *window); //random graphicdisplay code here
    ss << charArrToString(boardarr) << endl;
    if(active){ 
        ss << "===========" << '\n';
    } else { 
        ss << "-----------" << '\n';
    }
    ss << "Next:      " << '\n';
    //cout << "test: before printNextBlock()" << endl;
    ss << board->printNextBlock();
    return ss.str();
}

void Player::forceTopTile(const char b, const int col){
	board->forceTopColumnTile(b, col);
}

void Player::redrawBoard(){
    board->redrawBoard();
}
