#include "turngraphic.h"
#include "player.h"
#include "playerwindow.h"

void TurnGraphic::notify(const Event currEvent, int active){
    // active acts like a bool.  0 is false, 1 is true
    
    if(currEvent == beforeTextDisplay){
        //TODO: draw turngraphic
        if(active){
            window->fillRectangle(200, 482,  20,  20, PlayerWindow::Yellow);
        } else {
            window->fillRectangle(200, 482,  20,  20, PlayerWindow::Black);
        }
    }
}
