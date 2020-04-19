#include "effect.h"

void Effect::update() {
	if (temp) {
		if (currentDur < duration) {
			++duration;
		} else {
			kill();
		}
	}
}
