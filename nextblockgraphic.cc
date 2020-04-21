#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	if(currEvent == onNextBlockChange){
		window->fillRectangle(1, 441, 84, 483);
		Block tempBlock(c, -1);
		tempBlock.nowNotCurr();
		tempBlock.attachWindow(window);
		tempBlock.customDraw(1, 462);
	}
}
