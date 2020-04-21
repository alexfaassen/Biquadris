#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	if(currEvent == onNextBlockChange){
		window->fillRectangle(1, 446, 84, 42);
		Block tempBlock(c, -1);
		tempBlock.nowNotCurr();
		tempBlock.attachWindow(window);
		tempBlock.customDraw(1, 467);
	}
}
