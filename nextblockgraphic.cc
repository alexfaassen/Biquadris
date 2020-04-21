#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	if(currEvent == onNextBlockChange){
		window->fillRectangle(1, 442, 84, 483, PlayerWindow::White);
		Block tempBlock(c, -1);
		tempBlock.attachWindow(window);
		tempBlock.customDraw(1, 462);
	}
}
