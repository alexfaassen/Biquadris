#include "player.h"
#include "observer.h"

using namespace std;

void Player::initGraphicsObservers(){
    //TODO
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
    //TODO
}

void Player::startTurn(){
    setInputState(NORMAL);
    notifyObservers(onTurnStart);
}

void Player::endTurn(){
    notifyObservers(onTurnEnd);
    setInputState(END_TURN);
}

bool Player::setLevel(int){
}