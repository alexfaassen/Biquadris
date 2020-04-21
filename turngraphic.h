#ifndef TURNGRAPHIC_H
#define TURNGRAPHIC_H

#include "graphicsobserver.h"

class PlayerWindow;

class TurnGraphic : public GraphicsObserver {

    public:
    TurnGraphic(PlayerWindow* w = nullptr): GraphicsObserver(w) {};
    void notify(const Event currEvent, const int active) override;
};

#endif