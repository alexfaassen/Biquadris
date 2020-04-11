#ifndef LEVEL1_H
#define LEVEL1_H

class Level1 : public Level {
	public:
	Level1(bool customSeed, int seed, int identifier = 1, std::ifstream *file, const int playerID);

	Block *CreateBlock() override;
};

#endif
