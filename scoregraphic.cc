#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       window->drawString(window->getOffsetX() + 205, 30, std::to_string(player->getScore()), PlayerWindow::Black); 
}
