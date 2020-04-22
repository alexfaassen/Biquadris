#include "levelgraphic.h"
#include "player.h"
#include "playerwindow.h"

void LevelGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onLevelChange){
              window->fillRectangle(210, 1, 20, 15);
              window->drawString(221, 10, std::to_string(player->isLevel()));
       }
}
