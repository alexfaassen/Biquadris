#include "scoregraphic.h"
#include "player.h"
#include "playerwindow.h"

void ScoreGraphic::notify(const Event currEvent, Move m){
       if(currEvent == onScoreChange){
              window->fillRectangle(211, 19, 15, 10);
	      int over = player->getScore() / 10;
	      int i = 0;
	      while(over != 0){
		      over /= 10;
		      ++i;
	      }
              window->drawString(216 - (i * 4), 29, std::to_string(player->getScore())); 
       }
}
