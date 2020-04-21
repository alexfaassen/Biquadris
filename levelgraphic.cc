#include "levelgraphic.h"
#include "player.h"
#include "playerwindow.h"

void LevelGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onLevelChange){
              //TODO: fill the area with white first!
              window->drawString(221, 10, std::to_string(player->isLevel()));
       }
}
