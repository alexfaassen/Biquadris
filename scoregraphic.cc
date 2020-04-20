#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       window->drawString(0, 30, "Score: " + player->getScore(), Xwindow::Black); 
}
