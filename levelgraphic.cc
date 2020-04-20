#include "levelgraphic.h"
#include "player.h"
#include "playerwindow.h"

void LevelGraphic::notify(const Event currEvent, Move m){
       window->drawString(0, 10, "Level: " + player->isLevel(), PlayerWindow::Black);
}
