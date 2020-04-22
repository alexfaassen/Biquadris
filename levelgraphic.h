#ifndef LEVELGRAPHIC_H
#define LEVELGRAPHIC_H

#include "graphicsobserver.h"

class PlayerWindow;

class LevelGraphic : public GraphicsObserver {

    public:
    LevelGraphic(PlayerWindow* w = nullptr): GraphicsObserver(w) {};
    void notify(const Event currEvent, Move) override;
};

#endif

