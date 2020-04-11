#include "observer.h"

bool Observer::isAlive() { return alive; }

void Observer::kill() { delete this; }
