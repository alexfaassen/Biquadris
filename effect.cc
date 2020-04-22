#include "effect.h"
#include <iostream>

void Effect::update() {
	//std::cout << "Effect update" <<std::endl;
	if (temp) {
		if (currentDur < duration) {
			++duration;
		} else {
			kill();
		}
	}
}

