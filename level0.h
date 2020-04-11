#ifndef LEVEL0_H
#define LEVEL0_H

class Level0 : public Level {
	public:
	Level0(int seed = 1, int identifier = 0, std::ifstream *file = NULL, const int playerID);

	Block *CreateBlock() override;
};

#endif
