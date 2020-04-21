#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	window->fillRectangle(1, 443, 84, 484);
	Block tempBlock(c, -1, 1, 443);
	tempBlock.attachWindow(window);
	tempBlock.draw();
}
