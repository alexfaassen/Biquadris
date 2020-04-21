#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onScoreChange){
              window->fillRectangle(220, 19, 20, 20);
              window->drawString(221, 30, std::to_string(player->getScore())); 
       }
}
