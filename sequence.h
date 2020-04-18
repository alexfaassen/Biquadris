#ifndef SEQ_H
#define SEQ_H
#include "command.h"

class Sequence : public Command {
	public:
	Sequence(const std::string name = "sequence", bool needClean = 0) : Command(name, needClean) {}
	private:
	void run(Gamestate &game, const int times = 1) const override;
};

#endif
