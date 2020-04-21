#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

using namespace std;

void ScoreGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onScoreChange){
              //TODO: draw white square over old score
              window->drawString(221, 30, to_string(player->getScore()), PlayerWindow::Black); 
       }
}
