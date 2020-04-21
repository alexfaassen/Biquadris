#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onScoreChange){
              //TODO: draw white square over old score
              window->drawString(221, 30, std::to_string(player->getScore())); 
       }
}
