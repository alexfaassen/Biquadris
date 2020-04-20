#include "nextblockgraphic.h"
#include "player.h"
#include "playerwindow.h"

void NextBlockGraphic::notify(const Event currEvent, const char c){	
	window->drawString(0, 415, "Next:", PlayerWindow::Black);
}
