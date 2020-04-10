#ifndef EFFECT_H
#define EFFECT_H
#include "observer.h"

class Effect : public Observer {
	public:
	virtual void notify(const enum Event, const int linesCleared) = 0;
	virtual void notify(const enum Event, char[][] &boardPrint) = 0;
};

#endif
