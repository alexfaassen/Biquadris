#ifndef NEXTBLOCKGRAPHIC_H
#define NEXTBLOCKGRAPHIC_H

#include "graphicsobserver.h"

class PlayerWindow;

class NextBlockGraphic : public GraphicsObserver {

    public:
    NextBlockGraphic(PlayerWindow* w = nullptr): GraphicsObserver(w) {};
    void notify(const Event currEvent, const char c) override;
};

#endif

