#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	window->fillRectangle(1, 442, 84, 483);
	Block tempBlock(c, -1, 1, 442);
	tempBlock.attachWindow(window);
	tempBlock.draw();
}
