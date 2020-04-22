#ifndef SCOREGRAPHIC_H
#define SCOREGRAPHIC_H

#include "graphicsobserver.h"

class PlayerWindow;

class ScoreGraphic : public GraphicsObserver {

    public:
    ScoreGraphic(PlayerWindow* w = nullptr): GraphicsObserver(w) {};
    void notify(const Event currEvent, Move) override;
};

#endif

