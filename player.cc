#include "player.h"
#include "observer.h"

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
    //TODO once board is implemented
}

int Player::rotateClockWise(int times, bool isInput = false){
    //TODO once board is implemented
}

int Player::rotateCounterClockwise(int times, bool isInput = false){
    //TODO once board is implemented
}

int Player::drop(bool isInput = false){
    //TODO once board is implemented
}

bool Player::incLevel(int n){
       int currlvl = level->getLevel();
       int newlvl = currlvl + n;
       if (newlvl == currlvl) {
	       return 0;
       } else if (newlvl >= 4) {
	       if (currlvl == 4) return 0;
	       Level *temp{level};
	       level = new Level4(level);
	       delete temp;
	       temp = NULL;
       } else if (newlvl <= 0) {
	       if (currlvl == 0) return 0;
	       Level *temp{level};
	       level = new Level0(level);
	       delete temp;
	       temp = NULL;
       } else if (newlvl == 1) {
	       Level *temp{level};
	       level = new Level1(level);
	       delete temp;
	       temp = NULL;
       } else if (newlvl == 2) {
	       Level *temp{level};
	       level = new Level2{level};
	       delete temp;
	       temp = NULL;
       } else if (newlvl == 3) {
	       Level *temp{level};
	       level = new Level3{level};
	       delete temp;
	       temp = NULL;
       }
       return 1;
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
    //TODO
}

bool Player::setFileInput(fstream* stream){
    //TODO
}

void Player::specialAction(){
    setInputState(SA);
}   

void Player::pushToObservers(Observer* obs){
    observers.emplace_back(obs);
    obs->attach(this);
}

void Player::changeCurrentBlock(Block* block){
    //TODO once board is implemented
}

string Player::printToString(){
    //TODO
}

void Player::forceTopTile(Tile* tile){
	board->forceTopColumnTile(tile);
}
