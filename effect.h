#ifndef EFFECT_H
#define EFFECT_H
#include "observer.h"

class Effect : public Observer {
	protected:
	// default ctor
	Effect() : Observer() {}
};

#endif
