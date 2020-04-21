#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"
#include "block.h"
#include <iostream>

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	window->fillRectangle(1, 442, 84, 483, PlayerWindow::White);
	Block *tempBlock = new Block(c, -1, 0, 1, 442);
	std::cout << "tempBlock.getType() = " << tempBlock->getType() << std::endl;
	tempBlock->attachWindow(window);
	tempBlock->draw();
	delete tempBlock;
	std::cout << "tempBlock.draw() happening" << std::endl;
}
