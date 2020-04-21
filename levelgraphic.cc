#include "levelgraphic.h"
#include "player.h"
#include "playerwindow.h"

void LevelGraphic::notify(const Event currEvent, Move m){
       window->drawString(window->getOffsetX() + 221, 10, std::to_string(player->isLevel()), PlayerWindow::Black);
}
