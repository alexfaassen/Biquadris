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

void Player::initDrawWindow(){
	window->drawBigString(5, 10, "Level:");
	window->drawBigString(221, 10, "0");
	window->drawBigString(5, 30, "Score:");
	window->drawBigString(221, 30, "0");
	window->fillRectangle(0, 35, 231, 3, PlayerWindow::White);
	window->fillRectangle(0, 425, 231, 3, PlayerWindow::White);
	window->drawBigString(5, 442, "Next:");
}

int Player::cleanObservers(){
    int cleaned = 0;
    for(size_t i = 0; i < observers.size(); i++){
        if(!observers.at(i)->isAlive()){
            delete observers.at(i);
            observers.erase(observers.begin()+i);
            ++cleaned;
            i--;
        }
    }
    return cleaned;
}

void Player::notifyObservers(Event ev, int i){
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, i);
    }
}

void Player::notifyObservers(Event ev, Move m){
    for(auto p : observers){
        if (p->isAlive()) p->notify(ev, m);
    }
}

void Player::notifyObservers(Event ev, const char c){
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

Player::Player(Xwindow* w, int offsetX, int offsetY, int side, string scriptFile, int startlevel, bool fastmode)
: side{side}, scriptFile {scriptFile}, fastmode{fastmode} {
    if(w){
        window = new PlayerWindow(w, offsetX, offsetY);
        initDrawWindow();
        initGraphicsObservers();
    }
    if(!setLevel(startlevel)){
        cout << "Error: invalid startlevel. Using Level 0 instead" << endl;
        setLevel(0);
    }
    board = new Board(level, window, fastmode);
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
    if(isInput) preMove();
    int moves = board->moveCurrent(dir, times);
    if(isInput) {
	    Move m = mLeft;
	    if (dir == Right) m = mRight;
	    else if (dir == Down) m = mDown;
	    postMoveClean(m);
    }
    if(window) notifyObservers(afterMove, *window);
    return moves;
}

int Player::rotateClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = board->clockwiseCurrent(times);
    if(isInput) postMoveClean(mClockwise);
    if(window) notifyObservers(afterMove, *window);
    return successes;
}

int Player::rotateCounterClockwise(int times, bool isInput){
    if(isInput){
        preMove();
    }
    int successes = board->counterClockwiseCurrent(times);
    if(isInput) postMoveClean(mCounterClockwise);
    if(window) notifyObservers(afterMove, *window);
    return successes;
}

void Player::drop(int times, bool isInput){
    if(isInput) preMove();
    cout << "in drop(), after preMove()" << endl;

    // handles everything except the last drop in a multi drop
    for(int i = 1; i < times; ++i){
        board->dropCurrent();
        board->placeCurrent();
        //if dead, break out of loop and ignore everything else
        if(!pushNextBlockAndCheck()) break;
    }
    cout << "after drop() loop" << endl;
    // handles the final drop
    if(times > 0){ 
	cout << "in loop" << endl;
        board->dropCurrent();
	cout << "before place current" << endl;
	board->placeCurrent();
       	endTurn();
        if(!board->isAlive()){
		setInputState(LOSS);
		kill();
	}
    }
    cout << "after second drop() loop"<< endl;
    if(isInput && times > 0){
        notifyObservers(onDrop);
        checkEndTurn();
    }
}

int Player::incLevel(int n){
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
    pushNextBlockAndCheck();
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
		level = new Level0(side, scriptFile);
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
	     if (n < 0 || n > 4) {
		     // Error, Invalid Input
	             return false;
	     } else if (n == level->getIdentifier()) {
		     return true;
 	     } else {
		     Level *temp = level;
	     	     if (n == 0) {
			        level = new Level0(*temp, scriptFile);
	             } else if (n == 1) {
	                level = new Level1(*temp);
	     	     } else if (n == 2) {
	     		    level = new Level2(*temp);
	     	     } else if (n == 3) {
		   	        level = new Level3(*temp);
		    	    level->generateEffects(*this);
	     	     } else if (n == 4) {
		  	        level = new Level4(*temp);
		   	        level->generateEffects(*this);
	    	     }
                     delete temp;
	             temp = NULL;
	     }
    }
    cleanObservers();
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
    ss << "Level:" << setw(5) << level->getIdentifier() << '\n';
    ss << "Score:" << setw(5) << score << '\n';
    if(active){ 
        ss << "===========" << '\n';
    } else { 
        ss << "-----------" << '\n';
    }
    vector<vector<char>> boardarr = board->renderCharArray();
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
    ss << board->printNextBlock();
    return ss.str();
}

void Player::forceTopTile(const char b, const int col){
	board->forceTopColumnTile(b, col);
}

void Player::redrawBoard(){
    board->redrawBoard();
}
