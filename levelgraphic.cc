#include "levelgraphic.h"
#include "player.h"
#include "playerwindow.h"

void LevelGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onLevelChange){
              window->fillRectangle(211, 1, 15, 10);
              window->drawString(216, 10, std::to_string(player->isLevel()));
       }
}
