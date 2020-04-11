#ifndef LEVEL2_H
#define LEVEL2_H

class Level2 : public Level {
	public:
	Level2(bool customSeed = 0, int seed = 0, int identifier = 0, std::ifstream *file = NULL, const int playerID);

	Block *CreateBlock() override;
};

#endif
