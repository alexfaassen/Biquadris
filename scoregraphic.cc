#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       window->drawString(window->getOffsetX() + 221, 30, std::to_string(player->getScore()), PlayerWindow::Black); 
}
