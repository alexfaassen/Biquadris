#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"

class PlayerWindow;

class GraphicsObserver : public Observer {
    protected:
    PlayerWindow* window = nullptr;

    GraphicsObserver(PlayerWindow* w);

};

#endif