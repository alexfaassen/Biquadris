#ifndef LEVEL2_H
#define LEVEL2_H

class Level2 : public Level {
	public:
	Level2(bool customSeed, int seed, int identifier = 2, std::ifstream *file, const int playerID);

	Block *CreateBlock() override;
};

#endif
