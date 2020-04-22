#include "blind.h"
#include "blindeffect.h"
#include "gamestate.h"

void Blind::run(GameState &game, const int times) const {
    game.getNAP().pushToObservers(new BlindEffect(true)); 
    if(game.getNAP().getInputState() == END_TURN) game.getNAP().notifyObservers(onSAapplied);
}
