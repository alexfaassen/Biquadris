#include "turngraphic.h"
#include "player.h"
#include "playerwindow.h"
#include <cmath>

void TurnGraphic::notify(const Event currEvent, int active){
    // active acts like a bool.  0 is false, 1 is true
    
    if(currEvent == beforeTextDisplay){
        //TODO: draw turngraphic
        if(active){
            //window->fillRectangle(180, 442,  30,  30, PlayerWindow::Yellow);
            window->fillPolygon(220, 472, 3, 40, 0, PlayerWindow::White);
        } else {
            window->fillRectangle(180, 435,  40,  40, PlayerWindow::Black);
        }
    }
}
